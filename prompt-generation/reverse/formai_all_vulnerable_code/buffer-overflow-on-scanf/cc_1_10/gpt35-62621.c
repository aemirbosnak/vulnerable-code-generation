//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: detailed
#include<stdio.h>

struct item{
    int ID;
    char name[50];
    int quantity;
    float price;
};

void add_item(struct item *inventory, int *size);
void display_inventory(struct item *inventory, int size);
void remove_item(struct item *inventory, int *size);
void edit_item(struct item *inventory, int size);

int main(){
    struct item inventory[100];
    int size=0;
    int choice;

    printf("***WAREHOUSE MANAGEMENT SYSTEM***\n");
    do{
        printf("\n1. Add Item\n");
        printf("2. Display Inventory\n");
        printf("3. Remove Item\n");
        printf("4. Edit Item\n");
        printf("5. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: add_item(inventory, &size); break;
            case 2: display_inventory(inventory, size); break;
            case 3: remove_item(inventory, &size); break;
            case 4: edit_item(inventory, size); break;
            case 5: printf("\nExiting program...\n"); break;
            default: printf("\nInvalid choice. Please try again.\n"); break;
        }
    }while(choice!=5);

    return 0;
}

void add_item(struct item *inventory, int *size){
    printf("\nEnter item ID: ");
    scanf("%d",&inventory[*size].ID);
    printf("Enter item name: ");
    scanf("%s",inventory[*size].name);
    printf("Enter item quantity: ");
    scanf("%d",&inventory[*size].quantity);
    printf("Enter item price: ");
    scanf("%f",&inventory[*size].price);
    (*size)++;
    printf("\nItem successfully added!\n");
}

void display_inventory(struct item *inventory, int size){
    printf("\nID\tNAME\t\tQUANTITY\tPRICE\n");
    for(int i=0;i<size;i++){
        printf("%d\t%-15s%d\t\t$%.2f\n",inventory[i].ID,inventory[i].name,inventory[i].quantity,inventory[i].price);
    }
}

void remove_item(struct item *inventory, int *size){
    int id_to_remove;
    int found=0;
    printf("\nEnter item ID to remove: ");
    scanf("%d",&id_to_remove);
    for(int i=0;i<*size;i++){
        if(inventory[i].ID==id_to_remove){
            found=1;
            for(int j=i;j<*size-1;j++){
                inventory[j].ID=inventory[j+1].ID;
                strcpy(inventory[j].name,inventory[j+1].name);
                inventory[j].quantity=inventory[j+1].quantity;
                inventory[j].price=inventory[j+1].price;
            }
            (*size)--;
            printf("\nItem successfully removed!\n");
            break;
        }
    }
    if(!found){
        printf("\nItem with ID %d not found.\n",id_to_remove);
    }
}

void edit_item(struct item *inventory, int size){
    int id_to_edit;
    int found=0;
    printf("\nEnter item ID to edit: ");
    scanf("%d",&id_to_edit);
    for(int i=0;i<size;i++){
        if(inventory[i].ID==id_to_edit){
            found=1;
            printf("\nEnter new details for item with ID %d:\n",id_to_edit);
            printf("Item name (leave blank to keep current value of %s): ",inventory[i].name);
            scanf("%s",inventory[i].name);
            printf("Item quantity (leave blank to keep current value of %d): ",inventory[i].quantity);
            scanf("%d",&inventory[i].quantity);
            printf("Item price (leave blank to keep current value of $%.2f): ",inventory[i].price);
            scanf("%f",&inventory[i].price);
            printf("\nItem details successfully updated!\n");
            break;
        }
    }
    if(!found){
        printf("\nItem with ID %d not found.\n",id_to_edit);
    }
}