//Falcon-180B DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char website[MAX_PASSWORD_LENGTH];
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* password, char* username, char* website) {
    strncpy(passwords[num_passwords].password, password, MAX_PASSWORD_LENGTH);
    strncpy(passwords[num_passwords].username, username, MAX_PASSWORD_LENGTH);
    strncpy(passwords[num_passwords].website, website, MAX_PASSWORD_LENGTH);
    num_passwords++;
}

void print_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("Password: %s\n", passwords[i].password);
        printf("Username: %s\n", passwords[i].username);
        printf("Website: %s\n\n", passwords[i].website);
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char website[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter website: ");
        scanf("%s", website);
        printf("Enter password: ");
        scanf("%s", password);

        add_password(password, username, website);

        printf("Password added!\n");

        char choice;
        printf("Do you want to add another password? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    print_passwords();

    return 0;
}