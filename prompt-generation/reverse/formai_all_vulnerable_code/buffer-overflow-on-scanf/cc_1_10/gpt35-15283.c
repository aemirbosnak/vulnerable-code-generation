//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct item {
    char name[ITEM_NAME_LENGTH];
    int quantity;
} Item;

Item warehouse[MAX_ITEMS];
int num_items = 0;

void add_item(char *name, int quantity) {
    if(num_items == MAX_ITEMS) {
        printf("Warehouse is full, cannot add more items.\n");
        return;
    }
    
    strcpy(warehouse[num_items].name, name);
    warehouse[num_items].quantity = quantity;
    num_items++;
    
    printf("Item successfully added.\n");
}

void remove_item(char *name, int quantity) {
    for(int i=0; i<num_items; i++) {
        if(strcmp(warehouse[i].name, name) == 0) {
            if(warehouse[i].quantity >= quantity) {
                warehouse[i].quantity -= quantity;
                printf("%d %s successfully removed from warehouse.\n", quantity, name);
                return;
            } else {
                printf("Not enough %s in warehouse to remove.\n", name);
                return;
            }
        }
    }
    
    printf("%s not found in warehouse.\n", name);
}

void list_items() {
    printf("Warehouse inventory:\n");
    for(int i=0; i<num_items; i++) {
        printf("%s - %d\n", warehouse[i].name, warehouse[i].quantity);
    }
}

int main() {
    printf("Welcome to the warehouse management system.\n");
    
    while(1) {
        printf("Enter a command (add/remove/list/exit): ");
        char command[10];
        scanf("%s", command);
        
        if(strcmp(command, "add") == 0) {
            char name[ITEM_NAME_LENGTH];
            int quantity;
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item quantity: ");
            scanf("%d", &quantity);
            add_item(name, quantity);
        } else if(strcmp(command, "remove") == 0) {
            char name[ITEM_NAME_LENGTH];
            int quantity;
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item quantity: ");
            scanf("%d", &quantity);
            remove_item(name, quantity);
        } else if(strcmp(command, "list") == 0) {
            list_items();
        } else if(strcmp(command, "exit") == 0) {
            printf("Thank you for using the warehouse management system.\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
    
    return 0;
}