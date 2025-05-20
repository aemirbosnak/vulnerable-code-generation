//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[20];
    int quantity;
    float price;
};

struct Customer {
    char name[20];
    char address[50];
    int phone_number;
};

struct Employee {
    char name[20];
    char position[20];
    int salary;
};

void display_items() {
    struct Item item;
    FILE *fp = fopen("items.txt", "r");
    fscanf(fp, "%s %d %f", item.name, &item.quantity, &item.price);
    fclose(fp);
    printf("Items:\n");
    printf("Name: %s\n", item.name);
    printf("Quantity: %d\n", item.quantity);
    printf("Price: %.2f\n", item.price);
}

void add_item() {
    struct Item item;
    FILE *fp = fopen("items.txt", "a");
    printf("Enter item name:");
    scanf("%s", item.name);
    printf("Enter item quantity:");
    scanf("%d", &item.quantity);
    printf("Enter item price:");
    scanf("%f", &item.price);
    fprintf(fp, "%s %d %f\n", item.name, item.quantity, item.price);
    fclose(fp);
    printf("Item added successfully.\n");
}

void edit_item() {
    struct Item item;
    FILE *fp = fopen("items.txt", "r");
    fscanf(fp, "%s %d %f", item.name, &item.quantity, &item.price);
    fclose(fp);
    printf("Enter item name:");
    scanf("%s", item.name);
    printf("Enter new item quantity:");
    scanf("%d", &item.quantity);
    printf("Enter new item price:");
    scanf("%f", &item.price);
    fp = fopen("items.txt", "w");
    fprintf(fp, "%s %d %f\n", item.name, item.quantity, item.price);
    fclose(fp);
    printf("Item edited successfully.\n");
}

void delete_item() {
    struct Item item;
    FILE *fp = fopen("items.txt", "r");
    fscanf(fp, "%s %d %f", item.name, &item.quantity, &item.price);
    fclose(fp);
    printf("Enter item name:");
    scanf("%s", item.name);
    fp = fopen("items.txt", "w");
    char *item_name = item.name;
    int i = 0;
    while (fscanf(fp, "%s %d %f", item.name, &item.quantity, &item.price) != EOF) {
        if (strcmp(item_name, item.name) != 0) {
            fprintf(fp, "%s %d %f\n", item.name, item.quantity, item.price);
        } else {
            i++;
        }
    }
    fclose(fp);
    if (i == 0) {
        printf("Item deleted successfully.\n");
    } else {
        printf("Error deleting item.\n");
    }
}

int main() {
    int choice;
    printf("Welcome to the Medical Store Management System.\n");
    printf("Please select an option:\n");
    printf("1. Display Items\n");
    printf("2. Add Item\n");
    printf("3. Edit Item\n");
    printf("4. Delete Item\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            display_items();
            break;
        case 2:
            add_item();
            break;
        case 3:
            edit_item();
            break;
        case 4:
            delete_item();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}