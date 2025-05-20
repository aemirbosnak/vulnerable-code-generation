//Falcon-180B DATASET v1.0 Category: Password management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define SALT_LENGTH 16

typedef struct {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_salt(char *salt) {
    int i;

    for (i = 0; i < SALT_LENGTH; i++) {
        salt[i] = 'a' + rand() % 26;
    }

    salt[SALT_LENGTH] = '\0';
}

int hash_password(char *password, char *salt) {
    int i, j;
    char hash[MAX_PASSWORD_LENGTH];

    for (i = 0, j = 0; i < strlen(password); i++) {
        hash[j] = password[i] ^ salt[i % SALT_LENGTH];
        j++;
    }

    hash[j] = '\0';

    return 0;
}

int compare_passwords(char *password1, char *password2) {
    int i;

    for (i = 0; i < strlen(password1); i++) {
        if (password1[i]!= password2[i]) {
            return 1;
        }
    }

    return 0;
}

void add_password() {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
    char salt[SALT_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    generate_salt(salt);
    hash_password(password, salt);

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void view_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n\n", passwords[i].password);
    }
}

void main() {
    int choice;

    while (1) {
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}