//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: real-life
#include <stdio.h>
#include <string.h>

// Define the structure of a medicine item
typedef struct MedicineItem {
    char name[20];
    int quantity;
    float price;
} MedicineItem;

// Define the function to add a medicine item to the store
void addItem(MedicineItem *item) {
    printf("Enter the name of the medicine item: ");
    scanf("%s", item->name);
    printf("Enter the quantity of the medicine item: ");
    scanf("%d", &item->quantity);
    printf("Enter the price of the medicine item: ");
    scanf("%f", &item->price);
}

// Define the function to display all medicine items in the store
void displayItems(MedicineItem *items, int numItems) {
    for (int i = 0; i < numItems; i++) {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

// Define the function to search for a medicine item in the store
void searchItem(MedicineItem *items, int numItems) {
    char searchName[20];
    printf("Enter the name of the medicine item you are searching for: ");
    scanf("%s", searchName);

    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, searchName) == 0) {
            printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

int main() {
    // Create an array of medicine items
    MedicineItem items[10];

    // Initialize the number of medicine items to 0
    int numItems = 0;

    // Add a few medicine items to the store
    addItem(&items[numItems++]);
    addItem(&items[numItems++]);
    addItem(&items[numItems++]);

    // Display all medicine items in the store
    displayItems(items, numItems);

    // Search for a medicine item in the store
    searchItem(items, numItems);

    return 0;
}