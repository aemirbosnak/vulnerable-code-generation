//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    float price;
} Item;

typedef struct {
    int num_items;
    Item items[MAX_SIZE];
} Menu;

void read_menu(Menu *menu) {
    FILE *fp;
    char line[MAX_SIZE];
    int i = 0;

    fp = fopen("menu.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open menu file.\n");
        exit(1);
    }

    while (fgets(line, MAX_SIZE, fp)!= NULL) {
        char *name = strtok(line, ",");
        float price = atof(strtok(NULL, ","));

        strcpy(menu->items[i].name, name);
        menu->items[i].price = price;
        i++;
    }

    fclose(fp);
    menu->num_items = i;
}

void print_menu(Menu *menu) {
    int i;

    for (i = 0; i < menu->num_items; i++) {
        printf("%s - $%.2f\n", menu->items[i].name, menu->items[i].price);
    }
}

void order_item(Menu *menu, char *name) {
    int i;

    for (i = 0; i < menu->num_items; i++) {
        if (strcmp(menu->items[i].name, name) == 0) {
            printf("You ordered %s for $%.2f.\n", name, menu->items[i].price);
            break;
        }
    }
}

int main() {
    Menu menu;
    char choice;
    float total = 0.0;

    read_menu(&menu);

    do {
        printf("Welcome to the Cafe!\n");
        printf("Please choose an option:\n");
        printf("1. View menu\n2. Place order\n3. Check total\n4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                print_menu(&menu);
                break;
            case '2':
                printf("Enter the name of the item you want to order:\n");
                scanf("%s", menu.items[0].name);
                order_item(&menu, menu.items[0].name);
                break;
            case '3':
                printf("Your total is $%.2f.\n", total);
                break;
            case '4':
                printf("Thank you for visiting the Cafe!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '4');

    return 0;
}