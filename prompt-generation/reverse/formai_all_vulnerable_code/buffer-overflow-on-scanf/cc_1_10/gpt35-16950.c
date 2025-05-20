//FormAI DATASET v1.0 Category: Password management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Password {
    char account[30];
    char username[30];
    char password[30];
};

void menu();
int check_password(const char* pass);
void add_password(struct Password *, int *);
void view_password(struct Password *, int);

int main() {
    char password[50] = "";
    int is_correct = 0;
    struct Password passwords[100];
    int num_passwords = 0;

    printf("Welcome to the Password Manager! \n");
    printf("Please enter your master password: ");
    scanf("%s", password);

    is_correct = check_password(password);

    if (is_correct) {
        printf("Access Granted! \n");
        menu();
    } else {
        printf("Access Denied! \n");
        exit(0);
    }

    return 0;
}

void menu() {
    struct Password passwords[100];
    int num_passwords = 0;
    int choice = 0;

    do {
        printf("\nPlease select an option: \n");
        printf("1. Add a New Password \n");
        printf("2. View All Passwords \n");
        printf("3. Exit \n");

        scanf("%d", &choice);

        if (choice == 1) {
            add_password(passwords, &num_passwords);
        } else if (choice == 2) {
            view_password(passwords, num_passwords);
        } else if (choice == 3) {
            printf("Goodbye! \n");
            exit(0);
        } else {
            printf("Invalid choice! \n");
        }
    } while (choice != 3);
}

int check_password(const char* pass) {
    char password[50];
    FILE *fptr;
    int match = 0;

    if ((fptr = fopen("password.txt", "r")) == NULL) {
        printf("Error Opening File! \n");
        exit(0);
    }

    fgets(password, 50, fptr);
    password[strlen(password) - 1] = '\0';

    if (strcmp(password, pass) == 0) {
        match = 1;
    }

    fclose(fptr);
    return match;
}

void add_password(struct Password * passwords, int * n) {
    printf("\nPlease enter the account name: ");
    scanf("%s", passwords[*n].account);
    printf("\nPlease enter the username: ");
    scanf("%s", passwords[*n].username);
    printf("\nPlease enter the password: ");
    scanf("%s", passwords[*n].password);
    *n += 1;
    printf("\nPassword added successfully! \n");
}

void view_password(struct Password * passwords, int n) {
    int i;

    if (n == 0) {
        printf("\nNo passwords saved! \n");
        return;
    }

    printf("\nAll Passwords:\n");

    for (i = 0; i < n; i++) {
        printf("Account Name: %s \n", passwords[i].account);
        printf("Username: %s \n", passwords[i].username);
        printf("Password: %s \n", passwords[i].password);
    }
}