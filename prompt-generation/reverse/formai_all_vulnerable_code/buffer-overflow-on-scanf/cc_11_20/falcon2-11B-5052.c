//Falcon2-11B DATASET v1.0 Category: Weather simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int weather = rand() % 100; // Generate a random number between 0 and 100
    printf("Welcome to the Weather Simulation!\n");
    printf("Please enter a number between 1 and 5 to simulate a different weather condition:\n");
    printf("1. Sunny day\n");
    printf("2. Rainy day\n");
    printf("3. Cloudy day\n");
    printf("4. Snowy day\n");
    printf("5. Windy day\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            if (weather < 50) {
                printf("It is a sunny day.\n");
            } else {
                printf("The sun is shining brightly.\n");
            }
            break;
        case 2:
            if (weather < 30) {
                printf("It is a rainy day.\n");
            } else {
                printf("The rain is falling gently.\n");
            }
            break;
        case 3:
            if (weather < 70) {
                printf("It is a cloudy day.\n");
            } else {
                printf("The clouds are rolling in.\n");
            }
            break;
        case 4:
            if (weather < 20) {
                printf("It is a snowy day.\n");
            } else {
                printf("The snow is falling softly.\n");
            }
            break;
        case 5:
            if (weather < 40) {
                printf("It is a windy day.\n");
            } else {
                printf("The wind is blowing gently.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    return 0;
}