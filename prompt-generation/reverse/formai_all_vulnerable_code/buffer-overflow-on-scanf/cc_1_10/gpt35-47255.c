//FormAI DATASET v1.0 Category: Task Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct task_s {
    int id;
    char* name;
    time_t start_time;
    int duration;
    int priority;
} task;

typedef struct node_s {
    task* t;
    struct node_s* next;
} node;

node* head = NULL;

void add_task(int id, char* name, time_t start_time, int duration, int priority) {
    task* t = (task*) malloc(sizeof(task));
    t->id = id;
    t->name = name;
    t->start_time = start_time;
    t->duration = duration;
    t->priority = priority;

    node* n = (node*) malloc(sizeof(node));
    n->t = t;
    n->next = NULL;

    if (head == NULL) {
        head = n;
    }
    else {
        node* curr = head;
        node* prev = NULL;
        while (curr != NULL && curr->t->priority >= priority) {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL) {
            head = n;
        }
        else {
            prev->next = n;
        }
        n->next = curr;
    }
}

void remove_task(int id) {
    node* curr = head;
    node* prev = NULL;
    while (curr != NULL && curr->t->id != id) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Error: Task with id %d not found\n", id);
        return;
    }
    if (prev == NULL) {
        head = curr->next;
    }
    else {
        prev->next = curr->next;
    }
    free(curr->t);
    free(curr);
}

void print_task(task* t) {
    char* priority_str;
    switch (t->priority) {
        case 1:
            priority_str = "low";
            break;
        case 2:
            priority_str = "medium";
            break;
        case 3:
            priority_str = "high";
            break;
        default:
            priority_str = "unknown";
            break;
    }
    printf("Task ID: %d\n", t->id);
    printf("Task Name: %s\n", t->name);
    printf("Start Time: %s", ctime(&t->start_time));
    printf("Duration: %d seconds\n", t->duration);
    printf("Priority: %s\n", priority_str);
    printf("\n");
}

void print_tasks() {
    printf("List of tasks:\n");
    node* curr = head;
    while (curr != NULL) {
        print_task(curr->t);
        curr = curr->next;
    }
}

int main() {
    time_t raw_time = time(NULL);
    struct tm* current_time = localtime(&raw_time);
    int current_hour = current_time->tm_hour;
    int current_minute = current_time->tm_min;
    int current_second = current_time->tm_sec;

    add_task(1, "Clean the room", raw_time + 60, 120, 2);
    add_task(2, "Do the dishes", raw_time + 120, 90, 1);
    add_task(3, "Buy groceries", raw_time + 180, 180, 3);
    add_task(4, "Complete the report", raw_time + 240, 300, 2);
    add_task(5, "Attend the meeting", raw_time + 300, 60, 3);

    printf("Welcome to the Task Scheduler!\n");
    printf("Current time: %02d:%02d:%02d\n", current_hour, current_minute, current_second);
    printf("\n");

    while (1) {
        printf("Enter task ID to remove, or 0 to exit: ");
        int id;
        scanf("%d", &id);
        if (id == 0) {
            break;
        }
        remove_task(id);
        print_tasks();
    }

    return 0;
}