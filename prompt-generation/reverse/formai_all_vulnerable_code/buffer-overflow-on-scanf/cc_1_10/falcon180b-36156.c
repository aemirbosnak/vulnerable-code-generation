//Falcon-180B DATASET v1.0 Category: Password management ; Style: systematic
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
    strcpy(passwords[num_passwords].name, name);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

void print_passwords() {
    printf("Name\t\t\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t\t\t%s\n", passwords[i].name, passwords[i].password);
    }
}

int main() {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter password: ");
        scanf("%s", password);

        add_password(name, password);

        printf("Password added successfully!\n");

        char choice;
        printf("Do you want to add another password? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n') {
            break;
        }
    }

    print_passwords();

    return 0;
}