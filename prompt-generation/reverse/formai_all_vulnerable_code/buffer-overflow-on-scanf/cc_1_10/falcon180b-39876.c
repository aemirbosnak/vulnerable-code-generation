//Falcon-180B DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char username[50];
    char password[50];
} User;

int main() {
    int choice;
    User user;

    do {
        printf("1. Create account\n2. Login\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", user.username);
                printf("Enter password: ");
                scanf("%s", user.password);
                printf("Account created successfully.\n");
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", user.username);
                printf("Enter password: ");
                scanf("%s", user.password);

                if(strcmp(user.username, "admin") == 0 && strcmp(user.password, "password") == 0) {
                    printf("Login successful.\n");
                } else {
                    printf("Login failed.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while(choice!= 3);

    return 0;
}