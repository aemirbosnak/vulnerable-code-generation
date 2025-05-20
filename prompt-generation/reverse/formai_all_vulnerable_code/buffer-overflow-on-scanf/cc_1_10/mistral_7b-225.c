//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

#define STEPS_PER_MINUTE 1000
#define MAX_HEART_RATE 150
#define MIN_HEART_RATE 60
#define HEIGHT 1.8 // meters
#define WEIGHT 75 // kg

typedef struct {
    time_t timestamp;
    int steps;
    float heart_rate;
} FitnessData;

void print_menu() {
    printf("\n--- Fitness Tracker ---\n");
    printf("1. Record new data\n");
    printf("2. Display statistics\n");
    printf("3. Exit\n");
}

void record_data(FitnessData *data) {
    time_t now;
    struct tm *tm;

    time(&now);
    tm = localtime(&now);

    data->timestamp = now;
    data->steps = rand() % 500 + 500;
    data->heart_rate = (float) (rand() % (MAX_HEART_RATE - MIN_HEART_RATE + 1) + MIN_HEART_RATE);
}

float calculate_calories_burned(int steps) {
    float calories;

    calories = 0.2 * (HEIGHT * WEIGHT) * (steps / STEPS_PER_MINUTE);

    return calories;
}

void display_statistics(FitnessData *data, int num_records) {
    float total_calories, avg_heart_rate, avg_steps;
    float sum_calories = 0, sum_heart_rates = 0, sum_steps = 0;
    int i;

    printf("\n--- Statistics ---\n");

    for (i = 0; i < num_records; i++) {
        sum_calories += calculate_calories_burned(data[i].steps);
        sum_heart_rates += data[i].heart_rate;
        sum_steps += data[i].steps;
    }

    avg_heart_rate = sum_heart_rates / num_records;
    avg_steps = sum_steps / num_records;

    total_calories = sum_calories;

    printf("Total calories burned: %.2f\n", total_calories);
    printf("Average heart rate: %.2f bpm\n", avg_heart_rate);
    printf("Average steps per day: %.2f\n", avg_steps);
}

int main() {
    int num_records = 0;
    FitnessData data[100];

    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_records < 100) {
                    record_data(&data[num_records]);
                    num_records++;
                } else {
                    printf("Maximum number of records reached.\n");
                }
                break;
            case 2:
                if (num_records > 0) {
                    display_statistics(data, num_records);
                } else {
                    printf("No records to display.\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}