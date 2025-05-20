//FormAI DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// defining a structure to store user information
struct User {
    char email[50];
    char name[50];
};

// function to add a new user to the mailing list
void addUser(struct User *users, int *count) {
    printf("\nEnter email address: ");
    scanf("%s", users[*count].email);
    printf("Enter name: ");
    scanf("%s", users[*count].name);
    (*count)++;
    printf("\nUser added successfully!\n");
}

// function to print all users in the mailing list
void printAllUsers(struct User *users, int count) {
    if (count == 0) {
        printf("\nNo users found!\n");
        return;
    }
    printf("\n-----------------------\n");
    printf("  Email        | Name\n");
    printf("-----------------------\n");
    for (int i=0; i<count; i++) {
        printf("%s | %s\n", users[i].email, users[i].name);
    }
    printf("-----------------------\n");
}

int main() {
    int choice, count = 0;
    struct User *users = malloc(10 * sizeof(struct User));
    while(1) {
        // menu
        printf("\n--------Mailing List Manager--------\n");
        printf("1. Add a new user\n");
        printf("2. Print all users\n");
        printf("3. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addUser(users, &count);
                    break;
            case 2: printAllUsers(users, count);
                    break;
            case 3: printf("\nGoodbye!\n");
                    exit(0);
            default: printf("\nInvalid choice! Please try again.\n");
        }
    }
    free(users);
    return 0;
}