//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: statistical
#include <stdio.h>

float calculateBMI(float weight, float height, float age) {
    float bmi = weight / (height * height);
    return bmi;
}

float calculateLifespan(float age, char* gender) {
    float lifespan = 0.0;
    if (gender == 'M') {
        lifespan = 76.8;
    } else if (gender == 'F') {
        lifespan = 81.8;
    }
    return lifespan;
}

int main() {
    float weight, height, age;
    char gender[3];
    
    printf("Enter your weight (in kg): ");
    scanf("%f", &weight);
    printf("Enter your height (in meters): ");
    scanf("%f", &height);
    printf("Enter your age: ");
    scanf("%f", &age);
    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender);
    
    float bmi = calculateBMI(weight, height, age);
    float lifespan = calculateLifespan(age, gender);
    
    printf("Your BMI is: %.2f\n", bmi);
    printf("Your estimated lifespan is: %.2f years\n", lifespan);
    
    while (1) {
        printf("Do you want to calculate again? (Y/N): ");
        char choice;
        scanf(" %c", &choice);
        
        if (choice == 'N') {
            break;
        } else {
            printf("Enter your weight (in kg): ");
            scanf("%f", &weight);
            printf("Enter your height (in meters): ");
            scanf("%f", &height);
            printf("Enter your age: ");
            scanf("%f", &age);
            printf("Enter your gender (M/F): ");
            scanf(" %c", &gender);
            
            bmi = calculateBMI(weight, height, age);
            lifespan = calculateLifespan(age, gender);
            
            printf("Your BMI is: %.2f\n", bmi);
            printf("Your estimated lifespan is: %.2f years\n", lifespan);
        }
    }
    
    return 0;
}