//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to store inventory details
struct inventory{
    char item_name[20];
    int item_code, quantity;
    float cost_price, selling_price;
}inv[100];

//Function to add item to inventory
void add_item(){
    int n, i;
    printf("Enter the number of items you want to add: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("\nEnter the details of item %d: \n", i+1);
        printf("Item code: ");
        scanf("%d", &inv[i].item_code);
        printf("Item name: ");
        scanf("%s", inv[i].item_name);
        printf("Quantity: ");
        scanf("%d", &inv[i].quantity);
        printf("Cost price: ");
        scanf("%f", &inv[i].cost_price);
        printf("Selling price: ");
        scanf("%f", &inv[i].selling_price);
    }
}

//Function to display inventory details
void display_inventory(){
    if(!strcmp(inv[0].item_name, "")){
        printf("\nInventory is empty!\n");
        return;
    }
    int i;
    printf("\nInventory Details:\n");
    printf("--------------------------------------------------\n");
    printf("Item Code | Item Name | Quantity | Cost Price | Selling Price\n");
    printf("--------------------------------------------------\n");
    for(i=0; strcmp(inv[i].item_name, "")!=0; i++){
        printf("%-10d|%-10s|%-10d|%10.2f|%10.2f\n", inv[i].item_code, inv[i].item_name, inv[i].quantity, inv[i].cost_price, inv[i].selling_price);
    }
}

//Function to search for an item by item code
void search_item(){
    if(!strcmp(inv[0].item_name, "")){
        printf("\nInventory is empty!\n");
        return;
    }
    int i, code, flag = 0;
    printf("\nEnter the item code you want to search: ");
    scanf("%d", &code);
    for(i=0; strcmp(inv[i].item_name, "")!=0; i++){
        if(inv[i].item_code == code){
            printf("\nItem found!\n");
            printf("Item Code | Item Name | Quantity | Cost Price | Selling Price\n");
            printf("--------------------------------------------------\n");
            printf("%-10d|%-10s|%-10d|%10.2f|%10.2f\n", inv[i].item_code, inv[i].item_name, inv[i].quantity, inv[i].cost_price, inv[i].selling_price);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("\nItem not found!\n");
    }
}

//Function to update item details
void update_item(){
    if(!strcmp(inv[0].item_name, "")){
        printf("\nInventory is empty!\n");
        return;
    }
    int i, code, flag = 0;
    printf("\nEnter the item code you want to update: ");
    scanf("%d", &code);
    for(i=0; strcmp(inv[i].item_name, "")!=0; i++){
        if(inv[i].item_code == code){
            flag = 1;
            printf("\nEnter the updated details of the item:\n");
            printf("Item name: ");
            scanf("%s", inv[i].item_name);
            printf("Quantity: ");
            scanf("%d", &inv[i].quantity);
            printf("Cost price: ");
            scanf("%f", &inv[i].cost_price);
            printf("Selling price: ");
            scanf("%f", &inv[i].selling_price);
            printf("\nItem details updated successfully!\n");
            break;
        }
    }
    if(flag == 0){
        printf("\nItem not found!\n");
    }
}

//Function to delete an item from inventory
void delete_item(){
    if(!strcmp(inv[0].item_name, "")){
        printf("\nInventory is empty!\n");
        return;
    }
    int i, code, flag = 0;
    printf("\nEnter the item code you want to delete: ");
    scanf("%d", &code);
    for(i=0; strcmp(inv[i].item_name, "")!=0; i++){
        if(inv[i].item_code == code){
            flag = 1;
            //Shift all items after deleted item to left by 1 position
            for(int j=i; strcmp(inv[j].item_name, "")!=0; j++){
                strcpy(inv[j].item_name, inv[j+1].item_name);
                inv[j].item_code = inv[j+1].item_code;
                inv[j].quantity = inv[j+1].quantity;
                inv[j].cost_price = inv[j+1].cost_price;
                inv[j].selling_price = inv[j+1].selling_price;
            }
            printf("\nItem deleted successfully!\n");
            break;
        }
    }
    if(flag == 0){
        printf("\nItem not found!\n");
    }
}

int main(){
    int ch;
    while(1){
        printf("\n****Warehouse Management System****\n");
        printf("1.Add item\n");
        printf("2.Display inventory\n");
        printf("3.Search item\n");
        printf("4.Update item\n");
        printf("5.Delete item\n");
        printf("6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: add_item();
                    break;
            case 2: display_inventory();
                    break;
            case 3: search_item();
                    break;
            case 4: update_item();
                    break;
            case 5: delete_item();
                    break;
            case 6: exit(0);
                    break;
            default: printf("\nInvalid choice!\n");
                     break;
        }
    }
    return 0;
}