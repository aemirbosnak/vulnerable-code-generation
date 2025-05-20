#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_QUEUE_SIZE 100
#define JOB_NAME_LENGTH 256

typedef struct {
    char job_name[JOB_NAME_LENGTH];
    int priority;
} Job;

Job queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(Job job) {
    if ((rear + 1) % MAX_QUEUE_SIZE == front)
        printf("Queue Overflow\n");
    else {
        rear = (rear + 1) % MAX_QUEUE_SIZE;
        queue[rear] = job;
    }
}

Job dequeue() {
    Job temp;
    if (front == -1)
        printf("Queue Underflow\n");
    else {
        front = (front + 1) % MAX_QUEUE_SIZE;
        temp = queue[front - 1];
        return temp;
    }
    Job null_job = { "", -1 };
    return null_job;
}

void* worker_thread(void* arg) {
    while (1) {
        if (front != -1) {
            Job job = dequeue();
            printf("Processing job: %s with priority: %d\n", job.job_name, job.priority);
        } else {
            sleep(1);
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_id;

    if (pthread_create(&thread_id, NULL, worker_thread, NULL) != 0) {
        printf("Thread creation failed\n");
        return 1;
    }

    while (1) {
        printf("Enter job name (or 'exit' to quit): ");
        char input[JOB_NAME_LENGTH * 2];
        fgets(input, sizeof(input), stdin);

        if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't' && input[4] == '\n') {
            break;
        }

        Job new_job;
        strcpy(new_job.job_name, input);
        new_job.priority = rand() % 10; // Random priority

        enqueue(new_job);
    }

    pthread_join(thread_id, NULL);
    printf("Program terminated.\n");

    return 0;
}
