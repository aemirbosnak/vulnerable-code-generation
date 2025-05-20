//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    int due_date;
} item;

void add_item(item* arr, int size, char* name, float amount, int due_date) {
    if (size >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    strcpy(arr[size].name, name);
    arr[size].amount = amount;
    arr[size].due_date = due_date;
    size++;
}

void print_items(item* arr, int size) {
    printf("Item\tAmount\tDue Date\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%.2f\t%d\n", arr[i].name, arr[i].amount, arr[i].due_date);
    }
}

int get_item_index(item* arr, int size, char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    item items[MAX_ITEMS];
    int size = 0;

    add_item(items, size, "Rent", 1000, 10);
    add_item(items, size, "Electricity Bill", 200, 20);
    add_item(items, size, "Internet Bill", 100, 30);

    print_items(items, size);

    char search_name[50];
    printf("Enter the name of the item you want to search: ");
    scanf("%s", search_name);

    int index = get_item_index(items, size, search_name);
    if (index!= -1) {
        printf("Item found at index %d\n", index);
    } else {
        printf("Item not found.\n");
    }

    return 0;
}