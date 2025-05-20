//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 20
#define MAX_SUPPLIER_NAME 20
#define MAX_LOC_LENGTH 10

typedef struct{
    char name[MAX_NAME_LENGTH];
    char supplier[MAX_SUPPLIER_NAME];
    float price;
    int quantity;
    char location[MAX_LOC_LENGTH];
}Item;

void addNewItem(Item *p, int *n);
void displayAllItems(Item *p, int n);
void displayByLocation(Item *p, int n, char *location);
void updateItem(Item *p, int n, char *name, int newQuantity);
void removeItem(Item *p, int *n, char *name);

int main(){
    Item items[MAX_ITEMS];
    int numItems = 0;
    int choice;
    char loc[MAX_LOC_LENGTH];
    char name[MAX_NAME_LENGTH];
    int newQuantity;
    
    do{
        printf("\n---Warehouse Management System Menu---\n");
        printf("1. Add a new item\n");
        printf("2. Display all items\n");
        printf("3. Display items by location\n");
        printf("4. Update item quantity\n");
        printf("5. Remove an item\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                addNewItem(items, &numItems);
                break;
            case 2:
                displayAllItems(items, numItems);
                break;
            case 3:
                printf("Enter location: ");
                scanf("%s", loc);
                displayByLocation(items, numItems, loc);
                break;
            case 4:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter new quantity: ");
                scanf("%d", &newQuantity);
                updateItem(items, numItems, name, newQuantity);
                break;
            case 5:
                printf("Enter item name: ");
                scanf("%s", name);
                removeItem(items, &numItems, name);
                break;
            case 6:
                printf("Quitting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice != 6);
    
    return 0;
}

void addNewItem(Item *p, int *n){
    if(*n == MAX_ITEMS){
        printf("Warehouse is full. Cannot add more items.\n");
        return;
    }
    
    printf("Enter item name: ");
    scanf("%s", p[*n].name);
    printf("Enter supplier: ");
    scanf("%s", p[*n].supplier);
    printf("Enter price: ");
    scanf("%f", &p[*n].price);
    printf("Enter quantity: ");
    scanf("%d", &p[*n].quantity);
    printf("Enter location: ");
    scanf("%s", p[*n].location);
    
    (*n)++;
    
    printf("Item added successfully.\n");
}

void displayAllItems(Item *p, int n){
    if(n == 0){
        printf("No items in warehouse.\n");
        return;
    }
    
    printf("%-20s%-20s%-10s%-10s%-10s\n", "Name", "Supplier", "Price", "Quantity", "Location");
    
    for(int i=0; i<n; i++){
        printf("%-20s%-20s%-10.2f%-10d%-10s\n", p[i].name, p[i].supplier, p[i].price, p[i].quantity, p[i].location);
    }
}

void displayByLocation(Item *p, int n, char *location){
    if(n == 0){
        printf("No items in warehouse.\n");
        return;
    }
    
    printf("%-20s%-20s%-10s%-10s%-10s\n", "Name", "Supplier", "Price", "Quantity", "Location");
    
    for(int i=0; i<n; i++){
        if(strcmp(p[i].location, location) == 0){
            printf("%-20s%-20s%-10.2f%-10d%-10s\n", p[i].name, p[i].supplier, p[i].price, p[i].quantity, p[i].location);
        }
    }
}

void updateItem(Item *p, int n, char *name, int newQuantity){
    for(int i=0; i<n; i++){
        if(strcmp(p[i].name, name) == 0){
            p[i].quantity = newQuantity;
            printf("Item quantity updated successfully.\n");
            return;
        }
    }
    
    printf("Item not found. Please try again.\n");
}

void removeItem(Item *p, int *n, char *name){
    for(int i=0; i<*n; i++){
        if(strcmp(p[i].name, name) == 0){
            (*n)--;
            for(int j=i; j<*n; j++){
                p[j] = p[j+1];
            }
            
            printf("Item removed successfully.\n");
            return;
        }
    }
    
    printf("Item not found. Please try again.\n");
}