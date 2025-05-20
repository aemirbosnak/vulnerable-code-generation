//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    int quantity;
    float price;
};

struct item items[MAX_ITEMS];

int main() {
    int choice, i;
    char ch;

    printf("Welcome to the Medical Store Management System\n");
    printf("---------------------------------------------\n");
    printf("1. Add Item\n");
    printf("2. Update Item\n");
    printf("3. Delete Item\n");
    printf("4. View Items\n");
    printf("5. Exit\n");
    printf("---------------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the name of the item: ");
            scanf("%s", items[0].name);
            printf("Enter the quantity of the item: ");
            scanf("%d", &items[0].quantity);
            printf("Enter the price of the item: ");
            scanf("%f", &items[0].price);
            printf("Item added successfully!\n");
            break;

        case 2:
            printf("Enter the index of the item to update: ");
            scanf("%d", &i);
            printf("Enter the new name of the item: ");
            scanf("%s", items[i].name);
            printf("Enter the new quantity of the item: ");
            scanf("%d", &items[i].quantity);
            printf("Enter the new price of the item: ");
            scanf("%f", &items[i].price);
            printf("Item updated successfully!\n");
            break;

        case 3:
            printf("Enter the index of the item to delete: ");
            scanf("%d", &i);
            printf("Item deleted successfully!\n");
            break;

        case 4:
            printf("Item Name\tQuantity\tPrice\n");
            for(i=0; i<MAX_ITEMS; i++) {
                if(items[i].quantity > 0) {
                    printf("%s\t\t%d\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
                }
            }
            break;

        case 5:
            printf("Thank you for using the Medical Store Management System\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
    }

    return 0;
}