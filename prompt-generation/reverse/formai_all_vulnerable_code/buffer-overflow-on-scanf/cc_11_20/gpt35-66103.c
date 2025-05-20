//FormAI DATASET v1.0 Category: Product Inventory System ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

int main() {
    int choice, count = 0;
    struct product products[50];

    while(1) {
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Search for Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter product id: ");
                scanf("%d", &products[count].id);
                printf("Enter product name: ");
                scanf("%s", products[count].name);
                printf("Enter quantity: ");
                scanf("%d", &products[count].quantity);
                printf("Enter price: ");
                scanf("%f", &products[count].price);
                count++;
                printf("\nProduct added successfully!\n");
                break;
            case 2:
                if(count == 0) {
                    printf("\nNo products in inventory\n");
                }
                else {
                    printf("\nInventory:\n");
                    printf("ID\tName\tQuantity\tPrice\n");
                    for(int i=0; i<count; i++) {
                        printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
                    }
                }
                break;
            case 3:
                if(count == 0) {
                    printf("\nNo products in inventory\n");
                }
                else {
                    int searchID;
                    printf("\nEnter product id to search: ");
                    scanf("%d", &searchID);
                    int found = 0;
                    for(int i=0; i<count; i++) {
                        if(products[i].id == searchID) {
                            printf("\nProduct Found:\n");
                            printf("ID\tName\tQuantity\tPrice\n");
                            printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
                            found = 1;
                            break;
                        }
                    }
                    if(found == 0) {
                        printf("\nProduct not found\n");
                    }
                }
                break;
            case 4:
                if(count == 0) {
                    printf("\nNo products in inventory\n");
                }
                else {
                    int deleteID, deleteIndex = -1;
                    printf("\nEnter product id to delete: ");
                    scanf("%d", &deleteID);
                    for(int i=0; i<count; i++) {
                        if(products[i].id == deleteID) {
                            deleteIndex = i;
                            break;
                        }
                    }
                    if(deleteIndex == -1) {
                        printf("\nProduct not found\n");
                    }
                    else {
                        printf("\nProduct Deleted: %d %s %d %.2f\n", products[deleteIndex].id, products[deleteIndex].name, products[deleteIndex].quantity, products[deleteIndex].price);
                        for(int i=deleteIndex; i<count-1; i++) {
                            products[i] = products[i+1];
                        }
                        count--;
                    }
                }
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}