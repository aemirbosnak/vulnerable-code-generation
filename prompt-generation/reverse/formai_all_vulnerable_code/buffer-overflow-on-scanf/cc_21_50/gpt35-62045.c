//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Item {
    int id;
    char name[100];
    float price;
    int quantity;
};

int main() {
    struct Item items[100];
    int numItems = 0;
    bool isRunning = true;
    while(isRunning) {
        printf("\n----------Cafe Billing System----------");
        printf("\n1. Add Item");
        printf("\n2. Remove Item");
        printf("\n3. View Menu");
        printf("\n4. Generate Bill");
        printf("\n5. Exit");
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(numItems == 100) {
                    printf("\nCannot add more items. Maximum limit reached!\n");
                    break;
                }
                printf("\nEnter details of the new item: \n");
                struct Item newItem;
                printf("ID: ");
                scanf("%d", &newItem.id);
                printf("Name: ");
                scanf("%s", newItem.name);
                printf("Price: ");
                scanf("%f", &newItem.price);
                printf("Quantity: ");
                scanf("%d", &newItem.quantity);
                items[numItems++] = newItem;
                printf("\nItem added successfully!\n");
                break;
            case 2:
                if(numItems == 0) {
                    printf("\nNo items to remove!\n");
                    break;
                }
                int idToRemove;
                printf("\nEnter ID of item to remove: ");
                scanf("%d", &idToRemove);
                int itemIndex = -1;
                for(int i=0; i<numItems; i++) {
                    if(items[i].id == idToRemove) {
                        itemIndex = i;
                        break;
                    }
                }
                if(itemIndex == -1) {
                    printf("\nItem not found!\n");
                    break;
                }
                for(int i=itemIndex; i<numItems-1; i++) {
                    items[i] = items[i+1];
                }
                numItems--;
                printf("\nItem removed successfully!\n");
                break;
            case 3:
                if(numItems == 0) {
                    printf("\nNo items in menu!\n");
                    break;
                }
                printf("\n---------------------MENU---------------------\n");
                printf("\nID\tName\tPrice\tQuantity\n");
                for(int i=0; i<numItems; i++) {
                    printf("%d\t%s\t%.2f\t%d\n", items[i].id, items[i].name, items[i].price, items[i].quantity);
                }
                break;
            case 4:
                if(numItems == 0) {
                    printf("\nNo items in menu!\n");
                    break;
                }
                float totalBill = 0.0;
                printf("\nEnter IDs of items to purchase (separated by space): ");
                char ids[100];
                scanf("%[^\n]%*c", ids);
                printf("\nEnter quantities (separated by space): ");
                char quantities[100];
                scanf("%[^\n]%*c", quantities);
                char *idToken = strtok(ids, " ");
                char *quantityToken = strtok(quantities, " ");
                while(idToken != NULL && quantityToken != NULL) {
                    int id = atoi(idToken);
                    int quantity = atoi(quantityToken);
                    bool itemFound = false;
                    for(int i=0; i<numItems; i++) {
                        if(items[i].id == id) {
                            itemFound = true;
                            if(items[i].quantity < quantity) {
                                printf("\nError: Not enough quantity available for item with ID %d\n", id);
                                break;
                            }
                            totalBill += (items[i].price * quantity);
                            items[i].quantity -= quantity;
                            break;
                        }
                    }
                    if(!itemFound) {
                        printf("\nError: Item with ID %d not found!\n", id);
                        break;
                    }
                    idToken = strtok(NULL, " ");
                    quantityToken = strtok(NULL, " ");
                }
                printf("\nTotal Bill: %.2f\n", totalBill);
                break;
            case 5:
                isRunning = false;
                printf("\nThank you for using Cafe Billing System!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}