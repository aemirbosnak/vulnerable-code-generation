//Falcon-180B DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords == MAX_PASSWORDS) {
        printf("Error: maximum number of passwords (%d) reached.\n", MAX_PASSWORDS);
        return;
    }

    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);

    num_passwords++;
}

void remove_password(int index) {
    if (index < 0 || index >= num_passwords) {
        printf("Error: invalid password index.\n");
        return;
    }

    free(passwords[index].username);
    free(passwords[index].password);

    for (int i = index; i < num_passwords - 1; i++) {
        passwords[i] = passwords[i + 1];
    }

    num_passwords--;
}

void update_password(int index, char *new_password) {
    if (index < 0 || index >= num_passwords) {
        printf("Error: invalid password index.\n");
        return;
    }

    free(passwords[index].password);
    passwords[index].password = strdup(new_password);
}

void print_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    add_password("example1", "password1");
    add_password("example2", "password2");
    add_password("example3", "password3");

    print_passwords();

    remove_password(1);

    print_passwords();

    update_password(1, "new_password1");

    print_passwords();

    return 0;
}