//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX 1000

typedef struct {
    char name[20];
    int value;
} Item;

void print_menu() {
    printf("*************************************************\n");
    printf("*          Welcome to the Enchanted Search!      *\n");
    printf("*                                               *\n");
    printf("*            Enter a command:                    *\n");
    printf("*                                               *\n");
    printf("*         1. Add an item                        *\n");
    printf("*         2. Search for an item                  *\n");
    printf("*         3. Display the inventory              *\n");
    printf("*         4. Quit the game                       *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
}

void add_item(Item *items, int *count) {
    if (*count >= MAX) {
        printf("The inventory is full!\n");
        return;
    }

    printf("Enter the name of the item: ");
    scanf("%s", items[*count].name);
    items[*count].name[strlen(items[*count].name)] = '\0'; // Ensure null terminated
    printf("Enter the value of the item: ");
    scanf("%d", &items[*count].value);

    (*count)++;
}

int search_item(Item items[], int count, char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(items[i].name, name) == 0) {
            return items[i].value;
        }
    }

    printf("Item not found!\n");
    return -1;
}

void display_inventory(Item items[], int count) {
    printf("*************************************************\n");
    printf("*                 Inventory                      *\n");
    printf("*************************************************\n");

    for (int i = 0; i < count; i++) {
        printf("* %-15s: %d                                   *\n", items[i].name, items[i].value);
    }
}

int main() {
    Item items[MAX];
    int count = 0;
    char command[10];
    char name[20];
    int value;

    srand(time(NULL));

    while (1) {
        print_menu();
        scanf("%s", command);

        switch (command[0]) {
        case '1':
            add_item(items, &count);
            break;
        case '2':
            printf("Enter the name of the item to search: ");
            scanf("%s", name);
            value = search_item(items, count, name);
            if (value != -1) {
                printf("The value of the item is: %d\n", value);
            }
            break;
        case '3':
            display_inventory(items, count);
            break;
        case '4':
            printf("Thank you for playing the Enchanted Search! \n");
            exit(0);
        default:
            printf("Invalid command!\n");
            break;
        }
    }

    return 0;
}