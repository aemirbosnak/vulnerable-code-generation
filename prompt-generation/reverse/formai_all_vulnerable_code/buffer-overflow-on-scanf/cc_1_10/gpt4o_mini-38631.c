//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: inquisitive
#include <stdio.h>

#define DAYS 7

typedef struct {
    int steps[DAYS];
    float calories[DAYS];
    float weight[DAYS];
} FitnessTracker;

void inputData(FitnessTracker *tracker) {
    for (int i = 0; i < DAYS; i++) {
        printf("Day %d:\n", i + 1);
        
        printf("How many steps did you take today? ");
        scanf("%d", &tracker->steps[i]);
        
        printf("How many calories did you burn today? ");
        scanf("%f", &tracker->calories[i]);
        
        printf("What's your current weight (kg)? ");
        scanf("%f", &tracker->weight[i]);
        
        printf("\n--- Data Recorded! ---\n\n");
    }
}

void analyzeData(FitnessTracker tracker) {
    int totalSteps = 0;
    float totalCalories = 0;
    float totalWeightChange = tracker.weight[0] - tracker.weight[DAYS - 1];

    for (int i = 0; i < DAYS; i++) {
        totalSteps += tracker.steps[i];
        totalCalories += tracker.calories[i];
    }

    printf("\n--- Weekly Analysis ---\n");
    printf("Total Steps Taken: %d\n", totalSteps);
    printf("Total Calories Burned: %.2f\n", totalCalories);
    printf("Weight Change: %.2f kg\n", totalWeightChange);
    
    float avgSteps = totalSteps / (float)DAYS;
    float avgCalories = totalCalories / DAYS;
    
    printf("Average Steps Per Day: %.2f\n", avgSteps);
    printf("Average Calories Burned Per Day: %.2f\n", avgCalories);
}

void getMotivation(float weightChange) {
    if (weightChange > 0) {
        printf("Hmm, it seems you're gaining weight! Let's focus on staying active!\n");
    } else if (weightChange < 0) {
        printf("Great job! You're losing weight! Keep up the good work!\n");
    } else {
        printf("You're maintaining your weight. Consider adjusting your routine for better results!\n");
    }
}

int main() {
    FitnessTracker myTracker = {0}; // Initialize tracker
    printf("Welcome to Your Fitness Tracker!\n");
    
    inputData(&myTracker);
    
    analyzeData(myTracker);
    
    // Examine weight change
    float weightChange = myTracker.weight[0] - myTracker.weight[DAYS - 1];
    getMotivation(weightChange);

    printf("\nThank you for using the Fitness Tracker. Stay fit and healthy!\n");
    
    return 0;
}