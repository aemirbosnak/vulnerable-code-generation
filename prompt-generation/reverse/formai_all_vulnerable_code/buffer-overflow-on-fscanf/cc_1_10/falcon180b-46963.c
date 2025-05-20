//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    double amount;
} item_t;

item_t items[MAX_ITEMS];
int num_items = 0;

void add_item(char* name, double amount) {
    if (num_items >= MAX_ITEMS) {
        printf("Sorry, maximum number of items reached.\n");
        return;
    }
    strcpy(items[num_items].name, name);
    items[num_items].amount = amount;
    num_items++;
}

void remove_item(int index) {
    if (index < 0 || index >= num_items) {
        printf("Invalid item index.\n");
        return;
    }
    num_items--;
    for (int i = index; i < num_items; i++) {
        strcpy(items[i].name, items[i+1].name);
        items[i].amount = items[i+1].amount;
    }
}

void display_items() {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: $%.2f\n", items[i].name, items[i].amount);
    }
}

void save_items(char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error saving items.\n");
        return;
    }
    fprintf(file, "%d\n", num_items);
    for (int i = 0; i < num_items; i++) {
        fprintf(file, "%s $%.2f\n", items[i].name, items[i].amount);
    }
    fclose(file);
}

void load_items(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error loading items.\n");
        return;
    }
    fscanf(file, "%d", &num_items);
    for (int i = 0; i < num_items; i++) {
        fscanf(file, "%s $%.2f", items[i].name, &items[i].amount);
    }
    fclose(file);
}

int main() {
    add_item("Salary", 5000);
    add_item("Rent", 1500);
    add_item("Groceries", 400);
    display_items();
    save_items("items.txt");
    load_items("items.txt");
    display_items();
    remove_item(1);
    display_items();
    save_items("items.txt");
    load_items("items.txt");
    display_items();
    return 0;
}