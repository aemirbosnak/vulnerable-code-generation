//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSES 100
#define MAX_ITEMS 100
#define MAX_QUANTITY 999

typedef struct {
 char name[50];
 int stock;
} Item_t;

typedef struct {
 char id[10];
 Item_t items[MAX_ITEMS];
} Warehouse_t;

void initWarehouse(Warehouse_t *wh, char *id) {
 strcpy(wh->id, id);
 memset(wh->items, 0, sizeof(wh->items));
}

void addItem(Warehouse_t *wh, char *name, int qty) {
 int i;
 for (i = 0; i < MAX_ITEMS; i++) {
 if (wh->items[i].stock == 0) {
 strcpy(wh->items[i].name, name);
 wh->items[i].stock = qty;
 break;
 }
 }
 if (i == MAX_ITEMS) {
 fprintf(stderr, "Warehouse %s is full\n", wh->id);
 exit(EXIT_FAILURE);
 }
}

void removeItem(Warehouse_t *wh, char *name) {
 int i;
 for (i = 0; i < MAX_ITEMS; i++) {
 if (strcmp(wh->items[i].name, name) == 0) {
 wh->items[i].stock = 0;
 break;
 }
 }
 if (i == MAX_ITEMS) {
 fprintf(stderr, "Item %s not found in warehouse %s\n", name, wh->id);
 exit(EXIT_FAILURE);
 }
}

void displayInventory(Warehouse_t *wh) {
 int i;
 printf("Inventory of warehouse %s:\n", wh->id);
 for (i = 0; i < MAX_ITEMS; i++) {
 if (wh->items[i].stock > 0) {
 printf("%s: %d\n", wh->items[i].name, wh->items[i].stock);
 }
 }
}

int main() {
 Warehouse_t warehouses[MAX_WAREHOUSES];
 int i, j;
 char id[10], name[50];
 int qty;
 for (i = 0; i < MAX_WAREHOUSES; i++) {
 printf("Enter id for warehouse %d: ", i + 1);
 scanf("%s", id);
 initWarehouse(&warehouses[i], id);
 }
 for (i = 0; i < MAX_WAREHOUSES; i++) {
 for (j = 0; j < 3; j++) {
 printf("Enter name and quantity for item %d in warehouse %s:\n", j + 1, warehouses[i].id);
 scanf("%s%d", name, &qty);
 addItem(&warehouses[i], name, qty);
 }
 }
 for (i = 0; i < MAX_WAREHOUSES; i++) {
 printf("Inventory of warehouse %s:\n", warehouses[i].id);
 displayInventory(&warehouses[i]);
 }
 for (i = 0; i < MAX_WAREHOUSES; i++) {
 printf("Enter name of item to remove from warehouse %s: ", warehouses[i].id);
 scanf("%s", name);
 removeItem(&warehouses[i], name);
 }
 for (i = 0; i < MAX_WAREHOUSES; i++) {
 printf("Inventory of warehouse %s:\n", warehouses[i].id);
 displayInventory(&warehouses[i]);
 }
 return EXIT_SUCCESS;
}