//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int steps;
    int calories;
    int distance;
    int duration;
} FitnessData;

void generateRandomData(FitnessData *data) {
    srand(time(NULL));
    data->steps = rand() % 10000 + 1;
    data->calories = rand() % 500 + 1;
    data->distance = rand() % 10 + 1;
    data->duration = rand() % 100 + 1;
}

void printData(FitnessData data) {
    printf("Steps: %d\n", data.steps);
    printf("Calories: %d\n", data.calories);
    printf("Distance: %d\n", data.distance);
    printf("Duration: %d\n", data.duration);
}

int main() {
    FitnessData data;

    printf("How about we play a game?\n");
    printf("Let's see how active you've been today!\n");

    printf("Close your eyes and take a deep breath.\n");
    printf("Now, imagine yourself walking or running.\n");
    printf("Feel the wind in your hair and the sun on your skin.\n");

    printf("Open your eyes and tell me how many steps you took.\n");
    scanf("%d", &data.steps);

    printf("Now, tell me how many calories you burned.\n");
    scanf("%d", &data.calories);

    printf("How far did you travel?\n");
    scanf("%d", &data.distance);

    printf("And finally, how long did you spend exercising?\n");
    scanf("%d", &data.duration);

    printf("Let me summarize your fitness data:\n");
    printData(data);

    return 0;
}