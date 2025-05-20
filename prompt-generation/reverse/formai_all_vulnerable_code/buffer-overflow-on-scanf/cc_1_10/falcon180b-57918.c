//Falcon-180B DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *name, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }
    strcpy(passwords[num_passwords].name, name);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

void remove_password(char *name) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            memset(passwords[i].password, 0, MAX_PASSWORD_LENGTH);
            strcpy(passwords[i].name, "");
            num_passwords--;
            return;
        }
    }
    printf("Error: Password not found.\n");
}

void list_passwords() {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (passwords[i].name[0]!= '\0') {
            printf("%s: ********\n", passwords[i].name);
        }
    }
}

int main() {
    char command[MAX_PASSWORD_LENGTH];
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter password: ");
            scanf("%s", password);
            add_password(name, password);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            remove_password(name);
        } else if (strcmp(command, "list") == 0) {
            list_passwords();
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}