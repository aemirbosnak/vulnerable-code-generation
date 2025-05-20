//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: imaginative
// Welcome to the whimsical Cafe Concerto! A culinary symphony awaits your indulgence.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// An enchanting array of coffee concoctions
struct Coffee {
    char name[25];
    float price;
    char description[50];
};

// A Symphony of Scones - Deliciously British
struct Scone {
    char name[20];
    float price;
    char flavor[20];
};

// Cakes that Dance on Your Taste Buds
struct Cake {
    char name[25];
    float price;
    char icing[20];
};

// Creating our menu, a masterpiece of flavors
struct Coffee menu_coffee[] = {
    {"Celestial Cappuccino", 3.50, "A frothy symphony of espresso and steamed milk, topped with celestial swirls"},
    {"Enchanting Espresso", 2.50, "A robust brew, a jolt of pure enchantment"},
    {"Mystical Mocha", 3.75, "A chocolate lover's dream, a blend of espresso and velvety chocolate"}
};

struct Scone menu_scone[] = {
    {"Royal Raspberry Scone", 2.25, "A regal treat, bursting with juicy raspberries"},
    {"Earl Grey Scone", 2.00, "Aromatic and elegant, infused with the finest Earl Grey tea"},
    {"Golden Ginger Scone", 2.50, "A spicy delight, the perfect accompaniment to your cuppa"}
};

struct Cake menu_cake[] = {
    {"Chocolate Truffle Torte", 4.50, "A decadent masterpiece, layers of rich chocolate and velvety truffle"},
    {"Lemon Meringue Dream", 4.00, "A citrusy delight, a symphony of tart lemon and fluffy meringue"},
    {"Red Velvet Rhapsody", 4.25, "A classic indulgence, moist red velvet with a touch of cream cheese frosting"}
};

// The maestro takes your order
void takeOrder(int *coffee_count, int *scone_count, int *cake_count, int *total_items) {
    printf("Welcome to Cafe Concerto, where every sip and bite is a masterpiece.\n");
    printf("May I tempt you with our exquisite menu?\n\n");

    int choice;
    char temp[10];

    // Coffee: Brewing Your Dreams
    printf("**Coffee:**\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s (%.2f galleons)\n", i + 1, menu_coffee[i].name, menu_coffee[i].price);
    }
    printf("How many cups of coffee would you like to order? (0-3): ");
    fgets(temp, 10, stdin);
    sscanf(temp, "%d", coffee_count);
    *total_items += *coffee_count;

    // Scones: A Symphony of Delights
    printf("\n**Scones:**\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s (%.2f galleons)\n", i + 1, menu_scone[i].name, menu_scone[i].price);
    }
    printf("How many scones would you like to order? (0-3): ");
    fgets(temp, 10, stdin);
    sscanf(temp, "%d", scone_count);
    *total_items += *scone_count;

    // Cakes: A Sweet Indulgence
    printf("\n**Cakes:**\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s (%.2f galleons)\n", i + 1, menu_cake[i].name, menu_cake[i].price);
    }
    printf("How many slices of cake would you like to order? (0-3): ");
    fgets(temp, 10, stdin);
    sscanf(temp, "%d", cake_count);
    *total_items += *cake_count;
}

// The Sorcerer's Apprentice Calculates Your Bill
float calculateBill(int coffee_count, int scone_count, int cake_count) {
    float subtotal = 0;
    for (int i = 0; i < coffee_count; i++) {
        subtotal += menu_coffee[i].price;
    }
    for (int i = 0; i < scone_count; i++) {
        subtotal += menu_scone[i].price;
    }
    for (int i = 0; i < cake_count; i++) {
        subtotal += menu_cake[i].price;
    }
    float total = subtotal * 1.13f; // Add 13% Wizarding Tax
    return total;
}

// The Grand Finale: A Receipt Fit for Royalty
void printReceipt(int coffee_count, int scone_count, int cake_count, float total) {
    printf("\n\n**Your Magical Receipt**\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < coffee_count; i++) {
        printf("%s (x%d): %.2f galleons\n", menu_coffee[i].name, 1, menu_coffee[i].price);
    }
    for (int i = 0; i < scone_count; i++) {
        printf("%s (x%d): %.2f galleons\n", menu_scone[i].name, 1, menu_scone[i].price);
    }
    for (int i = 0; i < cake_count; i++) {
        printf("%s (x%d): %.2f galleons\n", menu_cake[i].name, 1, menu_cake[i].price);
    }
    printf("--------------------------------------------------\n");
    printf("Subtotal: %.2f galleons\n", total / 1.13f);
    printf("Wizarding Tax (13%%): %.2f galleons\n", total - (total / 1.13f));
    printf("**Total: %.2f galleons**\n", total);
    printf("--------------------------------------------------\n");
}

// The Enchanting Main Event
int main() {
    int coffee_count = 0, scone_count = 0, cake_count = 0, total_items = 0;
    takeOrder(&coffee_count, &scone_count, &cake_count, &total_items);
    if (total_items == 0) {
        printf("No worries, maybe next time! Expecto Patronum to cast away your hunger pangs.\n");
        return 0;
    }
    float total = calculateBill(coffee_count, scone_count, cake_count);
    printReceipt(coffee_count, scone_count, cake_count, total);
    printf("Thank you for dining at Cafe Concerto. May your culinary adventures continue!\n");
    return 0;
}