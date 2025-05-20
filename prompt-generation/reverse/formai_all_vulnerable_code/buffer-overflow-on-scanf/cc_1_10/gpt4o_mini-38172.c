//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int product_count;
} Inventory;

// Function prototypes
void add_product(Inventory *inventory);
void view_inventory(Inventory *inventory);
void sell_product(Inventory *inventory);
void restock_product(Inventory *inventory);
void show_menu();
void clear_buffer();

int main() {
    Inventory inventory = { .product_count = 0 };
    int choice;

    printf("🎉 Welcome to the Wacky Product Inventory System 🎉\n");

    do {
        show_menu();
        printf("Please choose an option: ");
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1:
                add_product(&inventory);
                break;
            case 2:
                view_inventory(&inventory);
                break;
            case 3:
                sell_product(&inventory);
                break;
            case 4:
                restock_product(&inventory);
                break;
            case 5:
                printf("Have a fantastic day! Bye-bye! 👋\n");
                break;
            default:
                printf("Oops! That's not a valid choice. Try again! 🤷‍♂️\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void show_menu() {
    printf("\n--- 🛒 Wacky Menu 🛒 ---\n");
    printf("1. Add Product 🛍️\n");
    printf("2. View Inventory 📦\n");
    printf("3. Sell Product 💸\n");
    printf("4. Restock Product 🛠️\n");
    printf("5. Exit 🚪\n");
}

void add_product(Inventory *inventory) {
    if (inventory->product_count >= MAX_PRODUCTS) {
        printf("Uh-oh! Inventory full! Can't add more products! 🚫\n");
        return;
    }

    Product new_product;
    printf("Enter product name: ");
    fgets(new_product.name, sizeof(new_product.name), stdin);
    new_product.name[strcspn(new_product.name, "\n")] = 0; // remove newline

    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);
    clear_buffer();

    inventory->products[inventory->product_count] = new_product;
    inventory->product_count++;
    printf("🎉 Product '%s' added successfully! 🎉\n", new_product.name);
}

void view_inventory(Inventory *inventory) {
    if (inventory->product_count == 0) {
        printf("Uh-oh! The inventory is empty. Just like my wallet! 😢\n");
        return;
    }

    printf("\n--- Product Inventory ---\n");
    for (int i = 0; i < inventory->product_count; i++) {
        Product *p = &inventory->products[i];
        printf("%d. Name: %s, Quantity: %d, Price: $%.2f\n", i + 1, p->name, p->quantity, p->price);
    }
    printf("-------------------------\n");
}

void sell_product(Inventory *inventory) {
    if (inventory->product_count == 0) {
        printf("Can’t sell products, because there are none! 😱\n");
        return;
    }

    int index;
    printf("Enter the product number you want to sell (1 to %d): ", inventory->product_count);
    scanf("%d", &index);
    clear_buffer();

    if (index < 1 || index > inventory->product_count) {
        printf("⛔ Invalid product number. Try again! ⛔\n");
        return;
    }

    Product *p = &inventory->products[index - 1];
    
    if (p->quantity == 0) {
        printf("❌ Sorry! '%s' is out of stock! 😩\n", p->name);
        return;
    }

    p->quantity--;
    printf("💰 Sold 1 unit of '%s'. Remaining: %d units. 💰\n", p->name, p->quantity);
}

void restock_product(Inventory *inventory) {
    if (inventory->product_count == 0) {
        printf("Whoa there! No products to restock! 🛑\n");
        return;
    }

    int index;
    printf("Enter the product number you want to restock (1 to %d): ", inventory->product_count);
    scanf("%d", &index);
    clear_buffer();

    if (index < 1 || index > inventory->product_count) {
        printf("⛔ Invalid product number. Try again! ⛔\n");
        return;
    }

    Product *p = &inventory->products[index - 1];
    int restock_amount;
    printf("How many to restock '%s'? ", p->name);
    scanf("%d", &restock_amount);
    clear_buffer();

    p->quantity += restock_amount;
    printf("🔧 Restocked '%s'. New quantity: %d units. 🥳\n", p->name, p->quantity);
}

void clear_buffer() {
    while (getchar() != '\n') ; // Clean the buffer, just like I clean my desk – occasionally!
}