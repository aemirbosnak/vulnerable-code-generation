//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_MENU_ITEMS 10
#define MIN_ORDER_SIZE 3

typedef struct {
    char name[50];
    float price;
} MenuItem;

void print_menu(MenuItem menu[], int size);
void place_order(MenuItem menu[], float *total_cost, int *num_items);

int main() {
    MenuItem menu[MAX_MENU_ITEMS];
    float total_cost = 0.0f;
    int num_items = 0;

    for (int i = 0; i < MAX_MENU_ITEMS; ++i) {
        printf("Enter menu item %d name: ", i + 1);
        scanf("%s", menu[i].name);
        printf("Enter menu item %d price: ", i + 1);
        scanf("%f", &menu[i].price);
    }

    print_menu(menu, MAX_MENU_ITEMS);
    place_order(menu, &total_cost, &num_items);

    printf("Total cost: $%.2f\n", total_cost);
    printf("Number of items ordered: %d\n", num_items);

    return 0;
}

void print_menu(MenuItem menu[], int size) {
    printf("\n--- MENU ---\n");
    for (int i = 0; i < size; ++i) {
        printf("%s - $%.2f\n", menu[i].name, menu[i].price);
    }
}

void place_order(MenuItem menu[], float *total_cost, int *num_items) {
    int i;
    char name[50];

    for (i = 0; i < MIN_ORDER_SIZE; ++i) {
        printf("Enter item %d name: ", i + 1);
        scanf("%s", name);

        for (int j = 0; j < MAX_MENU_ITEMS; ++j) {
            if (strcmp(menu[j].name, name) == 0) {
                (*total_cost) += menu[j].price;
                (*num_items)++;
                break;
            }
        }
    }
}