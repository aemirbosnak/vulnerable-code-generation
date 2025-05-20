//Falcon-180B DATASET v1.0 Category: Password management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    time_t last_updated;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_password(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }

    password[length] = '\0';
}

int main() {
    int choice, length;
    char password[MAX_PASSWORD_LENGTH];

    srand(time(NULL));

    while (1) {
        printf("Password Manager\n");
        printf("1. Generate new password\n");
        printf("2. Save password\n");
        printf("3. View saved passwords\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter password length: ");
                scanf("%d", &length);
                generate_password(password, length);
                printf("Generated password: %s\n", password);
                break;

            case 2:
                if (num_passwords >= MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                } else {
                    printf("Enter password: ");
                    scanf("%s", password);
                    strcpy(passwords[num_passwords].password, password);
                    passwords[num_passwords].last_updated = time(NULL);
                    num_passwords++;
                }
                break;

            case 3:
                if (num_passwords == 0) {
                    printf("No passwords saved.\n");
                } else {
                    printf("Saved passwords:\n");
                    int i;
                    for (i = 0; i < num_passwords; i++) {
                        printf("%s - Last updated: %s\n", passwords[i].password, ctime(&passwords[i].last_updated));
                    }
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}