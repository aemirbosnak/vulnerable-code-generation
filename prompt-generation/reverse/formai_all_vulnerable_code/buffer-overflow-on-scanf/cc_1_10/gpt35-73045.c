//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEMS 100

typedef struct{
    char name[50];
    int quantity;
    float price;
}item;

int current_items = 0;

item items[MAX_ITEMS];

void add_item(){
    if(current_items >= MAX_ITEMS){
        printf("Error: Maximum items reached\n");
        return;
    }

    item i;

    printf("Enter name of item: ");
    scanf("%s", i.name);

    printf("Enter quantity of item: ");
    scanf("%d", &i.quantity);

    printf("Enter price of item: ");
    scanf("%f", &i.price);

    items[current_items++] = i;

    printf("Item added successfully\n");
}

void delete_item(){
    char name[50];

    printf("Enter name of item to delete: ");
    scanf("%s", name);

    int found = 0;

    for(int i=0;i<current_items;i++){
        if(strcmp(items[i].name, name)==0){
            found = 1;
            for(int j=i;j<current_items-1;j++){
                items[j] = items[j+1];
            }
            current_items--;
            printf("Item deleted successfully\n");
            break;
        }
    }

    if(!found){
        printf("Error: Item not found\n");
    }
}

void display_items(){
    if(current_items==0){
        printf("No items found\n");
        return;
    }

    printf("Name\tQuantity\tPrice\n");

    for(int i=0;i<current_items;i++){
        printf("%s\t%d\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void update_item(){
    char name[50];

    printf("Enter name of item to update: ");
    scanf("%s", name);

    int found = 0;

    for(int i=0;i<current_items;i++){
        if(strcmp(items[i].name, name)==0){
            found = 1;

            printf("Enter new quantity of item: ");
            scanf("%d", &items[i].quantity);

            printf("Enter new price of item: ");
            scanf("%f", &items[i].price);

            printf("Item updated successfully\n");
            break;
        }
    }

    if(!found){
        printf("Error: Item not found\n");
    }
}

int main(){

    int ch;

    do{
        printf("1. Add item\n");
        printf("2. Delete item\n");
        printf("3. Display items\n");
        printf("4. Update item\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                add_item();
                break;
            case 2:
                delete_item();
                break;
            case 3:
                display_items();
                break;
            case 4:
                update_item();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    }while(ch!=5);

    return 0;
}