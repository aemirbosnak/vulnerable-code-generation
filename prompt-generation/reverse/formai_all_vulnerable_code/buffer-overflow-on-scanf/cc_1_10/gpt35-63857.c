//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

//Define the structure of the warehouse
typedef struct{
    int item_id; //unique ID for each item
    char item_name[20]; //name of the item
    int quantity; //quantity of item in stock
    float price; //price of item per unit
} Item;

//Declare global variables
Item items[50];
int num_items = 0;

//Function to add an item to the warehouse
void add_item(){
    Item new_item;
    printf("Enter item ID: ");
    scanf("%d",&new_item.item_id);
    printf("Enter item name: ");
    scanf("%s",new_item.item_name);
    printf("Enter quantity: ");
    scanf("%d",&new_item.quantity);
    printf("Enter price: ");
    scanf("%f",&new_item.price);
    items[num_items++] = new_item; //Add the new item to the array
    printf("Item added successfully!\n");
}

//Function to update an item in the warehouse
void update_item(){
    int id;
    printf("Enter item ID to update: ");
    scanf("%d",&id);
    int i;
    for(i=0;i<num_items;i++){
        if(items[i].item_id == id){
            printf("Enter updated quantity: ");
            scanf("%d",&items[i].quantity);
            printf("Enter updated price: ");
            scanf("%f",&items[i].price);
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("No item found with ID %d.\n",id);
}

//Function to remove an item from the warehouse
void remove_item(){
    int id;
    printf("Enter item ID to remove: ");
    scanf("%d",&id);
    int i;
    for(i=0;i<num_items;i++){
        if(items[i].item_id == id){
            int j;
            for(j=i;j<num_items-1;j++){
                items[j] = items[j+1]; //Shift all items after the removed item one position to the left
            }
            num_items--;
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("No item found with ID %d.\n",id);
}

//Function to display all items in the warehouse
void display_items(){
    int i;
    printf("Item ID\tItem Name\tQuantity\tPrice\n");
    for(i=0;i<num_items;i++){
        printf("%d\t%s\t%d\t\t%.2f\n",items[i].item_id,items[i].item_name,items[i].quantity,items[i].price);
    }
}

//Main function to run the program
int main(){
    int choice;
    do{
        printf("Warehouse Management System\n");
        printf("1. Add item\n");
        printf("2. Update item\n");
        printf("3. Remove item\n");
        printf("4. Display items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_item();
                break;
            case 2:
                update_item();
                break;
            case 3:
                remove_item();
                break;
            case 4:
                display_items();
                break;
            case 5:
                printf("Exiting program.");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }while(choice != 5);
    return 0;
}