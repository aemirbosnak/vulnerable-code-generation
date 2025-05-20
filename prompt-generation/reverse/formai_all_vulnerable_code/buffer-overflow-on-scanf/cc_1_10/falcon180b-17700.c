//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define MAX_THREADS 8
#define MAX_PROCESSES 8

struct process {
    char *name;
    int priority;
};

struct thread {
    int id;
    int priority;
    struct process *process;
};

void *thread_func(void *arg) {
    struct thread *thread = arg;
    struct process *process = thread->process;

    printf("Thread %d started for process %s\n", thread->id, process->name);

    sleep(process->priority);

    printf("Thread %d finished for process %s\n", thread->id, process->name);

    return NULL;
}

int main() {
    struct process processes[MAX_PROCESSES];
    struct thread threads[MAX_THREADS];
    int num_processes = 0, num_threads = 0;
    sem_t thread_sem;
    pthread_t thread_ids[MAX_THREADS];

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; i++) {
        char name[50];
        int priority;

        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", name);

        printf("Enter the priority of process %s: ", name);
        scanf("%d", &priority);

        processes[i].name = name;
        processes[i].priority = priority;
    }

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    for (int i = 0; i < num_threads; i++) {
        int id, priority;

        printf("Enter the id of thread %d: ", i + 1);
        scanf("%d", &id);

        printf("Enter the priority of thread %d: ", id);
        scanf("%d", &priority);

        threads[i].id = id;
        threads[i].priority = priority;
        threads[i].process = &processes[i % num_processes];
    }

    sem_init(&thread_sem, 0, 0);

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&thread_ids[i], NULL, thread_func, &threads[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        sem_wait(&thread_sem);
    }

    printf("All threads finished\n");

    return 0;
}