//Falcon-180B DATASET v1.0 Category: Password management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct {
    char name[50];
    char username[50];
    char password[100];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    printf("Enter website name: ");
    scanf("%s", passwords[num_passwords].name);

    printf("Enter username: ");
    scanf("%s", passwords[num_passwords].username);

    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);

    num_passwords++;
}

void view_passwords() {
    printf("Website\tUsername\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t%s\t%s\n", passwords[i].name, passwords[i].username, passwords[i].password);
    }
}

void search_password() {
    printf("Enter website name to search: ");
    char search_name[50];
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, search_name) == 0) {
            printf("Website: %s\nUsername: %s\nPassword: %s\n", passwords[i].name, passwords[i].username, passwords[i].password);
            found = 1;
        }
    }

    if (!found) {
        printf("Password not found.\n");
    }
}

void main() {
    int choice;

    do {
        printf("\n1. Add Password\n2. View Passwords\n3. Search Password\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                search_password();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
}