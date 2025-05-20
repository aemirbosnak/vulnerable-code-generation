//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
} ExpenseItem;

int main() {
    int numItems = 0;
    ExpenseItem items[MAX_ITEMS];
    char choice;

    do {
        printf("\nExpense Tracker\n");
        printf("--------------------\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter expense name: ");
                scanf("%s", items[numItems].name);
                printf("Enter expense amount: ");
                scanf("%s", items[numItems].amount);
                numItems++;
                break;
            case '2':
                printf("\nExpenses:\n");
                for(int i=0; i<numItems; i++) {
                    printf("%s: %s\n", items[i].name, items[i].amount);
                }
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= '3');

    return 0;
}