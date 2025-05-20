//Falcon-180B DATASET v1.0 Category: Error handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_NUM_ITEMS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
} item_t;

int main() {
    int num_items;
    item_t items[MAX_NUM_ITEMS];
    int i, j;
    char filename[MAX_NAME_LENGTH];
    FILE* fp;

    // Prompt user for number of items
    printf("Enter number of items: ");
    scanf("%d", &num_items);

    // Prompt user for item details
    for (i = 0; i < num_items; i++) {
        printf("Enter item name (%d): ", i+1);
        scanf("%s", items[i].name);
        printf("Enter item quantity: ");
        scanf("%d", &items[i].quantity);
        printf("Enter item price: ");
        scanf("%lf", &items[i].price);
    }

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file %s.\n", filename);
        exit(1);
    }

    // Write items to file
    for (i = 0; i < num_items; i++) {
        fprintf(fp, "Item %d:\n", i+1);
        fprintf(fp, "Name: %s\n", items[i].name);
        fprintf(fp, "Quantity: %d\n", items[i].quantity);
        fprintf(fp, "Price: $%.2f\n\n", items[i].price);
    }

    // Close file
    fclose(fp);

    return 0;
}