//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: portable
#include<stdio.h>
#include<stdlib.h>

// Node structure for item
struct item_node{
    int item_id; // unique item id
    int quantity; // quantity of item in stock
    struct item_node* next; // pointer to next item in the linked list
};

// Node structure for shelf
struct shelf_node{
    int shelf_id; // unique shelf id
    struct item_node* item_list; // pointer to linked list of items on the shelf
    struct shelf_node* next; // pointer to next shelf in the linked list
};

// Function to add an item to a shelf
void add_item(struct shelf_node* shelf, int item_id, int quantity){
    struct item_node* temp_item = (struct item_node*)malloc(sizeof(struct item_node)); // create new item node
    temp_item->item_id = item_id; // add item id
    temp_item->quantity = quantity; // add quantity
    temp_item->next = shelf->item_list; // add node to the beginning of item linked list
    shelf->item_list = temp_item; // update item list pointer
}

// Function to remove an item from a shelf
void remove_item(struct shelf_node* shelf, int item_id){
    struct item_node *current_item = shelf->item_list, *prev_item = NULL;
    while (current_item != NULL && current_item->item_id != item_id){
        prev_item = current_item;
        current_item = current_item->next;
    }
    if (current_item == NULL) return; // item with given id not found
    if (prev_item == NULL) shelf->item_list = current_item->next; // item is first in linked list
    else prev_item->next = current_item->next; // update previous item's next pointer
    free(current_item); // free memory allocated to item
}

// Function to display all items on a shelf
void display_items_on_shelf(struct shelf_node* shelf){
     printf("Items on Shelf with ID %d:\n", shelf->shelf_id);
     struct item_node* current_item = shelf->item_list;
     while (current_item != NULL){
         printf("Item ID: %d, Quantity: %d\n", current_item->item_id, current_item->quantity);
         current_item = current_item->next;
     }
}

// main function
int main(){
    int num_shelves, num_items, item_id, quantity, shelf_id, choice;
    struct shelf_node *head_shelf = NULL, *new_shelf, *current_shelf; // pointer variables for shelves
    printf("Enter number of shelves: ");
    scanf("%d", &num_shelves); // get number of shelves to create
    for (int i = 0; i < num_shelves; i++){
        new_shelf = (struct shelf_node*)malloc(sizeof(struct shelf_node)); // create new shelf node
        new_shelf->item_list = NULL; // set item list pointer to NULL initially
        printf("Enter ID for Shelf %d: ", i+1);
        scanf("%d", &new_shelf->shelf_id); // get shelf id
        new_shelf->next = head_shelf; // add shelf node to beginning of shelf linked list
        head_shelf = new_shelf; // update shelf pointer
    }
    while (1){
        printf("\n\nSelect Action:\n1. Add Item\n2. Remove Item\n3. Display Items on Shelf\n4. Quit\n\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter ID of Shelf to Add Item to: ");
                scanf("%d", &shelf_id);
                current_shelf = head_shelf;
                while (current_shelf != NULL && current_shelf->shelf_id != shelf_id) current_shelf = current_shelf->next;
                if (current_shelf == NULL){
                    printf("Shelf not found with given ID.\n");
                    break;
                }
                printf("Enter ID of Item to Add: ");
                scanf("%d", &item_id);
                printf("Enter Quantity of Item to Add: ");
                scanf("%d", &quantity);
                add_item(current_shelf, item_id, quantity);
                printf("Item added successfully.\n");
                break;
            case 2:
                printf("Enter ID of Shelf to Remove Item from: ");
                scanf("%d", &shelf_id);
                current_shelf = head_shelf;
                while (current_shelf != NULL && current_shelf->shelf_id != shelf_id) current_shelf = current_shelf->next;
                if (current_shelf == NULL){
                    printf("Shelf not found with given ID.\n");
                    break;
                }
                printf("Enter ID of Item to Remove: ");
                scanf("%d", &item_id);
                remove_item(current_shelf, item_id);
                printf("Item removed successfully.\n");
                break;
            case 3:
                printf("Enter ID of Shelf to Display Items on: ");
                scanf("%d", &shelf_id);
                current_shelf = head_shelf;
                while (current_shelf != NULL && current_shelf->shelf_id != shelf_id) current_shelf = current_shelf->next;
                if (current_shelf == NULL){
                    printf("Shelf not found with given ID.\n");
                    break;
                }
                display_items_on_shelf(current_shelf);
                break;
            case 4:
                exit(0); // exit program
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}