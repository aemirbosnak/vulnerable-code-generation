//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct for baggage
typedef struct Baggage {
    int weight;
    char* color;
} Baggage;

// Define a struct for conveyor belts
typedef struct Belt {
    int id;
    int speed;
    Baggage* baggages[10];
} Belt;

// Define a function to generate random baggage colors
char* random_color() {
    int r = rand() % 5;
    switch (r) {
        case 0:
            return "Red";
        case 1:
            return "Blue";
        case 2:
            return "Green";
        case 3:
            return "Yellow";
        case 4:
            return "Purple";
    }
}

int main() {

    // Seed the RNG
    srand(time(NULL));

    // Initialize the conveyor belts
    Belt belt1 = {1, 5};
    Belt belt2 = {2, 3};
    Belt belt3 = {3, 2};

    // Loop through 100 iterations
    for (int i = 0; i < 100; i++) {

        // Generate a new baggage object
        Baggage* new_baggage = (Baggage*) malloc(sizeof(Baggage));
        new_baggage->weight = rand() % 50 + 1;
        new_baggage->color = random_color();

        // Determine which belt to add the baggage to
        int r = rand() % 3;
        switch (r) {
            case 0:
                for (int j = 0; j < 10; j++) {
                    if (belt1.baggages[j] == NULL) {
                        belt1.baggages[j] = new_baggage;
                        printf("Added baggage with weight %d and color %s to belt %d\n", new_baggage->weight, new_baggage->color, belt1.id);
                        break;
                    }
                }
                break;
            case 1:
                for (int j = 0; j < 10; j++) {
                    if (belt2.baggages[j] == NULL) {
                        belt2.baggages[j] = new_baggage;
                        printf("Added baggage with weight %d and color %s to belt %d\n", new_baggage->weight, new_baggage->color, belt2.id);
                        break;
                    }
                }
                break;
            case 2:
                for (int j = 0; j < 10; j++) {
                    if (belt3.baggages[j] == NULL) {
                        belt3.baggages[j] = new_baggage;
                        printf("Added baggage with weight %d and color %s to belt %d\n", new_baggage->weight, new_baggage->color, belt3.id);
                        break;
                    }
                }
                break;
        }

        // Simulate the movement of the baggage on the belts
        for (int j = 0; j < 10; j++) {
            if (belt1.baggages[j] != NULL) {
                printf("Baggage with weight %d and color %s is moving on belt %d at speed %d\n", belt1.baggages[j]->weight, belt1.baggages[j]->color, belt1.id, belt1.speed);
            }
            if (belt2.baggages[j] != NULL) {
                printf("Baggage with weight %d and color %s is moving on belt %d at speed %d\n", belt2.baggages[j]->weight, belt2.baggages[j]->color, belt2.id, belt2.speed);
            }
            if (belt3.baggages[j] != NULL) {
                printf("Baggage with weight %d and color %s is moving on belt %d at speed %d\n", belt3.baggages[j]->weight, belt3.baggages[j]->color, belt3.id, belt3.speed);
            }
        }

        // Remove any baggage that has reached the end of a belt
        for (int j = 0; j < 10; j++) {
            if (belt1.baggages[j] != NULL && j == 9) {
                printf("Baggage with weight %d and color %s has reached the end of belt %d\n", belt1.baggages[j]->weight, belt1.baggages[j]->color, belt1.id);
                belt1.baggages[j] = NULL;
            }
            if (belt2.baggages[j] != NULL && j == 9) {
                printf("Baggage with weight %d and color %s has reached the end of belt %d\n", belt2.baggages[j]->weight, belt2.baggages[j]->color, belt2.id);
                belt2.baggages[j] = NULL;
            }
            if (belt3.baggages[j] != NULL && j == 9) {
                printf("Baggage with weight %d and color %s has reached the end of belt %d\n", belt3.baggages[j]->weight, belt3.baggages[j]->color, belt3.id);
                belt3.baggages[j] = NULL;
            }
        }

        // Add a surreal twist to the simulation
        if (i == 42) {
            printf("\nSuddenly, all the baggage on belt %d turned into large, sentient banana peels!\n", belt2.id);
            for (int j = 0; j < 10; j++) {
                if (belt2.baggages[j] != NULL) {
                    free(belt2.baggages[j]);
                    belt2.baggages[j] = NULL;
                }
            }
        }

    }

    return 0;
}