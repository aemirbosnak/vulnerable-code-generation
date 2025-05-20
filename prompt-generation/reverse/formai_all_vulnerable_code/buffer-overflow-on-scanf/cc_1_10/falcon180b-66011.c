//Falcon-180B DATASET v1.0 Category: Password management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100

struct {
    char username[50];
    char password[50];
} password_list[MAX_PASSWORDS];

int num_passwords = 0;

void add_password() {
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(password_list[num_passwords].username, username);
    strcpy(password_list[num_passwords].password, password);

    num_passwords++;
}

void view_passwords() {
    int i;

    printf("Username\tPassword\n");
    for (i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", password_list[i].username, password_list[i].password);
    }
}

void search_password() {
    char search_username[50];

    printf("Enter username to search: ");
    scanf("%s", search_username);

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(search_username, password_list[i].username) == 0) {
            printf("Password: %s\n", password_list[i].password);
            return;
        }
    }

    printf("Password not found.\n");
}

int main() {
    int choice;

    do {
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Search password\n");
        printf("4. Exit\n");
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
                search_password();
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