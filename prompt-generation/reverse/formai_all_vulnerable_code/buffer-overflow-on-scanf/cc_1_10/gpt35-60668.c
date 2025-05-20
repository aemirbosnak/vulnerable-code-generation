//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

struct fitness_tracker {
    char username[50];
    int age;
    float weight;
    float height;
    int steps_per_day;
    float calories_burned;
    float distance_walked;
};

void calculate_calories(struct fitness_tracker *tracker) {
    float metabolic_rate;
    
    if (tracker->age >= 18 && tracker->age <= 30) {
        metabolic_rate = 15.3 * tracker->weight + 679;
    } else if (tracker->age >= 31 && tracker->age <= 60) {
        metabolic_rate = 11.6 * tracker->weight + 879;
    } else if (tracker->age > 60) {
        metabolic_rate = 13.5 * tracker->weight + 487;
    }
    
    tracker->calories_burned = metabolic_rate * tracker->steps_per_day / 2000.0;
}

void calculate_distance_walked(struct fitness_tracker *tracker) {
    tracker->distance_walked = tracker->steps_per_day * tracker->height * 0.000414;
}

void print_tracker(struct fitness_tracker *tracker) {
    printf("Fitness Tracker for %s\n", tracker->username);
    printf("Age: %d\n", tracker->age);
    printf("Weight: %.1f kg\n", tracker->weight);
    printf("Height: %.2f m\n", tracker->height);
    printf("Steps per day: %d\n", tracker->steps_per_day);
    printf("Calories burned per day: %.1f\n", tracker->calories_burned);
    printf("Distance walked per day: %.2f km\n", tracker->distance_walked);
}

int main() {
    struct fitness_tracker tracker;
    
    printf("Please enter your name: ");
    scanf("%s", tracker.username);
    
    printf("Please enter your age: ");
    scanf("%d", &tracker.age);
    
    printf("Please enter your weight in kg: ");
    scanf("%f", &tracker.weight);
    
    printf("Please enter your height in meters: ");
    scanf("%f", &tracker.height);
    
    printf("Please enter your average steps per day: ");
    scanf("%d", &tracker.steps_per_day);
    
    calculate_calories(&tracker);
    calculate_distance_walked(&tracker);
    print_tracker(&tracker);
    
    return 0;
}