//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} item;

void add_item(item *list, int *size) {
    char input[100];
    printf("Enter item name: ");
    scanf("%s", input);
    strcpy(list[*size].name, input);
    printf("Enter item price: ");
    scanf("%f", &list[*size].price);
    printf("Enter item quantity: ");
    scanf("%d", &list[*size].quantity);
    (*size)++;
}

void display_items(item *list, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s - $%.2f - %d\n", list[i].name, list[i].price, list[i].quantity);
    }
}

void calculate_total(item *list, int size) {
    int i;
    float total = 0.0;
    for (i = 0; i < size; i++) {
        total += list[i].price * list[i].quantity;
    }
    printf("Total cost: $%.2f\n", total);
}

int main() {
    item list[MAX_ITEMS];
    int size = 0;

    while (size < MAX_ITEMS) {
        printf("\n1. Add item\n2. Display items\n3. Calculate total\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(list, &size);
                break;
            case 2:
                display_items(list, size);
                break;
            case 3:
                calculate_total(list, size);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}