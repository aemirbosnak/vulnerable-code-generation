//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char name[50];
    int quantity;
} Item;

Item* add_item(Item* items, const char* name, int quantity) {
    if (items == NULL || name == NULL) {
        return NULL;
    }
    Item new_item = {.name = name,.quantity = quantity};
    int i;
    for (i = 0; i < sizeof(items); i++) {
        if (strcmp(items[i].name, new_item.name) == 0) {
            break;
        }
    }
    if (i == sizeof(items)) {
        new_item.quantity = items[i-1].quantity + quantity;
        items[i] = new_item;
    } else {
        items[i] = new_item;
    }
    return items;
}

void remove_item(Item* items, const char* name) {
    int i;
    for (i = 0; i < sizeof(items); i++) {
        if (strcmp(items[i].name, name) == 0) {
            for (int j = i; j < sizeof(items); j++) {
                items[j] = items[j+1];
            }
            break;
        }
    }
}

void list_items(Item* items) {
    int i;
    for (i = 0; i < sizeof(items); i++) {
        printf("%s - %d\n", items[i].name, items[i].quantity);
    }
}

int main() {
    Item* items = NULL;
    const char* names[] = {"Widget", "Gizmo", "Doohickey"};
    int quantities[] = {10, 5, 3};
    int i;
    for (i = 0; i < sizeof(names); i++) {
        items = add_item(items, names[i], quantities[i]);
    }
    printf("Items in warehouse:\n");
    list_items(items);
    printf("Remove Widget:\n");
    remove_item(items, "Widget");
    printf("Items in warehouse:\n");
    list_items(items);
    printf("Remove Gizmo:\n");
    remove_item(items, "Gizmo");
    printf("Items in warehouse:\n");
    list_items(items);
    printf("Add 20 Doohickeys:\n");
    items = add_item(items, "Doohickey", 20);
    printf("Items in warehouse:\n");
    list_items(items);
    printf("Remove Doohickey:\n");
    remove_item(items, "Doohickey");
    printf("Items in warehouse:\n");
    list_items(items);
    return 0;
}