//Falcon-180B DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);
    num_passwords++;
}

void remove_password(char *username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);
            num_passwords--;
            break;
        }
    }
}

void list_passwords() {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

char *generate_password(int length) {
    char *password = malloc(length + 1);
    int i;

    for (i = 0; i < length; i++) {
        password[i] = rand() % 26 + 'a';
    }

    password[length] = '\0';
    return password;
}

int main() {
    char *username;
    char *password;
    int length;

    srand(time(0));

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password length (minimum 8): ");
        scanf("%d", &length);

        if (length < 8) {
            printf("Error: Password must be at least 8 characters long.\n");
            continue;
        }

        password = generate_password(length);
        add_password(username, password);
        printf("Password generated: %s\n", password);
    }

    return 0;
}