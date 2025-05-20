//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int weight, height, age, gender;
    
    printf("Welcome to the Fitness Tracker Program!\n");
    
    printf("Please enter your weight in kg: ");
    scanf("%d", &weight);
    printf("Please enter your height in cm: ");
    scanf("%d", &height);
    printf("Please enter your age: ");
    scanf("%d", &age);
    
    printf("Please enter your gender: \n1. Male\n2. Female\n");
    scanf("%d", &gender);
    
    float bmr;
    if(gender == 1)
    {
        //BMR calculation for males
        bmr = 88.36 + (13.4 * weight) + (4.8 * height) - (5.7 * age);
    }
    else
    {
        //BMR calculation for females
        bmr = 447.6 + (9.2 * weight) + (3.1 * height) - (4.3 * age);
    }
    
    printf("Your Basal Metabolic Rate (BMR) is: %.2f calories\n", bmr);
    
    float calorie_multiplier;
    
    printf("Please enter your activity level: \n1. Sedentary (Little or no exercise)\n2. Lightly Active (Light exercise/sports 1-3 days a week)\n3. Moderately Active (Moderate exercise/sports 3-5 days a week)\n4. Very Active (Hard exercise/sports 6-7 days a week)\n5. Super Active (Very hard exercise/sports, physical job or training twice a day)\n");
    scanf("%f", &calorie_multiplier);
    
    float tdee = bmr * calorie_multiplier;
    
    printf("Your Total Daily Energy Expenditure (TDEE) is: %.2f calories\n", tdee);
    
    float target_weight;
    printf("Please enter your target weight in kg: ");
    scanf("%f", &target_weight);
    
    printf("To reach your target weight, you need to consume %.2f calories per day\n", tdee - ((weight - target_weight) * 7000 / 30));
    
    return 0;
}