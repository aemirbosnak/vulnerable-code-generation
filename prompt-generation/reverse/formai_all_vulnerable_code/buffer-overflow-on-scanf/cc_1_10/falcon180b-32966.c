//Falcon-180B DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter the name of the password: ");
    scanf("%s", name);

    printf("Enter the password: ");
    scanf("%s", password);

    strcpy(passwords[num_passwords].name, name);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void delete_password() {
    char name[MAX_PASSWORD_LENGTH];

    printf("Enter the name of the password to delete: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            memmove(&passwords[i], &passwords[i + 1], (num_passwords - i - 1) * sizeof(Password));
            num_passwords--;
            break;
        }
    }
}

void display_passwords() {
    printf("Name\t\tPassword\n");
    printf("----------------------------------------\n");

    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%s\t\t%s\n", passwords[i].name, passwords[i].password);
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add Password\n");
        printf("2. Delete Password\n");
        printf("3. Display Passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_password();
            break;
        case 2:
            delete_password();
            break;
        case 3:
            display_passwords();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}