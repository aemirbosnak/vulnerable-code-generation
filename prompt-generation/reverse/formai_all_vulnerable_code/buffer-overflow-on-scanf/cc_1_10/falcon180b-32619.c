//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10

struct item {
    char name[50];
    char category[20];
    float price;
    int quantity;
};

struct category {
    char name[20];
    int count;
};

struct item items[MAX_ITEMS];
struct category categories[MAX_CATEGORIES];

int num_items = 0;
int num_categories = 0;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);

    printf("Enter item category: ");
    scanf("%s", items[num_items].category);

    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);

    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);

    num_items++;
}

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);

    num_categories++;
}

void display_items() {
    printf("\nItem List:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - %s - $%.2f - %d\n", i+1, items[i].name, items[i].category, items[i].price, items[i].quantity);
    }
}

void display_categories() {
    printf("\nCategory List:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s\n", i+1, categories[i].name);
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Add item\n2. Add category\n3. Display items\n4. Display categories\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                add_category();
                break;
            case 3:
                display_items();
                break;
            case 4:
                display_categories();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}