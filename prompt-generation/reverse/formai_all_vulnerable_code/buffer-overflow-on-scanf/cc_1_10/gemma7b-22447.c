//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20

typedef struct C_Fitness_Tracker {
    char name[MAX_NAME_LENGTH];
    int age;
    float weight;
    int steps_taken;
    time_t timestamp;
} C_Fitness_Tracker;

int main() {
    C_Fitness_Tracker tracker;

    // Initialize the tracker
    tracker.name[0] = '\0';
    tracker.age = 0;
    tracker.weight = 0.0f;
    tracker.steps_taken = 0;
    tracker.timestamp = time(NULL);

    // Get the tracker's name, age, and weight
    printf("Enter your name: ");
    scanf("%s", tracker.name);

    printf("Enter your age: ");
    scanf("%d", &tracker.age);

    printf("Enter your weight (in kilograms): ");
    scanf("%f", &tracker.weight);

    // Calculate the tracker's steps taken
    printf("Enter the number of steps you took today: ");
    scanf("%d", &tracker.steps_taken);

    // Update the tracker's timestamp
    tracker.timestamp = time(NULL);

    // Print the tracker's information
    printf("\nName: %s\n", tracker.name);
    printf("Age: %d\n", tracker.age);
    printf("Weight: %.2f kg\n", tracker.weight);
    printf("Steps taken: %d\n", tracker.steps_taken);
    printf("Timestamp: %s\n", ctime(&tracker.timestamp));

    return 0;
}