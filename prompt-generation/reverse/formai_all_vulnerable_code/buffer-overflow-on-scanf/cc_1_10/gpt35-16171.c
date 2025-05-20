//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

//Struct to store the warehouse item details
struct Item {
    int item_id;
    char item_name[50];
    int quantity;
    float price;
    char category[20];
};

//Function to display the main menu
void displayMainMenu() {
    printf("\n--Warehouse Management System--\n\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Search Item\n");
    printf("4. Update Item\n");
    printf("5. Display Inventory\n");
    printf("6. Exit\n");
}

int main() {
    int option;
    int count = 0;
    struct Item items[100];
    
    do {
        displayMainMenu();
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1: //Add Item
                printf("\n--Add Item--\n");
                printf("Enter Item ID: ");
                scanf("%d", &items[count].item_id);
                printf("Enter Item Name: ");
                scanf("%s", items[count].item_name);
                printf("Enter Quantity: ");
                scanf("%d", &items[count].quantity);
                printf("Enter Price: ");
                scanf("%f", &items[count].price);
                printf("Enter Category: ");
                scanf("%s", items[count].category);
                count++;
                printf("Item Added Successfully!\n");
                break;
            case 2: //Remove Item
                printf("\n--Remove Item--\n");
                printf("Enter Item ID: ");
                int remove_id;
                scanf("%d", &remove_id);
                int index = -1;
                for(int i=0; i<count; i++) {
                    if(items[i].item_id == remove_id) {
                        index = i;
                        break;
                    }
                }
                if(index == -1) {
                    printf("Item not found!\n");
                }
                else {
                    for(int i=index; i<count-1; i++) {
                        items[i] = items[i+1];
                    }
                    count--;
                    printf("Item Removed Successfully!\n");
                }
                break;
            case 3: //Search Item
                printf("\n--Search Item--\n");
                printf("Enter Item ID: ");
                int search_id;
                scanf("%d", &search_id);
                index = -1;
                for(int i=0; i<count; i++) {
                    if(items[i].item_id == search_id) {
                        index = i;
                        break;
                    }
                }
                if(index == -1) {
                    printf("Item not found!\n");
                }
                else {
                    printf("\n--Item Details--\n");
                    printf("Name: %s\n", items[index].item_name);
                    printf("Quantity: %d\n", items[index].quantity);
                    printf("Price: %.2f\n", items[index].price);
                    printf("Category: %s\n", items[index].category);
                }
                break;
            case 4: //Update Item
                printf("\n--Update Item--\n");
                printf("Enter Item ID: ");
                int update_id;
                scanf("%d", &update_id);
                index = -1;
                for(int i=0; i<count; i++) {
                    if(items[i].item_id == update_id) {
                        index = i;
                        break;
                    }
                }
                if(index == -1) {
                    printf("Item not found!\n");
                }
                else {
                    printf("Enter new Quantity: ");
                    scanf("%d", &items[index].quantity);
                    printf("Enter new Price: ");
                    scanf("%f", &items[index].price);
                    printf("Item Updated Successfully!\n");
                }
                break;
            case 5: //Display Inventory
                printf("\n--Inventory--\n");
                printf("ID\tName\t\tQuantity\tPrice\t\tCategory\n");
                for(int i=0; i<count; i++) {
                    printf("%d\t%s\t\t%d\t\t%.2f\t\t%s\n", items[i].item_id, items[i].item_name, items[i].quantity, items[i].price, items[i].category);
                }
                break;
            case 6: //Exit
                printf("\nThank You for using Warehouse Management System!\n\n");
                exit(0);
                break;
            default: //Invalid Option
                printf("Invalid Option!\n");
        }
    } while(1);

    return 0;
}