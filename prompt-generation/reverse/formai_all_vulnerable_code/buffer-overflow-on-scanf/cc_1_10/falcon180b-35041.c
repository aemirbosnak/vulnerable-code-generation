//Falcon-180B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

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

int main() {
    struct password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter name of website/service (or 'exit' to quit): ");
        scanf("%s", name);

        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter password for %s: ", name);
        scanf("%s", password);

        add_password(passwords, num_passwords, name, password);
    }

    printf("\nPasswords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }

    return 0;
}