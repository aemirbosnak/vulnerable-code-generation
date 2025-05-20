//Gemma-7B DATASET v1.0 Category: Database querying ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LENGTH 255

typedef struct Item {
    char name[50];
    int quantity;
    double price;
} Item;

int main() {

    // Create an array of items
    Item items[] = {
        {"Apple", 10, 1.20},
        {"Banana", 8, 1.30},
        {"Orange", 12, 1.40},
        {"Pear", 6, 1.50},
        {"Grape", 9, 1.60}
    };

    // Define the query language
    char query[MAX_QUERY_LENGTH];

    // Get the query from the user
    printf("Enter your query: ");
    scanf("%s", query);

    // Parse the query
    char *keywords = strsep(query, " ");
    char *filters = strsep(keywords, "=");
    char *values = strsep(filters, ";");

    // Create a list of matching items
    int matchingItems = 0;
    for (int i = 0; i < 5; i++) {
        int itemQuantity = items[i].quantity;
        double itemPrice = items[i].price;
        char *itemName = items[i].name;

        // Check if the item name matches the query
        if (strstr(itemName, keywords) != NULL) {
            // Check if the item quantity matches the filter
            if (filters && itemQuantity >= atoi(values)) {
                // Check if the item price matches the filter
                if (filters && itemPrice <= atof(values)) {
                    matchingItems++;
                }
            }
        }
    }

    // Print the matching items
    if (matchingItems > 0) {
        printf("Matching items:\n");
        for (int i = 0; i < matchingItems; i++) {
            printf("%s (%d) - $%.2lf\n", items[i].name, items[i].quantity, items[i].price);
        }
    } else {
        printf("No items found.\n");
    }

    return 0;
}