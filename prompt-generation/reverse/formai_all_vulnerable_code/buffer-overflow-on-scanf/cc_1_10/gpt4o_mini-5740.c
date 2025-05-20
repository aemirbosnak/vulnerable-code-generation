//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_DONUTS 10

// A structure to hold donut attributes
typedef struct {
    char flavor[20];
    double diameter;
} Donut;

// A fun function to create donuts
Donut* bake_donuts(int count) {
    // Check if the count is reasonable
    if (count < 1 || count > MAX_DONUTS) {
        printf("Whoa there! Are you trying to bake a universe of donuts? Choose between 1 and %d!\n", MAX_DONUTS);
        return NULL;
    }

    // Allocate memory for the donuts
    Donut* donuts = (Donut*)malloc(count * sizeof(Donut));
    if (donuts == NULL) {
        printf("Oh no! I dropped my wallet! Can't afford to bake donuts...\n");
        return NULL;
    }

    // Initialize donuts with flavors and diameters
    for (int i = 0; i < count; i++) {
        snprintf(donuts[i].flavor, sizeof(donuts[i].flavor), "Flavor %d", i + 1);
        donuts[i].diameter = 5.0 + i;  // Making donuts oversized, just for laughs
        printf("Baked a donut! Flavor: %s, Diameter: %.2f inches\n", donuts[i].flavor, donuts[i].diameter);
    }

    return donuts;
}

// A fun function to eat donuts
void eat_donuts(Donut* donuts, int count) {
    if (donuts == NULL) {
        printf("No donuts to eat! This is a tragedy of epic proportions.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("Yummy! Ate a %s donut with a diameter of %.2f inches!\n", donuts[i].flavor, donuts[i].diameter);
    }
}

// A marvelous function to party hard
void donut_party(int num_donuts) {
    Donut* donuts = bake_donuts(num_donuts);
    if (donuts == NULL) {
        printf("Can you believe it? No donuts for the party! Guests are leaving...\n");
        return;
    }

    eat_donuts(donuts, num_donuts);

    // Return donuts to the wild (free the memory)
    free(donuts);
    printf("What a party! All the donuts are gone. Let’s clean up this mess!\n");
}

// A quirky main function to get the donut party started
int main() {
    printf("Welcome to the Great Donut Bake-off!\n");
    printf("We will bake some donuts for an outrageous party.\n");

    int num_donuts;

    // Asking user for donuts count
    printf("How many donuts do you want to bake? (1-%d): ", MAX_DONUTS);
    scanf("%d", &num_donuts);

    donut_party(num_donuts);

    printf("Thanks for joining the donut party! Goodbye, my sweet friends.\n");
    return 0;
}