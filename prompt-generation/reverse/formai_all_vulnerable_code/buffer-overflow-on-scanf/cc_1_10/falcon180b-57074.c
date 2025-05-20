//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_STEPS 10000
#define MAX_DISTANCE 10000
#define MAX_CALORIES 10000
#define MAX_HEARTRATE 200
#define MAX_SLEEP 24

typedef struct {
    int steps;
    double distance;
    int calories;
    int heartrate;
    int sleep;
} fitness_data;

void print_header() {
    printf("+------------------+\n");
    printf("| FITNESS TRACKER   |\n");
    printf("+------------------+\n");
}

void print_data(fitness_data data) {
    printf("+------------------+\n");
    printf("| Steps: %d         |\n", data.steps);
    printf("| Distance: %.2f km |\n", data.distance);
    printf("| Calories: %d      |\n", data.calories);
    printf("| Heart Rate: %d bpm|\n", data.heartrate);
    printf("| Sleep: %d hours   |\n", data.sleep);
    printf("+------------------+\n");
}

int main() {
    fitness_data data;
    char input[100];

    print_header();

    while (1) {
        printf("Enter command: ");
        fgets(input, 100, stdin);

        if (strcmp(input, "exit") == 0) {
            break;
        } else if (strcmp(input, "steps") == 0) {
            printf("Enter number of steps: ");
            scanf("%d", &data.steps);
            data.distance = data.steps * 0.1;
            data.calories = data.steps * 0.05;
        } else if (strcmp(input, "distance") == 0) {
            printf("Enter distance in km: ");
            scanf("%lf", &data.distance);
            data.steps = data.distance / 0.1;
            data.calories = data.distance * 5;
        } else if (strcmp(input, "calories") == 0) {
            printf("Enter number of calories: ");
            scanf("%d", &data.calories);
            data.steps = data.calories / 5;
            data.distance = data.calories / 50;
        } else if (strcmp(input, "heartrate") == 0) {
            printf("Enter heart rate in bpm: ");
            scanf("%d", &data.heartrate);
        } else if (strcmp(input, "sleep") == 0) {
            printf("Enter hours of sleep: ");
            scanf("%d", &data.sleep);
        } else {
            printf("Invalid command\n");
        }

        print_data(data);
    }

    return 0;
}