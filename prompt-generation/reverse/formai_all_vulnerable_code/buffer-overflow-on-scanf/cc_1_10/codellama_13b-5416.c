//Code Llama-13B DATASET v1.0 Category: Greedy Algorithms ; Style: protected
// Greedy Algorithms Example Program

#include <stdio.h>
#include <stdlib.h>

// Function to get the maximum number of tasks that can be completed
int getMaxTasks(int tasks[], int n) {
    int i, j, max = 0;
    for (i = 0; i < n; i++) {
        if (tasks[i] > max) {
            max = tasks[i];
        }
    }
    return max;
}

// Function to sort the tasks in decreasing order
void sortTasks(int tasks[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (tasks[i] < tasks[j]) {
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

// Function to print the tasks
void printTasks(int tasks[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", tasks[i]);
    }
    printf("\n");
}

int main() {
    // Number of tasks
    int n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    // Array to store the tasks
    int tasks[n];

    // Get the tasks
    for (int i = 0; i < n; i++) {
        printf("Enter the duration of task %d: ", i + 1);
        scanf("%d", &tasks[i]);
    }

    // Sort the tasks in decreasing order
    sortTasks(tasks, n);

    // Print the tasks
    printf("Sorted tasks: ");
    printTasks(tasks, n);

    // Get the maximum number of tasks that can be completed
    int max = getMaxTasks(tasks, n);

    // Print the maximum number of tasks that can be completed
    printf("Maximum number of tasks that can be completed: %d\n", max);

    return 0;
}