//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} Item;

int main() {
    int numItems;
    Item items[MAX_ITEMS];
    char input[100];
    char delimiter = ',';
    FILE *fp;

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    for (int i = 0; i < numItems; i++) {
        printf("Enter item %d name: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter item %d amount: ", i+1);
        scanf("%s", items[i].amount);
    }

    printf("Enter the filename to save the data: ");
    scanf("%s", input);

    fp = fopen(input, "w");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    fprintf(fp, "Item Name,Amount\n");

    for (int i = 0; i < numItems; i++) {
        fprintf(fp, "%s,%s\n", items[i].name, items[i].amount);
    }

    fclose(fp);

    printf("Data saved to file.\n");

    return 0;
}