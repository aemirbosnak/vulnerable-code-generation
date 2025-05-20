//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: optimized
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Struct for storing user data
struct user {
    char name[20];
    int age;
    char gender[10];
    float height;
    float weight;
};

// Function for getting user data
void getUserData(struct user *u) {
    printf("Enter name: ");
    scanf("%s", u->name);
    printf("Enter age: ");
    scanf("%d", &u->age);
    printf("Enter gender: ");
    scanf("%s", u->gender);
    printf("Enter height in meters: ");
    scanf("%f", &u->height);
    printf("Enter weight in Kg: ");
    scanf("%f", &u->weight);
}

// Function for calculating BMI
float calculateBMI(struct user u) {
    float bmi = u.weight / (u.height * u.height);
    return bmi;
}

// Function for displaying user data and BMI status
void displayUserData(struct user u) {
    float bmi = calculateBMI(u);
    printf("\nUser Data\n");
    printf("Name: %s\n", u.name);
    printf("Age: %d\n", u.age);
    printf("Gender: %s\n", u.gender);
    printf("Height: %.2fm\n", u.height);
    printf("Weight: %.2fkg\n", u.weight);
    printf("BMI: %.2f\n", bmi);
    
    // Check BMI status
    if(bmi < 18.5) {
        printf("BMI status: Underweight\n");
    } else if(bmi >= 18.5 && bmi < 25) {
        printf("BMI status: Normal\n");
    } else if(bmi >= 25 && bmi < 30) {
        printf("BMI status: Overweight\n");
    } else {
        printf("BMI status: Obese\n");
    }
}

// Driver program
int main() {
    struct user u;
    getUserData(&u);
    displayUserData(u);
    return 0;
}