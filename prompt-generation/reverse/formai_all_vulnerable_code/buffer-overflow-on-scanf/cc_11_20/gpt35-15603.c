//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

struct Inventory {
    char productName[20];
    int quantity;
};

int main() {
    struct Inventory inv[20];
    int choice, numItems = 0;
    char searchName[20];
    
    do {
        printf("\nWarehouse Management System Menu:\n");
        printf("1. Add item\n");
        printf("2. Delete item\n");
        printf("3. Search item\n");
        printf("4. Display all items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if(numItems == 20) {
                    printf("Warehouse is full!\n");
                }
                else {
                    printf("\nEnter product name: ");
                    scanf("%s", inv[numItems].productName);
                    printf("Enter quantity: ");
                    scanf("%d", &inv[numItems].quantity);
                    numItems++;
                    printf("Item added successfully.\n");
                }
                break;
                
            case 2:
                if(numItems == 0) {
                    printf("Warehouse is empty!\n");
                }
                else {
                    int index = -1;
                    printf("\nEnter product name to delete: ");
                    scanf("%s", searchName);
                    for(int i=0; i<numItems; i++) {
                        if(strcmp(searchName, inv[i].productName) == 0) {
                            index = i;
                            break;
                        }
                    }
                    if(index == -1) {
                        printf("Item not found.\n");
                    }
                    else {
                        for(int i=index; i<numItems; i++) {
                            strcpy(inv[i].productName, inv[i+1].productName);
                            inv[i].quantity = inv[i+1].quantity;
                        }
                        numItems--;
                        printf("Item deleted successfully.\n");
                    }
                }
                break;
                
            case 3:
                if(numItems == 0) {
                    printf("Warehouse is empty!\n");
                }
                else {
                    int index = -1;
                    printf("\nEnter product name to search: ");
                    scanf("%s", searchName);
                    for(int i=0; i<numItems; i++) {
                        if(strcmp(searchName, inv[i].productName) == 0) {
                            index = i;
                            break;
                        }
                    }
                    if(index == -1) {
                        printf("Item not found.\n");
                    }
                    else {
                        printf("%s - %d\n", inv[index].productName, inv[index].quantity);
                    }
                }
                break;
                
            case 4:
                if(numItems == 0) {
                    printf("Warehouse is empty!\n");
                }
                else {
                    printf("\nWarehouse Inventory:\n");
                    for(int i=0; i<numItems; i++) {
                        printf("%s - %d\n", inv[i].productName, inv[i].quantity);
                    }
                }
                break;
                
            case 5:
                printf("Thank you for using Warehouse Management System!\n");
                break;
                
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}