//FormAI DATASET v1.0 Category: System boot optimizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PROCESSES 100
#define MAX_PROGRAM_NAME 20

typedef struct {
    char name[MAX_PROGRAM_NAME];
    int priority;
    int size;
} Process;

void swap(Process* xp, Process* yp) {
    Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(Process arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)       
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].priority > arr[j + 1].priority)
                swap(&arr[j], &arr[j + 1]);
}

void optimizeSystemBoot(Process arr[], int n) {
    printf("Starting System Optimization...\n\n");

    int i, totalSize = 0;
    for (i = 0; i < n; i++)
        totalSize += arr[i].size;

    double bootTime = (double)totalSize / 1024.0;
    printf("Estimated System Boot Time: %.2f seconds\n\n", bootTime);

    bubbleSort(arr, n);
    printf("Optimizing System Boot Order...\n\n");
    for (i = 0; i < n; i++) {
        printf("Loading %s (Priority: %d)\n", arr[i].name, arr[i].priority);
        printf("...");
        fflush(stdout);
        double loadTime = (double)arr[i].size / 1024.0;
        sleep(loadTime);
        printf("Done\n");
    }
    printf("\nSystem Boot Optimization Complete!\n");
}

int main() {
    srand(time(NULL));

    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Maximum number of processes is %d\n", MAX_PROCESSES);
        return 0;
    }

    Process arr[MAX_PROCESSES];
    for (i = 0; i < n; i++) {
        printf("Enter name of process %d: ", i + 1);
        scanf("%s", arr[i].name);
        printf("Enter priority of process %d (1-10): ", i + 1);
        scanf("%d", &arr[i].priority);
        if (arr[i].priority < 1 || arr[i].priority > 10) {
            printf("Invalid priority!\n");
            return 0;
        }
        printf("Enter size of process %d (in KB): ", i + 1);
        scanf("%d", &arr[i].size);
        if (arr[i].size < 1) {
            printf("Invalid size!\n");
            return 0;
        }
    }

    optimizeSystemBoot(arr, n);

    return 0;
}