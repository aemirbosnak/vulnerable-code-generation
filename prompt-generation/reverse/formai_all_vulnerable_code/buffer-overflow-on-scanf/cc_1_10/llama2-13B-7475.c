//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12
#define MAX_PASSWORDS 5

struct password {
    char name[20];
    char password[PASSWORD_LENGTH];
};

struct password passwords[MAX_PASSWORDS];
int current_password = 0;

void add_password(char *name, char *password) {
    int i;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i].name, name) != 0) {
            break;
        }
    }

    if (i == MAX_PASSWORDS) {
        printf("Too many passwords! 😱\n");
        return;
    }

    strcpy(passwords[i].name, name);
    strcpy(passwords[i].password, password);
    current_password = i + 1;
}

void print_passwords() {
    int i;

    for (i = 0; i < current_password; i++) {
        printf("%d. %s (%s)\n", i + 1, passwords[i].name, passwords[i].password);
    }
}

int main() {
    char name[20];
    char password[PASSWORD_LENGTH];

    srand(time(NULL));  // generate random passwords

    for (int i = 0; i < MAX_PASSWORDS; i++) {
        printf("Add password? (y/n) ");
        scanf(" %c", &name[0]);

        if (name[0] == 'y') {
            printf("Enter name: ");
            scanf(" %19s", name);

            printf("Enter password: ");
            scanf(" %11s", password);

            add_password(name, password);
        }
    }

    print_passwords();

    while (1) {
        printf("Enter number or 'q' to quit: ");
        scanf(" %d", &current_password);

        if (current_password > 0 && current_password <= MAX_PASSWORDS) {
            print_passwords();
        } else if (current_password == 0) {
            break;
        } else {
            printf("Invalid input! 😳\n");
        }
    }

    return 0;
}