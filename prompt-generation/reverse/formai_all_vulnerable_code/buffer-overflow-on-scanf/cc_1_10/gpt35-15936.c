//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person{
    char name[20];
    int age;
    float height;
    float weight;
    float bmi;
    int calories;
};

void displayMenu(){
    printf("Select an option:\n");
    printf("1. Add a person\n");
    printf("2. Calculate BMI\n");
    printf("3. Calculate Daily Calorie Intake\n");
    printf("4. Exit\n");
}

void addPerson(struct person p[], int* count){
    printf("Enter name: ");
    scanf("%s", p[*count].name);
    printf("Enter age: ");
    scanf("%d", &p[*count].age);
    printf("Enter height in meters: ");
    scanf("%f", &p[*count].height);
    printf("Enter weight in kgs: ");
    scanf("%f", &p[*count].weight);
    printf("Person added successfully!\n\n");
    *count += 1;
}

void calculateBMI(struct person p[], int count){
    int i;
    for(i=0;i<count;i++){
        p[i].bmi = p[i].weight / (p[i].height * p[i].height);
        printf("%s's BMI: %f\n", p[i].name, p[i].bmi);
        if(p[i].bmi < 18.5){
            printf("Underweight\n\n");
        }
        else if(p[i].bmi >= 18.5 && p[i].bmi < 25){
            printf("Normal\n\n");
        }
        else if(p[i].bmi >= 25 && p[i].bmi < 30){
            printf("Overweight\n\n");
        }
        else{
            printf("Obese\n\n");
        }
    }
}

void calculateCalories(struct person p[], int count){
    int i, gender, activityLevel;
    float bmr, calorieIntake;
    char activityLevels[4][50] = {"Sedentary (Little or no exercise)", "Lightly active (1-3 days per week)", "Moderately active (3-5 days per week)", "Very active (6-7 days per week)"};

    for(i=0;i<count;i++){
        printf("Is %s Male (1) or Female (0): ", p[i].name);
        scanf("%d", &gender);
        while(gender != 1 && gender != 0){
            printf("Invalid option. Is %s Male (1) or Female (0): ", p[i].name);
            scanf("%d", &gender);
        }

        printf("Enter %s's BMR: ", p[i].name);
        scanf("%f", &bmr);

        printf("Select activity level for %s:\n", p[i].name);
        printf("1. Sedentary (Little or no exercise)\n");
        printf("2. Lightly active (1-3 days per week)\n");
        printf("3. Moderately active (3-5 days per week)\n");
        printf("4. Very active (6-7 days per week)\n");

        scanf("%d", &activityLevel);
        while(activityLevel < 1 || activityLevel > 4){
            printf("Invalid option. Select activity level for %s:\n", p[i].name);
            printf("1. Sedentary (Little or no exercise)\n");
            printf("2. Lightly active (1-3 days per week)\n");
            printf("3. Moderately active (3-5 days per week)\n");
            printf("4. Very active (6-7 days per week)\n");
            scanf("%d", &activityLevel);
        }

        calorieIntake = bmr * activityLevel;
        printf("\n%s's Daily Calorie Intake: %f\n\n", p[i].name, calorieIntake);
    }
}

int main(){
    int choice, count = 0;
    struct person p[10];

    do{
        displayMenu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(count == 10){
                    printf("Max limit reached! Cannot add more people.\n\n");
                    break;
                }
                addPerson(p, &count);
                break;

            case 2:
                if(count == 0){
                    printf("No people added yet!\n\n");
                    break;
                }
                calculateBMI(p, count);
                break;

            case 3:
                if(count == 0){
                    printf("No people added yet!\n\n");
                    break;
                }
                calculateCalories(p, count);
                break;

            case 4:
                printf("Exiting program...");
                break;

            default:
                printf("Invalid option!\n\n");
        }
    }while(choice != 4);

    return 0;
}