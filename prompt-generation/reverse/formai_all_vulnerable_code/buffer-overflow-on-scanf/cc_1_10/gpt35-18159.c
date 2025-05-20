//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

//Function to check if the user input is a valid number
int checkInput(char input[])
{
    int i = 0;
    while (input[i] != '\0')
    {
        // If the input is not a digit, return 0
        if (input[i] < '0' || input[i] > '9')
            return 0;
        i++;
    }

    // If all the characters are digits, return 1
    return 1;
}

int main()
{
    char ageInput[3];
    int age;
    char weightInput[4];
    int weight;
    float BMI;

    // Prompt the user to enter their age
    printf("Enter your age (in years): ");
    scanf("%s", ageInput);

    // Validate the user input for age
    while (!checkInput(ageInput))
    {
        printf("Invalid input. Please enter a valid age: ");
        scanf("%s", ageInput);
    }
    age = atoi(ageInput);

    // Prompt the user to enter their weight
    printf("Enter your weight (in pounds): ");
    scanf("%s", weightInput);

    // Validate the user input for weight
    while (!checkInput(weightInput))
    {
        printf("Invalid input. Please enter a valid weight: ");
        scanf("%s", weightInput);
    }
    weight = atoi(weightInput);

    // Calculate the BMI of the user
    BMI = ((float)weight * 703) / ((float)age * (float)age);

    // Display the results to the user
    printf("Your BMI is: %.2f\n", BMI);

    if (BMI < 18.5)
        printf("You are underweight.\n");
    else if (BMI >= 18.5 && BMI < 25)
        printf("You have a healthy weight.\n");
    else if (BMI >= 25 && BMI < 30)
        printf("You are overweight.\n");
    else
        printf("You are obese.\n");

    return 0;
}