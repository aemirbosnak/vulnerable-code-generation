//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int age;
    char name[20];
    char gender;
    int heartRate;
    int fitnessScore;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your gender (m/f): ");
    scanf("%c", &gender);

    printf("Enter your current heart rate: ");
    scanf("%d", &heartRate);

    time_t now = time(NULL);
    struct tm* timeInfo = localtime(&now);

    fitnessScore = 0;
    if (age >= 18 && gender =='m') {
        fitnessScore = heartRate * 0.9 + (timeInfo->tm_hour * 0.1);
    }
    else if (age >= 18 && gender == 'f') {
        fitnessScore = heartRate * 0.8 + (timeInfo->tm_hour * 0.1);
    }
    else if (age >= 13 && age < 18 && gender =='m') {
        fitnessScore = heartRate * 0.8 + (timeInfo->tm_hour * 0.2);
    }
    else if (age >= 13 && age < 18 && gender == 'f') {
        fitnessScore = heartRate * 0.7 + (timeInfo->tm_hour * 0.2);
    }
    else if (age < 13 && gender =='m') {
        fitnessScore = heartRate * 0.7 + (timeInfo->tm_hour * 0.3);
    }
    else if (age < 13 && gender == 'f') {
        fitnessScore = heartRate * 0.6 + (timeInfo->tm_hour * 0.3);
    }

    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Gender: %c\n", gender);
    printf("Heart rate: %d\n", heartRate);
    printf("Fitness score: %d\n", fitnessScore);

    return 0;
}