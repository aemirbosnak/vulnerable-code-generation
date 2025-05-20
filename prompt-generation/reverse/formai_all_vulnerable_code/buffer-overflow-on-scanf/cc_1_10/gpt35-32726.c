//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define a structure for fitness tracker data
typedef struct fitness_data
{
    int steps;
    float distance;
    float calories_burned;
    int heart_rate;
} fitness_data_t;

// Define a function to update fitness data based on user input
void update_fitness_data(fitness_data_t *data)
{
    int steps;
    float distance, calories_burned;
    int heart_rate;

    printf("\nEnter the number of steps taken: ");
    scanf("%d", &steps);
    data->steps += steps;

    printf("\nEnter the distance travelled in km: ");
    scanf("%f", &distance);
    data->distance += distance;

    printf("\nEnter the number of calories burned: ");
    scanf("%f", &calories_burned);
    data->calories_burned += calories_burned;

    printf("\nEnter your heart rate: ");
    scanf("%d", &heart_rate);
    data->heart_rate = heart_rate;
}

// Define a function to print fitness data
void print_fitness_data(fitness_data_t data)
{
    printf("\n------------------\n");
    printf("Fitness Tracker Data\n");
    printf("------------------\n");
    printf("Steps taken: %d\n", data.steps);
    printf("Distance travelled: %.2f km\n", data.distance);
    printf("Calories burned: %.2f cal\n", data.calories_burned);
    printf("Heart rate: %d bpm\n", data.heart_rate);
}

int main()
{
    // Initialize fitness data structure
    fitness_data_t data = {0, 0.0f, 0.0f, 0};

    // Define a variable to store user input
    char choice;

    do {
        // Print menu
        printf("\nMenu:\n");
        printf("1. Update fitness data\n");
        printf("2. Print fitness data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        // Read user input
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                update_fitness_data(&data);
                break;
            case '2':
                print_fitness_data(data);
                break;
            case '3':
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    } while(choice != '3');

    return 0;
}