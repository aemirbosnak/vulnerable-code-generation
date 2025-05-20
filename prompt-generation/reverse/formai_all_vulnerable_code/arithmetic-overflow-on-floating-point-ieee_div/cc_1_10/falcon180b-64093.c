//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    int height;
    int weight;
    double bmi;
    int steps;
    int heartRate;
    time_t timestamp;
} fitnessData;

fitnessData data;

void init() {
    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", data.name);
    printf("Please enter your age: ");
    scanf("%d", &data.age);
    printf("Please enter your height in cm: ");
    scanf("%d", &data.height);
    printf("Please enter your weight in kg: ");
    scanf("%d", &data.weight);
    data.bmi = (double)data.weight / (double)(data.height/100)*(double)100;
    printf("Your BMI is: %.2f\n", data.bmi);
    data.steps = 0;
    data.heartRate = 0;
    data.timestamp = time(NULL);
}

void stepCounter() {
    printf("You have taken %d steps today.\n", data.steps);
}

void heartRateMonitor() {
    printf("Your heart rate is %d bpm.\n", data.heartRate);
}

int main() {
    init();
    int choice;
    while(1) {
        printf("What would you like to do?\n");
        printf("1. Step counter\n");
        printf("2. Heart rate monitor\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                stepCounter();
                break;
            case 2:
                heartRateMonitor();
                break;
            case 3:
                printf("Thank you for using the Fitness Tracker!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}