//Falcon-180B DATASET v1.0 Category: Password management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

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

int find_password(char *username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }

    return -1;
}

void delete_password(int index) {
    if (index >= 0 && index < num_passwords) {
        free(passwords[index].username);
        free(passwords[index].password);

        for (int i = index; i < num_passwords - 1; i++) {
            passwords[i] = passwords[i + 1];
        }

        num_passwords--;
    } else {
        printf("Error: Invalid password index.\n");
    }
}

int main() {
    char *username = "my_love";
    char *password = "our_secret";

    add_password(username, password);

    int index = find_password(username);
    if (index >= 0) {
        printf("Password found: %s\n", passwords[index].password);
    } else {
        printf("Password not found.\n");
    }

    delete_password(index);

    return 0;
}