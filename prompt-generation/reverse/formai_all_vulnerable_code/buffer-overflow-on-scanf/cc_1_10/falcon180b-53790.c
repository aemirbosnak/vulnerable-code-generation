//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main() {

    // Declare variables
    int n, i, j, max_profit = 0, curr_profit, job_profit[MAX], job_deadline[MAX], job_position[MAX];

    // Read number of jobs
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    // Read job details
    for (i = 0; i < n; i++) {
        printf("\nEnter details for job %d:\n", i+1);
        printf("Profit: ");
        scanf("%d", &job_profit[i]);
        printf("Deadline: ");
        scanf("%d", &job_deadline[i]);
        printf("Position: ");
        scanf("%d", &job_position[i]);
    }

    // Initialize arrays
    int job_selected[MAX] = {0};
    int job_index[MAX] = {0};

    // Initialize maximum profit
    max_profit = job_profit[0];

    // Initialize current profit
    curr_profit = job_profit[0];

    // Initialize position
    int position = 0;

    // Loop through jobs
    for (i = 1; i < n; i++) {

        // Check if current job can be selected
        if (job_deadline[i] >= position) {

            // Calculate current profit
            curr_profit += job_profit[i];

            // Update maximum profit
            if (curr_profit > max_profit) {
                max_profit = curr_profit;
            }

            // Update position
            position += job_deadline[i];
        }
    }

    // Print results
    printf("\nMaximum profit: %d\n", max_profit);

    // Print selected jobs
    printf("\nSelected jobs:\n");
    for (i = 0; i < n; i++) {
        if (job_selected[i]) {
            printf("%d ", i+1);
        }
    }

    return 0;
}