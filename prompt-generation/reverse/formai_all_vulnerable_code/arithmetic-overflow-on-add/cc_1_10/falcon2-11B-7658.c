//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void scheduler(int *queue, int length, int *count, int *interval);
void addTask(int *queue, int length, int task);
int deleteTask(int *queue, int length);
int getTime(int *queue, int length);
void printQueue(int *queue, int length);

int main() {
    int queue[100];
    int length = 0;
    int count = 0;
    int interval = 0;

    printf("Enter number of tasks: ");
    scanf("%d", &length);

    printf("Enter time interval: ");
    scanf("%d", &interval);

    addTask(queue, length, interval);

    scheduler(queue, length, &count, &interval);

    printf("Total tasks: %d\n", count);
    printf("Interval: %d\n", interval);
    printf("Time: %d\n", getTime(queue, length));

    return 0;
}

void addTask(int *queue, int length, int task) {
    if (length == 100) {
        printf("Queue is full\n");
        return;
    }

    queue[length] = task;
    length++;
}

int deleteTask(int *queue, int length) {
    if (length == 0) {
        printf("Queue is empty\n");
        return -1;
    }

    int task = queue[0];
    for (int i = 0; i < length - 1; i++) {
        queue[i] = queue[i + 1];
    }

    length--;
    return task;
}

int getTime(int *queue, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += queue[i];
    }

    return sum;
}

void scheduler(int *queue, int length, int *count, int *interval) {
    int task;
    clock_t start, end;

    while (*count > 0) {
        task = deleteTask(queue, length);

        start = clock();

        while (task > 0) {
            task--;
        }

        end = clock();
        *count --;
        *interval += (end - start);
    }
}

void printQueue(int *queue, int length) {
    printf("Queue: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}