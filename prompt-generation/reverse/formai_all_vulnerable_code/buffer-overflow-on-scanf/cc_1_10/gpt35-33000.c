//FormAI DATASET v1.0 Category: Password management ; Style: future-proof
#include<stdio.h>
#include<string.h>

#define MAX_PASSWORDS 100

struct Password {
    char domain[50];
    char username[50];
    char password[50];
};

int numPasswords = 0;
struct Password passwords[MAX_PASSWORDS];

void addPassword() {
    struct Password password;
    printf("Enter Domain: ");
    scanf("%s", password.domain);
    printf("Enter Username: ");
    scanf("%s", password.username);
    printf("Enter Password: ");
    scanf("%s", password.password);
    passwords[numPasswords++] = password;
    printf("Password added successfully.\n");
}

void viewPasswords() {
    printf("\nDomain\t\tUsername\tPassword\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t%s\t%s\n", passwords[i].domain, passwords[i].username, passwords[i].password);
    }
}

void searchPassword() {
    char domain[50], username[50];
    printf("Enter Domain: ");
    scanf("%s", domain);
    printf("Enter Username: ");
    scanf("%s", username);
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].domain, domain) == 0 && strcmp(passwords[i].username, username) == 0) {
            printf("Password: %s\n", passwords[i].password);
            return;
        }
    }
    printf("Password not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Password\n2. View Passwords\n3. Search Password\n4. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                addPassword();
                break;
            case 2: 
                viewPasswords();
                break;
            case 3: 
                searchPassword();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}