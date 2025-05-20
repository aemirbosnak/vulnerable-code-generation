//Falcon-180B DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char choice;

    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (num_passwords >= MAX_PASSWORDS) {
                printf("Maximum number of passwords reached!\n");
            } else {
                printf("Enter website: ");
                scanf("%s", passwords[num_passwords].website);
                printf("Enter username: ");
                scanf("%s", passwords[num_passwords].username);
                printf("Enter password: ");
                scanf("%s", passwords[num_passwords].password);
                num_passwords++;
            }
            break;

        case '2':
            printf("\nList of passwords:\n");
            for (int i = 0; i < num_passwords; i++) {
                printf("Website: %s\nUsername: %s\nPassword: %s\n", passwords[i].website, passwords[i].username, passwords[i].password);
            }
            break;

        case '3':
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}