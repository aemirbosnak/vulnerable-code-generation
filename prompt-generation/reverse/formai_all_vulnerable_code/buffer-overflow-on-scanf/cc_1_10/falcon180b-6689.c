//Falcon-180B DATASET v1.0 Category: Password management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64
#define HASH_LENGTH 32

struct password {
    char *name;
    char *hash;
};

void generate_hash(char *password, char *hash) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        char c = tolower(password[i]);
        hash[i] = c + (i * 31);
    }
    hash[i] = '\0';
}

int compare_hash(char *password, char *hash) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        char c = tolower(password[i]);
        if (hash[i]!= c + (i * 31)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    struct password passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char input[MAX_PASSWORD_LENGTH];

    memset(passwords, 0, sizeof(passwords));

    while (1) {
        printf("Enter a command (add, delete, list, exit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter the name of the password: ");
            scanf("%s", input);

            if (num_passwords >= MAX_PASSWORDS) {
                printf("Maximum number of passwords reached.\n");
            } else {
                printf("Enter the password: ");
                scanf("%s", input);

                char hash[HASH_LENGTH];
                generate_hash(input, hash);

                passwords[num_passwords].name = strdup(input);
                passwords[num_passwords].hash = strdup(hash);

                num_passwords++;
            }
        } else if (strcmp(input, "delete") == 0) {
            printf("Enter the name of the password to delete: ");
            scanf("%s", input);

            int i;
            for (i = 0; i < num_passwords; i++) {
                if (strcmp(passwords[i].name, input) == 0) {
                    free(passwords[i].name);
                    free(passwords[i].hash);

                    passwords[i] = passwords[num_passwords - 1];
                    num_passwords--;

                    break;
                }
            }
        } else if (strcmp(input, "list") == 0) {
            printf("Passwords:\n");
            for (int i = 0; i < num_passwords; i++) {
                printf("%s\n", passwords[i].name);
            }
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}