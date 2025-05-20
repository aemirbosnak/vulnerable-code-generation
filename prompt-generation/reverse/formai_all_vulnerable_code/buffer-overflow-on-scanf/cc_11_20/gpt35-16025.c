//FormAI DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product{
    int id;
    char name[100];
    int quantity;
    float price;
};

int main(){
    int option, id, pos=0;
    struct product inventory[100];
    do{
        printf("Welcome to Product Inventory System\n");
        printf("Choose an option:\n");
        printf("1. Add a new product\n");
        printf("2. Update an existing product\n");
        printf("3. Delete a product\n");
        printf("4. View all products\n");
        printf("5. View a specific product\n");
        printf("6. Exit\n");
        printf("Your option: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("\nAdd a new product\n");
                printf("Enter product name: ");
                scanf("%s", inventory[pos].name);
                printf("Enter product quantity: ");
                scanf("%d", &inventory[pos].quantity);
                printf("Enter product price: ");
                scanf("%f", &inventory[pos].price);
                inventory[pos].id = pos+1;
                pos++;
                printf("Product added successfully!\n\n");
                break;
            case 2:
                printf("\nUpdate an existing product\n");
                printf("Enter product id: ");
                scanf("%d", &id);
                for(int i=0;i<pos;i++){
                    if(inventory[i].id == id){
                        printf("Enter product name: ");
                        scanf("%s", inventory[i].name);
                        printf("Enter product quantity: ");
                        scanf("%d", &inventory[i].quantity);
                        printf("Enter product price: ");
                        scanf("%f", &inventory[i].price);
                        printf("Product updated successfully!\n\n");
                        break;
                    }
                }
                break;
            case 3:
                printf("\nDelete a product\n");
                printf("Enter product id: ");
                scanf("%d", &id);
                for(int i=0;i<pos;i++){
                    if(inventory[i].id == id){
                        for(int j=i;j<pos-1;j++){
                            inventory[j] = inventory[j+1];
                        }
                        pos--;
                        printf("Product deleted successfully!\n\n");
                        break;
                    }
                }
                break;
            case 4:
                printf("\nView all products\n");
                printf("ID\tName\tQuantity\tPrice\n");
                printf("--------------------------------------------------\n");
                for(int i=0;i<pos;i++){
                    printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                }
                printf("\n");
                break;
            case 5:
                printf("\nView a specific product\n");
                printf("Enter product id: ");
                scanf("%d", &id);
                printf("ID\tName\tQuantity\tPrice\n");
                printf("--------------------------------------------------\n");
                for(int i=0;i<pos;i++){
                    if(inventory[i].id == id){
                        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                        printf("\n");
                        break;
                    }
                }
                break;
            case 6:
                printf("\nExiting Program\n");
                exit(0);
            default:
                printf("\nInvalid option, please try again\n\n");
                break;
        }
    }while(1);
    return 0;
}