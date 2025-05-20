//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    char description[100];
    float price;
    int quantity;
} Item;

void display_menu() {
    printf("\n");
    printf("1. Add item\n");
    printf("2. Update item\n");
    printf("3. Delete item\n");
    printf("4. View items\n");
    printf("5. Exit\n");
    printf("\n");
}

int main() {
    FILE *fp;
    int choice, i;
    char filename[50] = "items.dat";
    Item items[MAX_ITEMS];

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    fread(&items, sizeof(Item), MAX_ITEMS, fp);
    fclose(fp);

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &items[i].id);
                printf("Enter item name: ");
                scanf("%s", items[i].name);
                printf("Enter item description: ");
                scanf("%s", items[i].description);
                printf("Enter item price: ");
                scanf("%f", &items[i].price);
                printf("Enter item quantity: ");
                scanf("%d", &items[i].quantity);
                i++;
                break;
            case 2:
                printf("Enter item ID to update: ");
                scanf("%d", &items[i-1].id);
                printf("Enter new item name: ");
                scanf("%s", items[i-1].name);
                printf("Enter new item description: ");
                scanf("%s", items[i-1].description);
                printf("Enter new item price: ");
                scanf("%f", &items[i-1].price);
                printf("Enter new item quantity: ");
                scanf("%d", &items[i-1].quantity);
                break;
            case 3:
                printf("Enter item ID to delete: ");
                scanf("%d", &items[i-1].id);
                for (int j = i-1; j < MAX_ITEMS-1; j++) {
                    items[j] = items[j+1];
                }
                i--;
                break;
            case 4:
                printf("\n");
                for (int j = 0; j < i; j++) {
                    printf("%d. %s - $%.2f - %d\n", items[j].id, items[j].name, items[j].price, items[j].quantity);
                }
                break;
            case 5:
                printf("Exiting...\n");
                fwrite(items, sizeof(Item), i, fp);
                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}