//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    double price;
} Item;

Item warehouse[MAX_ITEMS];
int item_count = 0;

void add_item() {
    if (item_count >= MAX_ITEMS) {
        printf("⚠️ Warehouse is full, cannot add more items! ⚠️\n");
        return;
    }
    
    Item new_item;
    printf("🔍 Enter the item name: ");
    scanf("%s", new_item.name);
    
    printf("📦 Enter the quantity: ");
    scanf("%d", &new_item.quantity);
    if (new_item.quantity < 0) {
        printf("❌ Quantity cannot be negative! \n");
        return;
    }

    printf("💰 Enter the price: ");
    scanf("%lf", &new_item.price);
    if (new_item.price < 0) {
        printf("❌ Price cannot be negative! \n");
        return;
    }

    warehouse[item_count++] = new_item;
    printf("✅ Item added successfully: %s | Quantity: %d | Price: %.2f 💵\n", 
            new_item.name, new_item.quantity, new_item.price);
}

void view_inventory() {
    printf("\n📦 Current Inventory:\n");
    for (int i = 0; i < item_count; i++) {
        printf("[%d] %s - Quantity: %d, Price: %.2f 💵\n", 
                i + 1, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
    printf("\n");
}

void update_item() {
    int index;
    printf("📝 Enter item's index to update (1 to %d): ", item_count);
    scanf("%d", &index);
    
    if (index < 1 || index > item_count) {
        printf("❌ Invalid index! Try again! ❌\n");
        return;
    }

    index -= 1; // Adjusting for 0-based index
    printf("📦 Current Item: %s | Quantity: %d | Price: %.2f 💵\n", 
            warehouse[index].name, warehouse[index].quantity, warehouse[index].price);
    
    printf("🔄 Enter new quantity (current: %d): ", warehouse[index].quantity);
    scanf("%d", &warehouse[index].quantity);
    
    if (warehouse[index].quantity < 0) {
        printf("❌ Quantity cannot be negative! \n");
        return;
    }

    printf("🔄 Enter new price (current: %.2f): ", warehouse[index].price);
    scanf("%lf", &warehouse[index].price);
    
    if (warehouse[index].price < 0) {
        printf("❌ Price cannot be negative! \n");
        return;
    }

    printf("✅ Item updated successfully to: %s | Quantity: %d | Price: %.2f 💵\n", 
            warehouse[index].name, warehouse[index].quantity, warehouse[index].price);
}

void delete_item() {
    int index;
    printf("🗑️ Enter item's index to delete (1 to %d): ", item_count);
    scanf("%d", &index);
    
    if (index < 1 || index > item_count) {
        printf("❌ Invalid index! Try again! ❌\n");
        return;
    }

    index -= 1; // Adjusting for 0-based index
    for (int i = index; i < item_count - 1; i++) {
        warehouse[i] = warehouse[i + 1];
    }
    item_count--;
    printf("✅ Item deleted successfully! ❌\n");
}

void show_menu() {
    printf("\n🌟 Warehouse Management System 🌟\n");
    printf("1. Add Item\n");
    printf("2. View Inventory\n");
    printf("3. Update Item\n");
    printf("4. Delete Item\n");
    printf("5. Exit\n");
    printf("📌 Select an option: ");
}

int main() {
    int choice;
    while (1) {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                view_inventory();
                break;
            case 3:
                update_item();
                break;
            case 4:
                delete_item();
                break;
            case 5:
                printf("👋 Exiting Warehouse Management System. Goodbye! 👋\n");
                return 0;
            default:
                printf("❌ Invalid choice! Please select again. ❌\n");
        }
    }
    return 0;
}