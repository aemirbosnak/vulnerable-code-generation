//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: random
#include<stdio.h>
#include<math.h>
int main(){
    printf("Welcome to C Fitness Tracker!\n");

    float weight; //float variable for weight
    printf("\nEnter your weight in kgs: ");
    scanf("%f", &weight);

    float height; //float variable for height
    printf("Enter your height in meters: ");
    scanf("%f", &height);

    float bmi = weight / (height * height); //BMI calculation
    printf("\nBased on your weight and height, your BMI is: %.2f \n", bmi);

    if (bmi < 18.5) {
        printf("You are underweight.\n");
    } else if (bmi >= 18.5 && bmi < 25) {
        printf("You are in the healthy weight range.\n");
    } else if (bmi >= 25 && bmi < 30){
        printf("You are overweight.\n");
    } else if (bmi >= 30){
        printf("You are obese.\n");
    }

    int age; //integer variable for age
    printf("\nPlease enter your age: ");
    scanf("%d", &age);

    printf("\nAvailable fitness programs: \n1. Cardio\n2. Strength Training\n3. Yoga\n");

    int choice; //integer variable for choice
    printf("Choose a fitness program (1, 2 or 3): ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("\nCardio is a great choice for improving your cardiovascular health!\n");
            printf("Here is a sample workout you can try:\n");
            printf("* Warm-up: 5 minutes of walking/jogging\n");
            printf("* Main workout: 30 minutes of running\n");
            printf("* Cool-down: 5 minutes of walking\n");
            break;
        case 2:
            printf("\nStrength training is an excellent way to build muscle and increase your metabolism!\n");
            printf("Here is a sample workout you can try:\n");
            printf("* Warm-up: 5 minutes of jumping jacks\n");
            printf("* Main workout: 3 sets of 10 reps of squats, push-ups, and lunges\n");
            printf("* Cool-down: 5 minutes of stretching\n");
            break;
        case 3:
            printf("\nYoga is a great way to improve your flexibility and reduce stress!\n");
            printf("Here is a sample workout you can try:\n");
            printf("* Warm-up: 5 minutes of deep breathing\n");
            printf("* Main workout: 30 minutes of various yoga poses\n");
            printf("* Cool-down: 5 minutes of savasana (relaxation pose)\n");
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
    }

    printf("\nThank you for using C Fitness Tracker. Have a healthy day!\n");

    return 0;
}