//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include<stdio.h>
#include<string.h>

struct inventory{
    int id;
    char name[20];
    int quantity;
    struct inventory *next;
};

void insert_item(struct inventory **head, int id, char name[], int quantity){
    struct inventory *newItem = (struct inventory*) malloc(sizeof(struct inventory));
    newItem->id = id;
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->next = *head;
    *head = newItem;
    printf("\nID %d was added successfully!\n", id);
}

void display_items(struct inventory *head){
    if(head){
        printf("\nID: %d \nName: %s \nQuantity: %d \n", head->id, head->name, head->quantity);
        return display_items(head->next);
    }
}

void search_item(struct inventory *head, int id){
    if(head){
        if(head->id == id){
            printf("\nItem found!\n");
            printf("ID: %d \nName: %s \nQuantity: %d \n", head->id, head->name, head->quantity);
            return;
        }
        return search_item(head->next, id);
    }
    printf("\nItem not found!\n");
}

void remove_item(struct inventory **head, int id){
    if((*head)->id == id){
        *head = (*head)->next;
        printf("\nID %d was removed successfully!\n", id);
        return;
    } else if((*head)->next->id == id){
        (*head)->next = (*head)->next->next;
        printf("\nID %d was removed successfully!\n", id);
        return;
    }
    return remove_item(&(*head)->next, id);
}

int main(){
    printf("Welcome to the Warehouse Management System!\n");
    struct inventory *head = NULL;
    int choice, id, quantity;
    char name[20];
    while(1){
        printf("\nMenu:\n 1. Insert item\n 2. Display all items\n 3. Search for an item\n 4. Remove an Item\n 5. Exit\n\n Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter item details: \n");
                printf("ID: ");
                scanf("%d", &id);
                printf("Name: ");
                scanf("%s", name);
                printf("Quantity: ");
                scanf("%d", &quantity);
                insert_item(&head, id, name, quantity);
                break;
            case 2:
                printf("\nAll Items:\n");
                display_items(head);
                break;
            case 3:
                printf("\nEnter the ID of the item you want to search: ");
                scanf("%d", &id);
                search_item(head, id);
                break;
            case 4:
                printf("\nEnter the ID of the item you want to remove: ");
                scanf("%d", &id);
                remove_item(&head, id);
                break;
            case 5:
                printf("\nThank you for using Warehouse Management System!");
                exit(0);
            default:
                printf("\nInvalid Choice! Try again.\n");
        }
    }
    return 0;
}