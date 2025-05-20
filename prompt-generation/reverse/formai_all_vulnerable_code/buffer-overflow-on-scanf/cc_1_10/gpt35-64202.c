//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Romeo and Juliet
#include <stdio.h>

#define MAX_EMPLOYEES 10

int main(void) {
    char employees[MAX_EMPLOYEES][20];
    int availabilities[MAX_EMPLOYEES];
    char tasks[5][30] = {"Task A", "Task B", "Task C", "Task D", "Task E"};
    int num_tasks = 5;
    int num_employees = 0;

    printf("Welcome to the Task Scheduler!\n");

    // Adding employees and their availability
    while (num_employees < MAX_EMPLOYEES) {
        printf("Enter employee name (or 'exit' to quit): ");
        scanf("%s", employees[num_employees]);

        if (strcmp(employees[num_employees], "exit") == 0) {
            break;
        }

        printf("Enter availability (0 - unavailable, 1 - available): ");
        scanf("%d", &availabilities[num_employees]);

        num_employees++;
    }

    // Scheduling tasks
    for (int i = 0; i < num_tasks; i++) {
        printf("\nAssigning task '%s':\n", tasks[i]);

        // Finding available employee
        int task_assigned = 0;
        for (int j = 0; j < num_employees; j++) {
            if (availabilities[j]) {
                printf("- %s has been assigned to '%s'.\n", employees[j], tasks[i]);
                availabilities[j] = 0; // Marking employee as unavailable
                task_assigned = 1;
                break;
            }
        }

        if (!task_assigned) {
            printf("Sorry, no employees available for '%s'.\n", tasks[i]);
        }
    }

    printf("\nTask scheduling complete! Thank you.\n");

    return 0;
}