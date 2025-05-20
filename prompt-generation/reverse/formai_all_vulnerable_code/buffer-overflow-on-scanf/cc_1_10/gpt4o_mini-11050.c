//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
    float total;
} Bill;

void addItem(Bill *bill, const char *name, float price, int quantity) {
    if (bill->itemCount < MAX_ITEMS) {
        strcpy(bill->items[bill->itemCount].name, name);
        bill->items[bill->itemCount].price = price;
        bill->items[bill->itemCount].quantity = quantity;
        bill->itemCount++;
    } else {
        printf("The cosmic menu has reached its limit and cannot accommodate more whims!\n");
    }
}

void calculateTotal(Bill *bill) {
    bill->total = 0;
    for (int i = 0; i < bill->itemCount; i++) {
        bill->total += bill->items[i].price * bill->items[i].quantity;
    }
}

void printBill(const Bill *bill) {
    printf("~~~~~~~~~~~~~~~~~~~ Ominous Cafe Receipt ~~~~~~~~~~~~~~~~~~~\n");
    printf("Behold the treasures you have gathered:\n");
    for (int i = 0; i < bill->itemCount; i++) {
        printf("%d. %s (Quantity: %d) - $%.2f\n", 
            i + 1, bill->items[i].name,
            bill->items[i].quantity, 
            bill->items[i].price * bill->items[i].quantity);
    }
    printf("-------------------------------------------------------------\n");
    printf("Total Cost: $%.2f\n", bill->total);
    printf("Thank you for your surreal visit to the Ominous Cafe!\n");
}

void whimsicalMenu() {
    printf("Welcome, curious traveler! Here's today's cosmic menu:\n");
    printf("1. Ambrosial Brew - $3.50\n");
    printf("2. Elixir of Dreams - $4.00\n");
    printf("3. Phantom Pie - $5.25\n");
    printf("4. Ethereal Scone - $2.75\n");
    printf("5. Nebula Nectar - $6.00\n");
}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    Bill bill = { .itemCount = 0, .total = 0 };
    srand(time(NULL));
    
    char menuChoice[MAX_NAME_LENGTH];
    int quantity;

    while (1) {
        whimsicalMenu();
        printf("Place your order (type 'exit' to leave): ");
        scanf("%s", menuChoice);

        if (strcmp(menuChoice, "exit") == 0) {
            break;
        }

        printf("How many of those splendid items would you like? ");
        scanf("%d", &quantity);

        if (strcmp(menuChoice, "Ambrosial Brew") == 0) {
            addItem(&bill, menuChoice, 3.50, quantity);
        } else if (strcmp(menuChoice, "Elixir of Dreams") == 0) {
            addItem(&bill, menuChoice, 4.00, quantity);
        } else if (strcmp(menuChoice, "Phantom Pie") == 0) {
            addItem(&bill, menuChoice, 5.25, quantity);
        } else if (strcmp(menuChoice, "Ethereal Scone") == 0) {
            addItem(&bill, menuChoice, 2.75, quantity);
        } else if (strcmp(menuChoice, "Nebula Nectar") == 0) {
            addItem(&bill, menuChoice, 6.00, quantity);
        } else {
            printf("Ah, the whimsy has woven itself into a tangle! Please choose from the menu.\n");
        }
    }

    calculateTotal(&bill);
    printBill(&bill);

    return 0;
}