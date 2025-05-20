//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 2048
#define MAX_NAME_LEN 256

typedef enum {ASCENDING, DESCENDING} SortOrder;

typedef struct {
    char name[MAX_NAME_LEN];
    int id;
    float value;
} Item;

// Function prototypes
void initializeItems(Item items[], int count);
void displayItems(Item items[], int count);
int compareAsc(const void* a, const void* b);
int compareDesc(const void* a, const void* b);
void sortItems(Item items[], int count, SortOrder order);

int main() {
    int count;
    printf("Welcome to the Quantum Item Sorting Simulator!\n");
    printf("Enter the number of items (max %d): ", MAX_ITEMS);
    scanf("%d", &count);

    if (count < 1 || count > MAX_ITEMS) {
        fprintf(stderr, "Invalid number of items. Exiting...\n");
        return 1;
    }

    Item items[MAX_ITEMS];
    initializeItems(items, count);

    printf("\nItems before sorting:\n");
    displayItems(items, count);

    char choice;
    printf("\nChoose sorting order: (A)scending or (D)escending: ");
    scanf(" %c", &choice);
    SortOrder order = (choice == 'A' || choice == 'a') ? ASCENDING : DESCENDING;

    sortItems(items, count, order);
    
    printf("\nItems after sorting:\n");
    displayItems(items, count);

    printf("\nThank you for using the Quantum Item Sorting Simulator. \n");
    return 0;
}

void initializeItems(Item items[], int count) {
    for (int i = 0; i < count; i++) {
        snprintf(items[i].name, MAX_NAME_LEN, "Item_%d", i + 1);
        items[i].id = i + 1;
        items[i].value = (float)(rand() % 1000) / 10.0; // Random float value between 0.0 and 100.0
    }
}

void displayItems(Item items[], int count) {
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Value: %.2f\n", items[i].id, items[i].name, items[i].value);
    }
}

int compareAsc(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;
    return (itemA->value > itemB->value) - (itemA->value < itemB->value);
}

int compareDesc(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;
    return (itemA->value < itemB->value) - (itemA->value > itemB->value);
}

void sortItems(Item items[], int count, SortOrder order) {
    if (order == ASCENDING) {
        qsort(items, count, sizeof(Item), compareAsc);
    } else {
        qsort(items, count, sizeof(Item), compareDesc);
    }
}