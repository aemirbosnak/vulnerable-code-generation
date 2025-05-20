//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Struct to hold user information
typedef struct {
    char name[50];
    int age;
    float weight;
} User;

// Function to create a new user
User* createUser(char* name, int age, float weight) {
    User* newUser = (User*)malloc(sizeof(User));
    strcpy(newUser->name, name);
    newUser->age = age;
    newUser->weight = weight;
    return newUser;
}

// Function to print user information
void printUser(User* user) {
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Weight: %f\n", user->weight);
}

// Function to update user weight
void updateWeight(User* user, float newWeight) {
    user->weight = newWeight;
}

// Function to calculate BMI
float calculateBMI(float weight, float height) {
    return (weight / (height * height));
}

// Function to categorize BMI
char* categorizeBMI(float bmi) {
    if (bmi < 18.5) {
        return "Underweight";
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        return "Normal weight";
    } else if (bmi >= 25 && bmi <= 29.9) {
        return "Overweight";
    } else {
        return "Obese";
    }
}

int main() {
    // Create new user
    User* user = createUser("John Doe", 25, 75);
    
    // Print user information
    printUser(user);
    
    // Update user weight
    updateWeight(user, 80);
    
    // Print updated user information
    printUser(user);
    
    // Calculate BMI
    float bmi = calculateBMI(user->weight, 1.8);
    
    // Categorize BMI
    char* bmiCategory = categorizeBMI(bmi);
    
    // Print BMI category
    printf("BMI Category: %s\n", bmiCategory);
    
    return 0;
}