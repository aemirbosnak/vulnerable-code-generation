//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char itemNo[10];
    char itemName[50];
    int quantity;
} Item;

void addItem(Item *items, int index) {
    printf("Enter Item No: ");
    scanf("%s", items[index].itemNo);

    printf("Enter Item Name: ");
    getchar(); // to clear buffer
    fgets(items[index].itemName, 50, stdin);

    printf("Enter Item Quantity: ");
    scanf("%d", &items[index].quantity);

    printf("\nItem added successfully!\n\n");

    char choice;
    printf("Do you want to add another item? (y/n): ");
    scanf(" %c", &choice);

    if(choice == 'y' || choice == 'Y') {
        index++;
        addItem(items, index);
    }
    else {
        return;
    }
}

void displayItems(Item *items, int index) {
    printf("No\tItem Name\tQuantity\n");
    printf("----------------------------------------\n");
    for(int i = 0; i < index; i++) {
        printf("%s\t%s\t%d\n", items[i].itemNo, items[i].itemName, items[i].quantity);
    }
    printf("----------------------------------------\n");
}

void searchItem(Item *items, int index) {
    char searchNo[10];
    printf("Enter Item No to search: ");
    scanf("%s", searchNo);

    for(int i = 0; i < index; i++) {
        if(strcmp(items[i].itemNo, searchNo) == 0) {
            printf("\nItem found!\n");
            printf("Item No: %s\nItem Name: %s\nItem Quantity: %d\n\n", items[i].itemNo, items[i].itemName, items[i].quantity);
            return;
        }
    }

    printf("\nItem not found!\n\n");
}

int main() {
    Item items[50];

    int index = 0;
    char choice;
    do {
        printf("\n----------WELCOME TO WAREHOUSE MANAGEMENT SYSTEM----------\n\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Search Item\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                addItem(items, index);
                index++;
                break;
            case '2':
                displayItems(items, index);
                break;
            case '3':
                searchItem(items, index);
                break;
            case '4':
                printf("Thank you for using the system!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != '4');

    return 0;
}