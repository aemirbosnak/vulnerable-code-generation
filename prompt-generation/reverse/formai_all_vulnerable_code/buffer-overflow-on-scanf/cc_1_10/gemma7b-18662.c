//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
    char name[20];
    char gender[10];
    int age;
    int heart_rate;
    int steps_taken;
    int distance_traveled;
    time_t timestamp;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your gender (male/female): ");
    scanf("%s", gender);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your current heart rate: ");
    scanf("%d", &heart_rate);

    printf("Enter the number of steps you took today: ");
    scanf("%d", &steps_taken);

    printf("Enter the distance you traveled today (in miles): ");
    scanf("%d", &distance_traveled);

    timestamp = time(NULL);

    // Calculate total calories burned
    int total_calories = (steps_taken * 0.03) + (distance_traveled * 0.00262);

    // Print results
    printf("\n**Your Personal Fitness Tracker Report**\n\n");
    printf("Name: %s\n", name);
    printf("Gender: %s\n", gender);
    printf("Age: %d\n", age);
    printf("Heart Rate: %d\n", heart_rate);
    printf("Steps Taken: %d\n", steps_taken);
    printf("Distance Traveled: %.2f miles\n", (double)distance_traveled);
    printf("Total Calories Burned: %d\n", total_calories);
    printf("Timestamp: %s\n", asctime(localtime(&timestamp)));

    return 0;
}