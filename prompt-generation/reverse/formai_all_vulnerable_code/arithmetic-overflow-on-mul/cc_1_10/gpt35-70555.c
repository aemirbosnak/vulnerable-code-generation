//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

const int VAT = 14; //VAT rate is 14%

void printMenu();
int calculateTotal(int price, int quantity);
float addVAT(float total);

int main() {
    int choice, quantity, price, total = 0;
    char ch;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                price = 200;
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += calculateTotal(price, quantity);
                break;
            case 2:
                price = 150;
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += calculateTotal(price, quantity);
                break;
            case 3:
                price = 100;
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += calculateTotal(price, quantity);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Do you want to order more (Y/N)? ");
        scanf(" %c", &ch);

    } while(ch == 'Y' || ch == 'y');

    float totalWithVAT = addVAT(total);
    printf("Total: Rs. %.2f (includes VAT of %d%%)\n", totalWithVAT, VAT);

    return 0;
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Coffee  - Rs. 200\n");
    printf("2. Tea     - Rs. 150\n");
    printf("3. Pastry  - Rs. 100\n");
}

int calculateTotal(int price, int quantity) {
    return price * quantity;
}

float addVAT(float total) {
    float amt = (VAT * total) / 100;
    return total + amt;
}