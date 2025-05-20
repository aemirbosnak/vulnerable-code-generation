//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 20
#define MAX_ITEMS 100
#define MAX_CHAR 50

struct item {
    char name[MAX_CHAR];
    char category[MAX_CHAR];
    float amount;
};

struct category {
    char name[MAX_CHAR];
    int count;
};

void add_item(struct item *items, int *num_items, char *name, char *category, float amount) {
    strcpy(items[*num_items].name, name);
    strcpy(items[*num_items].category, category);
    items[*num_items].amount = amount;
    (*num_items)++;
}

void display_items(struct item *items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        printf("%s - %.2f - %s\n", items[i].name, items[i].amount, items[i].category);
    }
}

void display_categories(struct category *categories, int num_categories) {
    for (int i = 0; i < num_categories; i++) {
        printf("%s - %d\n", categories[i].name, categories[i].count);
    }
}

int main() {
    char input[MAX_CHAR];
    struct item items[MAX_ITEMS];
    int num_items = 0;
    struct category categories[MAX_CATEGORIES];
    int num_categories = 0;

    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Display categories\n");
        printf("4. Quit\n");

        scanf("%s", input);

        switch (input[0]) {
            case '1':
                printf("Enter expense name: ");
                scanf("%s", input);
                printf("Enter expense category: ");
                scanf("%s", input);
                printf("Enter expense amount: ");
                scanf("%f", &items[num_items].amount);
                add_item(items, &num_items, input, input, items[num_items].amount);
                break;
            case '2':
                display_items(items, num_items);
                break;
            case '3':
                for (int i = 0; i < num_categories; i++) {
                    printf("%s - %d\n", categories[i].name, categories[i].count);
                }
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}