//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int id;
    int size;
} Process;

void generate_processes(Process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        processes[i].id = i;
        processes[i].size = rand() % MAX_SIZE + 1;
    }
}

int compare_processes(const void *a, const void *b) {
    const Process *p1 = a;
    const Process *p2 = b;

    if (p1->size < p2->size) {
        return -1;
    } else if (p1->size > p2->size) {
        return 1;
    } else {
        return 0;
    }
}

void sort_processes(Process *processes, int num_processes) {
    qsort(processes, num_processes, sizeof(Process), compare_processes);
}

int main() {
    int num_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    Process *processes = malloc(num_processes * sizeof(Process));

    generate_processes(processes, num_processes);
    sort_processes(processes, num_processes);

    printf("Processes sorted by size:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d: size %d\n", processes[i].id, processes[i].size);
    }

    free(processes);

    return 0;
}