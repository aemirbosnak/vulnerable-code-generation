//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*Medieval Fitness Tracker Program*/

//function to calculate calories burned during exercise
int calc_calories_burned(int time_spent_exercising, int intensity_level){
    int base_calories_burned = 100;
    int total_calories_burned;
    if(intensity_level == 1){
        total_calories_burned = base_calories_burned * time_spent_exercising;
    }
    else if(intensity_level == 2){
        total_calories_burned = (base_calories_burned+25) * time_spent_exercising;
    }
    else if(intensity_level == 3){
        total_calories_burned = (base_calories_burned+50) * time_spent_exercising;
    }
    return total_calories_burned;
}

//function to display fitness progress
void display_fitness_progress(int total_days, int total_calories_burned){
    printf("After %d days of training, you have burned %d calories.\n", total_days, total_calories_burned);
    if(total_calories_burned < 1000){
        printf("You need to train more, the journey is long.\n");
    }
    else if(total_calories_burned >= 1000 && total_calories_burned <2000){
        printf("Good start, keep it up.\n");
    }
    else if(total_calories_burned >= 2000 && total_calories_burned <4000){
        printf("Impressive, your body is getting stronger every day!\n");
    }
    else{
        printf("The gods themselves marvel at your strength and dedication!\n");
    }
}

int main(){
    //initialize variables
    int time_spent_exercising, intensity_level, total_days, total_calories_burned = 0;
    char response;

    printf("Welcome to the Medieval Fitness Tracker!\n");
    printf("We will track your progress on your journey to become a warrior of great physical prowess.\n");

    do{
        printf("\nHow long did you spend training today (in minutes)? ");
        scanf("%d", &time_spent_exercising);

        printf("How intense was your training today?\n1 for Light, 2 for Medium, 3 for Heavy: ");
        scanf("%d", &intensity_level);

        int calories_burned = calc_calories_burned(time_spent_exercising, intensity_level);
        total_calories_burned += calories_burned;

        printf("You have burned %d calories today.\n", calories_burned);

        //update days of training
        total_days++;

        printf("Do you wish to track another day's training? (Y/N): ");
        scanf(" %c", &response);

    }while(response == 'Y' || response == 'y');

    printf("\n***Training Summary***\n");
    display_fitness_progress(total_days, total_calories_burned);

    printf("\nFare thee well, warrior, and keep on training!\n");

    return 0;
}