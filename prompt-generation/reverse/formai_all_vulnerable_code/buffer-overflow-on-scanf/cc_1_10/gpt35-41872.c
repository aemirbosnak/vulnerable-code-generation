//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Alan Touring
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

struct task {
    char description[100];
    int priority;
    int duration;
};

void add_task(struct task *task_list, int *num_tasks);
void remove_task(struct task *task_list, int *num_tasks);
void display_tasks(struct task *task_list, int num_tasks);
void schedule_tasks(struct task *task_list, int num_tasks);

int main() {
    int option, num_tasks=0;
    struct task task_list[100];
    while (1) {
        printf("\n***** Task Scheduler *****\n");
        printf("1. Add task\n");
        printf("2. Remove task\n");
        printf("3. Display tasks\n");
        printf("4. Schedule tasks\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_task(task_list, &num_tasks);
                break;
            case 2:
                remove_task(task_list, &num_tasks);
                break;
            case 3:
                display_tasks(task_list, num_tasks);
                break;
            case 4:
                schedule_tasks(task_list, num_tasks);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}

void add_task(struct task *task_list, int *num_tasks) {
    printf("Enter task description: ");
    scanf("%s", task_list[*num_tasks].description);
    printf("Enter task priority (1-10): ");
    scanf("%d", &task_list[*num_tasks].priority);
    printf("Enter task duration (in minutes): ");
    scanf("%d", &task_list[*num_tasks].duration);
    printf("Task added successfully.\n");
    *num_tasks += 1;
}

void remove_task(struct task *task_list, int *num_tasks) {
    int i, task_index;
    printf("Enter task index to remove: ");
    scanf("%d", &task_index);
    if (task_index >= *num_tasks || task_index < 0) {
        printf("Invalid task index. Please try again.\n");
    } else {
        for (i=task_index; i<*num_tasks-1; i++) {
            task_list[i] = task_list[i+1];
        }
        *num_tasks -= 1;
        printf("Task removed successfully.\n");
    }
}

void display_tasks(struct task *task_list, int num_tasks) {
    int i;
    printf("Task list:\n");
    for (i=0; i<num_tasks; i++) {
        printf("%d. %s (Priority: %d, Duration: %d minutes)\n", i, task_list[i].description, task_list[i].priority, task_list[i].duration);
    }
}

void schedule_tasks(struct task *task_list, int num_tasks) {
    int i, j, priority_sum=0, total_time=0;
    int task_order[num_tasks];
    struct task temp_task;
    srand(time(NULL));
    if (num_tasks == 0) {
        printf("No tasks to schedule. Please add tasks and try again.\n");
        return;
    }
    // Calculate total priority of all tasks
    for (i=0; i<num_tasks; i++) {
        priority_sum += task_list[i].priority;
    }
    // Assign time slots to each task based on priority proportion
    for (i=0; i<num_tasks; i++) {
        task_list[i].duration = (int)(((float)task_list[i].priority/priority_sum)*480);
        total_time += task_list[i].duration;
    }
    // Shuffle task order randomly
    for (i=0; i<num_tasks; i++) {
        task_order[i] = i;
    }
    for (i=0; i<num_tasks; i++) {
        j = rand() % num_tasks;
        temp_task = task_list[task_order[i]];
        task_list[task_order[i]] = task_list[task_order[j]];
        task_list[task_order[j]] = temp_task;
    }
    // Print scheduled tasks
    printf("Scheduled tasks:\n");
    for (i=0; i<num_tasks; i++) {
        printf("%d. %s (Duration: %d minutes)\n", i, task_list[i].description, task_list[i].duration);
    }
    printf("Total time required: %d minutes\n", total_time);
}