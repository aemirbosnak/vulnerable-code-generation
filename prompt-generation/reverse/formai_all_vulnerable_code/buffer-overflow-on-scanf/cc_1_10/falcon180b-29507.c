//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CATEGORIES 100
#define MAX_EXPENSES 1000

struct expense {
    char category[50];
    char description[100];
    float amount;
    time_t date;
};

struct expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    printf("Enter category: ");
    scanf("%s", expenses[num_expenses].category);
    
    printf("Enter description: ");
    scanf("%s", expenses[num_expenses].description);
    
    printf("Enter amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    
    time_t now = time(NULL);
    expenses[num_expenses].date = now;
    
    num_expenses++;
}

void view_expenses() {
    for (int i = 0; i < num_expenses; i++) {
        printf("Category: %s\n", expenses[i].category);
        printf("Description: %s\n", expenses[i].description);
        printf("Amount: $%.2f\n", expenses[i].amount);
        printf("Date: %s\n\n", ctime(&expenses[i].date));
    }
}

void main() {
    srand(time(NULL));
    
    int choice;
    do {
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);
}