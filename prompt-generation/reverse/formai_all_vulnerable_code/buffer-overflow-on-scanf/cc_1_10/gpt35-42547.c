//FormAI DATASET v1.0 Category: Password management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PASSWORDS 100 // maximum number of stored passwords

typedef struct {
    char website[50];
    char username[50];
    char password[50];
} Password;

typedef struct {
    Password passwords[MAX_PASSWORDS];
    int count;
} PasswordList;

// function declarations
void addPassword(PasswordList *list);
void getPassword(PasswordList list);
void printPasswords(PasswordList list);

int main() {
    PasswordList list;
    list.count = 0;
    int choice;

    while (1) {
        printf("\n1. Add a password\n2. Get a password\n3. Print all passwords\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword(&list);
                break;
            case 2:
                getPassword(list);
                break;
            case 3:
                printPasswords(list);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void addPassword(PasswordList *list) {
    if (list->count == MAX_PASSWORDS) {
        printf("Password list is full.\n");
        return;
    }

    Password password;
    printf("Website: ");
    scanf("%s", password.website);
    printf("Username: ");
    scanf("%s", password.username);
    printf("Password: ");
    scanf("%s", password.password);

    list->passwords[list->count] = password;
    list->count++;

    printf("Password added successfully.\n");
}

void getPassword(PasswordList list) {
    char website[50];
    printf("Enter website: ");
    scanf("%s", website);

    int found = 0;
    for (int i=0; i<list.count; i++) {
        if (strcmp(list.passwords[i].website, website) == 0) {
            found = 1;
            printf("Username: %s\nPassword: %s\n", list.passwords[i].username, list.passwords[i].password);
            break;
        }
    }

    if (!found) {
        printf("Password not found.\n");
    }
}

void printPasswords(PasswordList list) {
    for (int i=0; i<list.count; i++) {
        printf("%s\nUsername: %s\nPassword: %s\n\n", list.passwords[i].website, list.passwords[i].username, list.passwords[i].password);
    }
}