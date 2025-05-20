//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: high level of detail
// C Fitness Tracker Example Program

#include <stdio.h>

// Define structure to store fitness data
struct fitness_data {
    int age;
    int height;
    int weight;
    int activity_level;
    int calories_burned;
};

// Function to calculate calories burned based on activity level
int calculate_calories_burned(int activity_level) {
    int calories_burned = 0;
    switch (activity_level) {
        case 1: // Sedentary
            calories_burned = 100;
            break;
        case 2: // Lightly active
            calories_burned = 200;
            break;
        case 3: // Moderately active
            calories_burned = 300;
            break;
        case 4: // Very active
            calories_burned = 400;
            break;
        case 5: // Extra active
            calories_burned = 500;
            break;
    }
    return calories_burned;
}

// Function to update fitness data
void update_fitness_data(struct fitness_data *data) {
    // Prompt user for input
    printf("Enter your age: ");
    scanf("%d", &data->age);
    printf("Enter your height: ");
    scanf("%d", &data->height);
    printf("Enter your weight: ");
    scanf("%d", &data->weight);
    printf("Enter your activity level (1-5): ");
    scanf("%d", &data->activity_level);

    // Calculate calories burned
    data->calories_burned = calculate_calories_burned(data->activity_level);
}

// Function to print fitness data
void print_fitness_data(struct fitness_data *data) {
    printf("Age: %d\n", data->age);
    printf("Height: %d\n", data->height);
    printf("Weight: %d\n", data->weight);
    printf("Activity level: %d\n", data->activity_level);
    printf("Calories burned: %d\n", data->calories_burned);
}

int main() {
    // Initialize fitness data
    struct fitness_data data;
    data.age = 0;
    data.height = 0;
    data.weight = 0;
    data.activity_level = 0;
    data.calories_burned = 0;

    // Update fitness data
    update_fitness_data(&data);

    // Print fitness data
    print_fitness_data(&data);

    return 0;
}