//Falcon-180B DATASET v1.0 Category: Password management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char username[50];
    char password[50];
    time_t last_modified;
} User;

int main() {
    FILE *fp;
    User user;
    char choice;
    int i = 0;

    fp = fopen("users.txt", "rb");
    if (fp == NULL) {
        fp = fopen("users.txt", "wb");
    }

    while (1) {
        printf("\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter username: ");
                scanf("%s", user.username);

                while (1) {
                    printf("Enter password: ");
                    scanf("%s", user.password);

                    if (strlen(user.password) >= 8 && (isalpha(user.password[0]) || isdigit(user.password[0]))) {
                        break;
                    } else {
                        printf("Password must be at least 8 characters long and contain at least one letter or number.\n");
                    }
                }

                if (fp == NULL) {
                    fp = fopen("users.txt", "wb");
                }

                fseek(fp, 0, SEEK_END);
                fprintf(fp, "%s|%s|%ld\n", user.username, user.password, time(NULL));
                printf("Account created successfully!\n");
                break;

            case '2':
                printf("Enter username: ");
                scanf("%s", user.username);

                if (fp == NULL) {
                    printf("No users found.\n");
                    break;
                }

                rewind(fp);

                while (fscanf(fp, "%s|%s|%ld", user.username, user.password, &user.last_modified)!= EOF) {
                    if (strcmp(user.username, user.username) == 0) {
                        printf("Enter password: ");
                        scanf("%s", user.password);

                        if (strcmp(user.password, user.password) == 0) {
                            printf("Login successful!\n");
                            break;
                        } else {
                            printf("Incorrect password.\n");
                        }
                    }
                }

                break;

            case '3':
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}