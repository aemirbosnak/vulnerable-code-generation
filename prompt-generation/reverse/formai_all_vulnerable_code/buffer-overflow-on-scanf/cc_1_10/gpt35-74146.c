//FormAI DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUCTS 100

struct product{
    int id;
    char name[50];
    int quantity;
    float price;
};

struct inventory{
    struct product products[MAX_PRODUCTS];
    int count;
};

struct inventory inventory;

void add_product(){
    printf("Enter product name: ");
    scanf("%s", &inventory.products[inventory.count].name);
    
    printf("Enter product quantity: ");
    scanf("%d", &inventory.products[inventory.count].quantity);
    
    printf("Enter product price: ");
    scanf("%f", &inventory.products[inventory.count].price);
    
    inventory.products[inventory.count].id = inventory.count + 1;
    inventory.count++;
    
    printf("Product added successfully!\n");
}

void view_products(){
    if(inventory.count == 0){
        printf("No products added to inventory yet.\n");
        return;
    }
    
    printf("ID\tName\tQuantity\tPrice\n");
    for(int i=0; i<inventory.count; i++){
        printf("%d\t%s\t%d\t\t%.2f\n", inventory.products[i].id, 
               inventory.products[i].name, 
               inventory.products[i].quantity, 
               inventory.products[i].price);
    }
}

void update_product(){
    int id, choice;
    
    printf("Enter ID of product to update: ");
    scanf("%d", &id);
    
    for(int i=0; i<inventory.count; i++){
        if(inventory.products[i].id == id){
            printf("What do you want to update?\n");
            printf("1. Name\n2. Quantity\n3. Price\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            
            switch(choice){
                case 1:
                    printf("Enter new product name: ");
                    scanf("%s", &inventory.products[i].name);
                    break;
                case 2:
                    printf("Enter new quantity: ");
                    scanf("%d", &inventory.products[i].quantity);
                    break;
                case 3:
                    printf("Enter new price: ");
                    scanf("%f", &inventory.products[i].price);
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            
            printf("Product updated successfully!\n");
            return;
        }
    }
    
    printf("Product not found.\n");
}

void sell_product(){
    int id, quantity;
    
    printf("Enter ID of product to sell: ");
    scanf("%d", &id);
    
    for(int i=0; i<inventory.count; i++){
        if(inventory.products[i].id == id){
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);
            
            if(quantity <= inventory.products[i].quantity){
                inventory.products[i].quantity -= quantity;
                printf("Sold %d units of %s for %.2f each for a total of %.2f.\n", 
                       quantity, inventory.products[i].name, 
                       inventory.products[i].price, 
                       quantity * inventory.products[i].price);
                return;
            }
            else{
                printf("Not enough quantity in stock.\n");
                return;
            }
        }
    }
    
    printf("Product not found.\n");
}

int main(){
    int choice;
    
    while(1){
        printf("\nProduct Inventory System\n");
        printf("------------------------\n");
        printf("1. Add product\n");
        printf("2. View all products\n");
        printf("3. Update product\n");
        printf("4. Sell product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                add_product();
                break;
            case 2:
                view_products();
                break;
            case 3:
                update_product();
                break;
            case 4:
                sell_product();
                break;
            case 5:
                printf("Thank you for using the system.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}