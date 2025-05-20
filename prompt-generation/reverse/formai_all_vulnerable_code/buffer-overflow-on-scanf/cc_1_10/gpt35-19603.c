//FormAI DATASET v1.0 Category: Product Inventory System ; Style: puzzling
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Inventory{
    char name[20];
    int quantity;
    float price;
};

void display_inventory(struct Inventory items[]){
    int i;
    printf("Name\tQuantity\tPrice\n");
    for(i=0;i<3;i++){
        printf("%s\t%d\t\t%.2f\n",items[i].name,items[i].quantity,items[i].price);
    }
}

void add_item(struct Inventory items[]){
    int i;
    char n[20];
    printf("Enter the name of the item to add: ");
    scanf("%s",n);
    for(i=0;i<3;i++){
        if(strcmp(n,items[i].name)==0){
            printf("Item already exists in the inventory.\n");
            return;
        }
    }
    strcpy(items[3].name,n);
    printf("Enter the quantity of the item to add: ");
    scanf("%d",&items[3].quantity);
    printf("Enter the price of the item to add: ");
    scanf("%f",&items[3].price);
    printf("Item added to inventory successfully.\n");
}

void delete_item(struct Inventory items[]){
    int i;
    char n[20];
    printf("Enter the name of the item to delete: ");
    scanf("%s",n);
    for(i=0;i<3;i++){
        if(strcmp(n,items[i].name)==0){
            strcpy(items[i].name,items[3].name);
            items[i].quantity = items[3].quantity;
            items[i].price = items[3].price;
            printf("Item deleted from inventory successfully.\n");
            return;
        }
    }
    printf("Item does not exist in the inventory.\n");
}

void update_item(struct Inventory items[]){
    int i;
    char n[20];
    printf("Enter the name of the item to update: ");
    scanf("%s",n);
    for(i=0;i<3;i++){
        if(strcmp(n,items[i].name)==0){
            printf("Enter the new quantity of the item: ");
            scanf("%d",&items[i].quantity);
            printf("Enter the new price of the item: ");
            scanf("%f",&items[i].price);
            printf("Item updated successfully.\n");
            return;
        }
    }
    printf("Item does not exist in the inventory.\n");
}

int main(){
    struct Inventory items[4]={
        {"Item1", 10, 100.50},
        {"Item2", 5, 75.25},
        {"Item3", 20, 50.75},
    };
    int choice=0;
    do{
        printf("\n1. Display Inventory\n");
        printf("2. Add Item\n");
        printf("3. Delete Item\n");
        printf("4. Update Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                display_inventory(items);
                break;
            case 2:
                add_item(items);
                break;
            case 3:
                delete_item(items);
                break;
            case 4:
                update_item(items);
                break;
            case 5:
                printf("Program terminated.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }while(1);
    return 0;
}