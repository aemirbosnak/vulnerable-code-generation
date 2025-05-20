//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct menu {
    char name[50];
    float price;
};

void add_menu(struct menu *menu, int *size) {
    printf("Enter the name of the menu:\n");
    scanf("%s", menu[*size].name);
    printf("Enter the price of the menu:\n");
    scanf("%f", &menu[*size].price);
    (*size)++;
}

void display_menu(struct menu menu[], int size) {
    printf("\nMenu:\n");
    for(int i=0; i<size; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

void calculate_total(struct menu menu[], int size, int choice, float *total) {
    for(int i=0; i<size; i++) {
        if(i+1 == choice) {
            *total += menu[i].price;
        }
    }
}

void main() {
    struct menu menu[100];
    int size = 0;

    add_menu(menu, &size);
    add_menu(menu, &size);
    add_menu(menu, &size);

    int choice;
    float total = 0;

    while(1) {
        system("clear");
        display_menu(menu, size);

        printf("\nEnter your choice:\n");
        scanf("%d", &choice);

        if(choice == 0) {
            exit(0);
        } else if(choice > 0 && choice <= size) {
            calculate_total(menu, size, choice-1, &total);
            printf("\nTotal: $%.2f\n", total);
        } else {
            printf("Invalid choice!\n");
        }
    }
}