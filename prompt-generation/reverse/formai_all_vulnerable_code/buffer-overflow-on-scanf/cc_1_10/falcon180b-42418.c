//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10

struct item {
    char name[50];
    char category[20];
    int quantity;
    float price;
};

struct item items[MAX_ITEMS];
char categories[MAX_CATEGORIES][20];
int num_items = 0;
int num_categories = 0;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);

    printf("Enter item category: ");
    scanf("%s", items[num_items].category);

    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);

    num_items++;
}

void view_items() {
    printf("\nItem List:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - %s - %d - $%.2f\n", i+1, items[i].name, items[i].category, items[i].quantity, items[i].price);
    }
}

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories]);

    num_categories++;
}

void view_categories() {
    printf("\nCategory List:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s\n", i+1, categories[i]);
    }
}

int main() {
    printf("Welcome to the Medical Store Management System!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add item\n");
        printf("2. View item list\n");
        printf("3. Add category\n");
        printf("4. View category list\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                view_items();
                break;
            case 3:
                add_category();
                break;
            case 4:
                view_categories();
                break;
            case 5:
                printf("Thank you for using the Medical Store Management System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}