//Falcon-180B DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct {
    char name[50];
    char username[50];
    char password[50];
} password_t;

void add_password(password_t passwords[], int num_passwords) {
    printf("Enter name: ");
    scanf("%s", passwords[num_passwords].name);

    printf("Enter username: ");
    scanf("%s", passwords[num_passwords].username);

    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);

    num_passwords++;
}

void view_passwords(password_t passwords[], int num_passwords) {
    printf("Name\tUsername\tPassword\n");

    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t%s\t%s\n", passwords[i].name, passwords[i].username, passwords[i].password);
    }
}

void search_password(password_t passwords[], int num_passwords) {
    printf("Enter name to search: ");
    char name[50];
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            printf("Name: %s\nUsername: %s\nPassword: %s\n", passwords[i].name, passwords[i].username, passwords[i].password);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Password not found.\n");
    }
}

int main() {
    password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    while (num_passwords < MAX_PASSWORDS) {
        int choice;
        printf("\n1. Add password\n2. View passwords\n3. Search password\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password(passwords, num_passwords);
                break;
            case 2:
                view_passwords(passwords, num_passwords);
                break;
            case 3:
                search_password(passwords, num_passwords);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}