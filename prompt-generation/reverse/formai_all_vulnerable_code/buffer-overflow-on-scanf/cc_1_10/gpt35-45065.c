//FormAI DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE 1000
#define MAX_QUANTITY 100
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
    char description[MAX_DESCRIPTION_LENGTH];
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    Item item;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter item price: $");
    scanf("%f", &item.price);
    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);
    printf("Enter item description (max 100 characters): ");
    scanf(" %[^\n]s", item.description); // read until newline char
    if (num_items < MAX_ITEMS) {
        items[num_items++] = item;
        printf("\nItem added to inventory!\n");
    } else {
        printf("\nInventory is full!\n");
    }
}

void display_items() {
    printf("Name\t\tPrice\tQuantity\tDescription\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t$%.2f\t%d\t\t%s\n", items[i].name, items[i].price, items[i].quantity, items[i].description);
    }
}

void sell_item() {
    char name[MAX_NAME_LENGTH];
    printf("Enter item name: ");
    scanf("%s", name);
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            int quantity;
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);
            if (quantity <= items[i].quantity) {
                items[i].quantity -= quantity;
                float total_price = quantity * items[i].price;
                printf("\nSold %d %ss for $%.2f\n", quantity, items[i].name, total_price);
                return;
            } else {
                printf("\nNot enough %ss in inventory!\n", items[i].name);
                return;
            }
        }
    }
    printf("\nItem not found in inventory!\n");
}

void restock_item() {
    char name[MAX_NAME_LENGTH];
    printf("Enter item name: ");
    scanf("%s", name);
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            int quantity;
            printf("Enter quantity to restock: ");
            scanf("%d", &quantity);
            if ((items[i].quantity + quantity) <= MAX_QUANTITY) {
                items[i].quantity += quantity;
                printf("\nRestocked %d %ss\n", quantity, items[i].name);
                return;
            } else {
                printf("\nInventory capacity exceeded!\n");
                return;
            }
        }
    }
    printf("\nItem not found in inventory!\n");
}

void random_event() {
    int event = rand() % 3; // generate random number between 0-2
    switch (event) {
        case 0: // inventory stolen
            printf("Your inventory has been stolen!\n");
            num_items = 0;
            break;
        case 1: // food gone bad
            for (int i = 0; i < num_items; i++) {
                if (strcmp(items[i].description, "food") == 0) {
                    items[i].quantity /= 2;
                    printf("Half of your %s has gone bad!\n", items[i].name);
                }
            }
            break;
        case 2: // new shipment
            if (num_items < MAX_ITEMS) {
                Item item;
                strcpy(item.name, "Supply Crate");
                item.price = MAX_PRICE;
                item.quantity = MAX_QUANTITY;
                strcpy(item.description, "mystery items");
                items[num_items++] = item;
                printf("A new shipment has arrived!\n");
            }
            break;
        default:
            break;
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator
    int choice;
    do {
        printf("\n1. Add item to inventory\n2. Display inventory\n3. Sell item\n4. Restock item\n5. Random event\n6. Quit\n\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_items();
                break;
            case 3:
                sell_item();
                break;
            case 4:
                restock_item();
                break;
            case 5:
                random_event();
                break;
            case 6:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != 6);
    return 0;
}