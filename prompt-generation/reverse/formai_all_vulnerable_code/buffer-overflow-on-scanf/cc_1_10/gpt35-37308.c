//FormAI DATASET v1.0 Category: Database simulation ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store the details of a user
struct user {
    char name[50];
    int age;
    char country[50];
};

// Function to add a new user to the database
void add_user(struct user *database, int *count) {
    printf("Enter the details of the user:\n");
    printf("Name: ");
    scanf("%s", database[*count].name);
    printf("Age: ");
    scanf("%d", &database[*count].age);
    printf("Country: ");
    scanf("%s", database[*count].country);
    (*count)++;
    printf("User added successfully!\n\n");
}

// Function to search for a user in the database
void search_user(struct user *database, int count) {
    char name[50];
    printf("Enter the name of the user: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("Country: %s\n", database[i].country);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("User not found in the database!\n\n");
}

// Function to display all the users in the database
void display_users(struct user *database, int count) {
    if (count == 0) {
        printf("No users in the database!\n\n");
        return;
    }
    printf("List of all users in the database:\n");
    for (int i = 0; i < count; i++) {
        printf("User %d:\n", i+1);
        printf("Name: %s\n", database[i].name);
        printf("Age: %d\n", database[i].age);
        printf("Country: %s\n", database[i].country);
    }
    printf("\n");
}

int main() {
    struct user database[100];
    int count = 0;
    int choice;
    while (1) {
        printf("\n1. Add a user\n");
        printf("2. Search for a user\n");
        printf("3. Display all users\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_user(database, &count);
                break;
            case 2:
                search_user(database, count);
                break;
            case 3:
                display_users(database, count);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}