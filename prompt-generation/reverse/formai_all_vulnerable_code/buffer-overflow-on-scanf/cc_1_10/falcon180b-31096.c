//Falcon-180B DATASET v1.0 Category: Data mining ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    int count;
} item;

typedef struct {
    char name[50];
    int total_sales;
} category;

int main() {
    system("color 2"); // Set console color to green

    int num_items, num_categories;
    item *items;
    category *categories;
    double *sales_data;
    int i, j, k;

    printf("Welcome to the Supermarket Data Mining Program!\n");
    printf("Please enter the number of items: ");
    scanf("%d", &num_items);

    items = (item *) malloc(sizeof(item) * num_items);

    for (i = 0; i < num_items; i++) {
        printf("Enter the name of item #%d: ", i + 1);
        scanf("%s", items[i].name);
        items[i].count = 0;
    }

    printf("Please enter the number of categories: ");
    scanf("%d", &num_categories);

    categories = (category *) malloc(sizeof(category) * num_categories);

    for (i = 0; i < num_categories; i++) {
        printf("Enter the name of category #%d: ", i + 1);
        scanf("%s", categories[i].name);
        categories[i].total_sales = 0;
    }

    printf("Please enter the total number of sales transactions: ");
    scanf("%d", &k);

    sales_data = (double *) malloc(sizeof(double) * k);

    for (i = 0; i < k; i++) {
        printf("Enter the amount of transaction #%d: ", i + 1);
        scanf("%lf", &sales_data[i]);
    }

    srand(time(NULL));

    for (i = 0; i < k; i++) {
        int index = rand() % num_items;
        items[index].count++;
        int category_index = rand() % num_categories;
        categories[category_index].total_sales += sales_data[i];
    }

    printf("\nData Mining Results:\n");

    for (i = 0; i < num_categories; i++) {
        printf("Category: %s\n", categories[i].name);
        printf("Total Sales: $%.2lf\n", categories[i].total_sales);
        printf("Average Sales per Item: $%.2lf\n", categories[i].total_sales / num_items);
        printf("\n");
    }

    system("color 7"); // Set console color to white

    return 0;
}