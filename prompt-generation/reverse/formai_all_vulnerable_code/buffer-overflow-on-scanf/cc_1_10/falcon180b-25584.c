//Falcon-180B DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    int num_passwords = 0;
    Password passwords[MAX_PASSWORDS];

    while (num_passwords < MAX_PASSWORDS) {
        printf("Enter username (or 'done' to quit): ");
        scanf("%s", passwords[num_passwords].username);

        if (strcmp(passwords[num_passwords].username, "done") == 0) {
            break;
        }

        printf("Enter password: ");
        scanf("%s", passwords[num_passwords].password);

        num_passwords++;
    }

    printf("\n");

    while (1) {
        char username[MAX_PASSWORD_LENGTH];
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
            printf("User not found.\n");
        }
    }

    return 0;
}