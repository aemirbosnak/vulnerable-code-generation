//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[MAX_SIZE];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_SIZE];
    int size;
} Warehouse;

Warehouse* createWarehouse() {
    Warehouse* w = (Warehouse*)malloc(sizeof(Warehouse));
    w->size = 0;
    return w;
}

void addItem(Warehouse* w, int id, char* name, int quantity) {
    if (w->size >= MAX_SIZE) {
        printf("Warehouse is full!\n");
        return;
    }

    Item* i = &w->items[w->size];
    i->id = id;
    strcpy(i->name, name);
    i->quantity = quantity;
    w->size++;
}

void removeItem(Warehouse* w, int id) {
    for (int i = 0; i < w->size; i++) {
        if (w->items[i].id == id) {
            w->size--;
            for (int j = i; j < w->size; j++) {
                w->items[j] = w->items[j+1];
            }
            return;
        }
    }
    printf("Item not found!\n");
}

void displayItems(Warehouse* w) {
    printf("ID\tName\tQuantity\n");
    for (int i = 0; i < w->size; i++) {
        printf("%d\t%s\t%d\n", w->items[i].id, w->items[i].name, w->items[i].quantity);
    }
}

int main() {
    Warehouse* w = createWarehouse();

    addItem(w, 1, "Apples", 100);
    addItem(w, 2, "Oranges", 200);
    addItem(w, 3, "Bananas", 300);

    displayItems(w);

    removeItem(w, 2);

    displayItems(w);

    return 0;
}