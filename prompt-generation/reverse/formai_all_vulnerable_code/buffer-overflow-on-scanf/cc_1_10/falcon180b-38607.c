//Falcon-180B DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    printf("Enter username: ");
    scanf("%s", passwords[num_passwords].username);
    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);
    passwords[num_passwords].length = strlen(passwords[num_passwords].password);
    num_passwords++;
}

void print_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("%s - %d characters\n", passwords[i].username, passwords[i].length);
    }
}

void delete_password() {
    printf("Enter username to delete: ");
    char username[MAX_PASSWORD_LENGTH];
    scanf("%s", username);
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            for (int j = i; j < num_passwords - 1; j++) {
                strcpy(passwords[j].username, passwords[j + 1].username);
                strcpy(passwords[j].password, passwords[j + 1].password);
                passwords[j].length = passwords[j + 1].length;
            }
            num_passwords--;
            break;
        }
    }
}

void search_password() {
    printf("Enter username to search: ");
    char username[MAX_PASSWORD_LENGTH];
    scanf("%s", username);
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password: %s\n", passwords[i].password);
            break;
        }
    }
}

int main() {
    int choice;
    do {
        printf("1. Add password\n2. Print passwords\n3. Delete password\n4. Search password\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_password();
            break;
        case 2:
            print_passwords();
            break;
        case 3:
            delete_password();
            break;
        case 4:
            search_password();
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