//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    char category[20];
} item;

void add_item(item items[], int num_items) {
    char input[100];
    printf("Enter item name: ");
    scanf("%s", input);
    strcpy(items[num_items].name, input);
    printf("Enter item amount: ");
    scanf("%f", &items[num_items].amount);
    printf("Enter item category: ");
    scanf("%s", items[num_items].category);
    num_items++;
}

void display_items(item items[], int num_items) {
    printf("Item Name\tAmount\tCategory\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%.2f\t%s\n", items[i].name, items[i].amount, items[i].category);
    }
}

void sort_items(item items[], int num_items) {
    for (int i = 0; i < num_items - 1; i++) {
        for (int j = i + 1; j < num_items; j++) {
            if (strcmp(items[i].category, items[j].category) > 0) {
                item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    item items[MAX_ITEMS];
    int num_items = 0;

    while (num_items < MAX_ITEMS) {
        printf("1. Add item\n2. Display items\n3. Sort items\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item(items, num_items);
                break;
            case 2:
                display_items(items, num_items);
                break;
            case 3:
                sort_items(items, num_items);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}