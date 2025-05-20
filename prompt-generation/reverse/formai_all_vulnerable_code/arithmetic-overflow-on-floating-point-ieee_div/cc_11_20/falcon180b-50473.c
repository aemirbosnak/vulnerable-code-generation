//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    int steps;
    double distance;
    double calories;
    double heartRate;
} FitnessData;

int main() {
    int choice;
    FitnessData data;
    double speed, time, distance, heartRate;

    do {
        system("clear");
        printf("Fitness Tracker\n");
        printf("1. Record Steps\n");
        printf("2. Record Distance\n");
        printf("3. Record Calories\n");
        printf("4. Record Heart Rate\n");
        printf("5. View Summary\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of steps: ");
                scanf("%d", &data.steps);
                break;
            case 2:
                printf("Enter distance in kilometers: ");
                scanf("%lf", &distance);
                data.distance += distance;
                break;
            case 3:
                printf("Enter calories burned: ");
                scanf("%lf", &data.calories);
                break;
            case 4:
                printf("Enter heart rate (bpm): ");
                scanf("%lf", &heartRate);
                data.heartRate += heartRate;
                break;
            case 5:
                printf("Summary:\n");
                if (data.steps > 0) {
                    printf("Steps: %d\n", data.steps);
                }
                if (data.distance > 0) {
                    printf("Distance: %.2lf km\n", data.distance);
                }
                if (data.calories > 0) {
                    printf("Calories burned: %.2lf\n", data.calories);
                }
                if (data.heartRate > 0) {
                    printf("Average heart rate: %.2lf bpm\n", data.heartRate / data.steps);
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 6);

    return 0;
}