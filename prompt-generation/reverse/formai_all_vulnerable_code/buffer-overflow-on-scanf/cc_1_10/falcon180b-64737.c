//Falcon-180B DATASET v1.0 Category: Password management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 1000
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char *username;
    char *password;
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_password(char *password) {
    int length = rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1) + MIN_PASSWORD_LENGTH;
    password[0] = toupper(rand() % 26 + 'A');
    for (int i = 1; i < length; i++) {
        password[i] = rand() % 26 + 'a';
    }
    password[length] = '\0';
}

void add_password() {
    char username[32];
    printf("Enter a username: ");
    scanf("%s", username);
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }
    char password[MAX_PASSWORD_LENGTH];
    generate_password(password);
    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);
    passwords[num_passwords].length = strlen(password);
    num_passwords++;
    printf("Password generated and saved.\n");
}

void view_passwords() {
    printf("Viewing %d passwords:\n", num_passwords);
    for (int i = 0; i < num_passwords; i++) {
        printf("%s (%d characters)\n", passwords[i].username, passwords[i].length);
    }
}

void delete_password() {
    printf("Enter a username to delete the associated password: ");
    char username[32];
    scanf("%s", username);
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);
            passwords[i] = passwords[--num_passwords];
            printf("Password deleted.\n");
            return;
        }
    }
    printf("Username not found.\n");
}

void main() {
    srand(time(0));
    for (int i = 0; i < num_passwords; i++) {
        generate_password(passwords[i].password);
    }
    int choice;
    while (1) {
        printf("\nPassword Management System\n");
        printf("1. Add a password\n");
        printf("2. View all passwords\n");
        printf("3. Delete a password\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}