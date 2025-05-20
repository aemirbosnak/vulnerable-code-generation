//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fitness_data {
    char date[20];
    int steps;
    float distance; // in kilometers
    int calories_burned;
    float weight; // in kilograms
};

void display_menu() {
    printf("\n===== FITNESS TRACKER MENU =====\n\n");
    printf("1. Add fitness data\n");
    printf("2. View fitness data\n");
    printf("3. Delete all fitness data\n");
    printf("4. Quit program\n");
}

void add_fitness_data(struct fitness_data *data) {
    printf("\n===== ADD FITNESS DATA =====\n\n");
    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%s", data->date);
    printf("Enter the number of steps: ");
    scanf("%d", &data->steps);
    printf("Enter the distance travelled (in km): ");
    scanf("%f", &data->distance);
    printf("Enter the calories burned: ");
    scanf("%d", &data->calories_burned);
    printf("Enter the weight (in kg): ");
    scanf("%f", &data->weight);
}

void view_fitness_data(struct fitness_data *data) {
    printf("\n===== VIEW FITNESS DATA =====\n\n");
    printf("Date: %s\n", data->date);
    printf("Number of steps: %d\n", data->steps);
    printf("Distance travelled: %0.2f km\n", data->distance);
    printf("Calories burned: %d\n", data->calories_burned);
    printf("Weight: %0.2f kg\n", data->weight);
}

int main() {
    int choice;
    int count = 0;
    struct fitness_data *data_array;
    struct fitness_data temp_data;

    data_array = (struct fitness_data*) malloc(sizeof(struct fitness_data));
    if (data_array == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    while (1) {
        display_menu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_fitness_data(&temp_data);
                count++;
                data_array = (struct fitness_data*) realloc(data_array, count * sizeof(struct fitness_data));
                if (data_array == NULL) {
                    printf("Memory allocation error\n");
                    return 1;
                }
                strcpy(data_array[count-1].date, temp_data.date);
                data_array[count-1].steps = temp_data.steps;
                data_array[count-1].distance = temp_data.distance;
                data_array[count-1].calories_burned = temp_data.calories_burned;
                data_array[count-1].weight = temp_data.weight;
                break;
            case 2:
                if (count == 0) {
                    printf("\nNo data to display\n");
                } else {
                    printf("\n===== FITNESS DATA =====\n\n");
                    for (int i = 0; i < count; i++) {
                        printf("Data #%d:\n", i+1);
                        view_fitness_data(&data_array[i]);
                    }
                }
                break;
            case 3:
                free(data_array);
                data_array = (struct fitness_data*) malloc(sizeof(struct fitness_data));
                if (data_array == NULL) {
                    printf("Memory allocation error\n");
                    return 1;
                }
                count = 0;
                printf("\nAll data deleted\n");
                break;
            case 4:
                free(data_array);
                printf("\nExiting program\n");
                return 0;
            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}