//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
// Linus Torvalds-style C Data Mining Example

// Greetings from Linus Torvalds!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data mining is like making a fine brew. Let's get started!

// Our trusty data set
struct coffee {
    char name[32];
    int strength;
    int acidity;
    int sweetness;
};

// A bag of beans to hold our data
struct coffee_bag {
    struct coffee *beans;
    int num_beans;
};

// Function to create a new bag of beans
struct coffee_bag *new_bag(int num_beans) {
    struct coffee_bag *bag = malloc(sizeof(struct coffee_bag));
    bag->beans = malloc(sizeof(struct coffee) * num_beans);
    bag->num_beans = num_beans;
    return bag;
}

// Function to free the bag and its beans
void free_bag(struct coffee_bag *bag) {
    free(bag->beans);
    free(bag);
}

// Function to load our data set into a bag
struct coffee_bag *load_data(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Get the number of beans
    int num_beans;
    fscanf(fp, "%d", &num_beans);

    // Create a bag to hold the beans
    struct coffee_bag *bag = new_bag(num_beans);

    // Load the beans into the bag
    for (int i = 0; i < num_beans; i++) {
        fscanf(fp, "%s %d %d %d", bag->beans[i].name, &bag->beans[i].strength, &bag->beans[i].acidity, &bag->beans[i].sweetness);
    }

    fclose(fp);

    return bag;
}

// Function to print the contents of a bag
void print_bag(struct coffee_bag *bag) {
    for (int i = 0; i < bag->num_beans; i++) {
        printf("%s %d %d %d\n", bag->beans[i].name, bag->beans[i].strength, bag->beans[i].acidity, bag->beans[i].sweetness);
    }
}

// Function to find the best coffee for a given taste profile
struct coffee find_best_coffee(struct coffee_bag *bag, int strength, int acidity, int sweetness) {
    struct coffee best_coffee;
    int best_score = 0;

    for (int i = 0; i < bag->num_beans; i++) {
        int score = abs(bag->beans[i].strength - strength) + abs(bag->beans[i].acidity - acidity) + abs(bag->beans[i].sweetness - sweetness);
        if (score < best_score) {
            best_coffee = bag->beans[i];
            best_score = score;
        }
    }

    return best_coffee;
}

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <data file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Load the data set
    struct coffee_bag *bag = load_data(argv[1]);

    // Print the contents of the bag
    printf("Data set:\n");
    print_bag(bag);

    // Get the user's taste profile
    int strength, acidity, sweetness;
    printf("Enter your taste profile (strength, acidity, sweetness): ");
    scanf("%d %d %d", &strength, &acidity, &sweetness);

    // Find the best coffee for the user
    struct coffee best_coffee = find_best_coffee(bag, strength, acidity, sweetness);

    // Print the results
    printf("The best coffee for you is: %s\n", best_coffee.name);

    // Free the bag and its beans
    free_bag(bag);

    return 0;
}