//Falcon2-11B DATASET v1.0 Category: Password management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 30

struct password {
    char* password;
    char* username;
    int index;
};

void add_password(struct password* passwords, int index, char* password, char* username) {
    passwords[index].password = password;
    passwords[index].username = username;
    passwords[index].index = index;
}

void print_passwords(struct password* passwords) {
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        if (passwords[i].index == -1) {
            printf("Username: %s, Password: %s\n", passwords[i].username, passwords[i].password);
        }
    }
}

int main() {
    struct password passwords[MAX_PASSWORDS];
    int index = 0;

    while (1) {
        char* password;
        char* username;

        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%s", password);

        add_password(passwords, index, password, username);

        printf("Do you want to add another password? (Y/N): ");
        char choice;
        scanf(" %c", &choice);

        if (choice!= 'Y' && choice!= 'y') {
            break;
        }

        index++;
    }

    print_passwords(passwords);

    return 0;
}