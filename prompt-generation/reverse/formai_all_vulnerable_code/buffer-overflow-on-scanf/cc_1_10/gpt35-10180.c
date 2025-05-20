//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>

struct Product {
    int pid, qoh, reorder_level;
    float price;
};
// Product Structure to hold product details

struct Node {
    struct Product value;
    struct Node *next;
};
// Linked List Node Structure

struct Node *head = NULL;
// Linked List head

void add_product() {
    struct Product p;
    printf("\nEnter product ID: ");
    scanf("%d",&p.pid);
    printf("\nEnter product quantity on hand: ");
    scanf("%d",&p.qoh);
    printf("\nEnter product price: ");
    scanf("%f",&p.price);
    printf("\nEnter product reorder level: ");
    scanf("%d",&p.reorder_level);

    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->value = p;
    new_node->next = NULL;

    if(head == NULL)
        head = new_node;
    else {
        struct Node *current = head;
        while(current->next != NULL)
            current = current->next;
        current->next = new_node;
    }
    printf("\nProduct Added!");
}

void display_all() {
    struct Node *current = head;
    printf("\n-------------------------------------------------------------------------\n");
    printf("\nPRODUCT ID\tQUANTITY\tPRICE\t\tREORDER LEVEL\n");
    printf("\n-------------------------------------------------------------------------\n");
    while(current != NULL) {
        printf("%d\t\t%d\t\t%.2f\t\t%d\n",current->value.pid,current->value.qoh,current->value.price,current->value.reorder_level);
        current = current->next;
    }
}

void check_reorder() {
    struct Node *current = head;
    printf("\nProducts that need to be reordered:\n");
    while(current != NULL) {
        if(current->value.qoh < current->value.reorder_level)
            printf("%d\t",current->value.pid);
        current = current->next;
    }
}

void update_quantity() {
    int pid,new_qty;
    printf("\nEnter Product ID: ");
    scanf("%d",&pid);
    printf("\nEnter new Quantity on Hand: ");
    scanf("%d",&new_qty);
    struct Node *current = head;
    while(current != NULL) {
        if(current->value.pid == pid)
            current->value.qoh = new_qty;
        current = current->next;
    }
    printf("\nQuantity Updated Successfully!");
}

void menu() {
    printf("\n\n\n------------------------Warehouse Management System------------------------\n");
    printf("\n1. Add Product");
    printf("\n2. Display All Products");
    printf("\n3. Check Reorder Level");
    printf("\n4. Update Quantity");
    printf("\n5. Exit");
    printf("\n\n--------------------------------------------------------------------------------");
    printf("\nPlease select your option (1-5): ");
}

int main() {
    int choice;
    do {
        menu(); // Menu display
        scanf("%d",&choice);
        switch(choice) {
            case 1: add_product(); break;
            case 2: display_all(); break;
            case 3: check_reorder(); break;
            case 4: update_quantity(); break;
            case 5: exit(0);
            default: printf("\nInvalid Option!");
        }
    }while(choice!=5);
    return 0;
}