//Falcon-180B DATASET v1.0 Category: Password management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generate_password(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    char username[MAX_USERNAME_LENGTH];
    printf("Enter thy noble username: ");
    scanf("%s", username);

    while (1) {
        printf("\nWhat dost thou wish to do?\n");
        printf("1. Enter a new password\n");
        printf("2. View all passwords\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            if (num_passwords >= MAX_PASSWORDS) {
                printf("Thou hast reached the limit of passwords! Pray, delete one before entering a new one.\n");
            } else {
                printf("Enter the name of the realm for which thou needest a password: ");
                scanf("%s", passwords[num_passwords].username);
                generate_password(passwords[num_passwords].password, strlen(passwords[num_passwords].username));
                printf("Password for %s: %s\n", passwords[num_passwords].username, passwords[num_passwords].password);
                num_passwords++;
            }
        } else if (choice == 2) {
            for (int i = 0; i < num_passwords; i++) {
                printf("%s: %s\n", passwords[i].username, passwords[i].password);
            }
        } else if (choice == 3) {
            printf("Farewell, noble user!\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}