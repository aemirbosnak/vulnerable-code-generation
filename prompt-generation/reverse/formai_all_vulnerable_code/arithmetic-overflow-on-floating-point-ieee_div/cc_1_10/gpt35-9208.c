//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: inquisitive
#include <stdio.h>

int main() {
    printf("Welcome to the Fitness Tracker!\n");
    
    int age;
    float weight, height;
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter your weight (in kg): ");
    scanf("%f", &weight);
    printf("Please enter your height (in meters): ");
    scanf("%f", &height);
    
    float bmi = weight / (height * height);
    printf("\nYour BMI value is: %.2f\n\n", bmi);
    printf("BMI Categories:\n");
    printf("Underweight: less than 18.5\n");
    printf("Normal:      between 18.5 and 24.9\n");
    printf("Overweight:  between 25 and 29.9\n");
    printf("Obese:       30 or greater\n\n");
    
    int bpm;
    printf("Please enter your current heart rate (in beats per minute): ");
    scanf("%d", &bpm);
    printf("Your heart rate is %d bpm.\n\n", bpm);
    printf("Heart Rate Zones (in bpm):\n");
    printf("Recovery Zone:    less than 70%% of Max HR\n");
    printf("Fat Burn Zone:    between 70%% and 85%% of Max HR\n");
    printf("Cardio Zone:      between 85%% and 95%% of Max HR\n");
    printf("Peak Zone:        greater than 95%% of Max HR\n\n");
    
    int max_hr = 220 - age;
    printf("Your Maximum Heart Rate is %d bpm.\n\n", max_hr);
    printf("Heart Rate Training Zones:\n");
    printf("Recovery Zone:    %.0f - %.0f bpm\n", 0.5 * max_hr, 0.7 * max_hr);
    printf("Fat Burn Zone:    %.0f - %.0f bpm\n", 0.7 * max_hr, 0.85 * max_hr);
    printf("Cardio Zone:      %.0f - %.0f bpm\n", 0.85 * max_hr, 0.95 * max_hr);
    printf("Peak Zone:        %.0f - %.0f bpm\n\n", 0.95 * max_hr, max_hr);
    
    float cal_burned;
    printf("Please enter the number of minutes you have exercised: ");
    int min;
    scanf("%d", &min);
    printf("Please enter the type of exercise performed (1 - Running, 2 - Cycling, 3 - Swimming): ");
    int type;
    scanf("%d", &type);
    switch(type) {
        case 1:
            cal_burned = 0.1 * weight * min;
            break;
        case 2:
            cal_burned = 0.08 * weight * min;
            break;
        case 3:
            cal_burned = 0.12 * weight * min;
            break;
        default:
            printf("Invalid exercise type!\n");
            return 1;
    }
    printf("\nYou have burnt %.2f calories.\n", cal_burned);
    printf("Great job!\n\n");
    
    return 0;
}