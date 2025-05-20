//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: energetic
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  // Struct for storing user information
  struct user {
    char name[20];
    int age;
    int height;
    int weight;
    int calories_burned;
  };

  // Function to get user information
  void get_user_info(struct user *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);

    printf("Enter your age: ");
    scanf("%d", &user->age);

    printf("Enter your height in cm: ");
    scanf("%d", &user->height);

    printf("Enter your weight in kg: ");
    scanf("%d", &user->weight);

    printf("Enter the number of calories you burned today: ");
    scanf("%d", &user->calories_burned);
  }

  // Function to calculate BMI
  float calculate_bmi(struct user *user) {
    return (user->weight / (user->height * user->height)) * 10000;
  }

  // Function to print user information
  void print_user_info(struct user *user) {
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Height: %d cm\n", user->height);
    printf("Weight: %d kg\n", user->weight);
    printf("BMI: %f\n", calculate_bmi(user));
    printf("Calories burned: %d\n", user->calories_burned);
  }

  int main() {
    // Declare and initialize a user struct
    struct user user;
    memset(&user, 0, sizeof(user));

    // Get user information
    get_user_info(&user);

    // Calculate and print BMI
    printf("Your BMI is: %f\n", calculate_bmi(&user));

    // Print user information
    print_user_info(&user);

    return 0;
  }