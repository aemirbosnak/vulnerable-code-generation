//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int cost;
} Item;

int main() {
    char input[100];
    int choice, i, j;
    Item items[MAX_ITEMS];
    int num_items = 0;

    printf("Welcome to the Medieval Personal Finance Planner!\n");
    printf("Please enter your name: ");
    scanf("%s", input);
    printf("Greetings, %s! How may I assist thee with thy finances?\n", input);

    while (1) {
        printf("\n1. Add an item\n2. Remove an item\n3. View items\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_items >= MAX_ITEMS) {
                    printf("Thy list is full! Please remove an item first.\n");
                } else {
                    printf("Enter the name of the item: ");
                    scanf("%s", items[num_items].name);
                    printf("Enter the cost of the item: ");
                    scanf("%d", &items[num_items].cost);
                    num_items++;
                    printf("%s has been added to thy list.\n", items[num_items-1].name);
                }
                break;

            case 2:
                if (num_items == 0) {
                    printf("Thy list is empty! Please add an item first.\n");
                } else {
                    printf("Enter the index of the item to remove: ");
                    scanf("%d", &j);
                    if (j >= 0 && j < num_items) {
                        printf("%s has been removed from thy list.\n", items[j].name);
                        for (i = j; i < num_items-1; i++) {
                            strcpy(items[i].name, items[i+1].name);
                            items[i].cost = items[i+1].cost;
                        }
                        num_items--;
                    } else {
                        printf("Invalid index!\n");
                    }
                }
                break;

            case 3:
                if (num_items == 0) {
                    printf("Thy list is empty!\n");
                } else {
                    printf("\nItem\t\tCost\n");
                    for (i = 0; i < num_items; i++) {
                        printf("%s\t\t%d\n", items[i].name, items[i].cost);
                    }
                }
                break;

            case 4:
                printf("Farewell, %s! May thy finances be ever in thy favor.\n", input);
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}