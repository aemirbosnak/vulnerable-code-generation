//FormAI DATASET v1.0 Category: Task Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Task structure
struct Task {
    char name[50];
    int priority;
};

// Insertion sort for sorting tasks by priority
void sortTasks(struct Task taskList[], int numTasks) {
    for (int i = 1; i < numTasks; i++) {
        struct Task temp = taskList[i];
        int j = i - 1;
        while (j >= 0 && taskList[j].priority > temp.priority) {
            taskList[j + 1] = taskList[j];
            j--;
        }
        taskList[j + 1] = temp;
    }
}

// Print the details of the task
void printTask(struct Task task) {
    printf("Task Name : %s\n", task.name);
    printf("Task Priority : %d\n", task.priority);
}

// Execute the task
void executeTask(struct Task task) {
    printf("Executing Task : %s\n", task.name);
}

int main() {
    int numTasks;
    printf("Enter the number of tasks to be scheduled : ");
    scanf("%d", &numTasks);

    // Allocate memory for task list
    struct Task* taskList = malloc(numTasks * sizeof(struct Task));

    // Get task details from user
    for (int i = 0; i < numTasks; i++) {
        printf("\nEnter details of Task %d\n", i + 1);
        printf("Enter Task Name : ");
        scanf("%s", taskList[i].name);
        printf("Enter Task Priority (1 is highest priority) : ");
        scanf("%d", &taskList[i].priority);
    }

    // Sort tasks by priority
    sortTasks(taskList, numTasks);

    // Print the task schedule
    printf("\nTask Schedule\n");
    for (int i = 0; i < numTasks; i++) {
        printf("Task %d\n", i + 1);
        printTask(taskList[i]);
        executeTask(taskList[i]);
        printf("\n");
    }

    // Free the memory allocated for task list
    free(taskList);
    
    return 0;
}