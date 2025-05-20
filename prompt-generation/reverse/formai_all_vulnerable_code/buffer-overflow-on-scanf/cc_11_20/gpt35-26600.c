//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 1000 //maximum number of items the warehouse can hold
#define MAX_NAME_LEN 50 //maximum length of an item name

typedef struct Item {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

int main() {
    Item warehouse[MAX_ITEMS]; //declaring an array of type Item to represent the warehouse
    int num_items = 0; //initializing the number of items in the warehouse to zero

    int user_choice = 0;
    do {
        printf("What would you like to do?\n");
        printf("1. Add an item to the warehouse.\n");
        printf("2. Remove an item from the warehouse.\n");
        printf("3. Display all items in the warehouse.\n");
        printf("4. Quit.\n");

        scanf("%d", &user_choice); //getting the user's choice

        switch(user_choice) {
            case 1: //adding an item
                if(num_items >= MAX_ITEMS) { //checking if the warehouse is full
                    printf("Warehouse is full. Cannot add item.\n");
                    break;
                }

                Item new_item;
                printf("Enter the name of the item: ");
                scanf("%s", new_item.name); //getting the name of the item

                printf("Enter the quantity of the item: ");
                scanf("%d", &new_item.quantity); //getting the quantity of the item

                printf("Enter the price of the item: ");
                scanf("%f", &new_item.price); //getting the price of the item

                warehouse[num_items] = new_item; //adding the new item to the warehouse
                num_items++; //incrementing the number of items in the warehouse
                break;

            case 2: //removing an item
                if(num_items <= 0) { //checking if the warehouse is empty
                    printf("Warehouse is empty. Cannot remove item.\n");
                    break;
                }

                printf("Enter the index of the item to remove: ");
                int remove_index;
                scanf("%d", &remove_index); //getting the index of the item to remove

                if(remove_index < 0 || remove_index >= num_items) { //checking if the index is valid
                    printf("Invalid item index. Cannot remove item.\n");
                    break;
                }

                for(int i = remove_index; i < num_items-1; i++) { //shifting all items to the left
                    warehouse[i] = warehouse[i+1];
                }

                num_items--; //decrementing the number of items in the warehouse
                break;

            case 3: //displaying all items
                if(num_items <= 0) { //checking if the warehouse is empty
                    printf("Warehouse is empty.\n");
                    break;
                }

                printf("Warehouse Items:\n");
                printf("| %-4s | %-20s | %-8s | %-8s | %-8s |\n", "Index", "Name", "Quantity", "Price", "Value"); //printing the header
                float total_value = 0;
                for(int i = 0; i < num_items; i++) { //printing each item
                    float curr_value = warehouse[i].quantity * warehouse[i].price; //calculating the value of the current item
                    printf("| %-4d | %-20s | %-8d | %-8.2f | %-8.2f |\n", i, warehouse[i].name, warehouse[i].quantity, warehouse[i].price, curr_value);
                    total_value += curr_value; //adding the current item's value to the total value
                }
                printf("Total Value: %.2f\n", total_value); //printing the total value of all items in the warehouse
                break;

            case 4: //quitting the program
                printf("Quitting Warehouse Management System.\n");
                break;

            default: //invalid choice
                printf("Invalid choice. Try again.\n");
                break;
        }

    } while(user_choice != 4); //repeating until the user chooses to quit

    return 0;
}