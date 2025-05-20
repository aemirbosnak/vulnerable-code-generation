//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char price[MAX_PRICE_LENGTH];
} item;

void add_item(item* menu, int* num_items) {
    printf("Enter the name of the item: ");
    scanf("%s", menu[*num_items].name);
    printf("Enter the price of the item: ");
    scanf("%s", menu[*num_items].price);
    (*num_items)++;
}

void display_menu(item* menu, int num_items) {
    printf("Menu:\n");
    for(int i=0; i<num_items; i++) {
        printf("%d. %s - $%s\n", i+1, menu[i].name, menu[i].price);
    }
}

void take_order(item* menu, int num_items, char* order, int* num_items_ordered) {
    printf("Enter the items you want to order (separated by spaces): ");
    scanf("%s", order);
    char* token = strtok(order, " ");
    while(token!= NULL) {
        for(int i=0; i<num_items; i++) {
            if(strcmp(menu[i].name, token) == 0) {
                strcat(order, " ");
                strcat(order, menu[i].price);
            }
        }
        token = strtok(NULL, " ");
    }
    (*num_items_ordered) = strlen(order);
}

void calculate_total(char* order, int num_items_ordered, float* total) {
    char* token = strtok(order, " ");
    while(token!= NULL) {
        *total += atof(token);
        token = strtok(NULL, " ");
    }
}

int main() {
    item menu[MAX_ITEMS];
    int num_items = 0;
    add_item(menu, &num_items);
    add_item(menu, &num_items);
    add_item(menu, &num_items);

    char order[MAX_ITEMS*MAX_PRICE_LENGTH];
    int num_items_ordered = 0;
    take_order(menu, num_items, order, &num_items_ordered);

    float total = 0;
    calculate_total(order, num_items_ordered, &total);

    printf("Your order: %s\nTotal: $%.2f\n", order, total);

    return 0;
}