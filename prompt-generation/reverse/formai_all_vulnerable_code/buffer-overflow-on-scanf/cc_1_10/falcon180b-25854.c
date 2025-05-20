//Falcon-180B DATASET v1.0 Category: Password management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

struct password {
    char service[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    int num_passwords = 0;
    struct password passwords[MAX_PASSWORDS];

    char input[MAX_PASSWORD_LENGTH];
    printf("Welcome to the password manager!\n");
    printf("Enter a service name: ");
    scanf("%s", input);

    while (1) {
        printf("\nEnter a command:\n");
        printf("1. Add a new password\n");
        printf("2. Retrieve a password\n");
        printf("3. Exit\n");
        scanf("%d", &num_passwords);

        if (num_passwords == 1) {
            printf("Enter a username: ");
            scanf("%s", input);

            printf("Enter a password: ");
            scanf("%s", input);

            strcpy(passwords[num_passwords - 1].service, input);
            strcpy(passwords[num_passwords - 1].username, input);
            strcpy(passwords[num_passwords - 1].password, input);

            num_passwords++;
            printf("\nPassword added successfully!\n");
        } else if (num_passwords == 2) {
            printf("Enter a service name: ");
            scanf("%s", input);

            int i;
            for (i = 0; i < num_passwords; i++) {
                if (strcmp(passwords[i].service, input) == 0) {
                    printf("\nUsername: %s\n", passwords[i].username);
                    printf("Password: %s\n", passwords[i].password);
                }
            }
        } else if (num_passwords == 3) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}