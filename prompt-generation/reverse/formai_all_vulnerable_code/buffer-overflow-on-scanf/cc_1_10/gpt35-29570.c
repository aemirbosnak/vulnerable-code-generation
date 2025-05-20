//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// DATA STRUCTURE OF ITEM
typedef struct item {
    int item_id;
    char item_name[50];
    float item_price;
    int item_quantity;
    struct item* next;
} ITEM;

// FUNCTION TO DISPLAY MENU
void display_menu() {
    printf("\n------MENU-------\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Update Item\n");
    printf("4. Display All Items\n");
    printf("5. Exit\n");
    printf("------------------\n");
}

// FUNCTION TO ADD ITEM TO THE WAREHOUSE
void add_item(ITEM** head_ref) {
    ITEM* new_item = (ITEM*)malloc(sizeof(ITEM));
    printf("Enter Item ID:");
    scanf("%d", &(new_item->item_id));
    printf("Enter Item Name:");
    scanf("%s", new_item->item_name);
    printf("Enter Item Price:");
    scanf("%f", &(new_item->item_price));
    printf("Enter Item Quantity:");
    scanf("%d", &(new_item->item_quantity));
    new_item->next = *head_ref;
    *head_ref = new_item;
    printf("Item Added Successfully!\n");
}

// FUNCTION TO REMOVE ITEM FROM THE WAREHOUSE
void remove_item(ITEM** head_ref, int item_id) {
    ITEM* temp = *head_ref;
    ITEM* prev = NULL;
    while (temp != NULL && temp->item_id != item_id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Item Not Found!\n");
        return;
    }
    if (prev != NULL) prev->next = temp->next;
    else *head_ref = temp->next;
    free(temp);
    printf("Item Removed Successfully!\n");
}

// FUNCTION TO DISPLAY ALL ITEMS IN THE WAREHOUSE
void display_items(ITEM* head) {
    if (head == NULL) printf("No Items Found!\n");
    else {
        printf("Item ID\tItem Name\tItem Price\tItem Quantity\n");
        while (head != NULL) {
            printf("%d\t%s\t%.2f\t\t%d\n", head->item_id, head->item_name, head->item_price, head->item_quantity);
            head = head->next;
        }
    }
}

// FUNCTION TO UPDATE ITEM DETAILS
void update_item(ITEM* head, int item_id) {
    ITEM* temp = head;
    while (temp != NULL && temp->item_id != item_id) temp = temp->next;
    if (temp == NULL) {
        printf("Item Not Found!\n");
        return;
    }
    printf("Enter Item Name:");
    scanf("%s", temp->item_name);
    printf("Enter Item Price:");
    scanf("%f", &(temp->item_price));
    printf("Enter Item Quantity:");
    scanf("%d", &(temp->item_quantity));
    printf("Item Updated Successfully!\n");
}

// DRIVER FUNCTION
int main() {
    ITEM* head = NULL;
    int choice, item_id;
    while (1) {
        display_menu();
        printf("Enter Your Choice:");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_item(&head);
            break;
        case 2:
            printf("Enter Item ID To Remove:");
            scanf("%d", &item_id);
            remove_item(&head, item_id);
            break;
        case 3:
            printf("Enter Item ID To Update:");
            scanf("%d", &item_id);
            update_item(head, item_id);
            break;
        case 4:
            display_items(head);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}