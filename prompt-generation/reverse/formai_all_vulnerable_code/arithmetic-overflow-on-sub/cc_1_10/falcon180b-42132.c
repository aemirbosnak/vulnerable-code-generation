//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct stock {
    char name[20];
    float price;
    int quantity;
};

void swap(struct stock *a, struct stock *b) {
    struct stock temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(struct stock arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    struct stock arr[MAX];
    int n, i, j, choice;

    printf("Enter the number of stocks: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter stock name: ");
        scanf("%s", arr[i].name);
        printf("Enter stock price: ");
        scanf("%f", &arr[i].price);
        printf("Enter stock quantity: ");
        scanf("%d", &arr[i].quantity);
    }

    printf("\nBefore Sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%s %f %d\n", arr[i].name, arr[i].price, arr[i].quantity);
    }

    sort(arr, n);

    printf("\n\nAfter Sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%s %f %d\n", arr[i].name, arr[i].price, arr[i].quantity);
    }

    return 0;
}