//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FitnessTracker {
    char name[20];
    int age;
    double weight;
    double height;
    double bmi;
    int stepsTaken;
    double totalDistanceTraveled;
    struct FitnessTracker *next;
} FitnessTracker;

void calculateBMI(FitnessTracker *ft) {
    ft->bmi = (ft->weight * 703) / (ft->height * ft->height);
}

void calculateTotalDistance(FitnessTracker *ft) {
    ft->totalDistanceTraveled = ft->stepsTaken * 0.025;
}

void addFitnessTracker(FitnessTracker **head) {
    FitnessTracker *newTracker = (FitnessTracker *)malloc(sizeof(FitnessTracker));
    printf("Enter name: ");
    scanf("%s", newTracker->name);
    printf("Enter age: ");
    scanf("%d", &newTracker->age);
    printf("Enter weight: ");
    scanf("%lf", &newTracker->weight);
    printf("Enter height: ");
    scanf("%lf", &newTracker->height);
    calculateBMI(newTracker);
    calculateTotalDistance(newTracker);
    newTracker->next = *head;
    *head = newTracker;
}

void displayFitnessTracker(FitnessTracker *head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Age: %d\n", head->age);
        printf("Weight: %.2lf\n", head->weight);
        printf("Height: %.2lf\n", head->height);
        printf("BMI: %.2lf\n", head->bmi);
        printf("Total Distance Traveled: %.2lf miles\n", head->totalDistanceTraveled);
        printf("\n");
        head = head->next;
    }
}

int main() {
    FitnessTracker *head = NULL;
    addFitnessTracker(&head);
    addFitnessTracker(&head);
    displayFitnessTracker(head);
    return 0;
}