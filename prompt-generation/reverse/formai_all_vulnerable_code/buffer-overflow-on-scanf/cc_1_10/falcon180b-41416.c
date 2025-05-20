//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: standalone
#include <stdio.h>

#define MAX 100

int job_profit[MAX];
int job_deadline[MAX];
int job_idx[MAX];

void job_sort(int n, int w[], int profit[], int deadline[]) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (profit[j] > profit[j + 1]) {
                int temp = job_idx[j];
                job_idx[j] = job_idx[j + 1];
                job_idx[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i, j, max_profit = 0, count = 0;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    printf("Enter the profit and deadline of each job:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &job_profit[i], &job_deadline[i]);
    }

    for (i = 0; i < n; i++) {
        job_idx[i] = i;
    }

    job_sort(n, job_profit, job_idx, job_deadline);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (job_idx[j] == i) {
                break;
            }
        }
        if (j == n) {
            count++;
            max_profit += job_profit[i];
        }
    }

    if (count == n) {
        printf("All jobs can be completed within the given deadline.\n");
    } else {
        printf("Maximum profit: %d\n", max_profit);
    }

    return 0;
}