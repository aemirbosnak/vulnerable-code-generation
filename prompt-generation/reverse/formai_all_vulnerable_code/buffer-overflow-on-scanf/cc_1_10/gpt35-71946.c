//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 1000
#define MAX_WORKOUTS 5

// User structure
struct User {
  char name[50];
  int age;
  float weight;
  float height;
  float BMI;
  int workoutCount;
  struct Workout *workouts[MAX_WORKOUTS];
};

// Workout structure
struct Workout {
  char name[50];
  float duration;
  float caloriesBurned;
};

// Global variables
struct User users[MAX_USERS];
int userCount = 0;

// Main menu function
void displayMenu() {
  printf("\n*** FITNESS TRACKER ***\n");
  printf("1. Create User\n");
  printf("2. View Users\n");
  printf("3. Add Workout\n");
  printf("4. View Workouts\n");
  printf("5. Exit\n");
}

// Create new user function
void createUser() {
  printf("Enter name: ");
  scanf("%s", &users[userCount].name);
  printf("Enter age: ");
  scanf("%d", &users[userCount].age);
  printf("Enter weight (kg): ");
  scanf("%f", &users[userCount].weight);
  printf("Enter height (m): ");
  scanf("%f", &users[userCount].height);
  users[userCount].BMI = users[userCount].weight / (users[userCount].height * users[userCount].height);
  users[userCount].workoutCount = 0;
  userCount++;
  printf("\nNew user created!\n");
}

// View all users function
void viewUsers() {
  printf("**** USERS (%d) ****\n", userCount);
  for(int i=0; i<userCount; i++) {
    printf("%d. %s (age=%d, weight=%.2fkg, height=%.2fm, BMI=%.2f)\n", i+1, users[i].name, users[i].age, users[i].weight, users[i].height, users[i].BMI);
  }
}

// Add new workout to a user function
void addWorkout() {
  char username[50];
  printf("Enter username: ");
  scanf("%s", &username);
  int foundUserIndex = -1;
  for(int i=0; i<userCount; i++) {
    if(strcmp(users[i].name, username) == 0) {
      foundUserIndex = i;
      break;
    }
  }
  if(foundUserIndex == -1) {
    printf("User %s not found!\n", username);
    return;
  }
  printf("Enter workout name: ");
  scanf("%s", &users[foundUserIndex].workouts[users[foundUserIndex].workoutCount]->name);
  printf("Enter workout duration (minutes): ");
  scanf("%f", &users[foundUserIndex].workouts[users[foundUserIndex].workoutCount]->duration);
  printf("Enter calories burned: ");
  scanf("%f", &users[foundUserIndex].workouts[users[foundUserIndex].workoutCount]->caloriesBurned);
  users[foundUserIndex].workoutCount++;
  printf("\nNew workout added to user %s!\n", username);
}

// View all workouts of a user function
void viewWorkouts() {
  char username[50];
  printf("Enter username: ");
  scanf("%s", &username);
  int foundUserIndex = -1;
  for(int i=0; i<userCount; i++) {
    if(strcmp(users[i].name, username) == 0) {
      foundUserIndex = i;
      break;
    }
  }
  if(foundUserIndex == -1) {
    printf("User %s not found!\n", username);
    return;
  }
  printf("**** WORKOUTS OF %s ****\n", username);
  for(int i=0; i<users[foundUserIndex].workoutCount; i++) {
    printf("%d. %s (duration=%.2f minutes, calories burned=%.2f)\n", i+1, users[foundUserIndex].workouts[i]->name, users[foundUserIndex].workouts[i]->duration, users[foundUserIndex].workouts[i]->caloriesBurned);
  }
}

int main() {
  int choice = 0;
  do {
    displayMenu();
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        createUser();
        break;
      case 2:
        viewUsers();
        break;
      case 3:
        addWorkout();
        break;
      case 4:
        viewWorkouts();
        break;
      case 5:
        printf("Exiting program...");
        break;
      default:
        printf("Invalid choice! Try again.\n");
        break;
    }
  } while(choice != 5);
  return 0;
}