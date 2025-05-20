//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 20
#define MAX_NAME 50
#define MAX_LINE 100

struct MenuItem {
    char name[MAX_NAME];
    int quantity;
    float price;
};

int main() {
    struct MenuItem menu[MAX_ITEMS];
    int num_items = 0;

    // Read menu file
    FILE *menu_file = fopen("menu.txt", "r");
    if (menu_file == NULL) {
        printf("Error: cannot open menu file\n");
        exit(1);
    }

    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, menu_file) != NULL) {
        if (num_items >= MAX_ITEMS) {
            printf("Error: too many items in menu\n");
            exit(1);
        }

        char *name = strtok(line, ",");
        int quantity = atoi(strtok(NULL, ","));
        float price = atof(strtok(NULL, ","));

        if (strlen(name) >= MAX_NAME) {
            printf("Error: item name too long\n");
            exit(1);
        }

        strcpy(menu[num_items].name, name);
        menu[num_items].quantity = quantity;
        menu[num_items].price = price;

        num_items++;
    }

    fclose(menu_file);

    // Main loop
    char choice[MAX_NAME];
    int order[MAX_ITEMS] = {0};
    float total = 0.0;

    printf("Welcome to the C Cafe!\n");
    while (1) {
        printf("\nMENU\n");
        printf("====\n");
        for (int i = 0; i < num_items; i++) {
            printf("%s ($%.2f)\n", menu[i].name, menu[i].price);
        }

        printf("\nYour order (or 'done' to finish): ");
        fgets(choice, MAX_NAME, stdin);
        choice[strlen(choice)-1] = '\0';

        if (strcmp(choice, "done") == 0) {
            break;
        }

        int item_index = -1;
        for (int i = 0; i < num_items; i++) {
            if (strcmp(choice, menu[i].name) == 0) {
                item_index = i;
                break;
            }
        }

        if (item_index == -1) {
            printf("Error: invalid menu item\n");
            continue;
        }

        int quantity;
        printf("Quantity: ");
        scanf("%d", &quantity);
        getchar(); // consume newline

        if (quantity <= 0) {
            printf("Error: invalid quantity\n");
            continue;
        }

        if (quantity > menu[item_index].quantity) {
            printf("Error: not enough stock\n");
            continue;
        }

        order[item_index] += quantity;
        menu[item_index].quantity -= quantity;
        total += quantity * menu[item_index].price;
    }

    // Print receipt
    printf("\nRECEIPT\n");
    printf("=======\n");
    for (int i = 0; i < num_items; i++) {
        if (order[i] > 0) {
            printf("%s x%d ($%.2f)\n", menu[i].name, order[i], order[i] * menu[i].price);
        }
    }

    printf("\nTotal: $%.2f\n", total);

    return 0;
}