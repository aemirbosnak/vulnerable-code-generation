//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 99

struct product {
    char name[MAX_NAME_LEN];
    int quantity;
};

typedef struct product Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, int quantity) {
    if (num_products < MAX_PRODUCTS) {
        strcpy(inventory[num_products].name, name);
        inventory[num_products].quantity = quantity;
        num_products++;
    } else {
        printf("Inventory is full.\n");
    }
}

void display_inventory() {
    int i;
    printf("\nProduct Inventory:\n");
    for (i = 0; i < num_products; i++) {
        printf("%d. %s - %d\n", i+1, inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    char name[MAX_NAME_LEN];
    int quantity, choice, index;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                add_product(name, quantity);
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}