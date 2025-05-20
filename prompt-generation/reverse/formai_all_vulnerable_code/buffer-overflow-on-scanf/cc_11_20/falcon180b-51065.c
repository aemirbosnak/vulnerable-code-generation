//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_QUANTITY 100
#define MAX_PRICE 1000000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Item;

int main() {
    Item items[MAX_ITEMS];
    int num_items = 0;
    char choice;
    do {
        printf("Medical Store Management System\n");
        printf("1. Add item\n");
        printf("2. View items\n");
        printf("3. Update item\n");
        printf("4. Delete item\n");
        printf("5. Exit\n");
        scanf("%c", &choice);
        switch(choice) {
            case '1':
                if(num_items >= MAX_ITEMS) {
                    printf("Cannot add more items. Maximum limit reached.\n");
                } else {
                    printf("Enter item name: ");
                    scanf("%s", items[num_items].name);
                    printf("Enter item description: ");
                    scanf("%s", items[num_items].description);
                    printf("Enter item quantity: ");
                    scanf("%d", &items[num_items].quantity);
                    printf("Enter item price: ");
                    scanf("%f", &items[num_items].price);
                    num_items++;
                }
                break;
            case '2':
                for(int i = 0; i < num_items; i++) {
                    printf("Item %d:\n", i+1);
                    printf("Name: %s\n", items[i].name);
                    printf("Description: %s\n", items[i].description);
                    printf("Quantity: %d\n", items[i].quantity);
                    printf("Price: %.2f\n\n", items[i].price);
                }
                break;
            case '3':
                printf("Enter item number to update: ");
                int item_num;
                scanf("%d", &item_num);
                if(item_num >= 0 && item_num < num_items) {
                    printf("Enter new item name: ");
                    scanf("%s", items[item_num].name);
                    printf("Enter new item description: ");
                    scanf("%s", items[item_num].description);
                    printf("Enter new item quantity: ");
                    scanf("%d", &items[item_num].quantity);
                    printf("Enter new item price: ");
                    scanf("%f", &items[item_num].price);
                } else {
                    printf("Invalid item number.\n");
                }
                break;
            case '4':
                printf("Enter item number to delete: ");
                int del_num;
                scanf("%d", &del_num);
                if(del_num >= 0 && del_num < num_items) {
                    for(int i = del_num; i < num_items-1; i++) {
                        items[i] = items[i+1];
                    }
                    num_items--;
                } else {
                    printf("Invalid item number.\n");
                }
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '5');
    return 0;
}