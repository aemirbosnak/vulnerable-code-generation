//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

struct item{
    int id;
    char name[20];
    int quantity;
    float price;
};

void add_item(struct item inventory[], int *count);
void remove_item(struct item inventory[], int *count);
void display_inventory(struct item inventory[], int count);
void search_item(struct item inventory[], int count);

int main(){

    struct item inventory[100];
    int count = 0;
    int choice;

    do{
        printf("\nWelcome to Inventory Management System\n");
        printf("1.Add Item\n");
        printf("2.Remove Item\n");
        printf("3.Display Inventory\n");
        printf("4.Search Item\n");
        printf("5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_item(inventory, &count);
                break;
            case 2:
                remove_item(inventory, &count);
                break;
            case 3:
                display_inventory(inventory, count);
                break;
            case 4:
                search_item(inventory, count);
                break;
            case 5:
                printf("\nThank you for using Inventory Management System.\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select a valid option.\n");
        }
    }while(1);

    return 0;
}

void add_item(struct item inventory[], int *count){
    printf("\nEnter the following details for the item:\n");
    printf("Item ID: ");
    scanf("%d", &inventory[*count].id);
    printf("Name: ");
    scanf("%s", inventory[*count].name);
    printf("Quantity: ");
    scanf("%d", &inventory[*count].quantity);
    printf("Price: ");
    scanf("%f", &inventory[*count].price);
    (*count)++;
    printf("\nItem added successfully!\n");
}

void remove_item(struct item inventory[], int *count){
    int id, i, found = 0;
    printf("\nEnter the ID of the item to be removed: ");
    scanf("%d", &id);
    for(i = 0; i < *count; i++){
        if(inventory[i].id == id){
            found = 1;
            break;
        }
    }
    if(found){
        for(;i < *count; i++){
            inventory[i] = inventory[i+1];
        }
        (*count)--;
        printf("\nItem removed successfully!\n");
    }
    else{
        printf("\nItem not found in inventory!\n");
    }
}

void display_inventory(struct item inventory[], int count){
    int i;
    if(count == 0){
        printf("\nInventory is empty!\n");
    }
    else{
        printf("\nID\tName\t\tQuantity\tPrice\n");
        printf("-------------------------------------------------------\n");
        for(i = 0; i < count; i++){
            printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

void search_item(struct item inventory[], int count){
    int id, i, found = 0;
    printf("\nEnter the ID of the item to be searched: ");
    scanf("%d", &id);
    for(i = 0; i < count; i++){
        if(inventory[i].id == id){
            found = 1;
            break;
        }
    }
    if(found){
        printf("\nID\tName\t\tQuantity\tPrice\n");
        printf("-------------------------------------------------------\n");
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    else{
        printf("\nItem not found in inventory!\n");
    } 
}