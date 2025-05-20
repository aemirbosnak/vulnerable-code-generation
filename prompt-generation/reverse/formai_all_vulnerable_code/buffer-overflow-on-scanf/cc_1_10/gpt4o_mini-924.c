//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Bill;

void addItem(Bill *bill) {
    if (bill->count >= MAX_ITEMS) {
        printf("The cosmic order has limited our items to %d! Cannot add more.\n", MAX_ITEMS);
        return;
    }
    
    Item new_item;
    printf("Enter the item name (a name whispered by the winds of time): ");
    scanf("%s", new_item.name);
    printf("Enter the price (a treasure hidden in the depths of the ocean): ");
    scanf("%lf", &new_item.price);
    
    bill->items[bill->count] = new_item;
    bill->count++;
    printf("The item '%s' has been inscribed into the annals of the billing ledger.\n", new_item.name);
}

void displayBill(Bill *bill) {
    if (bill->count == 0) {
        printf("The bill is a blank canvas, waiting for the brushstrokes of reality.\n");
        return;
    }
    
    printf("\n----- Cosmic Café Bill -----\n");
    double total = 0;
    for (int i = 0; i < bill->count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, bill->items[i].name, bill->items[i].price);
        total += bill->items[i].price;
    }
    printf("---------------------------\n");
    printf("Total: $%.2f\n", total);
    printf("\nIn the bizarre bazaar of existence, your total shines like a star.\n");
}

void clearBill(Bill *bill) {
    bill->count = 0;
    printf("The cosmic ledger has been cleansed, ready to record new tales.\n");
}

void saveBill(Bill *bill) {
    FILE *file = fopen("bill.txt", "w");
    if (!file) {
        printf("The astral phenomena have blocked our attempts to save the bill.\n");
        return;
    }
    
    for (int i = 0; i < bill->count; i++) {
        fprintf(file, "%s: %.2f\n", bill->items[i].name, bill->items[i].price);
    }
    fclose(file);
    printf("The echoes of your bill have been captured in 'bill.txt', eternalized on the fabric of reality.\n");
}

int main() {
    Bill bill;
    bill.count = 0;
    int choice;

    do {
        printf("\n--- Welcome to the Surreal Café Billing System ---\n");
        printf("1. Add Item\n");
        printf("2. Display Bill\n");
        printf("3. Clear Bill\n");
        printf("4. Save Bill\n");
        printf("5. Exit (Into the Unknown)\n");
        printf("Choose your path: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem(&bill);
                break;
            case 2:
                displayBill(&bill);
                break;
            case 3:
                clearBill(&bill);
                break;
            case 4:
                saveBill(&bill);
                break;
            case 5:
                printf("As you drift into the unknown, may your journey be adorned with whimsical dreams.\n");
                break;
            default:
                printf("In the garden of choices, that path is but a mirage.\n");
        }
    } while (choice != 5);

    return 0;
}