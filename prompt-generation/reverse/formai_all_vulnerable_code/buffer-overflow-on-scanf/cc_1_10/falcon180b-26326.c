//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char name[20];
    int id;
    int priority;
} process;

void swap(process *a, process *b) {
    process temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(process arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].priority > arr[j+1].priority) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process arr[n];

    printf("Enter the process name, ID and priority:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", arr[i].name, &arr[i].id, &arr[i].priority);
    }

    bubbleSort(arr, n);

    printf("Process Name\tID\tPriority\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\n", arr[i].name, arr[i].id, arr[i].priority);
    }

    return 0;
}