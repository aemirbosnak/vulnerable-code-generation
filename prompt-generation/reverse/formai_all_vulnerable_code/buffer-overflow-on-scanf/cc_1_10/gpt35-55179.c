//FormAI DATASET v1.0 Category: Expense Tracker ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Expense {
    char item[30];
    int price;
};

int main() {
    int numExpenses = 0, totalSpent = 0;
    struct Expense *expenses = (struct Expense *) malloc(sizeof(struct Expense));
    char choice[3], item[30];
    int price;

    printf("Welcome to Expense Tracker\n");
    printf("Enter 'a' to add an expense, 'r' to remove an expense, 'v' to view all expenses, and 'q' to quit\n");

    while(1) {
        printf("Enter choice: ");
        scanf("%s", choice);
        if(strcmp(choice, "a") == 0) {
            printf("Enter item name: ");
            scanf("%s", item);
            printf("Enter price: ");
            scanf("%d", &price);
            expenses[numExpenses].price = price;
            strcpy(expenses[numExpenses].item, item);
            numExpenses++;
            totalSpent += price;
            expenses = realloc(expenses, (numExpenses+1)*sizeof(struct Expense));
        } else if(strcmp(choice, "r") == 0) {
            printf("Enter item index to remove: ");
            int index;
            scanf("%d", &index);
            if(index < 0 || index >= numExpenses) {
                printf("Invalid index\n");
            } else {
                totalSpent -= expenses[index].price;
                for(int i=index;i<numExpenses-1;i++) {
                    expenses[i] = expenses[i+1];
                }
                numExpenses--;
                expenses = realloc(expenses, (numExpenses+1)*sizeof(struct Expense));
            }
        } else if(strcmp(choice, "v") == 0) {
            printf("Total spent: %d\n", totalSpent);
            for(int i=0;i<numExpenses;i++) {
                printf("%d. %s - %d\n", i, expenses[i].item, expenses[i].price);
            }
        } else if(strcmp(choice, "q") == 0) {
            printf("Quit\n");
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    free(expenses);
    return 0;
}