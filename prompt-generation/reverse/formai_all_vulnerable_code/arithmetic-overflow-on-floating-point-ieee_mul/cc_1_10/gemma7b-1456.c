//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a macro to format the time
#define TIME_FORMAT "%H:%M:%S"

// Define the main function
int main()
{
    // Declare variables
    char name[20];
    int age;
    float height;
    float weight;
    int heartRate;
    time_t timestamp;

    // Get the user's name, age, height, and weight
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your height (in inches): ");
    scanf("%f", &height);

    printf("Enter your weight (in pounds): ");
    scanf("%f", &weight);

    // Calculate the user's heart rate
    heartRate = (220 - age) * height / weight;

    // Get the current timestamp
    timestamp = time(NULL);

    // Format the timestamp
    char timestampStr[20];
    strftime(timestampStr, sizeof(timestampStr), TIME_FORMAT, localtime(&timestamp));

    // Print the results
    printf("\nHey, %s, here's your fitness tracker data:", name);

    printf("\nAge: %d", age);

    printf("\nHeight: %.2f inches", height);

    printf("\nWeight: %.2f pounds", weight);

    printf("\nHeart Rate: %d beats per minute", heartRate);

    printf("\nTimestamp: %s", timestampStr);

    return 0;
}