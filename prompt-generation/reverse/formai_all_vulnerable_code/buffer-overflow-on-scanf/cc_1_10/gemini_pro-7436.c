//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Watson, our dear assistant in this investigation
typedef struct _watson
{
    int steps;
    double distance;
    int calories;
    int heart_rate;
} watson;

// The great detective, Holmes
void holmes(watson *data)
{
    // Observe the data, Watson!
    printf("Steps taken: %d\n", data->steps);
    printf("Distance covered: %.2f miles\n", data->distance);
    printf("Calories burned: %d\n", data->calories);
    printf("Heart rate: %d bpm\n", data->heart_rate);

    // Deductions, my dear Watson
    if (data->steps >= 10000)
    {
        printf("Excellent! You've achieved your daily goal.\n");
    }
    else
    {
        printf("Come, Watson, you must do better! Exercise is essential for a healthy mind and body.\n");
    }

    if (data->heart_rate > 120)
    {
        printf("Caution! Your heart rate is elevated. Rest is advised.\n");
    }
}

int main()
{
    // Initialize the investigation
    watson data = {0, 0.0, 0, 0};

    // Gather evidence
    printf("Enter your fitness data, Watson:\n");
    printf("Steps taken: ");
    scanf("%d", &data.steps);
    printf("Distance covered (in miles): ");
    scanf("%lf", &data.distance);
    printf("Calories burned: ");
    scanf("%d", &data.calories);
    printf("Heart rate (in bpm): ");
    scanf("%d", &data.heart_rate);

    // Call upon the great detective
    printf("\nElementary, my dear Watson!\n");
    holmes(&data);

    return 0;
}