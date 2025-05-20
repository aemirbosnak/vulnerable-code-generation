//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_DESCRIPTION_LEN 200

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
    float price;
} Item;

void read_items(Item items[]) {
    FILE *fp;
    int i = 0;
    fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open items file.\n");
        exit(1);
    }
    while (fscanf(fp, "%s %s %s %d %f\n", items[i].name, items[i].category, items[i].description, &items[i].quantity, &items[i].price)!= EOF) {
        i++;
        if (i >= MAX_ITEMS) {
            printf("Error: too many items in file.\n");
            exit(1);
        }
    }
    fclose(fp);
}

void print_items(Item items[]) {
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0]!= '\0') {
            printf("%s | %s | %s | %d | $%.2f\n", items[i].name, items[i].category, items[i].description, items[i].quantity, items[i].price);
        }
    }
}

int main() {
    Item items[MAX_ITEMS];
    int choice;
    do {
        printf("1. Read items from file\n");
        printf("2. Print items\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                read_items(items);
                printf("Items read successfully.\n");
                break;
            case 2:
                print_items(items);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);
    return 0;
}