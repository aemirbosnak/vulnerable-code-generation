//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} CafeBillingSystem;

// Function prototypes
void addItem(CafeBillingSystem *billingSystem);
void displayMenu(CafeBillingSystem *billingSystem);
void calculateTotal(CafeBillingSystem *billingSystem);
void clearInputBuffer();
void displayBill(CafeBillingSystem *billingSystem);
void paranoidCheck();

int main() {
    CafeBillingSystem billingSystem;
    billingSystem.itemCount = 0;

    int choice;

    paranoidCheck();

    do {
        printf("\n--- Cafe Billing System ---\n");
        printf("1. Add Item\n");
        printf("2. Display Menu\n");
        printf("3. Calculate Total\n");
        printf("4. Display Bill\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 5) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        switch (choice) {
            case 1:
                addItem(&billingSystem);
                break;
            case 2:
                displayMenu(&billingSystem);
                break;
            case 3:
                calculateTotal(&billingSystem);
                break;
            case 4:
                displayBill(&billingSystem);
                break;
            case 5:
                printf("Exiting the program. Stay safe!\n");
                break;
            default:
                printf("Something feels off... Choose wisely!\n");
        }

    } while (choice != 5);

    return 0;
}

void addItem(CafeBillingSystem *billingSystem) {
    if (billingSystem->itemCount >= MAX_ITEMS) {
        printf("The system cannot handle more items! Max capacity reached.\n");
        return;
    }

    Item newItem;
    printf("Enter item name: ");
    clearInputBuffer();
    fgets(newItem.name, NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; // Remove newline from string

    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);

    billingSystem->items[billingSystem->itemCount] = newItem;
    billingSystem->itemCount++;
    printf("Item added successfully. But remember, someone might be watching...\n");
}

void displayMenu(CafeBillingSystem *billingSystem) {
    if (billingSystem->itemCount == 0) {
        printf("No items in the menu. What are you hiding?\n");
        return;
    }

    printf("\n--- Menu ---\n");
    for (int i = 0; i < billingSystem->itemCount; i++) {
        printf("%d. %s - $%.2f (Quantity: %d)\n",
               i + 1, billingSystem->items[i].name,
               billingSystem->items[i].price,
               billingSystem->items[i].quantity);
    }
    printf("\nKeep an eye on the competitors...\n");
}

void calculateTotal(CafeBillingSystem *billingSystem) {
    float total = 0.0f;

    for (int i = 0; i < billingSystem->itemCount; i++) {
        total += billingSystem->items[i].price * billingSystem->items[i].quantity;
    }

    printf("Total bill: $%.2f. But is it REALLY accurate?\n", total);
}

void displayBill(CafeBillingSystem *billingSystem) {
    if (billingSystem->itemCount == 0) {
        printf("No items to display. Suspicious, right?\n");
        return;
    }

    printf("\n--- Bill ---\n");
    for (int i = 0; i < billingSystem->itemCount; i++) {
        printf("%s x %d @ $%.2f each\n", 
               billingSystem->items[i].name, 
               billingSystem->items[i].quantity, 
               billingSystem->items[i].price);
    }
    float total = 0.0f;
    for (int i = 0; i < billingSystem->itemCount; i++) {
        total += billingSystem->items[i].price * billingSystem->items[i].quantity;
    }
    printf("Total: $%.2f. Always be on guard...\n", total);
}

void clearInputBuffer() {
    while (getchar() != '\n'); // clears the input buffer
}

void paranoidCheck() {
    printf("WARNING: System is under constant surveillance...\n\
You may proceed, but always remain cautious.\n");
}