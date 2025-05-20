//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a menu item
typedef struct {
    char name[50];
    float price;
    int quantity;
} MenuItem;

// Function prototypes
void displayMenu(MenuItem menu[], int size);
void takeOrder(MenuItem menu[], int size);
void generateBill(MenuItem order[], int size, int itemCount);

int main() {
    // futuristic cafe menu
    MenuItem menu[] = {
        {"Neon Latte", 4.99, 0},
        {"Cyber Mocha", 5.49, 0},
        {"Holo-Chai", 3.99, 0},
        {"Synthesized Green Tea", 2.99, 0},
        {"Galactic Croissant", 1.99, 0},
        {"Augmented Reality Bagel", 2.49, 0},
        {"Quantum Biscotti", 1.49, 0}
    };

    int menuSize = sizeof(menu) / sizeof(menu[0]);
    
    printf("Welcome to the Futuristic Cafe!\n");
    displayMenu(menu, menuSize);
    takeOrder(menu, menuSize);

    return 0;
}

// Function to display menu
void displayMenu(MenuItem menu[], int size) {
    printf("\n** Menu **\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("\nNote: Enter 0 to finish your order.\n");
}

// Function to take the customer's order
void takeOrder(MenuItem menu[], int size) {
    int choice, itemCount = 0;
    MenuItem order[100]; // Array to store items ordered

    while (1) {
        printf("\nEnter the number of the item you want to order: ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        } else if (choice > 0 && choice <= size) {
            printf("Enter quantity for %s: ", menu[choice - 1].name);
            scanf("%d", &menu[choice - 1].quantity);
            order[itemCount++] = menu[choice - 1]; // Save item ordered
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    generateBill(order, size, itemCount);
}

// Function to generate the bill
void generateBill(MenuItem order[], int size, int itemCount) {
    float total = 0.0;

    printf("\n** Your Bill **\n");
    for (int i = 0; i < itemCount; i++) {
        float itemTotal = order[i].price * order[i].quantity;
        printf("%s x%d - $%.2f\n", order[i].name, order[i].quantity, itemTotal);
        total += itemTotal;
    }

    printf("\nTotal Amount: $%.2f\n", total);
    printf("Thank you for visiting the Futuristic Cafe!\n");
    printf("Proceeding with futuristic payment...\n");
    printf("(Processing...)\n");
    
    // Simulating payment processing
    for (int j = 0; j < 3; j++) {
        printf("...\n");
        sleep(1); // delay to simulate processing time
    }
    
    printf("Payment Successful! Have a stellar day!\n");
}