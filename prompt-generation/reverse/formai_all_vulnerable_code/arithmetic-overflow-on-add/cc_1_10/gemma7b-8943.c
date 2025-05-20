//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: protected
#include <stdio.h>
#include <string.h>

// Define a structure for a medical store item
typedef struct item {
    char name[20];
    int quantity;
    float price;
} item;

// Create an array of items
item items[] = {
    {"Acetaminophen", 100, 2.50},
    {"Ibuprofen", 50, 3.00},
    {"Tylenol", 75, 2.25},
    {"Aspirin", 25, 3.50},
    {"Cough Syrup", 15, 4.00}
};

// Function to search for an item
int search(char *name) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(name, items[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to add an item
void add(char *name, int quantity, float price) {
    item new_item;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    new_item.price = price;

    items[5] = new_item;
    items[5].quantity++;
}

// Function to update an item
void update(char *name, int quantity, float price) {
    int index = search(name);
    if (index != -1) {
        items[index].quantity = quantity;
        items[index].price = price;
    }
}

// Function to delete an item
void delete(char *name) {
    int index = search(name);
    if (index != -1) {
        items[index].quantity = 0;
        items[index].price = 0.00;
    }
}

// Main function
int main() {
    char command;
    char name[20];
    int quantity;
    float price;

    printf("Enter command (add, update, delete, search): ");
    scanf("%c", &command);

    switch (command) {
        case 'a':
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item quantity: ");
            scanf("%d", &quantity);
            printf("Enter item price: ");
            scanf("%f", &price);
            add(name, quantity, price);
            printf("Item added.\n");
            break;
        case 'u':
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item quantity: ");
            scanf("%d", &quantity);
            printf("Enter item price: ");
            scanf("%f", &price);
            update(name, quantity, price);
            printf("Item updated.\n");
            break;
        case 'd':
            printf("Enter item name: ");
            scanf("%s", name);
            delete(name);
            printf("Item deleted.\n");
            break;
        case 's':
            printf("Enter item name: ");
            scanf("%s", name);
            int index = search(name);
            if (index != -1) {
                printf("Item name: %s\n", items[index].name);
                printf("Item quantity: %d\n", items[index].quantity);
                printf("Item price: %.2f\n", items[index].price);
            } else {
                printf("Item not found.\n");
            }
            break;
    }

    return 0;
}