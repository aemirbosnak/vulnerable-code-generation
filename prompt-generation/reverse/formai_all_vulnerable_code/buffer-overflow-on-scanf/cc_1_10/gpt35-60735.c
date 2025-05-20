//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: happy
#include <stdio.h>

#define MAX_PEOPLE 10

int main() {
    int happinessScores[MAX_PEOPLE];
    int numPeople, totalHappiness = 0;
    double avgHappiness;

    printf("Welcome! Let's calculate the happiness quotient of your group!\n");

    // Get input from the user
    printf("How many people are in your group (max %d)? ", MAX_PEOPLE);
    scanf("%d", &numPeople);

    for (int i = 0; i < numPeople; i++) {
        printf("Enter the happiness score (out of 10) for person #%d: ", i+1);
        scanf("%d", &happinessScores[i]);

        // Check that the input is valid
        while (happinessScores[i] < 0 || happinessScores[i] > 10) {
            printf("Invalid input. Please enter a score between 0 and 10: ");
            scanf("%d", &happinessScores[i]);
        }

        // Add the score to the total
        totalHappiness += happinessScores[i];
    }

    // Calculate the average happiness
    avgHappiness = (double) totalHappiness / numPeople;

    printf("\nHere are the happiness scores for your group:\n");
    for (int i = 0; i < numPeople; i++) {
        printf("Person #%d: %d\n", i+1, happinessScores[i]);
    }

    printf("\nThe average happiness score for your group is %.2f!\n", avgHappiness);

    // Print a happy message based on the group's happiness quotient
    if (avgHappiness >= 8.0) {
        printf("Wow, your group is extremely happy! Keep up the good vibes!\n");
    } else if (avgHappiness >= 6.0) {
        printf("Your group is doing pretty well in terms of happiness! Keep spreading joy!\n");
    } else {
        printf("Don't worry if your group's happiness score is low - there's always room for improvement! Keep smiling!\n");
    }

    return 0;
}