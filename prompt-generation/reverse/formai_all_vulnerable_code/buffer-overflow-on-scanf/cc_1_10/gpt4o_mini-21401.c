//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Job {
    char name[30];
    char priority[10];
} Job;

typedef struct Queue {
    Job jobs[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(Queue* q) {
    return (q->rear == MAX_SIZE - 1);
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

// Enqueue a new job
void enqueue(Queue* q, Job job) {
    if (isFull(q)) {
        printf("The neon-lit streets of the Cyber City are busy. Can't add job: %s\n", job.name);
        return;
    }
    
    if (isEmpty(q)) {
        q->front = 0;
    }
    
    q->rear++;
    q->jobs[q->rear] = job;
    printf("Added job: %s with priority %s to the cyber queue.\n", job.name, job.priority);
}

// Dequeue a job
Job dequeue(Queue* q) {
    Job job;
    
    if (isEmpty(q)) {
        printf("The queue is empty, like the void of cyberspace.\n");
        strcpy(job.name, "N/A");
        strcpy(job.priority, "N/A");
        return job;
    }

    job = q->jobs[q->front];
    q->front++;
    
    if (q->front > q->rear) {
        printf("The queue has been cleared, nothing but empty echoes remain.\n");
        q->front = q->rear = -1;
    }
    
    printf("Popped job: %s with priority %s from the cyber queue.\n", job.name, job.priority);
    return job;
}

// Display the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("The queue is empty, a desolate place in this cyber dystopia.\n");
        return;
    }

    printf("Currently queued jobs:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("Job Name: %s, Priority: %s\n", q->jobs[i].name, q->jobs[i].priority);
    }
}

// Main function
int main() {
    Queue cyberQueue;
    initQueue(&cyberQueue);

    while (1) {
        int choice;
        printf("\n--- Cyber Queue Management ---\n");
        printf("1. Enqueue Job\n");
        printf("2. Dequeue Job\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // consume newline

        switch (choice) {
            case 1: {
                Job newJob;
                printf("Enter job name: ");
                fgets(newJob.name, sizeof(newJob.name), stdin);
                newJob.name[strcspn(newJob.name, "\n")] = 0;  // Remove newline
                
                printf("Enter job priority (High/Medium/Low): ");
                fgets(newJob.priority, sizeof(newJob.priority), stdin);
                newJob.priority[strcspn(newJob.priority, "\n")] = 0;  // Remove newline
                
                enqueue(&cyberQueue, newJob);
                break;
            }
            case 2: {
                Job finishedJob = dequeue(&cyberQueue);
                if (strcmp(finishedJob.name, "N/A") != 0) {
                    printf("Job %s processed.\n", finishedJob.name);
                }
                break;
            }
            case 3:
                displayQueue(&cyberQueue);
                break;
            case 4:
                printf("Exiting the void. Stay safe in the neon shadows.\n");
                exit(0);
            default:
                printf("An error in the system... choose a valid option.\n");
                break;
        }
    }

    return 0;
}