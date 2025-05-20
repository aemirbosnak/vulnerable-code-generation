//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item_details{
    int item_id;
    char item_name[20];
    int quantity;
    float price;
};

void add_item(struct item_details*, int);
void remove_item(struct item_details*, int);
void update_item(struct item_details*, int);
void view_inventory(struct item_details*, int);

int main(){
    int n, choice;
    struct item_details *inventory;
    printf("Enter the number of items in the inventory: ");
    scanf("%d", &n);
    inventory = (struct item_details*)malloc(n*sizeof(struct item_details));
    printf("Enter the item details - id, name, quantity and price:\n");
    for(int i=0;i<n;i++){
        scanf("%d%s%d%f", &inventory[i].item_id, inventory[i].item_name, &inventory[i].quantity, &inventory[i].price);
    }
    printf("\nWarehouse Management System\n\n1. Add Item\n2. Remove Item\n3. Update Item\n4. View Inventory\n5. Exit\n\n");
    do{
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_item(inventory, n);
                    break;
            case 2: remove_item(inventory, n);
                    break;
            case 3: update_item(inventory, n);
                    break;
            case 4: view_inventory(inventory, n);
                    break;
            case 5: printf("Exiting program...\n");
                    break;
            default: printf("Invalid choice, try again.\n");
                    break;
        }
    }while(choice!=5);
    free(inventory);
    return 0;
}

void add_item(struct item_details *inventory, int n){
    int id, quantity, flag=0;
    char name[20];
    float price;
    printf("\nEnter the item details - id, name, quantity and price:\n");
    scanf("%d%s%d%f", &id, name, &quantity, &price);
    for(int i=0;i<n;i++){
        if(inventory[i].item_id==id){
            inventory[i].quantity+=quantity;
            printf("Item quantity updated successfully!\n");
            flag=1;
            break;
        }
    }
    if(flag==0){
        inventory = (struct item_details*)realloc(inventory, (n+1)*sizeof(struct item_details));
        inventory[n].item_id = id;
        strcpy(inventory[n].item_name, name);
        inventory[n].quantity = quantity;
        inventory[n].price = price;
        printf("Item added successfully!\n");
        n++;
    }
}

void remove_item(struct item_details *inventory, int n){
    int id, flag=0;
    printf("\nEnter the item id to be removed: ");
    scanf("%d", &id);
    for(int i=0;i<n;i++){
        if(inventory[i].item_id==id){
            for(int j=i;j<n-1;j++){
                inventory[j] = inventory[j+1];
            }
            inventory = (struct item_details*)realloc(inventory, (n-1)*sizeof(struct item_details));
            printf("Item removed successfully!\n");
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("Item not found, try again.\n");
    }
    else{
        n--;
    }
}

void update_item(struct item_details *inventory, int n){
    int id, quantity, flag=0;
    printf("\nEnter the item id to be updated: ");
    scanf("%d", &id);
    for(int i=0;i<n;i++){
        if(inventory[i].item_id==id){
            printf("Enter the quantity to be updated: ");
            scanf("%d", &quantity);
            inventory[i].quantity = quantity;
            printf("Item quantity updated successfully!\n");
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("Item not found, try again.\n");
    }
}

void view_inventory(struct item_details *inventory, int n){
    printf("\nItem ID\tItem Name\tQuantity\tPrice\n");
    for(int i=0;i<n;i++){
        printf("%d\t%s\t%d\t%.2f\n", inventory[i].item_id, inventory[i].item_name, inventory[i].quantity, inventory[i].price);
    }
}