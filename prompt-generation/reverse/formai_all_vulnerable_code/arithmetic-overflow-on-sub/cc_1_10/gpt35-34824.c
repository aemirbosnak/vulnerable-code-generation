//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

struct Job {
    char name[20];
    int deadline, profit;
};

void heapify(struct Job jobs[], int n, int i) {
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;
 
    if (left_child < n && jobs[left_child].profit > jobs[largest].profit)
        largest = left_child;
 
    if (right_child < n && jobs[right_child].profit > jobs[largest].profit)
        largest = right_child;
 
    if (largest != i) {
        struct Job temp = jobs[i];
        jobs[i] = jobs[largest];
        jobs[largest] = temp;
        heapify(jobs, n, largest);
    }
}

void heap_sort(struct Job jobs[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(jobs, n, i);
 
    for (int i = n - 1; i >= 0; i--) {
        struct Job temp = jobs[0];
        jobs[0] = jobs[i];
        jobs[i] = temp;
        heapify(jobs, i, 0);
    }
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    struct Job jobs[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the name, deadline and profit of Job %d: ", i+1);
        scanf("%s %d %d", jobs[i].name, &jobs[i].deadline, &jobs[i].profit);
    }

    heap_sort(jobs, n);

    int max_deadline = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > max_deadline)
            max_deadline = jobs[i].deadline;
    }

    int schedule[max_deadline];
    for (int i = 0; i < max_deadline; i++)
        schedule[i] = -1;

    int total_profit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (schedule[j] == -1) {
                schedule[j] = i;
                total_profit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Schedule: ");
    for (int i = 0; i < max_deadline; i++)
        printf("%s ", jobs[schedule[i]].name);
    printf("\n");

    printf("Total profit: %d\n", total_profit);

    return 0;
}