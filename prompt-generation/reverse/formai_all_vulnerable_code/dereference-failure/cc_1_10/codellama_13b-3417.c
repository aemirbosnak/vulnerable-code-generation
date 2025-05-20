//Code Llama-13B DATASET v1.0 Category: Task Scheduler ; Style: visionary
/*
 * C Task Scheduler Example Program
 *
 * This program demonstrates a simple task scheduler that runs tasks at
 * specific times. It uses a linked list to store the tasks and a
 * while loop to periodically check the current time and execute
 * any tasks that are due.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Structure to represent a task
 */
struct task {
    char *name;
    time_t due_time;
    void (*func)();
    struct task *next;
};

/*
 * Function to create a new task
 */
struct task *new_task(char *name, time_t due_time, void (*func)()) {
    struct task *t = malloc(sizeof(struct task));
    t->name = name;
    t->due_time = due_time;
    t->func = func;
    t->next = NULL;
    return t;
}

/*
 * Function to add a task to the list
 */
void add_task(struct task *head, struct task *t) {
    struct task *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = t;
}

/*
 * Function to remove a task from the list
 */
void remove_task(struct task *head, struct task *t) {
    struct task *curr = head;
    while (curr->next != t) {
        curr = curr->next;
    }
    curr->next = t->next;
}

/*
 * Function to execute all tasks that are due
 */
void execute_tasks(struct task *head) {
    struct task *curr = head;
    while (curr != NULL) {
        if (curr->due_time <= time(NULL)) {
            curr->func();
            remove_task(head, curr);
        }
        curr = curr->next;
    }
}

int main() {
    struct task *head = NULL;

    /*
     * Add some tasks to the list
     */
    add_task(head, new_task("Task 1", time(NULL) + 10, (void *)(void *)&printf));
    add_task(head, new_task("Task 2", time(NULL) + 20, (void *)(void *)&printf));
    add_task(head, new_task("Task 3", time(NULL) + 30, (void *)(void *)&printf));

    /*
     * Run the tasks
     */
    while (1) {
        execute_tasks(head);
        sleep(1);
    }

    return 0;
}