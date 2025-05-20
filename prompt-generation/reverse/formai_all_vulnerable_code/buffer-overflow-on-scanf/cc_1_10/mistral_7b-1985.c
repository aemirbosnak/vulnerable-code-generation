//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FOOD 10
#define MAX_NAME_LEN 20
#define MAX_LOCATION_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    char location[MAX_LOCATION_LEN];
} Food;

Food food_list[MAX_FOOD];

void initialize_database() {
    int i;
    for (i = 0; i < MAX_FOOD; i++) {
        food_list[i].quantity = 0;
        strcpy(food_list[i].name, "");
        strcpy(food_list[i].location, "");
    }
}

int add_food(char *name, int quantity, char *location) {
    int i;
    for (i = 0; i < MAX_FOOD; i++) {
        if (food_list[i].quantity == 0) {
            strcpy(food_list[i].name, name);
            food_list[i].quantity = quantity;
            strcpy(food_list[i].location, location);
            return i;
        }
    }
    return -1;
}

void print_database() {
    int i;
    for (i = 0; i < MAX_FOOD; i++) {
        if (food_list[i].quantity > 0) {
            printf("%s (%s): %d units\n", food_list[i].name, food_list[i].location, food_list[i].quantity);
        }
    }
}

int main() {
    char name[MAX_NAME_LEN];
    char location[MAX_LOCATION_LEN];
    int quantity;
    int index;

    initialize_database();

    while (1) {
        printf("Enter food name: ");
        scanf("%s", name);

        printf("Enter food quantity: ");
        scanf("%d", &quantity);

        printf("Enter food location: ");
        scanf("%s", location);

        index = add_food(name, quantity, location);

        if (index >= 0) {
            printf("Food added successfully.\n");
        } else {
            printf("Failed to add food.\n");
        }

        printf("Do you want to add another food? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice != 'y') {
            break;
        }
    }

    printf("\nFood database:\n");
    print_database();

    return 0;
}