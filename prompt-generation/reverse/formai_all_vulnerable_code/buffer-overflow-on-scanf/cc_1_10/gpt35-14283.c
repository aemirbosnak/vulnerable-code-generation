//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char name[20];
    double price;
    int quantity;
} Item;

double calculate_total(Item items[], int num_items);
void print_bar(char ch, int length);

int main() {
    int num_items;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    Item items[num_items];
    for(int i=0; i<num_items; i++) {
        printf("\nEnter the name of item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter the price of item %d: ", i+1);
        scanf("%lf", &items[i].price);
        printf("Enter the quantity of item %d: ", i+1);
        scanf("%d", &items[i].quantity);
    }

    double total = calculate_total(items, num_items);

    printf("\n\n\n\n***************************\n");
    printf("*  C Cafe Billing System  *\n");
    printf("***************************\n\n");

    printf("  Item Name\t\tPrice\tQuantity\tTotal\n");
    printf("  -----------------------------------------------------------\n");
    for(int i=0; i<num_items; i++) {
        printf("  %s\t\t\t%.2lf\t%d\t\t%.2lf\n", items[i].name, items[i].price, items[i].quantity, (items[i].price * items[i].quantity));
    }
    print_bar('-', 60);
    printf("  Total Bill: \t\t\t\t\t%.2lf\n", total);

    return 0;
}

double calculate_total(Item items[], int num_items) {
    double total = 0;
    for(int i=0; i<num_items; i++) {
        total += (items[i].price * items[i].quantity);
    }
    return total;
}

void print_bar(char ch, int length) {
    for(int i=0; i<length; i++) {
        printf("%c", ch);
    }
    printf("\n");
}