//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
    char name[20];
    int age;
    float weight;
    float height;
};

struct exercise {
    char name[20];
    float calories;
    int duration;
};

int main() {
    int num_users, num_exercises, user_choice, exercise_choice, time_spent;
    float user_bmi, user_bmr, user_total_calories = 0;
    struct user *users;
    struct exercise *exercises;
    
    // Get user and exercise information
    printf("Enter the number of users: ");
    scanf("%d", &num_users);
    
    printf("\nEnter the number of exercises: ");
    scanf("%d", &num_exercises);
    
    users = (struct user*) malloc(num_users * sizeof(struct user));
    exercises = (struct exercise*) malloc(num_exercises * sizeof(struct exercise));
    
    for (int i = 0; i < num_users; i++) {
        printf("\nEnter User %d's Name: ", i+1);
        scanf("%s", users[i].name);
        
        printf("Enter User %d's Age: ", i+1);
        scanf("%d", &users[i].age);
        
        printf("Enter User %d's Weight (in kgs): ", i+1);
        scanf("%f", &users[i].weight);
        
        printf("Enter User %d's Height (in cms): ", i+1);
        scanf("%f", &users[i].height);
    }
    
    for (int i = 0; i < num_exercises; i++) {
        printf("\nEnter Exercise %d's Name: ", i+1);
        scanf("%s", exercises[i].name);
        
        printf("Enter Exercise %d's Calories Burned Per Minute: ", i+1);
        scanf("%f", &exercises[i].calories);
    }
    
    // Present user with choices
    printf("\nSelect a user (1-%d):\n", num_users);
    for (int i = 0; i < num_users; i++) {
        printf("%d. %s\n", i+1, users[i].name);
    }
    scanf("%d", &user_choice);
    user_choice--;
    
    // Calculate user's BMI and BMR
    user_bmi = users[user_choice].weight / ((users[user_choice].height / 100) * (users[user_choice].height / 100));
    user_bmr = 10 * users[user_choice].weight + 6.25 * users[user_choice].height - 5 * users[user_choice].age + 5;
    
    // Present user with exercise choices
    printf("\nSelect an exercise (1-%d):\n", num_exercises);
    for (int i = 0; i < num_exercises; i++) {
        printf("%d. %s\n", i+1, exercises[i].name);
    }
    scanf("%d", &exercise_choice);
    exercise_choice--;

    // Get user input for time spent on exercise
    printf("\nHow many minutes did you spend on the exercise? ");
    scanf("%d", &time_spent);
    
    // Calculate total calories burned by user
    user_total_calories = exercises[exercise_choice].calories * time_spent;

    printf("\n%s burned %.2f calories doing %s for %d minutes.\n\n", users[user_choice].name, user_total_calories, exercises[exercise_choice].name, time_spent);
    
    // Print User's BMI and BMR
    printf("%s's BMI: %.2f\n%s's BMR: %.2f\n\n", users[user_choice].name, user_bmi, users[user_choice].name, user_bmr);
    
    // Free memory allocated for users and exercises
    free(users);
    free(exercises);
    
    return 0;
}