//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int cost;
} item;

void add_item(item* items, int count, char* name, int cost) {
    if (count >= MAX_ITEMS) {
        printf("Thou hast reached the limit of items thou canst add!\n");
        return;
    }
    strcpy(items[count].name, name);
    items[count].cost = cost;
    count++;
}

int main() {
    char input[100];
    int choice, count = 0;
    item items[MAX_ITEMS];

    printf("Welcome to the Personal Finance Planner, ser!\n");
    printf("What wouldst thou like to do first?\n");
    printf("1. Add an item\n2. View thy items\n3. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the name of the item thou wishest to add: ");
            scanf("%s", input);
            printf("Enter the cost of the item: ");
            scanf("%d", &items[count].cost);
            add_item(items, count, input, items[count].cost);
            break;
        case 2:
            printf("Thy items:\n");
            for (int i = 0; i < count; i++) {
                printf("%s - %d gold coins\n", items[i].name, items[i].cost);
            }
            break;
        case 3:
            printf("Farewell, ser! May thy finances be ever in thy favor.\n");
            break;
        default:
            printf("Invalid choice, ser.\n");
    }

    return 0;
}