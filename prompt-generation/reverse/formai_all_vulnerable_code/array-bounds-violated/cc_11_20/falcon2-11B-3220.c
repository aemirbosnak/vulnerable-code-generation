//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: excited
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

int main() {
    Item items[MAX_ITEMS] = {{"Aspirin", 50, 1.50}, {"Paracetamol", 100, 0.75}, {"Band-Aid", 50, 1.25}, {"Tylenol", 100, 1.00}, {"Vaseline", 50, 1.75}, {"Neosporin", 50, 2.50}, {"Balmex", 50, 2.00}, {"Ibuprofen", 50, 1.75}, {"Hydrocortisone", 50, 2.25}, {"Saline Solution", 50, 1.50}};
    
    int numItems = sizeof(items) / sizeof(items[0]);
    
    printf("Welcome to the Medical Store Management System!\n");
    printf("Please choose an option:\n");
    printf("1. View Items\n");
    printf("2. Add Item\n");
    printf("3. Remove Item\n");
    printf("4. Update Item\n");
    printf("5. Exit\n");
    int choice;
    scanf("%d", &choice);
    
    while (choice!= 5) {
        switch (choice) {
            case 1:
                printf("Items in stock:\n");
                for (int i = 0; i < numItems; i++) {
                    printf("%s - %d units - $%.2f\n", items[i].name, items[i].quantity, items[i].price);
                }
                break;
                
            case 2:
                printf("Enter the name of the item: ");
                fgets(items[numItems].name, sizeof(items[0].name), stdin);
                printf("Enter the quantity: ");
                scanf("%d", &items[numItems].quantity);
                printf("Enter the price: ");
                scanf("%f", &items[numItems].price);
                items[numItems].name[strcspn(items[numItems].name, "\n")] = 0;
                items[numItems].quantity = (items[numItems].quantity > 0)? items[numItems].quantity : 0;
                items[numItems].price = (items[numItems].price > 0)? items[numItems].price : 0;
                numItems++;
                break;
                
            case 3:
                printf("Enter the name of the item to remove: ");
                fgets(items[numItems - 1].name, sizeof(items[0].name), stdin);
                printf("Do you want to confirm the removal? (y/n): ");
                char confirm[10];
                scanf("%s", confirm);
                if (strcmp(confirm, "y") == 0) {
                    for (int i = numItems - 1; i >= 0; i--) {
                        if (strcmp(items[i].name, items[numItems - 1].name) == 0) {
                            strcpy(items[i].name, items[i + 1].name);
                            strcpy(items[i + 1].name, items[i].name);
                            strcpy(items[i].name, "");
                            strcpy(items[i].name, "");
                            items[i].quantity = (items[i].quantity > 0)? items[i].quantity : 0;
                            items[i + 1].quantity = (items[i + 1].quantity > 0)? items[i + 1].quantity : 0;
                            items[i].price = (items[i].price > 0)? items[i].price : 0;
                            items[i + 1].price = (items[i + 1].price > 0)? items[i + 1].price : 0;
                            numItems--;
                            break;
                        }
                    }
                }
                break;
                
            case 4:
                printf("Enter the name of the item to update: ");
                fgets(items[numItems - 1].name, sizeof(items[0].name), stdin);
                printf("Enter the new name: ");
                fgets(items[numItems - 1].name, sizeof(items[0].name), stdin);
                printf("Enter the new quantity: ");
                scanf("%d", &items[numItems - 1].quantity);
                printf("Enter the new price: ");
                scanf("%f", &items[numItems - 1].price);
                items[numItems - 1].name[strcspn(items[numItems - 1].name, "\n")] = 0;
                items[numItems - 1].quantity = (items[numItems - 1].quantity > 0)? items[numItems - 1].quantity : 0;
                items[numItems - 1].price = (items[numItems - 1].price > 0)? items[numItems - 1].price : 0;
                break;
                
            case 5:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice!\n");
                break;
        }
        
        printf("Please choose an option:\n");
        printf("1. View Items\n");
        printf("2. Add Item\n");
        printf("3. Remove Item\n");
        printf("4. Update Item\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
    }
    
    printf("Thank you for using the Medical Store Management System!\n");
    return 0;
}