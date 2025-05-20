//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} item;

void print_menu() {
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Sandwich\n");
    printf("4. Salad\n");
    printf("5. Quit\n");
}

item get_order() {
    item i;
    printf("Enter item name: ");
    scanf("%s", i.name);
    printf("Enter quantity: ");
    scanf("%d", &i.quantity);
    printf("Enter price: ");
    scanf("%f", &i.price);
    return i;
}

float calculate_total(item *items, int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += items[i].quantity * items[i].price;
    }
    return total;
}

void print_receipt(item *items, int size, float total) {
    printf("Receipt:\n");
    for (int i = 0; i < size; i++) {
        printf("%s %d %f\n", items[i].name, items[i].quantity, items[i].price);
    }
    printf("Total: %f\n", total);
}

int main() {
    int size = 0;
    item *items = malloc(sizeof(item));
    float total = 0;

    while (1) {
        print_menu();
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            items[size++] = get_order();
            break;
        case 2:
            items[size++] = get_order();
            break;
        case 3:
            items[size++] = get_order();
            break;
        case 4:
            items[size++] = get_order();
            break;
        case 5:
            total = calculate_total(items, size);
            print_receipt(items, size, total);
            free(items);
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}