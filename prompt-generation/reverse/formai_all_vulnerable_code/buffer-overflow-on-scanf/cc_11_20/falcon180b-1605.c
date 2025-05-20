//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    double price;
} Item;

int main() {
    int num_items = 0;
    Item items[MAX_ITEMS];
    char choice;

    printf("Welcome to the Expense Tracker!\n");
    do {
        printf("\n");
        printf("1. Add new expense\n");
        printf("2. View expenses\n");
        printf("3. Edit expense\n");
        printf("4. Delete expense\n");
        printf("5. Exit\n");
        printf("\n");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                if(num_items >= MAX_ITEMS) {
                    printf("Sorry, you can't add any more expenses.\n");
                } else {
                    printf("Enter the name of the expense: ");
                    scanf(" %s", items[num_items].name);
                    printf("Enter a description of the expense: ");
                    scanf(" %s", items[num_items].description);
                    printf("Enter the price of the expense: $");
                    scanf(" %lf", &items[num_items].price);
                    num_items++;
                    printf("\nExpense added successfully!\n");
                }
                break;
            case '2':
                if(num_items == 0) {
                    printf("No expenses to view.\n");
                } else {
                    printf("\nExpenses:\n");
                    for(int i = 0; i < num_items; i++) {
                        printf("%s - $%.2f\n", items[i].name, items[i].price);
                    }
                }
                break;
            case '3':
                if(num_items == 0) {
                    printf("No expenses to edit.\n");
                } else {
                    int index;
                    printf("\nEnter the index of the expense to edit: ");
                    scanf(" %d", &index);
                    if(index >= 0 && index < num_items) {
                        printf("\nEnter the new name of the expense: ");
                        scanf(" %s", items[index].name);
                        printf("Enter a new description of the expense: ");
                        scanf(" %s", items[index].description);
                        printf("Enter the new price of the expense: $");
                        scanf(" %lf", &items[index].price);
                        printf("\nExpense updated successfully!\n");
                    } else {
                        printf("Invalid index.\n");
                    }
                }
                break;
            case '4':
                if(num_items == 0) {
                    printf("No expenses to delete.\n");
                } else {
                    int index;
                    printf("\nEnter the index of the expense to delete: ");
                    scanf(" %d", &index);
                    if(index >= 0 && index < num_items) {
                        num_items--;
                        printf("\nExpense deleted successfully!\n");
                    } else {
                        printf("Invalid index.\n");
                    }
                }
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '5');

    return 0;
}