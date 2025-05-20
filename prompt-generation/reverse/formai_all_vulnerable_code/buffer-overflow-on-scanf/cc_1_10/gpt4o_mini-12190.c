//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: real-life
#include <stdio.h>

struct Book {
    char title[50];
    float price;
    int quantity;
};

void displayInventory(struct Book books[], int count) {
    printf("Current Inventory:\n");
    printf("--------------------------------------------------\n");
    printf("| %-30s | Price ($) | Quantity |\n", "Title");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("| %-30s | %-8.2f | %-8d |\n", books[i].title, books[i].price, books[i].quantity);
    }
    printf("--------------------------------------------------\n");
}

float calculateTotalSales(struct Book books[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += books[i].price * books[i].quantity;
    }
    return total;
}

float applyDiscount(float total, float discount) {
    return total - (total * (discount / 100));
}

void updateInventory(struct Book books[], int index, int sold) {
    if (books[index].quantity >= sold) {
        books[index].quantity -= sold;
    } else {
        printf("Not enough stock for %s. Available: %d\n", books[index].title, books[index].quantity);
    }
}

int main() {
    struct Book books[5] = {
        {"The Great Gatsby", 10.99, 5},
        {"1984", 8.99, 10},
        {"To Kill a Mockingbird", 12.99, 7},
        {"The Catcher in the Rye", 9.99, 4},
        {"Moby Dick", 11.99, 3}
    };

    int choice, sold, bookIndex;
    float discount;

    while (1) {
        printf("\nBookstore Management System\n");
        printf("1. Display Inventory\n");
        printf("2. Calculate Total Sales\n");
        printf("3. Apply Discount\n");
        printf("4. Sell Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayInventory(books, 5);
                break;
            case 2: {
                float totalSales = calculateTotalSales(books, 5);
                printf("Total Sales: $%.2f\n", totalSales);
                break;
            }
            case 3:
                printf("Enter discount percentage: ");
                scanf("%f", &discount);
                float totalSales = calculateTotalSales(books, 5);
                float discountedTotal = applyDiscount(totalSales, discount);
                printf("Total Sales after %.2f%% discount: $%.2f\n", discount, discountedTotal);
                break;
            case 4:
                printf("Enter the index of the book to sell (0-4): ");
                scanf("%d", &bookIndex);
                printf("Enter quantity to sell: ");
                scanf("%d", &sold);
                updateInventory(books, bookIndex, sold);
                break;
            case 5:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}