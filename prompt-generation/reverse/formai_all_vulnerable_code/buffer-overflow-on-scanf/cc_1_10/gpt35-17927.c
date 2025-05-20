//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50

struct item{
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
};

struct warehouse{
    struct item inventory[MAX_ITEMS];
    int num_items;
};

void add_item(struct warehouse* w, int id, char* name, int quantity){
    if(w->num_items == MAX_ITEMS){
        printf("Warehouse is full, cannot add more items\n");
        return;
    }
    struct item new_item;
    new_item.id = id;
    strncpy(new_item.name, name, MAX_NAME_LENGTH);
    new_item.quantity = quantity;
    w->inventory[w->num_items++] = new_item;
    printf("Item added to warehouse\n");
}

void display_inventory(struct warehouse* w){
    printf("Items in warehouse:\n");
    for(int i=0;i<w->num_items;i++){
        printf("%d %s %d\n", w->inventory[i].id, w->inventory[i].name, w->inventory[i].quantity);
    }
}

void remove_item(struct warehouse* w, int id){
    int found = 0;
    for(int i=0;i<w->num_items;i++){
        if(w->inventory[i].id == id){
            found = 1;
            for(int j=i+1;j<w->num_items;j++){
                w->inventory[j-1] = w->inventory[j];
            }
            w->num_items--;
            printf("Item removed from warehouse\n");
            break;
        }
    }
    if(!found){
        printf("Item with id %d not found in warehouse\n", id);
    }
}

void update_quantity(struct warehouse* w, int id, int quantity){
    int found = 0;
    for(int i=0;i<w->num_items;i++){
        if(w->inventory[i].id == id){
            found = 1;
            w->inventory[i].quantity = quantity;
            printf("Quantity updated in warehouse\n");
            break;
        }
    }
    if(!found){
        printf("Item with id %d not found in warehouse\n", id);
    }
}

int main(){
    struct warehouse w;
    w.num_items = 0;
    int choice = 0;
    while(choice != 5){
        printf("\nEnter choice:\n1. Add item\n2. Display inventory\n3. Remove item\n4. Update quantity\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                int id, quantity;
                char name[MAX_NAME_LENGTH];
                printf("Enter id, name and quantity of item to be added:\n");
                scanf("%d %s %d", &id, name, &quantity);
                add_item(&w, id, name, quantity);
                break;
            }
            case 2:{
                display_inventory(&w);
                break;
            }
            case 3:{
                int id;
                printf("Enter id of item to be removed:\n");
                scanf("%d", &id);
                remove_item(&w, id);
                break;
            }
            case 4:{
                int id, quantity;
                printf("Enter id and new quantity of item to be updated:\n");
                scanf("%d %d", &id, &quantity);
                update_quantity(&w, id, quantity);
                break;
            }
            case 5:{
                printf("Exiting...\n");
                break;
            }
            default:{
                printf("Invalid choice, please try again\n");
                break;
            }
        }
    }
    return 0;
}