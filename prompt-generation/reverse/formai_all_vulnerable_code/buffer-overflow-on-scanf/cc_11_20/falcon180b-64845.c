//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

struct medicine {
    char name[100];
    char manufacturer[100];
    int quantity;
    float price;
};

int main() {
    int choice;
    struct medicine* inventory = NULL;
    int inventory_size = 0;

    do {
        printf("1. Add medicine\n");
        printf("2. Display inventory\n");
        printf("3. Search for medicine\n");
        printf("4. Purchase medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter medicine name: ");
                scanf("%s", inventory[inventory_size].name);
                printf("Enter manufacturer name: ");
                scanf("%s", inventory[inventory_size].manufacturer);
                printf("Enter quantity: ");
                scanf("%d", &inventory[inventory_size].quantity);
                printf("Enter price: ");
                scanf("%f", &inventory[inventory_size].price);
                inventory_size++;
                break;
            case 2:
                printf("Inventory:\n");
                for(int i=0; i<inventory_size; i++) {
                    printf("%s - %s - %d - %.2f\n", inventory[i].name, inventory[i].manufacturer, inventory[i].quantity, inventory[i].price);
                }
                break;
            case 3:
                printf("Enter medicine name to search: ");
                char search_name[100];
                scanf("%s", search_name);
                for(int i=0; i<inventory_size; i++) {
                    if(strcmp(inventory[i].name, search_name) == 0) {
                        printf("%s - %s - %d - %.2f\n", inventory[i].name, inventory[i].manufacturer, inventory[i].quantity, inventory[i].price);
                    }
                }
                break;
            case 4:
                printf("Enter medicine name to purchase: ");
                char purchase_name[100];
                scanf("%s", purchase_name);
                for(int i=0; i<inventory_size; i++) {
                    if(strcmp(inventory[i].name, purchase_name) == 0) {
                        inventory[i].quantity--;
                        printf("%s purchased successfully.\n", purchase_name);
                        break;
                    }
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