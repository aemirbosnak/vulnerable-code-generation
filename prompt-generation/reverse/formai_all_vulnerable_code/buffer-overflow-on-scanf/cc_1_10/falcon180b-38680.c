//Falcon-180B DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100 // Maximum number of passwords

typedef struct {
    char website[50];
    char username[50];
    char password[100];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    printf("Enter website: ");
    scanf("%s", passwords[num_passwords].website);

    printf("Enter username: ");
    scanf("%s", passwords[num_passwords].username);

    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);

    num_passwords++;
}

void edit_password() {
    int i, found = 0;
    char search_website[50];

    printf("Enter website to search: ");
    scanf("%s", search_website);

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].website, search_website) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Enter new username: ");
        scanf("%s", passwords[i].username);

        printf("Enter new password: ");
        scanf("%s", passwords[i].password);
    } else {
        printf("Website not found.\n");
    }
}

void delete_password() {
    char search_website[50];

    printf("Enter website to delete: ");
    scanf("%s", search_website);

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].website, search_website) == 0) {
            memmove(&passwords[i], &passwords[i+1], (num_passwords-i-1)*sizeof(Password));
            num_passwords--;
            break;
        }
    }
}

void view_passwords() {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("Website: %s\nUsername: %s\nPassword: %s\n\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add Password\n2. Edit Password\n3. Delete Password\n4. View Passwords\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                edit_password();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                view_passwords();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}