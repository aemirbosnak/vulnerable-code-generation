//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// A brave knight embarks on a perilous quest, where he must collect treasures to appease the gods.
// The knight has limited space in his satchel, and must carefully choose the most valuable treasures to carry.
// Help the knight maximize his haul by implementing a greedy algorithm that selects treasures in descending order of value.

// Each treasure is represented by a weight and a value.
typedef struct treasure {
    int weight;
    int value;
} treasure_t;

// The knight's satchel can hold a maximum weight of capacity.
int capacity;

// The knight's satchel contains a list of treasures.
treasure_t* satchel;
int satchel_size;

// Function to initialize the knight's satchel.
void init_satchel(int cap) {
    capacity = cap;
    satchel = malloc(sizeof(treasure_t) * capacity);
    satchel_size = 0;
}

// Function to add a treasure to the knight's satchel.
void add_to_satchel(treasure_t* treasure) {
    if (satchel_size < capacity && treasure->weight <= capacity - satchel[satchel_size - 1].weight) {
        satchel[satchel_size++] = *treasure;
    }
}

// Function to sort treasures in descending order of value.
void sort_treasures(treasure_t* treasures, int num_treasures) {
    for (int i = 0; i < num_treasures - 1; i++) {
        for (int j = i + 1; j < num_treasures; j++) {
            if (treasures[i].value < treasures[j].value) {
                treasure_t temp = treasures[i];
                treasures[i] = treasures[j];
                treasures[j] = temp;
            }
        }
    }
}

// Function to perform a greedy algorithm to select treasures.
void greedy_treasure_selection(treasure_t* treasures, int num_treasures) {
    sort_treasures(treasures, num_treasures);
    for (int i = 0; i < num_treasures; i++) {
        add_to_satchel(&treasures[i]);
    }
}

// Function to calculate the total value of the treasures in the knight's satchel.
int calculate_total_value() {
    int total_value = 0;
    for (int i = 0; i < satchel_size; i++) {
        total_value += satchel[i].value;
    }
    return total_value;
}

// Function to print the contents of the knight's satchel.
void print_satchel() {
    printf("The knight's satchel contains:\n");
    for (int i = 0; i < satchel_size; i++) {
        printf("Weight: %d, Value: %d\n", satchel[i].weight, satchel[i].value);
    }
    printf("Total value: %d\n", calculate_total_value());
}

// Main function.
int main() {
    // Initialize the knight's satchel with a capacity of 15.
    init_satchel(15);

    // Create a list of treasures.
    treasure_t treasures[] = {
        {5, 10},
        {3, 6},
        {2, 4},
        {7, 12},
        {4, 8}
    };

    // Perform a greedy algorithm to select treasures.
    greedy_treasure_selection(treasures, sizeof(treasures) / sizeof(treasures[0]));

    // Print the contents of the knight's satchel.
    print_satchel();

    return 0;
}