//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 99

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void load_inventory_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_NAME_LENGTH + MAX_QUANTITY + 2]; // +2 for '\0' and '\n'

    while (fgets(line, sizeof(line), file)) {
        char *name_start = line;
        int name_length = 0;
        int quantity = 0;

        while (*name_start && isalpha(*name_start)) {
            name_start++;
            name_length++;
        }

        *name_start++ = '\0'; // terminate name string
        sscanf(name_start, "%d", &quantity);

        if (num_products >= MAX_PRODUCTS) {
            printf("Error: Maximum number of products reached.\n");
            exit(1);
        }

        strncpy(inventory[num_products].name, name_start - name_start, name_length);
        inventory[num_products++].quantity = quantity;
    }

    fclose(file);
}

void save_inventory_file(const char *filename) {
    FILE *file = fopen(filename, "w");

    for (int i = 0; i < num_products; i++) {
        fprintf(file, "%s %d\n", inventory[i].name, inventory[i].quantity);
    }

    fclose(file);
}

void display_inventory() {
    printf("\nCurrent Inventory:\n");

    for (int i = 0; i < num_products; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    const char *filename = "inventory.txt";

    load_inventory_file(filename);
    display_inventory();

    // Add, remove or modify products interactively here...

    save_inventory_file(filename);

    return 0;
}