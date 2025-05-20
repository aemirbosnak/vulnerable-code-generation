//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the user struct
typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
} User;

// Function to calculate BMI
float calculateBMI(float weight, float height) {
    return (weight / (height * height));
}

// Function to display user info
void displayUserInfo(User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %f\n", user.weight);
    printf("Height: %f\n", user.height);
    printf("BMI: %f\n", user.bmi);
}

// Function to get user input
void getUserInput(User* user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your weight: ");
    scanf("%f", &user->weight);
    printf("Enter your height: ");
    scanf("%f", &user->height);
}

// Function to calculate and display BMI
void calculateAndDisplayBMI(User user) {
    user.bmi = calculateBMI(user.weight, user.height);
    printf("\nYour BMI is: %f\n", user.bmi);
}

// Main function
int main() {
    User user;
    getUserInput(&user);
    calculateAndDisplayBMI(user);
    displayUserInfo(user);
    return 0;
}