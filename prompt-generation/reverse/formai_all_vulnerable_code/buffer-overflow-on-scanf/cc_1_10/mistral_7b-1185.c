//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_DISHES 20
#define MAX_INGREDIENTS 10
#define MAX_INGREDIENT_PER_DISH 5

struct dish {
    char name[30];
    int capacity;
    int ingredients[MAX_INGREDIENTS];
    int num_ingredients;
};

struct customer {
    int id;
    char favorite[30];
    int happiness;
};

struct kitchen {
    int capacity;
    int dishes_served[MAX_CUSTOMERS];
};

struct dish dishes[MAX_DISHES];
struct customer customers[MAX_CUSTOMERS];
struct kitchen kitchen;

void initialize() {
    int i, j;

    // Initialize dishes
    for (i = 0; i < MAX_DISHES; i++) {
        dishes[i].num_ingredients = rand() % 5 + 1;
        for (j = 0; j < dishes[i].num_ingredients; j++) {
            dishes[i].ingredients[j] = rand() % MAX_INGREDIENTS + 1;
        }
        strcpy(dishes[i].name, "");
        scanf("%s", dishes[i].name);
        dishes[i].capacity = rand() % 10 + 1;
    }

    // Initialize customers
    for (i = 0; i < MAX_CUSTOMERS; i++) {
        customers[i].id = i + 1;
        scanf("%s", customers[i].favorite);
    }

    // Initialize kitchen
    scanf("%d", &kitchen.capacity);
}

void serve_dishes() {
    int i, j, dishes_served = 0;

    // Serve dishes to customers in order of their arrival
    for (i = 0; i < MAX_CUSTOMERS; i++) {
        int required_capacity = 0;

        // Find a dish that matches the customer's favorite and can be served in the kitchen
        for (j = 0; j < MAX_DISHES; j++) {
            if (strcmp(dishes[j].name, customers[i].favorite) == 0 && dishes[j].capacity > 0 && required_capacity + dishes[j].capacity <= kitchen.capacity) {
                kitchen.dishes_served[dishes_served] = j;
                customers[i].happiness = 100;
                dishes_served++;
                dishes[j].capacity--;
                break;
            }
            required_capacity += dishes[j].capacity;
        }

        // If no matching dish is found, the customer leaves unhappy
        if (dishes_served == i) {
            customers[i].happiness = 0;
        }
    }
}

int main() {
    int i;

    initialize();

    // Greedy approach: Serve dishes to customers in the order they arrive
    serve_dishes();

    // Print results
    for (i = 0; i < MAX_CUSTOMERS; i++) {
        printf("Customer %d is %s happy.\n", customers[i].id, customers[i].happiness > 50 ? "very" : "not very");
    }

    return 0;
}