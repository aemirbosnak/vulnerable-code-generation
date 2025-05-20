//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototypes
void distribute_task(int task_id, int num_tasks, double *data);
void receive_results(int num_tasks, double *results);

int main(int argc, char *argv[]) {
    int num_tasks, task_id, i;
    double temperature, converted_temperature, *results;

    // Read the input temperature and the number of tasks
    printf("Enter the input temperature: ");
    scanf("%lf", &temperature);
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    // Allocate memory for the results array
    results = (double *) malloc(num_tasks * sizeof(double));

    // Distribute the task among the available processors
    for (i = 0; i < num_tasks; i++) {
        distribute_task(i, num_tasks, &temperature);
    }

    // Receive the results from all the processors
    receive_results(num_tasks, results);

    // Print the converted temperature
    printf("The converted temperature is: %lf\n", results[0]);

    return 0;
}

// Function to distribute the task among the available processors
void distribute_task(int task_id, int num_tasks, double *data) {
    int i;

    // Convert the temperature from Celsius to Fahrenheit
    for (i = task_id; i < num_tasks; i += num_tasks) {
        (*data) = (*data) * 1.8 + 32;
    }
}

// Function to receive the results from all the processors
void receive_results(int num_tasks, double *results) {
    int i;

    // Combine the results from all the processors
    for (i = 0; i < num_tasks; i++) {
        results[0] += results[i];
    }
}