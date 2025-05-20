//Falcon-180B DATASET v1.0 Category: Password management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100
#define MAX_USERNAME_LENGTH 100

struct password {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    int num_passwords = 0;
    struct password passwords[MAX_PASSWORDS];

    while (num_passwords < MAX_PASSWORDS) {
        printf("Enter username: ");
        scanf("%s", passwords[num_passwords].username);

        printf("Enter password: ");
        char password_input[MAX_PASSWORD_LENGTH];
        scanf("%s", password_input);
        strcpy(passwords[num_passwords].password, password_input);

        num_passwords++;
    }

    printf("Enter username to search for: ");
    char search_username[MAX_USERNAME_LENGTH];
    scanf("%s", search_username);

    int search_result = -1;

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, search_username) == 0) {
            search_result = i;
            break;
        }
    }

    if (search_result == -1) {
        printf("User not found.\n");
    } else {
        printf("Password: %s\n", passwords[search_result].password);
    }

    return 0;
}