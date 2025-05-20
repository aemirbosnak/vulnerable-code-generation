//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_AMOUNT_LEN 10
#define MAX_DATE_LEN 20
#define MAX_NOTES_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char amount[MAX_AMOUNT_LEN];
    char date[MAX_DATE_LEN];
    char notes[MAX_NOTES_LEN];
} Item;

int main() {
    int num_items = 0;
    Item items[MAX_ITEMS];

    while (num_items < MAX_ITEMS) {
        printf("Enter item name (up to %d characters): ", MAX_NAME_LEN - 1);
        scanf("%s", items[num_items].name);

        printf("Enter item category (up to %d characters): ", MAX_CATEGORY_LEN - 1);
        scanf("%s", items[num_items].category);

        printf("Enter item amount (up to %d characters): ", MAX_AMOUNT_LEN - 1);
        scanf("%s", items[num_items].amount);

        printf("Enter item date (up to %d characters): ", MAX_DATE_LEN - 1);
        scanf("%s", items[num_items].date);

        printf("Enter item notes (up to %d characters): ", MAX_NOTES_LEN - 1);
        scanf("%s", items[num_items].notes);

        num_items++;
    }

    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\n", items[i].name);
        printf("%s\n", items[i].category);
        printf("%s\n", items[i].amount);
        printf("%s\n", items[i].date);
        printf("%s\n", items[i].notes);
        printf("\n");
    }

    return 0;
}