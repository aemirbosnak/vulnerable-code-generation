//FormAI DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

struct Password {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    struct Password *next;
};

struct Password *head = NULL;

void add_password() {
    struct Password *new_password = (struct Password*) malloc(sizeof(struct Password));
    printf("\nEnter username: ");
    scanf("%s", new_password->username);
    printf("Enter password: ");
    scanf("%s", new_password->password);
    new_password->next = head;
    head = new_password;
    printf("\nPassword added successfully!\n\n");
}

void show_passwords() {
    if (head == NULL) {
        printf("\nNo passwords found.\n\n");
        return;
    }
    printf("\nList of passwords:\n\n");
    struct Password *curr = head;
    int count = 1;
    while (curr != NULL) {
        printf("%d. Username: %s, Password: %s\n", count, curr->username, curr->password);
        curr = curr->next;
        count++;
    }
    printf("\n");
}

void delete_password() {
    if (head == NULL) {
        printf("\nNo passwords found.\n\n");
        return;
    }
    char username[MAX_USERNAME_LENGTH];
    printf("\nEnter username of password to delete: ");
    scanf("%s", username);
    struct Password *curr = head;
    struct Password *prev = NULL;
    while (curr != NULL && strcmp(curr->username, username) != 0) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("\nPassword not found.\n\n");
        return;
    }
    if (prev == NULL) {
        head = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
    printf("\nPassword deleted successfully!\n\n");
}

void save_passwords() {
    if (head == NULL) {
        printf("\nNo passwords found to save.\n\n");
        return;
    }
    FILE *fptr;
    fptr = fopen("passwords.txt", "w");
    if (fptr == NULL) {
        printf("\nError opening file.\n\n");
        return;
    }
    struct Password *curr = head;
    while (curr != NULL) {
        fprintf(fptr, "%s %s\n", curr->username, curr->password);
        curr = curr->next;
    }
    fclose(fptr);
    printf("\nPasswords saved to file.\n\n");
}

void load_passwords() {
    FILE *fptr;
    fptr = fopen("passwords.txt", "r");
    if (fptr == NULL) {
        printf("\nFile not found or error opening file.\n\n");
        return;
    }
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    while (fscanf(fptr, "%s %s\n", username, password) != EOF) {
        struct Password *new_password = (struct Password*) malloc(sizeof(struct Password));
        strcpy(new_password->username, username);
        strcpy(new_password->password, password);
        new_password->next = head;
        head = new_password;
    }
    fclose(fptr);
    printf("\nPasswords loaded from file.\n\n");
}

int main() {
    printf("Welcome to Password Manager\n\n");
    while (1) {
        printf("Please select an option:\n");
        printf("1. Add password\n");
        printf("2. Show passwords\n");
        printf("3. Delete password\n");
        printf("4. Save passwords to file\n");
        printf("5. Load passwords from file\n");
        printf("6. Exit\n\n");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1:
                add_password();
                break;
            case 2:
                show_passwords();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                save_passwords();
                break;
            case 5:
                load_passwords();
                break;
            case 6:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid option. Please try again.\n\n");
        }
    }
    return 0;
}