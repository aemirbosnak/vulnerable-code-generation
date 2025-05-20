//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: retro
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
    item items[MAX_ITEMS];
    int num_items = 0;
    char choice;
    int i;

    do {
        printf("\n");
        printf("Welcome to the Expense Tracker!\n");
        printf("a. Add an expense\n");
        printf("b. View expenses\n");
        printf("c. Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case 'a':
                if(num_items >= MAX_ITEMS) {
                    printf("Error: Maximum number of items reached.\n");
                } else {
                    printf("Enter the name of the expense: ");
                    scanf("%s", items[num_items].name);
                    printf("Enter the amount of the expense: ");
                    scanf("%s", items[num_items].amount);
                    num_items++;
                    printf("Item added successfully!\n");
                }
                break;
            case 'b':
                if(num_items == 0) {
                    printf("No expenses added yet.\n");
                } else {
                    printf("List of expenses:\n");
                    for(i = 0; i < num_items; i++) {
                        printf("%s: %s\n", items[i].name, items[i].amount);
                    }
                }
                break;
            case 'c':
                printf("Thank you for using the Expense Tracker!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 'c');

    return 0;
}