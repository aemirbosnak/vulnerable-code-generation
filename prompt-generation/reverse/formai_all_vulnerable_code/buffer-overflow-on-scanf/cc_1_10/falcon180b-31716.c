//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

// Item structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

// Function to compare two items based on their names
int compare_items(const void *a, const void *b) {
    const Item *item1 = a;
    const Item *item2 = b;

    return strcmp(item1->name, item2->name);
}

// Function to print the item details
void print_item(const Item *item) {
    printf("Name: %s\n", item->name);
    printf("Quantity: %d\n", item->quantity);
    printf("Price: %.2f\n", item->price);
}

// Function to search for an item in the list
int search_item(Item *items, int num_items, const char *name) {
    qsort(items, num_items, sizeof(Item), compare_items);

    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            print_item(&items[i]);
            return 1;
        }
    }

    printf("Item not found.\n");
    return 0;
}

int main() {
    Item items[MAX_ITEMS];
    int num_items = 0;

    // Add some items to the list
    items[num_items++] = (Item) {"Apple", 10, 1.00};
    items[num_items++] = (Item) {"Banana", 5, 0.50};
    items[num_items++] = (Item) {"Pear", 2, 1.50};

    // Search for an item
    char search_name[MAX_NAME_LENGTH];
    printf("Enter the name of the item to search for: ");
    scanf("%s", search_name);

    search_item(items, num_items, search_name);

    return 0;
}