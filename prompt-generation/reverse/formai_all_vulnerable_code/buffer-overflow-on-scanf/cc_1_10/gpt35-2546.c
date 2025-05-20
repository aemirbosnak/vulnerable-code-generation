//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: ephemeral
#include <stdio.h>

struct Medicine {
    char name[50];
    float price;
    int quantity;
};

struct Medicine stock[100];
int medicineCount = 0;

float totalSales = 0;

void addMedicine() {
    struct Medicine m;

    printf("Enter the medicine name: ");
    scanf("%s", m.name);

    printf("Enter the medicine price: ");
    scanf("%f", &m.price);

    printf("Enter the medicine quantity: ");
    scanf("%d", &m.quantity);

    stock[medicineCount++] = m;
    printf("\nMedicine added successfully!\n");
}

void sellMedicine() {
    int index, quantity;
    float price;

    printf("Enter the medicine index: ");
    scanf("%d", &index);

    printf("Enter the medicine quantity: ");
    scanf("%d", &quantity);

    if (stock[index].quantity < quantity) {
        printf("\nInsufficient stock!\n");
        return;
    }

    price = stock[index].price * quantity;
    totalSales += price;

    printf("\nTotal price: $%.2f\n", price);
    stock[index].quantity -= quantity;
    printf("Medicine sold successfully!\n");
}

void viewSales() {
    printf("\nTotal Sales: $%.2f\n", totalSales);
}

void printStock(struct Medicine m) {
    printf("%d - %s - $%.2f - %d\n", medicineCount++, m.name, m.price, m.quantity);
}

void viewStock() {
    printf("\nCurrent Stock:\n");
    for (int i = 0; i < medicineCount; i++) {
        printStock(stock[i]);
    }
}

void showMenu() {
    int choice;

    printf("\nMedical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. Sell Medicine\n");
    printf("3. View Stock\n");
    printf("4. View Sales\n");
    printf("5. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addMedicine();
            break;
        case 2:
            sellMedicine();
            break;
        case 3:
            viewStock();
            break;
        case 4:
            viewSales();
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid choice!\n");
    }

    showMenu();
}

int main() {
    showMenu();
    return 0;
}