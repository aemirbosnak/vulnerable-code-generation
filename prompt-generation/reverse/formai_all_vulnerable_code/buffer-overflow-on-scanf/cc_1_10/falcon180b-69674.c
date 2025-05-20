//Falcon-180B DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

void add_password(password_t *passwords, int *num_passwords) {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter website name: ");
    scanf("%s", name);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[*num_passwords].name, name);
    strcpy(passwords[*num_passwords].password, password);

    (*num_passwords)++;
}

void list_passwords(password_t *passwords, int num_passwords) {
    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s - %s\n", passwords[i].name, passwords[i].password);
    }
}

void search_password(password_t *passwords, int num_passwords, char *name) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            printf("Password for %s: %s\n", name, passwords[i].password);
            return;
        }
    }

    printf("Password not found.\n");
}

int main() {
    password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    printf("Welcome to the password manager!\n");

    while (1) {
        printf("1. Add password\n2. List passwords\n3. Search password\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                add_password(passwords, &num_passwords);
                break;
            }
            case 2: {
                list_passwords(passwords, num_passwords);
                break;
            }
            case 3: {
                char name[MAX_PASSWORD_LENGTH];
                printf("Enter website name: ");
                scanf("%s", name);

                search_password(passwords, num_passwords, name);
                break;
            }
            case 4: {
                printf("Exiting...\n");
                return 0;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}