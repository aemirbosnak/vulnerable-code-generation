//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int age;
} User;

User users[MAX_RECORDS];
int record_count = 0;

void display_menu() {
    printf("\nData Mining Example Program\n");
    printf("1. Add User Record\n");
    printf("2. Display All Records\n");
    printf("3. Search by Email\n");
    printf("4. Delete Record by Email\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void add_user() {
    if (record_count >= MAX_RECORDS) {
        printf("Record limit reached. Cannot add more users.\n");
        return;
    }

    User new_user;
    printf("Enter name: ");
    getchar();  // consume newline
    fgets(new_user.name, MAX_NAME_LENGTH, stdin);
    new_user.name[strcspn(new_user.name, "\n")] = 0; // Remove trailing newline

    printf("Enter email: ");
    fgets(new_user.email, MAX_EMAIL_LENGTH, stdin);
    new_user.email[strcspn(new_user.email, "\n")] = 0; // Remove trailing newline

    printf("Enter age: ");
    scanf("%d", &new_user.age);

    users[record_count++] = new_user;
    printf("User record added successfully.\n");
}

void display_users() {
    if (record_count == 0) {
        printf("No records available.\n");
        return;
    }
    
    printf("\nUser Records:\n");
    for (int i = 0; i < record_count; i++) {
        printf("Name: %s, Email: %s, Age: %d\n", users[i].name, users[i].email, users[i].age);
    }
}

void search_user() {
    char email[MAX_EMAIL_LENGTH];
    printf("Enter email to search: ");
    getchar();  // consume newline
    fgets(email, MAX_EMAIL_LENGTH, stdin);
    email[strcspn(email, "\n")] = 0; // Remove trailing newline
    int found = 0;

    for (int i = 0; i < record_count; i++) {
        if (strcmp(users[i].email, email) == 0) {
            printf("Found record - Name: %s, Email: %s, Age: %d\n", users[i].name, users[i].email, users[i].age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No record found with the email: %s\n", email);
    }
}

void delete_user() {
    char email[MAX_EMAIL_LENGTH];
    printf("Enter email to delete: ");
    getchar();  // consume newline
    fgets(email, MAX_EMAIL_LENGTH, stdin);
    email[strcspn(email, "\n")] = 0; // Remove trailing newline
    int found = 0;

    for (int i = 0; i < record_count; i++) {
        if (strcmp(users[i].email, email) == 0) {
            for (int j = i; j < record_count - 1; j++) {
                users[j] = users[j + 1]; // Shift records left
            }
            record_count--;
            printf("Record with email %s deleted successfully.\n", email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No record found with the email: %s\n", email);
    }
}

int main() {
    int option;

    while (1) {
        display_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_user();
                break;
            case 2:
                display_users();
                break;
            case 3:
                search_user();
                break;
            case 4:
                delete_user();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}