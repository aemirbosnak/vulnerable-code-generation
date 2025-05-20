//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char price[MAX_PRICE_LENGTH];
} item;

void addItem(item items[], int numItems) {
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);
    printf("Enter item price: ");
    scanf("%s", items[numItems].price);
}

int main() {
    FILE *fp;
    item items[MAX_ITEMS];
    int numItems = 0;
    char choice;
    double totalExpense = 0.0;

    do {
        system("clear");
        printf("Romeo and Juliet's Expense Tracker\n");
        printf("1. Add item\n");
        printf("2. View items\n");
        printf("3. Calculate total expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (numItems == MAX_ITEMS) {
                printf("Cannot add more items.\n");
            } else {
                addItem(items, numItems);
                numItems++;
            }
            break;

        case '2':
            printf("Item\tPrice\n");
            for (int i = 0; i < numItems; i++) {
                printf("%s\t%s\n", items[i].name, items[i].price);
            }
            break;

        case '3':
            for (int i = 0; i < numItems; i++) {
                totalExpense += atof(items[i].price);
            }
            printf("Total expense: $%.2f\n", totalExpense);
            break;

        case '4':
            printf("Goodbye, dear Juliet.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}