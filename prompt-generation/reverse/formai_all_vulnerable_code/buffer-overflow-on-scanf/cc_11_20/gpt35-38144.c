//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product{
    int id;
    char name[50];
    int quantity;
};

int main(){
    int choice, id, qty, count=0, max_qty=100, i;
    char name[50];
    struct Product inventory[100];

    printf("Welcome to our product inventory system!\n");

    while(1){
        printf("\nChoose an option:\n");
        printf("1. Add a new product\n");
        printf("2. Remove a product\n");
        printf("3. Update product quantity\n");
        printf("4. Print inventory\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(count == max_qty){
                    printf("Cannot add new product. Maximum quantity reached.\n");
                    break;
                }
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product quantity: ");
                scanf("%d", &qty);

                inventory[count].id = count + 1;
                strcpy(inventory[count].name, name);
                inventory[count].quantity = qty;

                printf("Product added successfully!\n");
                count++;
                break;

            case 2:
                if(count == 0){
                    printf("Cannot remove product. Inventory is empty.\n");
                    break;
                }
                printf("Enter product ID to remove: ");
                scanf("%d", &id);

                for(i=0; i<count; i++){
                    if(inventory[i].id == id){
                        for(int j=i; j<count-1; j++){
                            inventory[j] = inventory[j+1];
                        }
                        count--;
                        printf("Product removed successfully!\n");
                        break;
                    }
                }
                if(i == count){
                   printf("Product ID not found in inventory.\n"); 
                }
                break;

            case 3:
                if(count == 0){
                    printf("Cannot update product quantity. Inventory is empty.\n");
                    break;
                }
                printf("Enter product ID to update quantity: ");
                scanf("%d", &id);

                for(i=0; i<count; i++){
                    if(inventory[i].id == id){
                        printf("Enter new quantity: ");
                        scanf("%d", &qty);
                        inventory[i].quantity = qty;
                        printf("Quantity updated successfully!\n");
                        break;
                    }
                }
                if(i == count){
                   printf("Product ID not found in inventory.\n"); 
                }
                break;

            case 4:
                if(count == 0){
                    printf("Inventory is empty.\n");
                    break;
                }
                printf("\nProduct ID\tProduct Name\tQuantity\n");
                for(i=0; i<count; i++){
                    printf("%d\t\t%s\t\t%d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
                }
                break;

            case 5:
                printf("Exiting inventory system...\n");
                exit(0);

            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    }
    return 0;
}