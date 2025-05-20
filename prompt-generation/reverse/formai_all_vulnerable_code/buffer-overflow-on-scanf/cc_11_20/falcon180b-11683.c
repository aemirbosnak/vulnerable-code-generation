//Falcon-180B DATASET v1.0 Category: Password management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 32

typedef struct {
    char password[PASSWORD_LENGTH];
    int length;
} Password;

int main() {
    char input[100];
    char *password;
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    printf("Welcome to the password manager!\n");
    while (1) {
        printf("Enter a command (add/remove/list/exit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter the password to add: ");
            password = malloc(PASSWORD_LENGTH * sizeof(char));
            scanf("%s", password);

            for (int i = 0; i < strlen(password); i++) {
                if (!isalpha(password[i])) {
                    printf("Password must only contain letters.\n");
                    free(password);
                    continue;
                }
            }

            strcpy(passwords[num_passwords].password, password);
            passwords[num_passwords].length = strlen(password);
            num_passwords++;

            printf("Password added successfully!\n");
        } else if (strcmp(input, "remove") == 0) {
            printf("Enter the password to remove: ");
            scanf("%s", input);

            for (int i = 0; i < num_passwords; i++) {
                if (strcmp(passwords[i].password, input) == 0) {
                    memset(passwords[i].password, 0, PASSWORD_LENGTH);
                    num_passwords--;
                    printf("Password removed successfully!\n");
                    break;
                }
            }
        } else if (strcmp(input, "list") == 0) {
            printf("Passwords:\n");
            for (int i = 0; i < num_passwords; i++) {
                printf("%s (%d characters)\n", passwords[i].password, passwords[i].length);
            }
        } else if (strcmp(input, "exit") == 0) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}