//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: cheerful
#include <stdio.h>
#include <string.h>

struct MedicalStore {
    char name[50];
    int quantity;
    float price;
};

int main() {
    int choice, i, j, count;
    float totalCost = 0.0;
    char searchName[50];
    struct MedicalStore store[100];

    printf("Welcome to Happy Medical Store Management System!\n");

    do {
        printf("\nChoose one of the following options:\n");
        printf("1. Add items to the store\n");
        printf("2. Search for an item\n");
        printf("3. Display all items in the store\n");
        printf("4. Purchase items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nHow many items do you wish to add? ");
                scanf("%d", &count);

                printf("\n--------Add Items to Store--------\n");
                for (i = 0; i < count; i++) {
                    printf("\nItem %d:\n", i+1);
                    printf("Enter item name: ");
                    scanf("%s", store[i].name);
                    printf("Enter item quantity: ");
                    scanf("%d", &store[i].quantity);
                    printf("Enter item price: ");
                    scanf("%f", &store[i].price);
                }
                break;
            case 2:
                printf("\n--------Search for an Item--------\n");
                printf("Enter the name of the item: ");
                scanf("%s", searchName);

                for (i = 0; i < count; i++) {
                    if (strcmp(store[i].name, searchName) == 0) {
                        printf("\nItem Found!\n");
                        printf("Item Name: %s\n", store[i].name);
                        printf("Item Quantity: %d\n", store[i].quantity);
                        printf("Item Price: %.2f\n", store[i].price);
                        break;
                    }
                }
                if (i == count) {
                    printf("\nItem not found!\n");
                }
                break;
            case 3:
                printf("\n--------All Items in the Store--------\n");
                for (i = 0; i < count; i++) {
                    printf("\nItem %d:\n", i+1);
                    printf("Item Name: %s\n", store[i].name);
                    printf("Item Quantity: %d\n", store[i].quantity);
                    printf("Item Price: %.2f\n", store[i].price);
                }
                break;
            case 4:
                printf("\n--------Purchase Items--------\n");

                do {
                    printf("Enter the name of the item you wish to purchase: ");
                    scanf("%s", searchName);

                    for (i = 0; i < count; i++) {
                        if (strcmp(store[i].name, searchName) == 0) {
                            printf("Enter the quantity you wish to purchase: ");
                            scanf("%d", &j);
                            if (j > store[i].quantity) {
                                printf("Sorry, only %d items available in store\n", store[i].quantity);
                            } else {
                                totalCost += j * store[i].price;
                                store[i].quantity -= j;
                                printf("\nThank you for your purchase!\n");
                                printf("Item Name: %s\n", store[i].name);
                                printf("Item Quantity: %d\n", j);
                                printf("Item Price: %.2f\n", store[i].price);
                                printf("Total Cost: %.2f\n", totalCost);
                                break;
                            }
                        }
                    }
                    if (i == count) {
                        printf("\nItem not found!\n");
                    }
                    printf("Do you wish to purchase more items? (y/n) ");
                    getchar();  // Clear input buffer
                } while (getchar() == 'y');

                break;
            case 5:
                printf("\nThank you for using Happy Medical Store Management System!\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}