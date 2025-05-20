//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <string.h>

struct Item {
    char name[100];
    int quantity;
    float price;
};

void addItems(struct Item items[], int* count) {
    printf("\nAdding Items:\n");
    printf("------------------------\n");
    printf("Enter Name: ");
    scanf("%s", items[*count].name);
    printf("Enter Quantity: ");
    scanf("%d", &items[*count].quantity);
    printf("Enter Price: ");
    scanf("%f", &items[*count].price);
    (*count)++;
}

void displayItems(struct Item items[], int count) {
    printf("\nDisplaying Items:\n");
    printf("------------------------\n");
    for(int i=0; i<count; i++) {
        printf("Name: %s\tQuantity: %d\tPrice: %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void searchItems(struct Item items[], int count) {
    char search[100];
    printf("\nEnter Name of Item to Search: ");
    scanf("%s", search);
    for(int i=0; i<count; i++) {
        if(strcmp(search, items[i].name) == 0) {
            printf("\nItem Found:\n");
            printf("------------------------\n");
            printf("Name: %s\tQuantity: %d\tPrice: %.2f\n", items[i].name, items[i].quantity, items[i].price);
            return;
        }
    }
    printf("\nItem Not Found!\n");
}

void updateItems(struct Item items[], int count) {
    char update[100];
    printf("\nEnter Name of Item to Update: ");
    scanf("%s", update);
    for(int i=0; i<count; i++) {
        if(strcmp(update, items[i].name) == 0) {
            printf("\nItem Found:\n");
            printf("------------------------\n");
            printf("Name: %s\tQuantity: %d\tPrice: %.2f\n", items[i].name, items[i].quantity, items[i].price);
            printf("\nEnter New Details:\n");
            printf("Enter Name: ");
            scanf("%s", items[i].name);
            printf("Enter Quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Enter Price: ");
            scanf("%f", &items[i].price);
            printf("\nItem Updated Successfully!\n");
            return;
        }
    }
    printf("\nItem Not Found!\n");
}

int main() {
    struct Item items[100];
    int count = 0;
    int choice;

    printf("Welcome to the Warehouse Management System!\n");

    do {
        printf("\nMenu:\n");
        printf("------------------------\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addItems(items, &count); break;
            case 2: displayItems(items, count); break;
            case 3: searchItems(items, count); break;
            case 4: updateItems(items, count); break;
            case 5: printf("\nThank You for Using the Warehouse Management System!\n"); break;
            default: printf("\nInvalid Choice!\n"); break;
        }
    } while(choice!=5);

    return 0;
}