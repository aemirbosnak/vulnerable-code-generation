//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct workout{
    char name[20];
    int calories_burned;
    float time;
};

int main(){
    int option, num_workouts = 0;
    struct workout workouts[10];
    printf("***Fitness Tracker***\n");

    do{
        printf("\nChoose an option:\n");
        printf("1. Add a new workout\n");
        printf("2. Display all workouts\n");
        printf("3. Display total calories burned\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch(option){
            case 1:
                if(num_workouts == 10){
                    printf("Maximum number of workouts reached!\n");
                    break;
                }
                printf("Enter workout name: ");
                scanf("%s", workouts[num_workouts].name);
                printf("Enter time spent (in hours): ");
                scanf("%f", &workouts[num_workouts].time);
                printf("Enter calories burned: ");
                scanf("%d", &workouts[num_workouts].calories_burned);
                num_workouts++;
                printf("Workout added successfully!\n");
                break;
            
            case 2:
                if(num_workouts == 0){
                    printf("No workouts to display!\n");
                    break;
                }
                printf("\nWorkout History:\n");
                printf("%-20s %-10s %-10s\n", "Workout Name", "Time (h)", "Calories");
                for(int i=0; i<num_workouts; i++){
                    printf("%-20s %-10.2f %-10d\n", workouts[i].name, workouts[i].time, workouts[i].calories_burned);
                }
                break;

            case 3:
                if(num_workouts == 0){
                    printf("No workouts to display!\n");
                    break;
                }
                int total_calories = 0;
                for(int i=0; i<num_workouts; i++){
                    total_calories += workouts[i].calories_burned;
                }
                printf("\nTotal Calories Burned: %d\n", total_calories);
                break;
            
            case 4:
                printf("Thank you for using Fitness Tracker!\n");
                break;

            default:
                printf("Invalid option!\n");
                break;
        }
    }while(option != 4);

    return 0;
}