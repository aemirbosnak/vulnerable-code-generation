//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    float price;
    int quantity;
};

int main() {
    int choice;
    struct item items[MAX_ITEMS];
    int num_items = 0;

    do {
        printf("1. Add item\n");
        printf("2. View items\n");
        printf("3. Update item\n");
        printf("4. Delete item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_items >= MAX_ITEMS) {
                    printf("Maximum number of items reached.\n");
                } else {
                    printf("Enter item name: ");
                    scanf("%s", items[num_items].name);
                    printf("Enter item price: ");
                    scanf("%f", &items[num_items].price);
                    printf("Enter item quantity: ");
                    scanf("%d", &items[num_items].quantity);
                    num_items++;
                }
                break;
            case 2:
                printf("Items:\n");
                for(int i=0; i<num_items; i++) {
                    printf("%s - %.2f - %d\n", items[i].name, items[i].price, items[i].quantity);
                }
                break;
            case 3:
                printf("Enter item number to update: ");
                scanf("%d", &choice);
                if(choice >= 0 && choice < num_items) {
                    printf("Enter new item name: ");
                    scanf("%s", items[choice].name);
                    printf("Enter new item price: ");
                    scanf("%f", &items[choice].price);
                    printf("Enter new item quantity: ");
                    scanf("%d", &items[choice].quantity);
                } else {
                    printf("Invalid item number.\n");
                }
                break;
            case 4:
                printf("Enter item number to delete: ");
                scanf("%d", &choice);
                if(choice >= 0 && choice < num_items) {
                    num_items--;
                    for(int i=choice; i<num_items; i++) {
                        items[i] = items[i+1];
                    }
                } else {
                    printf("Invalid item number.\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 5);

    return 0;
}