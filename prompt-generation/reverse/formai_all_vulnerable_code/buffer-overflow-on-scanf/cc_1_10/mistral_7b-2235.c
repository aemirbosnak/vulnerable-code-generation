//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FRUITS 10
#define FRUIT_SIZE 20

typedef struct {
    char name[FRUIT_SIZE];
    float weight;
} Fruit;

void print_error(const char *msg, int err_num) {
    printf("\nOops! An error occurred: %s\n", msg);
    printf("Error number: %d\n", err_num);
}

Fruit *create_fruits_array() {
    Fruit *fruits = (Fruit *)malloc(MAX_FRUITS * sizeof(Fruit));
    if (!fruits) {
        print_error("Memory allocation failed!", 1);
        return NULL;
    }
    return fruits;
}

void get_fruit_name(Fruit *fruit, char *name, int max_size) {
    printf("Enter the name of the fruit: ");
    fgets(name, max_size, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character
    strcpy(fruit->name, name);
}

void get_fruit_weight(Fruit *fruit) {
    float weight;

    while (1) {
        printf("Enter the weight of the fruit (in kg): ");
        scanf("%f", &weight);

        if (weight >= 0) {
            fruit->weight = weight;
            break;
        } else {
            print_error("Invalid weight! Please enter a positive value.", 2);
        }
    }
}

void add_fruit_to_array(Fruit *fruits, int *num_fruits) {
    Fruit *new_fruit = NULL;

    if (*num_fruits >= MAX_FRUITS) {
        print_error("Maximum number of fruits reached!", 3);
        return;
    }

    new_fruit = &fruits[*num_fruits];
    get_fruit_name(new_fruit, new_fruit->name, FRUIT_SIZE);
    get_fruit_weight(new_fruit);
    (*num_fruits)++;
}

int main() {
    Fruit *fruits = NULL;
    int num_fruits = 0;

    fruits = create_fruits_array();

    if (!fruits) {
        printf("Exiting the program...\n");
        return 1;
    }

    printf("Let's pick some cheerful fruits!\n");

    while (1) {
        add_fruit_to_array(fruits, &num_fruits);

        printf("Do you want to add another fruit? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'N' || answer == 'n') {
            break;
        }
    }

    printf("\nYou have picked %d fruits:\n", num_fruits);

    for (int i = 0; i < num_fruits; i++) {
        printf("Fruit %d: %s - %0.2f kg\n", i + 1, fruits[i].name, fruits[i].weight);
    }

    free(fruits);

    printf("\nThank you for picking fruits with us! Have a cheerful day!\n");

    return 0;
}