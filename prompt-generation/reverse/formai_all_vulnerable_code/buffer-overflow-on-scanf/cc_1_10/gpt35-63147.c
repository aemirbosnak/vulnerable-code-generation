//FormAI DATASET v1.0 Category: Product Inventory System ; Style: active
#include<stdio.h>
#include<string.h>

//define structure for product
struct product {
    int id;
    char name[20];
    float price;
    int quantity;
};

//function to add product to inventory
void add_product(struct product *p) {
    printf("Enter product id: ");
    scanf("%d", &p->id);
    printf("Enter product name: ");
    scanf("%s", p->name);
    printf("Enter product price: $");
    scanf("%f", &p->price);
    printf("Enter product quantity: ");
    scanf("%d", &p->quantity);
}

//function to display inventory
void display_inventory(struct product *inventory, int size) {
    printf("Product ID\tProduct Name\tPrice\t\tQuantity\n");
    for(int i=0; i < size; i++) {
        printf("%d\t\t%s\t\t$%.2f\t\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

int main() {
    //create inventory array with maximum of 50 products
    struct product inventory[50];
    int inventory_size = 0;

    //menu for interacting with product inventory system
    char choice;
    do {
        printf("\nProduct Inventory System Menu:\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Exit\n");
        printf("Enter Your Choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                if(inventory_size < 50) {
                    printf("\nAdd Product:\n");
                    add_product(&inventory[inventory_size]);
                    inventory_size++;
                } else {
                    printf("\nInventory is full. Cannot add more products!\n");
                }
                break;
            case '2':
                printf("\nDisplaying Inventory:\n");
                display_inventory(inventory, inventory_size);
                break;
            case '3':
                printf("\nExiting Product Inventory System. Goodbye!\n");
                break;
            default:
                printf("\nInvalid Choice. Please try again.\n");
        }
    } while(choice != '3');

    return 0;
}