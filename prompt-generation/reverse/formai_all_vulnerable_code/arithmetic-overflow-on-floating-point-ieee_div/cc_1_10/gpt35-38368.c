//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: immersive
#include <stdio.h>
#include <stdbool.h>

// Function to calculate BMI
float calculateBMI(float weight, float height) {
    float bmi;
    bmi = weight / (height * height);
    return bmi;
}

int main() {
    float weight, height, bmi;
    bool isUnderweight, isNormalweight, isOverweight, isObese;

    printf("Enter your weight in kg: ");
    scanf("%f", &weight);

    printf("Enter your height in meters: ");
    scanf("%f", &height);

    bmi = calculateBMI(weight, height);

    printf("Your BMI is: %.2f\n", bmi);

    if (bmi < 18.5) {
        isUnderweight = true;
        isNormalweight = false;
        isOverweight = false;
        isObese = false;
        printf("You are underweight.\n");
    } else if (bmi >= 18.5 && bmi < 25) {
        isUnderweight = false;
        isNormalweight = true;
        isOverweight = false;
        isObese = false;
        printf("You are of normal weight.\n");
    } else if (bmi >= 25 && bmi < 30) {
        isUnderweight = false;
        isNormalweight = false;
        isOverweight = true;
        isObese = false;
        printf("You are overweight.\n");
    } else {
        isUnderweight = false;
        isNormalweight = false;
        isOverweight = false;
        isObese = true;
        printf("You are obese.\n");
    }

    FILE *fp;
    fp = fopen("fitness_tracker.txt", "a");

    if (fp != NULL) {
        fprintf(fp, "Weight: %.2f kg \n", weight);
        fprintf(fp, "Height: %.2f m \n", height);
        fprintf(fp, "BMI: %.2f \n", bmi);

        if (isUnderweight) {
            fprintf(fp, "Status: Underweight \n");
        } else if (isNormalweight) {
            fprintf(fp, "Status: Normal weight \n");
        } else if (isOverweight) {
            fprintf(fp, "Status: Overweight \n");
        } else {
            fprintf(fp, "Status: Obese \n");
        }

        fprintf(fp, "\n");
        fclose(fp);
    }

    return 0;
}