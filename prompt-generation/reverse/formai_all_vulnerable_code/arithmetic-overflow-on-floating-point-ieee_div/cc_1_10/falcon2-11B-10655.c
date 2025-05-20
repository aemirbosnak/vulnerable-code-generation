//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: light-weight
#include <stdio.h>
#include <time.h>

// Function to calculate BMI (Body Mass Index)
float calculate_bmi(float height, float weight) {
    float bmi = weight / (height * height);
    return bmi;
}

// Function to check if BMI is in the normal range
int is_bmi_normal(float bmi) {
    if (bmi >= 18.5 && bmi <= 24.9) {
        return 1; // Normal BMI
    } else if (bmi < 18.5) {
        return 2; // Underweight
    } else if (bmi > 24.9 && bmi <= 29.9) {
        return 3; // Overweight
    } else {
        return 4; // Obese
    }
}

int main() {
    float height, weight;
    int bmi_status;
    char response;

    printf("Enter your height in meters: ");
    scanf("%f", &height);

    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);

    float bmi = calculate_bmi(height, weight);
    bmi_status = is_bmi_normal(bmi);

    printf("Your BMI is %.2f.\n", bmi);
    switch (bmi_status) {
        case 1:
            printf("Your BMI is in the normal range.\n");
            break;
        case 2:
            printf("Your BMI is underweight.\n");
            break;
        case 3:
            printf("Your BMI is overweight.\n");
            break;
        case 4:
            printf("Your BMI is obese.\n");
            break;
    }

    printf("Do you want to calculate BMI again? (Y/N): ");
    scanf(" %c", &response);

    return 0;
}