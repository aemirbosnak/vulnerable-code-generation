//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of users
#define MAX_USERS 10

// Define the structure for a user
typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
} User;

// Function to initialize a user with default values
void initUser(User* user) {
    strcpy(user->name, "Unknown");
    user->age = 0;
    user->weight = 0;
    user->height = 0;
}

// Function to read a user from standard input
void readUser(User* user) {
    printf("Enter your name: ");
    scanf("%s", user->name);

    printf("Enter your age: ");
    scanf("%d", &user->age);

    printf("Enter your weight (in kg): ");
    scanf("%f", &user->weight);

    printf("Enter your height (in cm): ");
    scanf("%f", &user->height);
}

// Function to print a user's information
void printUser(User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %0.2f kg\n", user.weight);
    printf("Height: %0.2f cm\n", user.height);
}

// Function to calculate a user's BMI
float calculateBMI(User user) {
    return (user.weight / (user.height * user.height));
}

// Function to classify a user's BMI
char* classifyBMI(float bmi) {
    if (bmi < 18.5) {
        return "Underweight";
    } else if (bmi >= 18.5 && bmi < 25) {
        return "Normal weight";
    } else if (bmi >= 25 && bmi < 30) {
        return "Overweight";
    } else {
        return "Obese";
    }
}

int main() {
    // Initialize an array of users
    User users[MAX_USERS];

    // Initialize all users with default values
    for (int i = 0; i < MAX_USERS; i++) {
        initUser(&users[i]);
    }

    // Read users from standard input
    int numUsers = 0;
    while (numUsers < MAX_USERS && scanf("%d", &numUsers) == 1) {
        for (int i = 0; i < numUsers; i++) {
            readUser(&users[i]);
        }
    }

    // Print each user's information and BMI classification
    printf("Fitness Tracker Results\n");
    for (int i = 0; i < numUsers; i++) {
        printUser(users[i]);
        printf("BMI: %0.2f (%s)\n\n", calculateBMI(users[i]), classifyBMI(calculateBMI(users[i])));
    }

    return 0;
}