//Falcon-180B DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char* username;
    char* password;
} Password;

Password* passwords = NULL;
int num_passwords = 0;

void add_password(char* username, char* password) {
    Password* new_password = malloc(sizeof(Password));
    strcpy(new_password->username, username);
    strcpy(new_password->password, password);
    passwords = realloc(passwords, sizeof(Password) * (num_passwords + 1));
    passwords[num_passwords] = *new_password;
    num_passwords++;
}

int authenticate(char* username, char* password) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0 && strcmp(passwords[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char* username = "admin";
    char* password = "password123";

    add_password(username, password);

    char* input_username = malloc(MAX_PASSWORD_LENGTH);
    char* input_password = malloc(MAX_PASSWORD_LENGTH);

    while (1) {
        printf("Username: ");
        scanf("%s", input_username);
        printf("Password: ");
        scanf("%s", input_password);

        if (authenticate(input_username, input_password)) {
            printf("Login successful!\n");
            break;
        } else {
            printf("Login failed. Please try again.\n");
        }
    }

    return 0;
}