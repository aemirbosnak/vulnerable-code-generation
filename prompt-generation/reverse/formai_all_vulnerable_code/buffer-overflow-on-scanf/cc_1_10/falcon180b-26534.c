//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[100];
    int age;
    double weight;
    double height;
    int steps;
    time_t startTime;
    time_t endTime;
    double distance;
} User;

void printUserInfo(User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %lf\n", user.weight);
    printf("Height: %lf\n", user.height);
    printf("Steps: %d\n", user.steps);
    printf("Start time: %s\n", ctime(&user.startTime));
    printf("End time: %s\n", ctime(&user.endTime));
    printf("Distance: %lf\n\n", user.distance);
}

void startFitnessTracker(User* user) {
    time_t startTime = time(NULL);
    user->startTime = startTime;
    printf("Fitness tracker started at %s\n", ctime(&startTime));
}

void endFitnessTracker(User* user) {
    time_t endTime = time(NULL);
    user->endTime = endTime;
    user->distance = (double)user->steps / (double)user->height;
    printf("Fitness tracker ended at %s\n", ctime(&endTime));
}

void updateSteps(User* user) {
    printf("Enter the number of steps taken: ");
    scanf("%d", &user->steps);
}

int main() {
    User user;
    startFitnessTracker(&user);

    while (1) {
        printf("1. Update steps\n2. View user info\n3. End fitness tracker\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                updateSteps(&user);
                break;
            case 2:
                printUserInfo(user);
                break;
            case 3:
                endFitnessTracker(&user);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}