//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

typedef struct Item{
    char name[20];
    int quantity;
    float price;
} Item;

int main(){
    Item *warehouse;
    int num_items, choice, item_choice;
    float total_value = 0.0;

    printf("Welcome to the Warehouse Management System.\n\n");
    printf("How many items are in your warehouse? ");
    scanf("%d", &num_items);

    warehouse = malloc(num_items * sizeof(Item));

    printf("\n");

    for(int i = 0; i < num_items; i++){
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", warehouse[i].name);
        printf("Enter the quantity of item %d: ", i+1);
        scanf("%d", &warehouse[i].quantity);
        printf("Enter the price of item %d: ", i+1);
        scanf("%f", &warehouse[i].price);
        printf("\n");
    }

    while(1){
        printf("What would you like to do?\n");
        printf("1. Add item.\n");
        printf("2. Remove item.\n");
        printf("3. View warehouse.\n");
        printf("4. View total value of warehouse.\n");
        printf("5. Quit.\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1:
                printf("Which item would you like to add? (1-%d): ", num_items);
                scanf("%d", &item_choice);
                printf("How many would you like to add? ");
                int add;
                scanf("%d", &add);
                warehouse[item_choice-1].quantity += add;
                printf("%d %s(s) have been added to the warehouse.\n\n", add, warehouse[item_choice-1].name);
                break;
            case 2:
                printf("Which item would you like to remove? (1-%d): ", num_items);
                scanf("%d", &item_choice);
                printf("How many would you like to remove? ");
                int remove;
                scanf("%d", &remove);
                if(remove > warehouse[item_choice-1].quantity){
                    printf("There are not enough %s(s) in the warehouse to remove.\n\n", warehouse[item_choice-1].name);
                } else {
                    warehouse[item_choice-1].quantity -= remove;
                    printf("%d %s(s) have been removed from the warehouse.\n\n", remove, warehouse[item_choice-1].name);
                }
                break;
            case 3:
                printf("Warehouse:\n");
                for(int i = 0; i < num_items; i++){
                    printf("%d. %s - Quantity: %d Price: %.2f\n", i+1, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
                }
                printf("\n");
                break;
            case 4:
                for(int i = 0; i < num_items; i++){
                    total_value += warehouse[i].price * warehouse[i].quantity;
                }
                printf("The total value of the warehouse is $%.2f.\n\n", total_value);
                break;
            case 5:
                printf("Thank you for using the Warehouse Management System.\n");
                free(warehouse);
                return 0;
            default:
                printf("Invalid choice. Please enter a valid choice.\n\n");
                break;
        }
    }
}