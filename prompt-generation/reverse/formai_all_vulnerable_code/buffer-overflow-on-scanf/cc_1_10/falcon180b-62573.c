//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_CATEGORY_LEN 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LEN + 1];
    char description[MAX_DESCRIPTION_LEN + 1];
    char category[MAX_CATEGORY_LEN + 1];
    int quantity;
} Item;

int main() {
    char filename[MAX_NAME_LEN + 1];
    FILE *file;
    Item items[MAX_ITEMS];
    int num_items = 0;

    printf("Enter the name of the inventory file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fscanf(file, "%s %s %s %d", items[num_items].name, items[num_items].description, items[num_items].category, &items[num_items].quantity) == 4) {
        num_items++;
        if (num_items >= MAX_ITEMS) {
            printf("Error: too many items in file.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    printf("Inventory:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s\n", i + 1, items[i].name);
        printf("\tDescription: %s\n", items[i].description);
        printf("\tCategory: %s\n", items[i].category);
        printf("\tQuantity: %d\n\n", items[i].quantity);
    }

    return 0;
}