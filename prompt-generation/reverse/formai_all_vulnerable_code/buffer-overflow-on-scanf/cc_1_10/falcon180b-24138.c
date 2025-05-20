//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    int category;
} item;

item items[MAX_ITEMS];
int num_items;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter amount: $");
    scanf("%f", &items[num_items].amount);
    printf("Enter category (0-9): ");
    scanf("%d", &items[num_items].category);
    num_items++;
}

void display_items() {
    printf("\nItem\tAmount\tCategory\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t$%.2f\t%d\n", items[i].name, items[i].amount, items[i].category);
    }
}

void sort_items() {
    for (int i = 0; i < num_items - 1; i++) {
        for (int j = i + 1; j < num_items; j++) {
            if (items[i].amount > items[j].amount) {
                item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    printf("Welcome to the Personal Finance Planner!\n\n");
    num_items = 0;
    while (num_items < MAX_ITEMS) {
        printf("\nEnter 1 to add an item, 2 to display items, 3 to sort items, or any other key to exit: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_items();
                break;
            case 3:
                sort_items();
                display_items();
                break;
            default:
                printf("Exiting program...\n");
                return 0;
        }
    }
    return 0;
}