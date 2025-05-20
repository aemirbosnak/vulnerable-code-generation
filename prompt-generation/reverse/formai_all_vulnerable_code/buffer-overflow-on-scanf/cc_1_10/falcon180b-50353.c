//Falcon-180B DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter the name of the website/service:\n");
    scanf("%s", name);

    printf("Enter the password:\n");
    scanf("%s", password);

    strcpy(passwords[num_passwords].name, name);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void display_passwords() {
    printf("\nPasswords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s - %s\n", passwords[i].name, passwords[i].password);
    }
}

void search_password() {
    char name[MAX_PASSWORD_LENGTH];

    printf("Enter the name of the website/service to search for:\n");
    scanf("%s", name);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            printf("Password for %s: %s\n", name, passwords[i].password);
            return;
        }
    }

    printf("Password not found.\n");
}

void delete_password() {
    char name[MAX_PASSWORD_LENGTH];

    printf("Enter the name of the website/service to delete:\n");
    scanf("%s", name);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            memset(passwords[i].name, 0, MAX_PASSWORD_LENGTH);
            memset(passwords[i].password, 0, MAX_PASSWORD_LENGTH);
            printf("Password for %s deleted.\n", name);
            return;
        }
    }

    printf("Password not found.\n");
}

int main() {
    int choice;

    do {
        printf("\nPassword Manager\n");
        printf("1. Add password\n");
        printf("2. Display passwords\n");
        printf("3. Search password\n");
        printf("4. Delete password\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                display_passwords();
                break;
            case 3:
                search_password();
                break;
            case 4:
                delete_password();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}