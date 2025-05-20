//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: surprised
#include<stdio.h>
#include<string.h>

// Structure for storing customer details
struct Customer {
    char name[50];
    int age;
    float height;
    float weight;
    char gender;
    char email[50];
};

// Function to calculate Body Mass Index (BMI)
float calculateBMI(float height, float weight) {
    float bmi = (weight / ((height/100) * (height/100)));
    return bmi;
}

// Function to display customer data
void displayCustomerData(struct Customer c) {
    printf("\nName: %s", c.name);
    printf("\nAge: %d", c.age);
    printf("\nHeight: %.2f cm", c.height);
    printf("\nWeight: %.2f kg", c.weight);
    printf("\nGender: %c", c.gender);
    printf("\nEmail: %s\n", c.email);
}

int main() {
    struct Customer c;  // Creating instance of Customer structure
    
    printf("Welcome to the C Fitness Tracker!\n");
    printf("Please enter your name: ");
    gets(c.name);
    printf("Please enter your age: ");
    scanf("%d", &c.age);
    printf("Please enter your height (in cm): ");
    scanf("%f", &c.height);
    printf("Please enter your weight (in kg): ");
    scanf("%f", &c.weight);
    printf("Please enter your gender (M/F): ");
    scanf(" %c", &c.gender);
    printf("Please enter your email: ");
    scanf("%s", c.email);

    printf("\nThank you for providing your details. Here are your details:\n");
    displayCustomerData(c);

    float bmi = calculateBMI(c.height, c.weight);
    printf("\nYour Body Mass Index (BMI) is %.2f\n", bmi);

    if (bmi < 18.5) {
        printf("You are Underweight. Please consult a dietician and start exercising.\n");
    }
    else if (bmi >= 18.5 && bmi <= 24.9) {
        printf("Congratulations! Your BMI is in the Normal range. Keep up the good work!\n");
    }
    else if (bmi >= 25 && bmi <= 29.9) {
        printf("You are Overweight. Please consult a dietician and start exercising.\n");
    }
    else {
        printf("You are Obese. Please consult a dietician and start exercising\n");
    }

    printf("\nWe hope to see you soon at the gym. Have a great day!\n");
    return 0;
}