//Falcon-180B DATASET v1.0 Category: Password management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

struct password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void add_password(struct password *passwords, int num_passwords, char *name, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].name, name);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void delete_password(struct password *passwords, int num_passwords, char *name) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            memset(passwords[i].name, 0, MAX_PASSWORD_LENGTH);
            memset(passwords[i].password, 0, MAX_PASSWORD_LENGTH);

            num_passwords--;
            break;
        }
    }
}

void print_passwords(struct password *passwords, int num_passwords) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("Name: %s\nPassword: %s\n", passwords[i].name, passwords[i].password);
    }
}

int main() {
    struct password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter password: ");
        scanf("%s", password);

        add_password(passwords, num_passwords, name, password);
    }

    return 0;
}