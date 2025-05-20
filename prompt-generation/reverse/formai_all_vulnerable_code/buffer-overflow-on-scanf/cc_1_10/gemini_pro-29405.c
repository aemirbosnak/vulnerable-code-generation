//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Our hero in this epic tale, ever so valiant: the Greedy Algorithm!
int greedy_treasure(int treasures[], int n) {
    // Behold, the mighty variables that shall guide our quest:
    int max_value = 0;
    int current_value = 0;

    // Embark on a thrilling tour through the kingdom of treasures:
    for (int i = 0; i < n; i++) {
        // Each treasure demands a tactical choice:
        // Should we embrace its riches or forge onwards?
        if (treasures[i] + current_value > max_value) {
            // A bolder path! Embrace the treasure's allure:
            current_value += treasures[i];
            if (current_value > max_value) {
                max_value = current_value;
            }
        } else {
            // A wiser path! Let go of the treasure's grasp:
            current_value = 0;
        }
    }

    // Our triumphant return! Behold the wealth we've amassed:
    return max_value;
}

int main() {
    // Behold, the fabled kingdom of treasures, calling out to be conquered!
    int n;
    printf("Enter the number of treasures lurking in the kingdom: ");
    scanf("%d", &n);

    // Let us unveil the treasures, one by one:
    int treasures[n];
    printf("Reveal the treasures, separated by spaces: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &treasures[i]);
    }

    // Unveil the secrets of the Greedy Algorithm!
    int max_treasure = greedy_treasure(treasures, n);

    // Behold, adventurers, the greatest treasure we've seized:
    printf("Our Greedy quest has bestowed upon us a treasure of: %d\n", max_treasure);

    return 0;
}