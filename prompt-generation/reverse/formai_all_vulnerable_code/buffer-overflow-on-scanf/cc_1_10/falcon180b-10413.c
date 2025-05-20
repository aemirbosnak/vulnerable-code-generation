//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 10
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 6

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
} item_t;

void read_items(item_t items[]) {
    int count = 0;
    while (count < MAX_ITEMS) {
        printf("Enter the name of the item (%d characters max):\n", MAX_NAME_LEN - 1);
        scanf("%s", items[count].name);
        printf("Enter the price of the item (%d characters max):\n", MAX_PRICE_LEN - 1);
        scanf("%s", items[count].price);
        count++;
    }
}

void display_menu(item_t items[]) {
    printf("\nMenu:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0]!= '\0') {
            printf("%d. %s - $%s\n", i + 1, items[i].name, items[i].price);
        }
    }
}

void take_order(item_t items[], int customer_choice[], int num_items) {
    printf("\nEnter your order (1-%d):\n", num_items);
    for (int i = 0; i < num_items; i++) {
        customer_choice[i] = 0;
    }
    int count = 0;
    while (count < num_items) {
        int choice;
        scanf("%d", &choice);
        if (choice >= 1 && choice <= num_items) {
            customer_choice[choice - 1] = 1;
            count++;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
}

void calculate_total(item_t items[], int customer_choice[], int num_items) {
    float total = 0.0;
    for (int i = 0; i < num_items; i++) {
        if (customer_choice[i] == 1) {
            total += atof(items[i].price);
        }
    }
    printf("\nTotal: $%.2f\n", total);
}

int main() {
    item_t items[MAX_ITEMS];
    read_items(items);

    int num_items = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0]!= '\0') {
            num_items++;
        }
    }

    int customer_choice[MAX_ITEMS];
    take_order(items, customer_choice, num_items);

    calculate_total(items, customer_choice, num_items);

    return 0;
}