//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include <stdio.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[30];
    float price;
} MenuItem;

void displayMenu(MenuItem menu[], int count) {
    printf("\nMenu:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

float calculateTotal(int itemIds[], int quantities[], int itemCount, MenuItem menu[], int menuCount) {
    float total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        for (int j = 0; j < menuCount; j++) {
            if (menu[j].id == itemIds[i]) {
                total += menu[j].price * quantities[i];
            }
        }
    }
    return total;
}

int main() {
    MenuItem menu[] = {
        {1, "Coffee", 2.50},
        {2, "Tea", 1.75},
        {3, "Sandwich", 5.00},
        {4, "Cake", 3.25},
        {5, "Juice", 2.00}
    };
    
    int itemIds[MAX_ITEMS];
    int quantities[MAX_ITEMS];
    int itemCount = 0;

    while (1) {
        displayMenu(menu, 5);
        printf("\nEnter item ID to add to bill (0 to finish): ");
        int itemId;
        scanf("%d", &itemId);

        if (itemId == 0) break;
        
        printf("Enter quantity: ");
        int quantity;
        scanf("%d", &quantity);

        itemIds[itemCount] = itemId;
        quantities[itemCount] = quantity;
        itemCount++;
    }

    float total = calculateTotal(itemIds, quantities, itemCount, menu, 5);
    printf("\nTotal Bill: $%.2f\n", total);

    return 0;
}