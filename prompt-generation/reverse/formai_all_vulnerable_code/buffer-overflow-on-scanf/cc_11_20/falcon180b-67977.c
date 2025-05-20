//Falcon-180B DATASET v1.0 Category: Password management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 32

typedef struct {
    char username[32];
    char password[PASSWORD_LENGTH];
    int length;
} password_t;

int main() {
    password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char input[80];

    while (1) {
        printf("Enter a command:\n");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            if (num_passwords >= MAX_PASSWORDS) {
                printf("Maximum number of passwords reached.\n");
            } else {
                printf("Enter username: ");
                scanf("%s", passwords[num_passwords].username);

                printf("Enter password: ");
                scanf("%s", passwords[num_passwords].password);

                passwords[num_passwords].length = strlen(passwords[num_passwords].password);
                num_passwords++;
            }
        } else if (strcmp(input, "delete") == 0) {
            printf("Enter username: ");
            scanf("%s", input);

            int i;
            for (i = 0; i < num_passwords; i++) {
                if (strcmp(passwords[i].username, input) == 0) {
                    memset(passwords[i].password, 0, PASSWORD_LENGTH);
                    passwords[i].length = 0;
                    break;
                }
            }
        } else if (strcmp(input, "view") == 0) {
            printf("Enter username: ");
            scanf("%s", input);

            int i;
            for (i = 0; i < num_passwords; i++) {
                if (strcmp(passwords[i].username, input) == 0) {
                    printf("Password: %s\n", passwords[i].password);
                    break;
                }
            }
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}