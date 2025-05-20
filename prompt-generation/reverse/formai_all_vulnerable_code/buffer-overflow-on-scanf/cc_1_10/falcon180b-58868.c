//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

void addItem(Item items[], int *size) {
    printf("Enter item name: ");
    scanf("%s", (*size == MAX_ITEMS - 1)? "" : items[*size].name);
    printf("Enter item price: ");
    scanf("%f", &items[*size].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[*size].quantity);
    (*size)++;
}

void displayItems(Item items[], int size) {
    printf("\nItem List:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f - %d\n", i+1, items[i].name, items[i].price, items[i].quantity);
    }
}

void searchItem(Item items[], int size) {
    char searchName[50];
    printf("\nEnter item name to search: ");
    scanf("%s", searchName);
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(items[i].name, searchName) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nItem not found.\n");
    } else {
        printf("\nItem found at position %d:\n", index+1);
        printf("%s - $%.2f - %d\n", items[index].name, items[index].price, items[index].quantity);
    }
}

void updateItem(Item items[], int size) {
    int index;
    printf("\nEnter item index to update: ");
    scanf("%d", &index);
    if (index >= 0 && index < size) {
        printf("\nEnter new item name: ");
        scanf("%s", items[index].name);
        printf("Enter new item price: ");
        scanf("%f", &items[index].price);
        printf("Enter new item quantity: ");
        scanf("%d", &items[index].quantity);
    } else {
        printf("\nInvalid item index.\n");
    }
}

void deleteItem(Item items[], int *size) {
    int index;
    printf("\nEnter item index to delete: ");
    scanf("%d", &index);
    if (index >= 0 && index < *size) {
        for (int i = index; i < *size-1; i++) {
            items[i] = items[i+1];
        }
        (*size)--;
    } else {
        printf("\nInvalid item index.\n");
    }
}

int main() {
    Item items[MAX_ITEMS];
    int size = 0;

    addItem(items, &size);
    addItem(items, &size);
    addItem(items, &size);

    displayItems(items, size);

    searchItem(items, size);

    updateItem(items, size);

    deleteItem(items, &size);

    displayItems(items, size);

    return 0;
}