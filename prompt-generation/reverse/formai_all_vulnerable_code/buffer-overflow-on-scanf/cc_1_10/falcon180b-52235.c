//Falcon-180B DATASET v1.0 Category: Password management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

int main(void) {
    int num_passwords = 0;
    password_t passwords[MAX_PASSWORDS];

    char choice;
    do {
        printf("\nWelcome to the Password Management System!\n");
        printf("Please select an option:\n");
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. View passwords\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_passwords >= MAX_PASSWORDS) {
                    printf("Error: Maximum number of passwords reached.\n");
                } else {
                    printf("Enter name for password: ");
                    scanf("%s", passwords[num_passwords].name);
                    printf("Enter password: ");
                    scanf("%s", passwords[num_passwords].password);
                    num_passwords++;
                }
                break;
            case '2':
                if (num_passwords == 0) {
                    printf("Error: No passwords to delete.\n");
                } else {
                    printf("Enter name of password to delete: ");
                    scanf("%s", passwords[num_passwords - 1].name);
                    memset(passwords[num_passwords - 1].password, 0, strlen(passwords[num_passwords - 1].password));
                    num_passwords--;
                }
                break;
            case '3':
                printf("Passwords:\n");
                for (int i = 0; i < num_passwords; i++) {
                    printf("%s: %s\n", passwords[i].name, passwords[i].password);
                }
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Error: Invalid option.\n");
        }
    } while (choice!= '4');

    return 0;
}