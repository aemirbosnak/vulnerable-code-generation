//Falcon-180B DATASET v1.0 Category: Password management ; Style: visionary
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    int length;
} Password;

void generatePassword(char* password, int length) {
    const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        password[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    password[length] = '\0';
}

int main() {
    int choice;
    char username[MAX_PASSWORD_LENGTH];
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    do {
        printf("Enter username: ");
        scanf("%s", username);

        if (numPasswords == MAX_PASSWORDS) {
            printf("Maximum number of passwords reached.\n");
        } else {
            printf("Enter password length: ");
            scanf("%d", &passwords[numPasswords].length);
            generatePassword(passwords[numPasswords].password, passwords[numPasswords].length);
            strcpy(passwords[numPasswords].username, username);
            numPasswords++;
        }

        printf("1. Generate new password\n2. View passwords\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                break;
            case 2:
                for (int i = 0; i < numPasswords; i++) {
                    printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

    } while(1);

    return 0;
}