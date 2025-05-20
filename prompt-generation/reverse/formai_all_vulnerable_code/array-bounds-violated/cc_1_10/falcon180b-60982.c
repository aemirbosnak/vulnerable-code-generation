//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME 100
#define MAX_QUANTITY 100

struct item {
    char name[MAX_NAME];
    int quantity;
};

int main() {
    struct item inventory[MAX_ITEMS];
    int count = 0;
    char choice;
    int i;

    do {
        printf("\nProduct Inventory System\n");
        printf("------------------------\n");
        printf("1. Add item\n");
        printf("2. Update item\n");
        printf("3. Delete item\n");
        printf("4. View inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
        case '1':
            printf("Enter item name: ");
            scanf("%s", inventory[count].name);
            printf("Enter item quantity: ");
            scanf("%d", &inventory[count++].quantity);
            break;
        case '2':
            printf("Enter item index to update: ");
            scanf("%d", &i);
            printf("Enter new item name: ");
            scanf("%s", inventory[i].name);
            printf("Enter new item quantity: ");
            scanf("%d", &inventory[i].quantity);
            break;
        case '3':
            printf("Enter item index to delete: ");
            scanf("%d", &i);
            for(int j=i; j<count; j++) {
                strcpy(inventory[j].name, inventory[j+1].name);
                inventory[j].quantity = inventory[j+1].quantity;
            }
            count--;
            break;
        case '4':
            printf("Inventory:\n");
            for(int j=0; j<count; j++) {
                printf("%s - %d\n", inventory[j].name, inventory[j].quantity);
            }
            break;
        case '5':
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while(choice!= '5');

    return 0;
}