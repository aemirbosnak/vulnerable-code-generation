//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 5
#define MENU_SIZE 5

// Struct to represent a menu item
typedef struct {
    char name[20];
    float price;
} MenuItem;

// Function prototypes
void displayMenu(MenuItem menu[], int size);
void takeOrder(MenuItem menu[], int size);
float calculateTotal(float prices[], int count);
void thankCustomer();

int main() {
    // Create a hilarious menu
    MenuItem menu[MENU_SIZE] = {
        {"Coffee (Caffeine Jolt)", 2.5},
        {"Tea (Leafy Serenity)", 1.5},
        {"Muffin (Fluff N' Stuff)", 1.0},
        {"Sandwich (Carbohydrate Hulk)", 3.0},
        {"Cake (Sugar Rush)", 2.0}
    };

    printf("Welcome to the C Cafe, where our coffee is like programming: it gets better with every compile!\n");
    displayMenu(menu, MENU_SIZE);
    
    takeOrder(menu, MENU_SIZE);
    thankCustomer();
    
    return 0;
}

void displayMenu(MenuItem menu[], int size) {
    printf("\n=== C Cafe Menu ===\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("====================\n");
}

void takeOrder(MenuItem menu[], int size) {
    int order[MAX_ITEMS];
    float prices[MAX_ITEMS];
    int count = 0;

    printf("What's your order? (Enter item numbers, 0 to finish)\n");
    while (1) {
        int item;
        printf("Item number: ");
        scanf("%d", &item);

        if (item == 0) {
            break;
        }

        if (item < 1 || item > size) {
            printf("Oops! Not on the menu! Are you trying to order the keyboard? 😂\n");
            continue;
        }

        prices[count] = menu[item - 1].price;
        order[count] = item; // Store the item number
        count++;

        if (count >= MAX_ITEMS) {
            printf("Wow! Are you a hungry hippo? You can only order %d items. 😅\n", MAX_ITEMS);
            break;
        }
    }

    float total = calculateTotal(prices, count);
    printf("\nYour order details:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - $%.2f\n", menu[order[i] - 1].name, prices[i]);
    }
    printf("Total: $%.2f\n", total);
}

float calculateTotal(float prices[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += prices[i];
    }
    return total;
}

void thankCustomer() {
    printf("\nThank you for visiting the C Cafe!\n");
    printf("Remember, life is too short for bad coffee (or bad code)! ☕️\n");
    printf("Have a caffeinated day! 🚀\n");
}