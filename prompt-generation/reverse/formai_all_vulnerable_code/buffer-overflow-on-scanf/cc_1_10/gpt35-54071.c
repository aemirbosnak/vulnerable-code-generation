//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h>
#include <string.h>

struct Exercise {
  char name[50];
  int duration;
};

struct Diet {
  char food[50];
  int calories;
};

struct User {
  char name[50];
  int age;
  int weight;
  int height;
  struct Exercise exercises[7];
  struct Diet diets[7];
  int total_exercise_duration;
  int total_calories_consumed;
};

void add_exercise(struct User *user, char name[], int duration) {
  int index = -1;
  for (int i = 0; i < 7; i++) {
    if (strcmp(user->exercises[i].name, "") == 0) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    printf("You have reached the maximum limit of exercises for the week! \n");
  } else {
    strcpy(user->exercises[index].name, name);
    user->exercises[index].duration = duration;
    user->total_exercise_duration += duration;
    printf("Successfully added exercise: %s for %d minutes! \n", name, duration);
  }
}

void add_diet(struct User *user, char food[], int calories) {
  int index = -1;
  for (int i = 0; i < 7; i++) {
    if (strcmp(user->diets[i].food, "") == 0) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    printf("You have reached the maximum limit of diets for the week! \n");
  } else {
    strcpy(user->diets[index].food, food);
    user->diets[index].calories = calories;
    user->total_calories_consumed += calories;
    printf("Successfully added food: %s with %d calories! \n", food, calories);
  }
}

void display_user(struct User user) {
  printf("\nUser's profile: \n");
  printf("- Name: %s \n", user.name);
  printf("- Age: %d \n", user.age);
  printf("- Weight: %d kg \n", user.weight);
  printf("- Height: %d cm \n", user.height);
  printf("- Total exercise duration: %d minutes \n", user.total_exercise_duration);
  printf("- Total calories consumed: %d calories \n", user.total_calories_consumed);
  printf("- Exercises for the week: \n");
  for (int i = 0; i < 7; i++) {
    if (strcmp(user.exercises[i].name, "") != 0) {
      printf("  * %s for %d minutes \n", user.exercises[i].name, user.exercises[i].duration);
    }
  }
  printf("- Diets for the week: \n");
  for (int i = 0; i < 7; i++) {
    if (strcmp(user.diets[i].food, "") != 0) {
      printf("  * %s with %d calories \n", user.diets[i].food, user.diets[i].calories);
    }
  }
}

int main() {
  struct User user = { "", 0, 0, 0, {}, {}, 0, 0 };
  printf("Welcome to the Fitness Tracker! Please create your profile: \n");
  printf("Enter your name: ");
  scanf("%s", user.name);
  printf("Enter your age: ");
  scanf("%d", &user.age);
  printf("Enter your weight (kg): ");
  scanf("%d", &user.weight);
  printf("Enter your height (cm): ");
  scanf("%d", &user.height);
  printf("\nHello %s! Here's what you can do: \n", user.name);
  
  char option;
  do {
    printf("\nEnter 'E' to add an exercise, 'D' to add a diet, 'V' to view your profile or 'Q' to quit: ");
    scanf(" %c", &option);
    switch (option) {
      case 'E': {
        char name[50];
        int duration;
        printf("Enter the name of the exercise: ");
        scanf("%s", name);
        printf("Enter the duration (minutes): ");
        scanf("%d", &duration);
        add_exercise(&user, name, duration);
        break;
      }
      case 'D': {
        char food[50];
        int calories;
        printf("Enter the name of the food: ");
        scanf("%s", food);
        printf("Enter the calories: ");
        scanf("%d", &calories);
        add_diet(&user, food, calories);
        break;
      }
      case 'V': {
        display_user(user);
        break;
      }
      case 'Q': {
        printf("Goodbye %s! Keep up the good work!\n", user.name);
        break;
      }
      default: {
        printf("Invalid option! Try again.\n");
      }
    }
  } while (option != 'Q');
  return 0;
}