//FormAI DATASET v1.0 Category: Product Inventory System ; Style: unmistakable
#include <stdio.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    float price;
    int quantity;
};

int main() {
    struct product inventory[100];
    int n = 0;
    int choice;
    int id, quantity;
    float price;
    char name[50];
    
    do {
        printf("\n1. Add new product\n");
        printf("2. Display all products\n");
        printf("3. Update product quantity\n");
        printf("4. Update product price\n");
        printf("5. Search product by ID\n");
        printf("6. Delete product by ID\n");
        printf("7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            
            case 1:
                printf("\nEnter product ID: ");
                scanf("%d", &id);
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product price: ");
                scanf("%f", &price);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                
                inventory[n].id = id;
                strcpy(inventory[n].name, name);
                inventory[n].price = price;
                inventory[n].quantity = quantity;
                
                printf("\nNew product added successfully!\n");
                n++;
                break;
            
            case 2:
                printf("\nProduct Inventory:\n");
                printf("ID\tName\tPrice\tQuantity\n");
                printf("---------------------------------------\n");
                for(int i=0; i<n; i++) {
                    printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
                }
                printf("---------------------------------------\n");
                break;
            
            case 3:
                printf("\nEnter product ID: ");
                scanf("%d", &id);
                
                for(int i=0; i<n; i++) {
                    if(inventory[i].id == id) {
                        printf("Enter new quantity: ");
                        scanf("%d", &quantity);
                        inventory[i].quantity = quantity;
                        printf("\nProduct quantity updated successfully!\n");
                        goto end;
                    }
                }
                printf("\nProduct with ID %d not found!\n", id);
                end:
                break;
            
            case 4:
                printf("\nEnter product ID: ");
                scanf("%d", &id);
                
                for(int i=0; i<n; i++) {
                    if(inventory[i].id == id) {
                        printf("Enter new price: ");
                        scanf("%f", &price);
                        inventory[i].price = price;
                        printf("\nProduct price updated successfully!\n");
                        goto end2;
                    }
                }
                printf("\nProduct with ID %d not found!\n", id);
                end2:
                break;
            
            case 5:
                printf("\nEnter product ID: ");
                scanf("%d", &id);
                
                for(int i=0; i<n; i++) {
                    if(inventory[i].id == id) {
                        printf("\nID\tName\tPrice\tQuantity\n");
                        printf("---------------------------------------\n");
                        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
                        printf("---------------------------------------\n");
                        goto end3;
                    }
                }
                printf("\nProduct with ID %d not found!\n", id);
                end3:
                break;
            
            case 6:
                printf("\nEnter product ID: ");
                scanf("%d", &id);
                
                for(int i=0; i<n; i++) {
                    if(inventory[i].id == id) {
                        for(int j=i; j<n-1; j++) {
                            inventory[j] = inventory[j+1];
                        }
                        n--;
                        printf("\nProduct deleted successfully!\n");
                        goto end4;
                    }
                }
                printf("\nProduct with ID %d not found!\n", id);
                end4:
                break;
            
            case 7:
                printf("\nExiting program...Goodbye!\n");
                break;
            
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice != 7);
    
    return 0;
}