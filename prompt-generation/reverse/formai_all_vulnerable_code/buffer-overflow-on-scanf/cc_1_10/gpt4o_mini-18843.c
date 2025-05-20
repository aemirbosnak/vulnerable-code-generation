//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_ENTRIES 100
#define NAME_LEN 50
#define DESC_LEN 100

typedef struct {
    char description[DESC_LEN];
    float amount;
} Expense;

typedef struct {
    char name[NAME_LEN];
    Expense expenses[MAX_ENTRIES];
    int expense_count;
} User;

User users[MAX_USERS];
int user_count = 0;

void addUser() {
    if (user_count >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }
    printf("Enter user name: ");
    scanf("%s", users[user_count].name);
    users[user_count].expense_count = 0;
    user_count++;
    printf("User %s added.\n", users[user_count - 1].name);
}

User* findUser(const char* name) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].name, name) == 0) {
            return &users[i];
        }
    }
    return NULL;
}

void addExpense(User *user) {
    if (user->expense_count >= MAX_ENTRIES) {
        printf("Maximum number of expenses reached for %s.\n", user->name);
        return;
    }
    printf("Enter expense description: ");
    scanf(" %[^\n]%*c", user->expenses[user->expense_count].description);
    printf("Enter expense amount: ");
    scanf("%f", &user->expenses[user->expense_count].amount);
    user->expense_count++;
    printf("Expense added for user %s.\n", user->name);
}

void viewExpenses(User *user) {
    if (user->expense_count == 0) {
        printf("No expenses found for user %s.\n", user->name);
        return;
    }
    float total = 0.0f;
    printf("Expenses for %s:\n", user->name);
    for (int i = 0; i < user->expense_count; i++) {
        printf("%s: $%.2f\n", user->expenses[i].description, user->expenses[i].amount);
        total += user->expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

void displayMenu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add User\n");
    printf("2. Add Expense\n");
    printf("3. View Expenses\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char user_name[NAME_LEN];
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                printf("Enter user name: ");
                scanf("%s", user_name);
                {
                    User *user = findUser(user_name);
                    if (user) {
                        addExpense(user);
                    } else {
                        printf("User %s not found.\n", user_name);
                    }
                }
                break;
            case 3:
                printf("Enter user name: ");
                scanf("%s", user_name);
                {
                    User *user = findUser(user_name);
                    if (user) {
                        viewExpenses(user);
                    } else {
                        printf("User %s not found.\n", user_name);
                    }
                }
                break;
            case 4:
                printf("Exiting the Personal Finance Planner.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}