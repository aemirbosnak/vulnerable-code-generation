//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    Item item;
    int quantity;
    float total;
} Order;

void print_menu() {
    printf("\n\n===== C Cafe Billing System =====\n\n");
    printf("Menu:\n");
    printf("1. Add item\n");
    printf("2. View order\n");
    printf("3. Checkout\n");
    printf("4. Cancel order\n");
    printf("5. Exit\n");
}

void add_item(Item *item) {
    printf("\nEnter the name of the item: ");
    scanf("%s", item->name);
    printf("Enter the price of the item: ");
    scanf("%f", &item->price);
    printf("Enter the quantity of the item: ");
    scanf("%d", &item->quantity);
    printf("\n%s added to the menu!\n", item->name);
}

void view_order(Order *order, int count) {
    float grand_total = 0;
    printf("\n\n===== Order Summary =====\n");
    for (int i = 0; i < count; i++) {
        printf("\nItem name: %s\n", order[i].item.name);
        printf("Quantity: %d\n", order[i].quantity);
        printf("Price per item: %.2f\n", order[i].item.price);
        printf("Total for this item: %.2f\n", order[i].total);
        grand_total += order[i].total;
    }
    printf("\n\nGrand total: %.2f\n", grand_total);
}

void checkout(Order *order, int count) {
    float grand_total = 0;
    printf("\n\n===== Checkout =====\n");
    for (int i = 0; i < count; i++) {
        grand_total += order[i].total;
    }
    printf("\n\nTotal amount due: %.2f\n", grand_total);
    printf("Payment received: ");
    float payment = 0;
    scanf("%f", &payment);
    if (payment < grand_total) {
        printf("\n\nError: Payment is less than total amount due!\n");
        printf("Please try again.\n");
        return;
    }
    printf("\n\nPayment received: %.2f\n", payment);
    printf("Change due: %.2f\n", payment - grand_total);
    printf("\n\nThank you for your order!\n");
    exit(0);
}

void cancel_order(Order *order, int *count) {
    printf("\nAre you sure you want to cancel your order? (y/n): ");
    char answer;
    scanf(" %c", &answer);
    if (answer == 'y') {
        *count = 0;
        printf("\n\nYour order has been cancelled.\n");
    }
}

int main() {
    int choice, count = 0;
    Order order[50];
    Item item;
    while (1) {
        print_menu();
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item(&item);
                order[count].item = item;
                printf("\nEnter quantity: ");
                scanf("%d", &order[count].quantity);
                order[count].total = order[count].quantity * order[count].item.price;
                printf("\n%.2f %s added to your order!\n", order[count].total, item.name);
                count++;
                break;
            case 2:
                if (count == 0) {
                    printf("\n\nError: Your order is empty!\n");
                    break;
                }
                view_order(order, count);
                break;
            case 3:
                if (count == 0) {
                    printf("\n\nError: Your order is empty!\n");
                    break;
                }
                checkout(order, count);
                break;
            case 4:
                if (count == 0) {
                    printf("\n\nError: Your order is empty!\n");
                    break;
                }
                cancel_order(order, &count);
                break;
            case 5:
                printf("\n\nThank you for using C Cafe Billing System!\n");
                exit(0);
            default:
                printf("\n\nError: Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}