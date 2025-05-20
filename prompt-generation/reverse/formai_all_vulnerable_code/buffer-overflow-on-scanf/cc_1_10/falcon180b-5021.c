//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    double amount;
} item_t;

void add_item(item_t *items, int num_items, char *name, char *category, double amount) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Max number of items reached.\n");
        return;
    }

    strcpy(items[num_items].name, name);
    strcpy(items[num_items].category, category);
    items[num_items].amount = amount;

    num_items++;
}

void print_items(item_t *items, int num_items) {
    printf("Item\tCategory\tAmount\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%s\t%.2f\n", items[i].name, items[i].category, items[i].amount);
    }
}

void save_items(item_t *items, int num_items, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    fprintf(fp, "Item\tCategory\tAmount\n");
    for (int i = 0; i < num_items; i++) {
        fprintf(fp, "%s\t%s\t%.2f\n", items[i].name, items[i].category, items[i].amount);
    }

    fclose(fp);
}

void load_items(item_t *items, int *num_items, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (*num_items >= MAX_ITEMS) {
            printf("Error: Max number of items reached.\n");
            fclose(fp);
            return;
        }

        char *name = strtok(line, "\t");
        char *category = strtok(NULL, "\t");
        double amount = atof(strtok(NULL, "\n"));

        strcpy(items[*num_items].name, name);
        strcpy(items[*num_items].category, category);
        items[*num_items].amount = amount;

        (*num_items)++;
    }

    fclose(fp);
}

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;

    printf("Enter items (name category amount):\n");
    while (1) {
        char name[MAX_NAME_LEN];
        char category[MAX_CATEGORY_LEN];
        double amount;

        printf("Item %d: ", num_items + 1);
        scanf("%s %s %lf", name, category, &amount);

        add_item(items, num_items, name, category, amount);
        num_items++;

        char choice;
        printf("Enter Y to add another item or N to save and exit: ");
        scanf(" %c", &choice);
        if (choice == 'N' || choice == 'n') {
            break;
        }
    }

    save_items(items, num_items, "expenses.txt");

    printf("Saved expenses to file.\n");

    return 0;
}