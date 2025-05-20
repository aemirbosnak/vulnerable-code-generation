//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} Item;

void addItem(Item items[], int numItems, char name[], char amount[]) {
    int i;
    for (i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Item already exists!\n");
            return;
        }
    }
    strcpy(items[numItems].name, name);
    strcpy(items[numItems].amount, amount);
    numItems++;
}

void displayItems(Item items[], int numItems) {
    int i;
    for (i = 0; i < numItems; i++) {
        printf("%s - $%s\n", items[i].name, items[i].amount);
    }
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;
    char choice;

    do {
        printf("Personal Finance Planner\n");
        printf("1. Add an item\n");
        printf("2. Display items\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name of item: ");
                scanf("%s", items[numItems].name);
                printf("Enter amount: $");
                scanf("%s", items[numItems].amount);
                numItems++;
                break;

            case '2':
                displayItems(items, numItems);
                break;

            case '3':
                printf("Thank you for using the Personal Finance Planner!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '3');

    return 0;
}