//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

struct Password {
    char name[32];
    char password[32];
};

volatile struct Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *name, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Thou canst not add more passwords, good knight!\n");
        return;
    }

    strcpy(passwords[num_passwords].name, name);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

void list_passwords() {
    if (num_passwords == 0) {
        printf("Thou hast no passwords to list, brave warrior!\n");
        return;
    }

    printf("\n-------------------------\n");
    printf("| Name                | Password |\n");
    printf("-------------------------\n");

    for (int i = 0; i < num_passwords; i++) {
        printf("| %-15s | %-15s |\n", passwords[i].name, passwords[i].password);
    }
}

void main() {
    char command[32];
    char name[32], password[32];

    while (1) {
        printf("\n-------------------------\n");
        printf("| Welcome to the Password Keeper! | \n");
        printf("-------------------------\n");
        printf("| What wouldst thou like to do? |\n");
        printf("-------------------------\n");
        printf("| 1. Add a new password    | \n");
        printf("| 2. List all passwords   | \n");
        printf("| 3. Quit                 | \n");
        printf("-------------------------\n");
        printf("| Enter thy command:     | \n");
        printf("-------------------------\n");

        scanf("%s", command);

        switch (command[0]) {
            case '1':
                printf("What is the name of the new password? ");
                scanf("%s", name);
                printf("What is the password? ");
                scanf("%s", password);
                add_password(name, password);
                break;
            case '2':
                list_passwords();
                break;
            case '3':
                printf("Farewell, brave knight!\n");
                exit(0);
            default:
                printf("Invalid command!\n");
        }
    }
}