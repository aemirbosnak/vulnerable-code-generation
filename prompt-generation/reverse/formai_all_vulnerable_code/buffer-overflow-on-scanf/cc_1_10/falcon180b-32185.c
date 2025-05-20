//Falcon-180B DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

struct password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void add_password(struct password *passwords, int num_passwords, char *name, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Cannot add more passwords.\n");
        return;
    }
    strcpy(passwords[num_passwords].name, name);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

void print_passwords(struct password *passwords, int num_passwords) {
    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
}

void main() {
    struct password passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int choice;
    while (1) {
        printf("1. Add password\n2. Print passwords\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter password: ");
                scanf("%s", password);
                add_password(passwords, num_passwords, name, password);
                break;
            case 2:
                print_passwords(passwords, num_passwords);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}