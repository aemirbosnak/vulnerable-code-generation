//Falcon-180B DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char *username;
    char *password;
} Password;

int main() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    Password *passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char choice;
    int i;

    do {
        printf("Enter your username: ");
        scanf("%s", username);
        printf("Enter your password: ");
        scanf("%s", password);

        for (i = 0; i < num_passwords; i++) {
            if (strcmp(passwords[i]->username, username) == 0) {
                printf("Password already exists.\n");
                break;
            }
        }

        if (i == num_passwords) {
            passwords[num_passwords] = (Password *)malloc(sizeof(Password));
            passwords[num_passwords]->username = strdup(username);
            passwords[num_passwords]->password = strdup(password);
            num_passwords++;
        }

        printf("Do you want to add another password? (y/n)\n");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Enter your username: ");
    scanf("%s", username);

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i]->username, username) == 0) {
            printf("Password: %s\n", passwords[i]->password);
        }
    }

    return 0;
}