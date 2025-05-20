//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_AMOUNT 100000

typedef struct {
    char name[50];
    float amount;
    int date;
} item;

void add_item(item* arr, int n, char name[], float amt, int dt) {
    if (n >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        exit(1);
    }
    strcpy(arr[n].name, name);
    arr[n].amount = amt;
    arr[n].date = dt;
    n++;
}

void display_items(item* arr, int n) {
    printf("\nItem\tAmount\tDate\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%.2f\t%d\n", arr[i].name, arr[i].amount, arr[i].date);
    }
}

void main() {
    item arr[MAX_ITEMS];
    int n = 0;
    char name[50];
    float amt;
    int dt;

    printf("\n\nWelcome to the Medieval Personal Finance Planner!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an item\n2. Display items\n3. Exit\n");
        scanf("%d", &dt);

        switch (dt) {
        case 1:
            printf("\nEnter item name: ");
            scanf("%s", name);
            printf("Enter amount: ");
            scanf("%f", &amt);
            printf("Enter date (dd/mm/yyyy): ");
            scanf("%d", &dt);
            add_item(arr, n, name, amt, dt);
            break;

        case 2:
            display_items(arr, n);
            break;

        case 3:
            printf("\nThank you for using the Medieval Personal Finance Planner!\n");
            exit(0);

        default:
            printf("Invalid option.\n");
        }
    }
}