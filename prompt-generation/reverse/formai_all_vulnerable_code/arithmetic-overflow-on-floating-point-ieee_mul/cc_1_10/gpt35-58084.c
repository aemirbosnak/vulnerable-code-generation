//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Cryptic
#include<stdio.h>

// Define structure for storing data
struct FitnessTracker {
    char name[20];
    int age;
    float height;
    float weight;
    float BMI;
};

int main() {
    int n, i;
    float totalBMI = 0.0;

    printf("Enter the number of people to track: ");
    scanf("%d", &n);

    // Dynamically allocate memory for array of structures
    struct FitnessTracker *people = malloc(n * sizeof(struct FitnessTracker));

    for(i=0; i<n; i++) {
        printf("\nEnter name of person %d: ", i+1);
        scanf("%s", people[i].name);

        printf("Enter age of %s: ", people[i].name);
        scanf("%d", &people[i].age);

        printf("Enter height of %s in meters: ", people[i].name);
        scanf("%f", &people[i].height);

        printf("Enter weight of %s in kilograms: ", people[i].name);
        scanf("%f", &people[i].weight);

        // Calculate BMI
        people[i].BMI = people[i].weight / (people[i].height * people[i].height);

        totalBMI += people[i].BMI;
    }

    // Display Results
    printf("\n=====FITNESS TRACKING RESULTS=====\n");

    for(i=0; i<n; i++) {
        printf("\nName: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Height: %.2f meters\n", people[i].height);
        printf("Weight: %.2f kilograms\n", people[i].weight);
        printf("BMI: %.2f\n", people[i].BMI);
    }

    printf("\nAverage BMI: %.2f", totalBMI/n);

    // Free dynamically allocated memory
    free(people);

    return 0;
}