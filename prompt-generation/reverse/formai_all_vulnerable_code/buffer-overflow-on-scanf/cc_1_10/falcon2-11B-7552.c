//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int id;
    char name[50];
    float price;
} item;

int main() {
    item items[10];
    int num_items = 0;
    int item_id = 1;

    printf("Welcome to the Warehouse Management System!\n");
    printf("-----------------------------------------\n");

    printf("Enter the number of items:\n");
    int num_items_input;
    scanf("%d", &num_items_input);

    while (num_items < num_items_input) {
        printf("Enter item %d details:\n", item_id);

        printf("ID: ");
        scanf("%d", &items[num_items].id);

        printf("Name: ");
        scanf("%s", items[num_items].name);

        printf("Price: ");
        scanf("%f", &items[num_items].price);

        num_items++;
        item_id++;
    }

    printf("Enter item details to add:\n");

    printf("ID: ");
    scanf("%d", &items[num_items].id);

    printf("Name: ");
    scanf("%s", items[num_items].name);

    printf("Price: ");
    scanf("%f", &items[num_items].price);

    num_items++;

    printf("-----------------------------------------\n");

    printf("Here are the items in the warehouse:\n");
    for (int i = 0; i < num_items; i++) {
        printf("ID: %d, Name: %s, Price: $%.2f\n", items[i].id, items[i].name, items[i].price);
    }

    printf("-----------------------------------------\n");

    printf("Do you want to add more items? (Y/N): ");
    char response;
    scanf(" %c", &response);

    if (response == 'Y' || response == 'y') {
        printf("Enter item details to add:\n");

        printf("ID: ");
        scanf("%d", &items[num_items].id);

        printf("Name: ");
        scanf("%s", items[num_items].name);

        printf("Price: ");
        scanf("%f", &items[num_items].price);

        num_items++;
    } else {
        printf("Goodbye!\n");
    }

    return 0;
}