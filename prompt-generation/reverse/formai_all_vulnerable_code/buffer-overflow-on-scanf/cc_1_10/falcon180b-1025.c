//Falcon-180B DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int is_used;
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_password(char *password) {
    int i;
    for (i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        password[i] = rand() % 26 + 'a';
    }
    password[MAX_PASSWORD_LENGTH - 1] = '\0';
}

int is_password_used(char *password) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

void add_password(char *password) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (!passwords[i].is_used) {
            strcpy(passwords[i].password, password);
            passwords[i].is_used = 1;
            num_passwords++;
            return;
        }
    }
    printf("Error: Maximum number of passwords reached.\n");
}

int main() {
    int choice;
    char password[MAX_PASSWORD_LENGTH];

    srand(time(NULL));

    do {
        printf("1. Generate password\n");
        printf("2. Add password\n");
        printf("3. Check if password is used\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generate_password(password);
                printf("Generated password: %s\n", password);
                break;
            case 2:
                printf("Enter password: ");
                scanf("%s", password);
                add_password(password);
                break;
            case 3:
                printf("Enter password to check: ");
                scanf("%s", password);
                if (is_password_used(password)) {
                    printf("Password is used.\n");
                } else {
                    printf("Password is not used.\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}