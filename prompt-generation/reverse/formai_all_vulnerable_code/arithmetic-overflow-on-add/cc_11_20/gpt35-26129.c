//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

struct item{
    char name[50];
    int quantity;
    float cost;
};

struct warehouse{
    struct item items[MAX_SIZE];
    int count;
};


int main(){
    struct warehouse wHouse;
    wHouse.count = 0;
    int option;

    do{
        // Display the menu
        printf("\nWarehouse Management System\n");
        printf("----------------------------\n");
        printf("1. Add an item\n");
        printf("2. Remove an item\n");
        printf("3. Search for an item\n");
        printf("4. Display all items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // Take input from user
        scanf("%d", &option);

        switch(option){
            case 1:{
                // Add an item
                printf("\nADD ITEM\n");
                printf("--------\n");

                // Ask user for item name, quantity and cost
                printf("Enter item name: ");
                scanf("%s", wHouse.items[wHouse.count].name);

                printf("Enter item quantity: ");
                scanf("%d", &wHouse.items[wHouse.count].quantity);

                printf("Enter item cost: ");
                scanf("%f", &wHouse.items[wHouse.count].cost);

                printf("\nItem added successfully!");

                // Increment item count
                wHouse.count++;

                break;
            }
            case 2:{
                // Remove an item
                printf("\nREMOVE ITEM\n");
                printf("-----------\n");

                // Ask user for item name
                char itemName[50];
                int itemIndex;

                printf("Enter item name: ");
                scanf("%s", itemName);

                // Search for item
                int i;
                for(i=0; i<wHouse.count; i++){
                    if(strcmp(itemName, wHouse.items[i].name) == 0){
                        itemIndex = i;
                        break;
                    }
                }

                // If item is found, remove it
                if(i < wHouse.count){
                    for(i=itemIndex; i<wHouse.count-1; i++){
                        wHouse.items[i] = wHouse.items[i+1];
                    }

                    wHouse.count--;
                    printf("\nItem removed successfully!");
                }
                else{
                    printf("\nItem not found!");
                }

                break;
            }
            case 3:{
                // Search for an item
                printf("\nSEARCH ITEM\n");
                printf("-----------\n");

                // Ask user for item name
                char itemName[50];

                printf("Enter item name: ");
                scanf("%s", itemName);

                // Search for item
                int i;
                for(i=0; i<wHouse.count; i++){
                    if(strcmp(itemName, wHouse.items[i].name) == 0){
                        printf("\nItem found!\n");
                        printf("Name: %s\n", wHouse.items[i].name);
                        printf("Quantity: %d\n", wHouse.items[i].quantity);
                        printf("Cost: %.2f\n", wHouse.items[i].cost);
                        break;
                    }
                }

                // If item is not found
                if(i == wHouse.count){
                    printf("\nItem not found!");
                }

                break;
            }
            case 4:{
                // Display all items
                printf("\nALL ITEMS\n");
                printf("---------\n");

                // If there are no items in the warehouse
                if(wHouse.count == 0){
                    printf("\nNo items to display!");
                }
                else{
                    // Display all items
                    int i;
                    printf("Name\t\tQuantity\tCost\n");
                    printf("----\t\t--------\t----\n");

                    for(i=0; i<wHouse.count; i++){
                        printf("%s\t\t%d\t\t%.2f\n", wHouse.items[i].name, wHouse.items[i].quantity, wHouse.items[i].cost);
                    }
                }

                break;
            }
            case 5:{
                // Exit
                printf("\nThank you for using Warehouse Management System.\n");
                printf("Have a nice day!\n");

                exit(0);

                break;
            }
            default:{
                printf("\nInvalid option! Please try again.");
            }
        }
    }while(1);

    return 0;
}