//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1000

int count = 0; // counter of items in the database

//Warehouse item structure
struct item{
    int id;
    char name[20];
    int quantity;
    float price;
};

//Warehouse Database that stores the items
struct database {
    struct item data[MAX_SIZE];
};

//Function to add a new item to the warehouse
void add_item(struct database *db){
    if(count >= MAX_SIZE){
        printf("Warehouse full! No more items can be added\n");
        return;
    }
    printf("\nEnter item details: \n");
    printf("\nItem Id: ");
    scanf("%d", &db->data[count].id);
    printf("\nItem name: ");
    scanf("%s", db->data[count].name);
    printf("\nItem quantity: ");
    scanf("%d", &db->data[count].quantity);
    printf("\nItem price: ");
    scanf("%f", &db->data[count].price);
    printf("\nItem added successfully!\n");
    count++;
}

//Function to display all the items in the database
void display_items(struct database *db, int i){
    if(i==count) { 
        printf("\nEnd of Database!\n");
        return;
    }
    printf("\nItem Id: %d\n",db->data[i].id);
    printf("Item Name: %s\n", db->data[i].name);
    printf("Item quantity: %d\n", db->data[i].quantity);
    printf("Item price: %.2f\n", db->data[i].price);
    i++;
    display_items(db, i); 
}

//Function to search and display the item details by its name
void search_item(struct database *db, char name[], int i){
    if(i == count){
        printf("Item not found!\n");
        return;
    }
    if(strcmp(name, db->data[i].name) == 0){
        printf("\nItem Id: %d\n",db->data[i].id);
        printf("Item Name: %s\n", db->data[i].name);
        printf("Item quantity: %d\n", db->data[i].quantity);
        printf("Item price: %.2f\n", db->data[i].price);
        return;
    }
    i++;
    search_item(db, name, i);
}

int main(){
    int choice;
    char name[20];
    struct database db;
    do{
        printf("\n------Warehouse Management System------");
        printf("\n1. Add an item to the warehouse");
        printf("\n2. Display all items in the warehouse");
        printf("\n3. Search for an item");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_item(&db);
                break;
            case 2:
                if(count == 0){
                    printf("No items found!\n");
                    break;
                }
                printf("\n------Items in the warehouse------\n");
                display_items(&db, 0);
                break;
            case 3:
                printf("\nEnter the item name to be searched: ");
                scanf("%s", name);
                search_item(&db, name, 0);
                break;
            case 4:
                printf("\nExiting Program...\n");
                exit(0);
            default:
                printf("\nPlease enter valid choice\n");
        }
    }while(choice != 4);
    return 0;
}