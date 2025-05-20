//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    int quantity;
    float price;
} Item;

void read_items(Item items[]) {
    FILE *fp;
    char filename[20] = "items.txt";
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %d %f\n", items[count].name, items[count].description, &items[count].quantity, &items[count].price)!= EOF) {
        count++;
    }

    fclose(fp);
}

void display_items(Item items[]) {
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0]!= '\0') {
            printf("%-20s %-40s %d $%.2f\n", items[i].name, items[i].description, items[i].quantity, items[i].price);
        }
    }
}

void search_item(Item items[], char search_name[]) {
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, search_name) == 0) {
            printf("%s\n", items[i].description);
            return;
        }
    }
    printf("Item not found.\n");
}

int main() {
    Item items[MAX_ITEMS];
    read_items(items);

    char choice;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Display items\n");
        printf("2. Search item\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            display_items(items);
            break;
        case '2':
            printf("Enter item name: ");
            char search_name[MAX_NAME_LEN];
            scanf("%s", search_name);
            search_item(items, search_name);
            break;
        case '3':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '3');

    return 0;
}