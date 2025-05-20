//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Stock {
    char symbol[5];
    double price;
} Stock;

typedef struct Node {
    Stock stock;
    struct Node *left, *right;
} Node;

Node *new_node(Stock stock) {
    Node *new = malloc(sizeof(Node));
    new->stock = stock;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Node *insert(Node *root, Stock stock) {
    if (root == NULL)
        return new_node(stock);

    if (strcmp(stock.symbol, root->stock.symbol) < 0)
        root->left = insert(root->left, stock);
    else if (strcmp(stock.symbol, root->stock.symbol) > 0)
        root->right = insert(root->right, stock);

    return root;
}

void portfolio_value(Node *root, double *total, double *avg) {
    if (root == NULL)
        return;

    portfolio_value(root->left, total, avg);
    *total += root->stock.price;
    *avg += root->stock.price;
    portfolio_value(root->right, total, avg);
}

int main() {
    Node *tree = NULL;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Stock s;
        scanf("%s %lf", s.symbol, &s.price);
        tree = insert(tree, s);
    }

    double total = 0.0, avg = 0.0;
    portfolio_value(tree, &total, &avg);

    printf("Total value of the portfolio: %.2f\n", total);
    printf("Average price of each stock: %.2f\n", avg / n);

    return 0;
}