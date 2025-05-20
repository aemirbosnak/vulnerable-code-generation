//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float height;
    float weight;
    char gender[10];
    int steps;
    float distance;
    int calories;
} User;

void createUser(User* user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your height in cm: ");
    scanf("%f", &user->height);
    printf("Enter your weight in kg: ");
    scanf("%f", &user->weight);
    printf("Enter your gender (M/F/O): ");
    scanf("%s", user->gender);
}

void setSteps(User* user) {
    printf("Enter the number of steps: ");
    scanf("%d", &user->steps);
}

void setDistance(User* user) {
    printf("Enter the distance in km: ");
    scanf("%f", &user->distance);
}

void setCalories(User* user) {
    printf("Enter the number of calories burned: ");
    scanf("%d", &user->calories);
}

void displayUser(User* user) {
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Height: %0.2f cm\n", user->height);
    printf("Weight: %0.2f kg\n", user->weight);
    printf("Gender: %s\n", user->gender);
    printf("Steps: %d\n", user->steps);
    printf("Distance: %0.2f km\n", user->distance);
    printf("Calories burned: %d\n", user->calories);
}

int main() {
    User user;
    createUser(&user);
    setSteps(&user);
    setDistance(&user);
    setCalories(&user);
    displayUser(&user);
    return 0;
}