//FormAI DATASET v1.0 Category: Product Inventory System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product{
    char name[20];
    int id;
    float price;
    int quantity;
};

int main(){
    int choice, n=0, i=0, id, flag=0;
    float p;
    char nme[20];
    struct product inventory[50];

    do{
        printf("\nProduct Inventory System:\n");
        printf("1. Add a product\n2. Display all products\n3. Search a product by ID\n4. Search a product by Name");
        printf("\n5. Quit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1: // Adding a product
                printf("\nEnter product name, ID, price, and quantity: ");
                scanf("%s %d %f %d", &inventory[n].name, &inventory[n].id, &inventory[n].price, &inventory[n].quantity);
                n++;
                break;

            case 2: // Displaying all products
                if(n == 0){
                    printf("\nNo products have been added yet.\n");
                    break;
                }
                printf("\nInventory:\n");
                printf("Name\tID\tPrice\tQuantity\n");
                for(i=0;i<n;i++){
                    printf("%s\t%d\t%.2f\t%d\n", inventory[i].name, inventory[i].id, inventory[i].price, inventory[i].quantity);
                }
                break;

            case 3: // Searching a product by ID
                printf("\nEnter product ID to be searched: ");
                scanf("%d", &id);
                flag = 0;
                for(i=0;i<n;i++){
                    if(inventory[i].id == id){
                        printf("\nProduct Found!\n");
                        printf("Name\tID\tPrice\tQuantity\n");
                        printf("%s\t%d\t%.2f\t%d\n", inventory[i].name, inventory[i].id, inventory[i].price, inventory[i].quantity);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    printf("\nProduct ID not found.\n");
                }
                break;

            case 4: // Searching a product by name
                printf("\nEnter product name to be searched: ");
                scanf("%s", nme);
                flag = 0;
                for(i=0;i<n;i++){
                    if(strcmp(inventory[i].name,nme) == 0){
                        printf("\nProduct Found!\n");
                        printf("Name\tID\tPrice\tQuantity\n");
                        printf("%s\t%d\t%.2f\t%d\n", inventory[i].name, inventory[i].id, inventory[i].price, inventory[i].quantity);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    printf("\nProduct name not found.\n");
                }
                break;

            case 5: // Exiting the program
                printf("\nExiting program.\n");
                break;

            default: // Invalid choice
                printf("\nInvalid choice. Please enter again.\n");
                break;

        }

    }while(choice != 5);

    return 0;
}