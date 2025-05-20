//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 30
#define MAX_PRICE_LEN 8

typedef struct {
    char name[MAX_NAME_LEN+1];
    char price[MAX_PRICE_LEN+1];
} item_t;

item_t items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    printf("Enter name of item: ");
    scanf("%s", items[num_items].name);

    printf("Enter price of item: ");
    scanf("%s", items[num_items].price);

    num_items++;
}

void print_items() {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - %s\n", items[i].name, items[i].price);
    }
}

void calculate_total() {
    double total = 0.0;
    printf("Calculating total...\n");
    for (int i = 0; i < num_items; i++) {
        total += atof(items[i].price);
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    int choice;
    char choice_str[10];

    printf("Welcome to the Cafe Billing System!\n");

    while (1) {
        printf("Enter choice (A-add item, P-print items, T-calculate total, Q-quit): ");
        scanf("%s", choice_str);
        choice = tolower(choice_str[0]);

        switch (choice) {
            case 'a':
            case 'A':
                add_item();
                break;
            case 'p':
            case 'P':
                print_items();
                break;
            case 't':
            case 'T':
                calculate_total();
                break;
            case 'q':
            case 'Q':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}