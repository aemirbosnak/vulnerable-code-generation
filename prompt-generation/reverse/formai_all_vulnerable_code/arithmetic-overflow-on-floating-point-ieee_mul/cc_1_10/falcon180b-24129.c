//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

// Struct to hold user data
typedef struct {
    char name[MAX_STR_LEN];
    int age;
    double weight;
    double height;
} User;

// Function to initialize user data
void initUser(User *user) {
    strcpy(user->name, "");
    user->age = 0;
    user->weight = 0;
    user->height = 0;
}

// Function to print user data
void printUser(User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %f\n", user.weight);
    printf("Height: %f\n", user.height);
}

// Function to get user input for name
void getName(User *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
}

// Function to get user input for age
void getAge(User *user) {
    printf("Enter your age: ");
    scanf("%d", &user->age);
}

// Function to get user input for weight
void getWeight(User *user) {
    printf("Enter your weight (in kg): ");
    scanf("%lf", &user->weight);
}

// Function to get user input for height
void getHeight(User *user) {
    printf("Enter your height (in cm): ");
    scanf("%lf", &user->height);
}

// Function to calculate BMI
double calculateBMI(double weight, double height) {
    return weight / (height * height);
}

// Function to display user's BMI
void displayBMI(User user) {
    double bmi = calculateBMI(user.weight, user.height);
    printf("Your BMI is: %f\n", bmi);
}

int main() {
    User user;
    initUser(&user);
    getName(&user);
    getAge(&user);
    getWeight(&user);
    getHeight(&user);
    printUser(user);
    displayBMI(user);
    return 0;
}