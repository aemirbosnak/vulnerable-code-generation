//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

#define MAX_WORKOUTS 10

typedef struct workout{
  char name[20];
  int duration;
  int caloriesBurnt;
} Workout;

int main(){
  Workout workouts[MAX_WORKOUTS];
  int numWorkouts = 0;
  printf("Welcome to Fitness Tracker\n\n");
  int choice;
  do{
    printf("1. Add a Workout\n");
    printf("2. Print Workouts\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        if(numWorkouts == MAX_WORKOUTS){
          printf("Maximum number of workouts reached.\n\n");
        }else{
          printf("Enter workout name: ");
          scanf("%s", workouts[numWorkouts].name);
          printf("Enter duration (mins): ");
          scanf("%d", &workouts[numWorkouts].duration);
          printf("Enter calories burnt: ");
          scanf("%d", &workouts[numWorkouts].caloriesBurnt);
          numWorkouts++;
          printf("\nWorkout added!\n\n");
        }
        break;
      case 2:
        if(numWorkouts == 0){
          printf("No workouts to display.\n\n");
        }else{
          printf("Workouts:\n");
          printf("%-20s%-10s%-10s\n", "Name", "Duration", "Calories");
          for(int i = 0; i < numWorkouts; i++){
            printf("%-20s%-10d%-10d\n", workouts[i].name, workouts[i].duration, workouts[i].caloriesBurnt);
          }
          printf("\n");
        }
        break;
      case 3:
        printf("Thank you for using Fitness Tracker!\n");
        break;
      default:
        printf("Invalid choice. Please enter a number between 1 and 3.\n\n");
        break;
    }
  }while(choice != 3);
  return 0;
}