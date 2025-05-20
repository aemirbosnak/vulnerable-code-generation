//FormAI DATASET v1.0 Category: Data mining ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_ITEMS 100

typedef struct {
    char name[MAX_STRING_LENGTH];
    int quantity;
    float price;
} Item;

int main() {
    char filename[MAX_STRING_LENGTH];
    FILE *file;
    Item items[MAX_ITEMS];
    int num_items = 0;

    // Get filename from user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read data from file
    char line[MAX_STRING_LENGTH];
    while (fgets(line, MAX_STRING_LENGTH, file)) {
        char *token = strtok(line, ",");
        strcpy(items[num_items].name, token);

        token = strtok(NULL, ",");
        items[num_items].quantity = atoi(token);

        token = strtok(NULL, ",");
        items[num_items].price = atof(token);

        num_items++;
    }

    // Close file
    fclose(file);

    // Print all items
    printf("\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item %d:\n", i+1);
        printf("Name: %s\n", items[i].name);
        printf("Quantity: %d\n", items[i].quantity);
        printf("Price: $%.2f\n", items[i].price);
        printf("\n");
    }

    return 0;
}