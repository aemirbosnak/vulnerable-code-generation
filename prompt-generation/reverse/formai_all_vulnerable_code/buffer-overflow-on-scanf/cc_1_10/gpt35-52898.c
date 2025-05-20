//FormAI DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Password {
    char website[50];
    char username[50];
    char password[50];
};

void displayMenu() {
    printf("--- Password Manager ---\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Exit\n");
}

void addPassword(struct Password *pass, int *size) {
    printf("Enter website: ");
    scanf("%s", pass[*size].website);

    printf("Enter username: ");
    scanf("%s", pass[*size].username);

    printf("Enter password: ");
    scanf("%s", pass[*size].password);

    (*size)++;
}

void viewPasswords(struct Password *pass, int size) {
    if (size == 0) {
        printf("No passwords stored.\n\n");
        return;
    }
    printf("Website\t\tUsername\tPassword\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t\t%s\t\t%s\n", pass[i].website, pass[i].username, pass[i].password);
    }
}

int main() {
    struct Password passwords[100];
    int count = 0, choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addPassword(passwords, &count);
                break;
            case 2:
                viewPasswords(passwords, count);
                break;
            case 3:
                printf("Thanks for using Password Manager!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again!\n");
        }
    }
    return 0;
}