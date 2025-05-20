//Falcon-180B DATASET v1.0 Category: Password management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char website[MAX_PASSWORD_LENGTH];
} Password;

void generate_password(char* password, int length) {
    const char alphanumeric_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        password[i] = alphanumeric_chars[rand() % strlen(alphanumeric_chars)];
    }
    password[length] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    char username[MAX_PASSWORD_LENGTH];
    char website[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter website: ");
        scanf("%s", website);

        generate_password(password, rand() % MAX_PASSWORD_LENGTH + 8);
        strcpy(passwords[num_passwords].password, password);
        strcpy(passwords[num_passwords].username, username);
        strcpy(passwords[num_passwords].website, website);

        num_passwords++;

        if (num_passwords >= MAX_PASSWORDS) {
            printf("Maximum number of passwords reached. Exiting...\n");
            break;
        }

        printf("Do you want to add another password? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice!= 'y') {
            break;
        }
    }

    printf("\nPasswords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("Username: %s\nPassword: %s\nWebsite: %s\n\n", passwords[i].username, passwords[i].password, passwords[i].website);
    }

    return 0;
}