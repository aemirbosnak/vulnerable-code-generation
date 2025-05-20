//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 20
#define MAX_AMOUNT_LEN 8
#define MAX_DESCRIPTION_LEN 40

typedef struct {
    char name[MAX_NAME_LEN];
    double amount;
    char description[MAX_DESCRIPTION_LEN];
} Item;

Item items[MAX_ITEMS];
int itemCount = 0;

void addItem(char *name, double amount, char *description) {
    int i;
    for (i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Item already exists!\n");
            return;
        }
    }

    Item item;
    strcpy(item.name, name);
    item.amount = amount;
    strcpy(item.description, description);

    items[itemCount] = item;
    itemCount++;
}

void displayItems() {
    int i;
    printf("Name: ");
    for (i = 0; i < itemCount; i++) {
        printf("%s ", items[i].name);
    }
    printf("\nAmount: ");
    for (i = 0; i < itemCount; i++) {
        printf("%f ", items[i].amount);
    }
    printf("\nDescription: ");
    for (i = 0; i < itemCount; i++) {
        printf("%s ", items[i].description);
    }
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name: ");
                scanf("%s", items[itemCount].name);
                printf("Enter the amount: ");
                scanf("%lf", &items[itemCount].amount);
                printf("Enter the description: ");
                scanf("%s", items[itemCount].description);
                addItem(items[itemCount].name, items[itemCount].amount, items[itemCount].description);
                break;
            case 2:
                displayItems();
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}