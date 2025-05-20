//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
// Fitness Tracker Example Program

#include <stdio.h>
#include <stdlib.h>

// Define the struct for the user data
struct user_data {
    char name[100];
    int age;
    float height;
    float weight;
    float daily_calories;
    float daily_steps;
};

// Define the struct for the daily data
struct daily_data {
    int day;
    float distance_walked;
    float calories_burned;
};

// Define the struct for the monthly data
struct monthly_data {
    int month;
    float total_distance;
    float total_calories;
};

// Define the struct for the yearly data
struct yearly_data {
    int year;
    float total_distance;
    float total_calories;
};

// Define the struct for the fitness tracker
struct fitness_tracker {
    struct user_data user;
    struct daily_data daily[30];
    struct monthly_data monthly[12];
    struct yearly_data yearly;
};

// Function to calculate the BMI of a user
float calculate_bmi(struct user_data *user) {
    return (user->weight / (user->height * user->height));
}

// Function to calculate the daily calories burned
float calculate_daily_calories_burned(struct user_data *user, struct daily_data *daily) {
    return (user->daily_calories * daily->distance_walked);
}

// Function to calculate the total distance walked
float calculate_total_distance(struct daily_data *daily, int num_days) {
    float total = 0;
    for (int i = 0; i < num_days; i++) {
        total += daily[i].distance_walked;
    }
    return total;
}

// Function to calculate the total calories burned
float calculate_total_calories(struct daily_data *daily, int num_days) {
    float total = 0;
    for (int i = 0; i < num_days; i++) {
        total += daily[i].calories_burned;
    }
    return total;
}

// Function to print the fitness tracker data
void print_fitness_tracker(struct fitness_tracker *tracker) {
    printf("User Data:\n");
    printf("Name: %s\n", tracker->user.name);
    printf("Age: %d\n", tracker->user.age);
    printf("Height: %f\n", tracker->user.height);
    printf("Weight: %f\n", tracker->user.weight);
    printf("Daily Calories: %f\n", tracker->user.daily_calories);
    printf("Daily Steps: %f\n", tracker->user.daily_steps);
    printf("BMI: %f\n\n", calculate_bmi(&tracker->user));

    printf("Daily Data:\n");
    for (int i = 0; i < 30; i++) {
        printf("Day %d: %f\n", tracker->daily[i].day, tracker->daily[i].distance_walked);
    }
    printf("\n");

    printf("Monthly Data:\n");
    for (int i = 0; i < 12; i++) {
        printf("Month %d: %f\n", tracker->monthly[i].month, tracker->monthly[i].total_distance);
    }
    printf("\n");

    printf("Yearly Data:\n");
    printf("Year: %d\n", tracker->yearly.year);
    printf("Total Distance: %f\n", tracker->yearly.total_distance);
    printf("Total Calories: %f\n", tracker->yearly.total_calories);
    printf("\n");
}

// Function to update the fitness tracker data
void update_fitness_tracker(struct fitness_tracker *tracker, struct daily_data *daily, int num_days) {
    // Update the daily data
    for (int i = 0; i < num_days; i++) {
        tracker->daily[i].distance_walked = daily[i].distance_walked;
        tracker->daily[i].calories_burned = calculate_daily_calories_burned(&tracker->user, &daily[i]);
    }

    // Update the monthly data
    for (int i = 0; i < 12; i++) {
        tracker->monthly[i].total_distance = calculate_total_distance(&tracker->daily[i * 30], 30);
        tracker->monthly[i].total_calories = calculate_total_calories(&tracker->daily[i * 30], 30);
    }

    // Update the yearly data
    tracker->yearly.total_distance = calculate_total_distance(&tracker->daily[0], 365);
    tracker->yearly.total_calories = calculate_total_calories(&tracker->daily[0], 365);
}

int main() {
    // Initialize the fitness tracker
    struct fitness_tracker tracker;
    struct daily_data daily[30];

    // Get the user data
    printf("Enter your name: ");
    scanf("%s", tracker.user.name);
    printf("Enter your age: ");
    scanf("%d", &tracker.user.age);
    printf("Enter your height (in inches): ");
    scanf("%f", &tracker.user.height);
    printf("Enter your weight (in pounds): ");
    scanf("%f", &tracker.user.weight);
    printf("Enter your daily calories: ");
    scanf("%f", &tracker.user.daily_calories);
    printf("Enter your daily steps: ");
    scanf("%f", &tracker.user.daily_steps);

    // Get the daily data
    for (int i = 0; i < 30; i++) {
        printf("Enter the distance walked on day %d: ", i + 1);
        scanf("%f", &daily[i].distance_walked);
    }

    // Update the fitness tracker data
    update_fitness_tracker(&tracker, daily, 30);

    // Print the fitness tracker data
    print_fitness_tracker(&tracker);

    return 0;
}