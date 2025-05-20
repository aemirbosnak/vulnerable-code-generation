//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} item;

int main() {
    int num_items = 0;
    item items[MAX_ITEMS];
    char choice;
    double total_expense = 0.0;

    do {
        printf("\nExpense Tracker\n");
        printf("===================\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. View total expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_items >= MAX_ITEMS) {
                    printf("Maximum number of items reached.\n");
                } else {
                    printf("Enter expense name: ");
                    scanf("%s", items[num_items].name);
                    printf("Enter expense amount: ");
                    scanf("%s", items[num_items].amount);
                    num_items++;
                    total_expense += atof(items[num_items-1].amount);
                }
                break;
            case '2':
                printf("\nExpenses:\n");
                for(int i=0; i<num_items; i++) {
                    printf("%s: $%.2f\n", items[i].name, atof(items[i].amount));
                }
                break;
            case '3':
                printf("Total expense: $%.2f\n", total_expense);
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '4');

    return 0;
}