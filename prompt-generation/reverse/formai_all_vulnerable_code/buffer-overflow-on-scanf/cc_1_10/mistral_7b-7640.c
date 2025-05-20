//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 10

struct Item {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
};

void printMenu() {
    printf("\n----- MENU -----\n");
    printf("1. Coffee\t\t\tPrice: $1.50\n");
    printf("2. Tea\t\t\tPrice: $1.20\n");
    printf("3. Hot Chocolate\tPrice: $2.00\n");
    printf("4. Sandwich\t\tPrice: $3.50\n");
    printf("5. Salad\t\tPrice: $4.00\n");
    printf("6. Burger\t\tPrice: $5.00\n");
    printf("7. Pizza\t\tPrice: $7.50\n");
    printf("8. Soda\t\tPrice: $1.00\n");
    printf("9. Water\t\tPrice: $0.50\n");
    printf("10. Exit\n");
}

void getItemDetails(struct Item items[]) {
    int i;
    char name[MAX_NAME_LEN];
    int quantity;

    for(i = 0; i < MAX_ITEMS; i++) {
        printf("\nEnter item name: ");
        scanf("%s", name);
        strcpy(items[i].name, name);

        printf("Enter quantity: ");
        scanf("%d", &quantity);
        items[i].quantity = quantity;

        if(i == 0) {
            items[i].price = 0.0;
            continue;
        }

        switch(i) {
            case 1: items[i].price = 1.50; break;
            case 2: items[i].price = 1.20; break;
            case 3: items[i].price = 2.00; break;
            case 4: items[i].price = 3.50; break;
            case 5: items[i].price = 4.00; break;
            case 6: items[i].price = 5.00; break;
            case 7: items[i].price = 7.50; break;
            case 8: items[i].price = 1.00; break;
            case 9: items[i].price = 0.50; break;
            default: return;
        }
    }
}

void calculateTotal(struct Item items[], float *total) {
    int i;
    *total = 0.0;

    for(i = 0; i < MAX_ITEMS; i++) {
        *total += (items[i].quantity * items[i].price);
    }
}

int main() {
    struct Item items[MAX_ITEMS];
    float total = 0.0;

    printMenu();

    getItemDetails(items);

    calculateTotal(items, &total);

    printf("\nTotal: $%.2f\n", total);

    return 0;
}