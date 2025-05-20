//Falcon-180B DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    int numPasswords = 0;
    Password passwords[MAX_PASSWORDS];

    char choice;

    do {
        printf("Enter choice:\n");
        printf("1. Add password\n2. Remove password\n3. Search password\n4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (numPasswords >= MAX_PASSWORDS) {
                printf("Maximum number of passwords reached!\n");
            } else {
                printf("Enter username:\n");
                scanf("%s", passwords[numPasswords].username);
                printf("Enter password:\n");
                scanf("%s", passwords[numPasswords].password);
                numPasswords++;
            }
            break;

        case '2':
            printf("Enter username to remove:\n");
            char username[MAX_USERNAME_LENGTH];
            scanf("%s", username);

            int i;
            for (i = 0; i < numPasswords; i++) {
                if (strcmp(passwords[i].username, username) == 0) {
                    strcpy(passwords[i].username, "");
                    strcpy(passwords[i].password, "");
                    numPasswords--;
                    break;
                }
            }

            if (i == numPasswords) {
                printf("Username not found!\n");
            }

            break;

        case '3':
            printf("Enter username to search:\n");
            char searchUsername[MAX_USERNAME_LENGTH];
            scanf("%s", searchUsername);

            int j;
            for (j = 0; j < numPasswords; j++) {
                if (strcmp(passwords[j].username, searchUsername) == 0) {
                    printf("Password: %s\n", passwords[j].password);
                }
            }

            break;

        case '4':
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice!= '4');

    return 0;
}