//Falcon-180B DATASET v1.0 Category: Password management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_password(char* password, int length) {
    const char* characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+=[{]}\\|;:'\",<.>/? ";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = characters[rand() % strlen(characters)];
    }

    password[length] = '\0';
}

int main() {
    int choice;
    char input[100];

    do {
        printf("Welcome to the Password Management System!\n");
        printf("1. Generate a new password\n");
        printf("2. Save a password\n");
        printf("3. Retrieve a password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the desired length of the password: ");
                scanf("%d", &passwords[num_passwords].length);
                generate_password(passwords[num_passwords].password, passwords[num_passwords].length);
                num_passwords++;
                printf("Password generated and saved.\n");
                break;
            case 2:
                printf("Enter the password to save: ");
                scanf("%s", input);
                strcpy(passwords[num_passwords].password, input);
                num_passwords++;
                printf("Password saved.\n");
                break;
            case 3:
                printf("Enter the index of the password to retrieve: ");
                scanf("%d", &choice);
                if (choice >= 0 && choice < num_passwords) {
                    printf("Password: %s\n", passwords[choice].password);
                } else {
                    printf("Invalid index.\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}