//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: accurate
#include<stdio.h>
#include<string.h>

struct inventory {
    char item_name[50];
    int quantity;
    float price;
};

void add_item(struct inventory item[], int n) {
    printf("\nEnter item name: ");
    scanf("%s", item[n].item_name);
    printf("Enter quantity: ");
    scanf("%d", &item[n].quantity);
    printf("Enter price: ");
    scanf("%f", &item[n].price);
}

void edit_item(struct inventory item[]) {
    char name[50];
    printf("\nEnter item name to edit: ");
    scanf("%s", name);
    for(int i=0; i<10; i++) {
        if(strcmp(item[i].item_name, name)==0) {
            printf("Enter quantity: ");
            scanf("%d", &item[i].quantity);
            printf("Enter price: ");
            scanf("%f", &item[i].price);
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item not found in inventory!\n");
}

void remove_item(struct inventory item[], int n) {
    char name[50];
    printf("\nEnter item name to remove: ");
    scanf("%s", name);
    for(int i=0; i<n; i++) {
        if(strcmp(item[i].item_name, name)==0) {
            for(int j=i; j<n-1; j++) {
                item[j] = item[j+1];
            }
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item not found in inventory!\n");
}

void display_inventory(struct inventory item[], int n) {
    printf("\n--------------- Inventory ---------------\n");
    printf("Item Name\tQuantity\tPrice\n");
    for(int i=0; i<n; i++) {
        printf("%s\t\t%d\t\t%.2f\n", item[i].item_name, item[i].quantity, item[i].price);
    }
    printf("-----------------------------------------\n");
}

int main() {
    struct inventory item[10];
    int choice, n=0;
    do {
        printf("\n***** Warehouse Management System *****\n");
        printf("1. Add item\n");
        printf("2. Edit item\n");
        printf("3. Remove item\n");
        printf("4. Display inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_item(item, n);
                n++;
                break;
            case 2:
                edit_item(item);
                break;
            case 3:
                remove_item(item, n);
                n--;
                break;
            case 4:
                display_inventory(item, n);
                break;
            case 5:
                printf("\nExiting Warehouse Management System...\n");
                break;
            default:
                printf("\nInvalid choice! Try again...\n");
        }
    } while(choice != 5);
    return 0;
}