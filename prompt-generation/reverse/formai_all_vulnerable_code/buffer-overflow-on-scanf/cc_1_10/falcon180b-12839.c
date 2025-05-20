//Falcon-180B DATASET v1.0 Category: Password management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generate_password(char *password) {
    int length = rand() % MAX_PASSWORD_LENGTH + 8;
    for (int i = 0; i < length; i++) {
        password[i] = rand() % 26 + 'a';
    }
    password[length] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    char username[MAX_USERNAME_LENGTH];
    while (1) {
        printf("Enter username: ");
        scanf("%s", username);

        int found = 0;
        for (int i = 0; i < num_passwords; i++) {
            if (strcmp(passwords[i].username, username) == 0) {
                printf("Password: %s\n", passwords[i].password);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Invalid username.\n");
            continue;
        }

        char action;
        printf("Enter action (c/d): ");
        scanf(" %c", &action);

        if (action == 'c') {
            char website[MAX_USERNAME_LENGTH];
            printf("Enter website: ");
            scanf("%s", website);

            generate_password(passwords[num_passwords].password);
            strcpy(passwords[num_passwords].username, username);
            strcat(passwords[num_passwords].username, "@");
            strcat(passwords[num_passwords].username, website);
            num_passwords++;

            printf("Password generated and saved for %s@%s.\n", username, website);
        } else if (action == 'd') {
            int index;
            printf("Enter index of password to delete: ");
            scanf("%d", &index);

            if (index >= 0 && index < num_passwords) {
                printf("Deleting password for %s@%s...\n", passwords[index].username, passwords[index].username + strlen(username) + 1);
                memset(passwords[index].password, 0, MAX_PASSWORD_LENGTH);
            } else {
                printf("Invalid index.\n");
            }
        } else {
            printf("Invalid action.\n");
        }
    }

    return 0;
}