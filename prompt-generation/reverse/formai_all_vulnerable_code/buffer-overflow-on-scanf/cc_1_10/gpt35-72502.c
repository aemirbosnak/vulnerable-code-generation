//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define struct to hold user's data
struct user_info {
    int age;
    float height;
    float weight;
    char gender[10];
};

// Define struct to hold user's fitness data
struct fitness_data {
    float calories_burned;
    float distance_covered;
    float time;
};

// Function to get user's data
struct user_info get_user_info() {
    struct user_info user;
    printf("Enter your age: ");
    scanf("%d", &user.age);
    printf("Enter your height in meters: ");
    scanf("%f", &user.height);
    printf("Enter your weight in kilograms: ");
    scanf("%f", &user.weight);
    printf("Enter your gender [M or F]: ");
    scanf("%s", user.gender);
    return user;
}

// Function to display user's data
void display_user_info(struct user_info user) {
    printf("\nUser Info:\n");
    printf("Age: %d\n", user.age);
    printf("Height: %.2f meters\n", user.height);
    printf("Weight: %.2f kilograms\n", user.weight);
    printf("Gender: %s\n", user.gender);
}

// Function to generate random fitness data
struct fitness_data generate_fitness_data() {
    struct fitness_data fitness;
    fitness.calories_burned = (float)(rand() % 500 + 100);
    fitness.distance_covered = (float)(rand() % 5 + 1);
    fitness.time = (float)(rand() % 60 + 30);
    return fitness;
}

// Function to display fitness data
void display_fitness_data(struct fitness_data fitness) {
    printf("\nFitness Data:\n");
    printf("Calories Burned: %.2f\n", fitness.calories_burned);
    printf("Distance Covered: %.2f km\n", fitness.distance_covered);
    printf("Time: %.2f minutes\n", fitness.time);
}

int main() {
    int i;
    struct user_info user = get_user_info();
    display_user_info(user);
    printf("\nGenerating random fitness data...\n");
    srand(time(NULL));
    for (i = 1; i <= 7; i++) {
        printf("\nData for Day %d\n", i);
        struct fitness_data fitness = generate_fitness_data();
        display_fitness_data(fitness);
    }
    return 0;
}