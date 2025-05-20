//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX 100

struct item {
    char name[20];
    int price;
};

struct item menu[MAX]; // menu items
int num_items = 0; // number of items in the menu

void add_item(char* name, int price) { // function to add items to the menu
    if (num_items == MAX) {
        printf("Menu is full.\n");
        return;
    }
    strcpy(menu[num_items].name, name);
    menu[num_items].price = price;
    num_items++;
}

void print_menu() { // function to print the menu
    printf("Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%d\n", i+1, menu[i].name, menu[i].price);
    }
}

int main() {
    add_item("Coffee", 2);
    add_item("Tea", 1);
    add_item("Cake", 3);

    int choice;
    while (true) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= num_items) {
            printf("You chose %s for $%d.\n", menu[choice-1].name, menu[choice-1].price);
        } else {
            printf("Invalid choice.\n");
        }
        printf("Do you want to order something else? (y/n): ");
        char answer;
        scanf(" %c", &answer);
        if (tolower(answer) == 'n') { // check if the user wants to exit
            break;
        }
    }

    return 0;
}