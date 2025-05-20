//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 50
#define ITEMS_FILE "items.txt"

typedef struct {
    char id[MAX_SIZE];
    char name[MAX_SIZE];
    int stock;
} Item;

int total_items = 0;

// Function to add a new item to the inventory
void add_item(Item *inventory) {
    printf("Enter item ID: ");
    scanf("%s", inventory[total_items].id);
    printf("Enter item name: ");
    scanf("%s", inventory[total_items].name);
    printf("Enter item stock: ");
    scanf("%d", &inventory[total_items].stock);
    total_items++;
}

// Function to search for an item in the inventory
void search_item(Item *inventory) {
    char search_id[MAX_SIZE];
    printf("Enter item ID to search: ");
    scanf("%s", search_id);
    int found = 0;
    for(int i=0; i<total_items; i++) {
        if(strcmp(inventory[i].id, search_id) == 0) {
            found = 1;
            printf("Item ID: %s\n", inventory[i].id);
            printf("Item Name: %s\n", inventory[i].name);
            printf("Item Stock: %d\n", inventory[i].stock);
            break;
        }
    }
    if(!found) {
        printf("Item ID not found!\n");
    }
}

// Function to update item stock in the inventory
void update_stock(Item *inventory) {
    char update_id[MAX_SIZE];
    printf("Enter item ID to update: ");
    scanf("%s", update_id);
    int found = 0;
    for(int i=0; i<total_items; i++) {
        if(strcmp(inventory[i].id, update_id) == 0) {
            found = 1;
            printf("Enter new stock for item '%s': ", inventory[i].name);
            scanf("%d", &inventory[i].stock);
            printf("Item stock updated successfully!\n");
            break;
        }
    }
    if(!found) {
        printf("Item ID not found!\n");
    }
}

// Function to display all items in the inventory
void display_all_items(Item *inventory) {
    printf("Item ID\tItem Name\tItem Stock\n");
    for(int i=0; i<total_items; i++) {
        printf("%s\t%s\t%d\n", inventory[i].id, inventory[i].name, inventory[i].stock);
    }
}

// Function to save items to file
void save_items(Item *inventory) {
    FILE *fp;
    fp = fopen(ITEMS_FILE, "w");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for(int i=0; i<total_items; i++) {
        fprintf(fp, "%s %s %d\n", inventory[i].id, inventory[i].name, inventory[i].stock);
    }
    fclose(fp);
    printf("Items saved successfully to file!\n");
}

// Function to load items from file
void load_items(Item *inventory) {
    FILE *fp;
    fp = fopen(ITEMS_FILE, "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    char id[MAX_SIZE], name[MAX_SIZE];
    int stock;
    while(fscanf(fp, "%s %s %d", id, name, &stock) != EOF) {
        strcpy(inventory[total_items].id, id);
        strcpy(inventory[total_items].name, name);
        inventory[total_items].stock = stock;
        total_items++;
    }
    fclose(fp);
    printf("Items loaded successfully from file!\n");
}

int main() {
    Item inventory[MAX_SIZE];
    int choice;
    while(1) {
        printf("\nWarehouse Management System\n");
        printf("---------------------------\n");
        printf("1. Add new item\n");
        printf("2. Search item\n");
        printf("3. Update stock\n");
        printf("4. Display all items\n");
        printf("5. Save items to file\n");
        printf("6. Load items from file\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_item(inventory);
                break;
            case 2:
                search_item(inventory);
                break;
            case 3:
                update_stock(inventory);
                break;
            case 4:
                display_all_items(inventory);
                break;
            case 5:
                save_items(inventory);
                break;
            case 6:
                load_items(inventory);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}