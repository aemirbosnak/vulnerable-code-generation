//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct FitnessTracker{
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
    float calorieGoal;
    float calorieIntake;
    float calorieBurned;
};

typedef struct FitnessTracker Tracker;

void getBMI(Tracker *t){
    t->bmi = t->weight/(t->height*t->height);
}

void getCalorieGoal(Tracker *t){
    if(t->bmi < 18.5){
        t->calorieGoal = 2000;
    }else if(t->bmi >= 18.5 && t->bmi <= 24.9){
        t->calorieGoal = 2500;
    }else{
        t->calorieGoal = 3000;
    }
}

void recordCalorieIntake(Tracker *t, float calorieIntake){
    t->calorieIntake += calorieIntake;
}

void recordCalorieBurned(Tracker *t, float calorieBurned){
    t->calorieBurned += calorieBurned;
}

int main(){
    int choice;
    Tracker t;
    printf("Welcome to Fitness Tracker!\n");
    printf("Please enter your name: ");
    fgets(t.name, 50, stdin);
    t.name[strcspn(t.name, "\n")] = 0;
    printf("Please enter your age: ");
    scanf("%d", &t.age);
    printf("Please enter your weight (in kgs): ");
    scanf("%f", &t.weight);
    printf("Please enter your height (in m): ");
    scanf("%f", &t.height);
    getBMI(&t);
    getCalorieGoal(&t);
    printf("\n");
    while(1){
        printf("\n");
        printf("1. Record calorie intake\n");
        printf("2. Record calorie burned\n");
        printf("3. View daily calorie summary\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                float calorieIntake;
                printf("Enter calorie intake (in calories): ");
                scanf("%f", &calorieIntake);
                recordCalorieIntake(&t, calorieIntake);
                break;
            }
            case 2:{
                float calorieBurned;
                printf("Enter calorie burned (in calories): ");
                scanf("%f", &calorieBurned);
                recordCalorieBurned(&t, calorieBurned);
                break;
            }
            case 3:{
                printf("\n");
                printf("----------Calorie Summary----------\n");
                printf("Calorie Goal: %.2f\n", t.calorieGoal);
                printf("Calorie Intake: %.2f\n", t.calorieIntake);
                printf("Calorie Burned: %.2f\n", t.calorieBurned);
                float calorieBalance = t.calorieIntake - t.calorieBurned;
                if(calorieBalance > 0){
                    printf("Calorie Balance: %.2f (Extra calorie intake)\n", calorieBalance);
                }else if(calorieBalance < 0){
                    printf("Calorie Balance: %.2f (Extra calorie burned)\n", -calorieBalance);
                }else{
                    printf("Calorie Balance: %.2f\n", calorieBalance);
                }
                break;
            }
            case 4:{
                exit(0);
            }
            default:{
                printf("Invalid choice. Please choose again.\n");
                break;
            }
        }
    }
    return 0;
}