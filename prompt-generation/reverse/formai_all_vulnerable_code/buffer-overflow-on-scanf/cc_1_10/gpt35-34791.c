//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int task_id;
    char task_name[50];
    int duration;
    int start_time;
    bool is_complete;
} Task;

Task task_list[10];
int num_tasks = 0;
int time_counter = 0;

void add_task(int task_id, char task_name[], int duration) {
    Task new_task = {
        .task_id = task_id,
        .duration = duration,
        .start_time = -1,
        .is_complete = false
    };
    int i;
    for (i = 0; i < 50; i++) {
        new_task.task_name[i] = task_name[i];
        if (task_name[i] == '\0') break;
    }
    task_list[num_tasks++] = new_task;
    printf("Task %d (%s) added.\n", task_id, task_name);
}

void print_task_list() {
    printf("TASK LIST:\n");
    int i;
    for (i = 0; i < num_tasks; i++) {
        printf("  Task %d: %s (%d min)\n", task_list[i].task_id, task_list[i].task_name, task_list[i].duration);
    }
    printf("\n");
}

void start_task(int task_id) {
    int i;
    for (i = 0; i < num_tasks; i++) {
        if (task_list[i].task_id == task_id) {
            if (task_list[i].start_time == -1) {
                task_list[i].start_time = time_counter;
                printf("Task %d (%s) started at time %d.\n", task_id, task_list[i].task_name, time_counter);
            } else {
                printf("Task %d (%s) is already in progress.\n", task_id, task_list[i].task_name);
            }
            return;
        }
    }
    printf("Task %d not found.\n", task_id);
}

void complete_task(int task_id) {
    int i;
    for (i = 0; i < num_tasks; i++) {
        if (task_list[i].task_id == task_id) {
            if (task_list[i].is_complete) {
                printf("Task %d (%s) is already complete.\n", task_id, task_list[i].task_name);
            } else if (task_list[i].start_time == -1) {
                printf("Task %d (%s) has not been started yet.\n", task_id, task_list[i].task_name);
            } else {
                int task_time_elapsed = time_counter - task_list[i].start_time;
                if (task_time_elapsed >= task_list[i].duration) {
                    task_list[i].is_complete = true;
                    printf("Task %d (%s) completed at time %d.\n", task_id, task_list[i].task_name, time_counter);
                } else {
                    printf("Task %d (%s) is %d minutes from completion.\n", task_id, task_list[i].task_name, task_list[i].duration - task_time_elapsed);
                }
            }
            return;
        }
    }
    printf("Task %d not found.\n", task_id);
}

int main() {
    printf("Sherlock Holmes' Task Scheduler\n\n");
    printf("Sherlock Holmes is investigating a case that requires him to complete various tasks throughout the day.\n");
    printf("Using his task scheduler, he can keep track of which tasks he's completed and which still need to be done.\n\n");

    add_task(1, "Examine crime scene", 30);
    add_task(2, "Interview witness", 20);
    add_task(3, "Analyze evidence", 45);
    add_task(4, "Consult with Dr. Watson", 15);

    print_task_list();

    printf("Sherlock Holmes starts his day.\n\n");

    while (true) {
        char command[50];
        printf("Enter command ([h]elp for list of commands): ");
        scanf("%s", command);

        if (command[0] == 'h') {
            printf("Commands:\n");
            printf("  [l]ist tasks: displays the current task list\n");
            printf("  [s]tart task [task_id]: starts the specified task\n");
            printf("  [c]omplete task [task_id]: completes the specified task if possible\n");
            printf("  [q]uit: ends the task scheduler program\n\n");
        } else if (command[0] == 'l') {
            print_task_list();
        } else if (command[0] == 's') {
            int task_id;
            scanf("%d", &task_id);
            start_task(task_id);
        } else if (command[0] == 'c') {
            int task_id;
            scanf("%d", &task_id);
            complete_task(task_id);
        } else if (command[0] == 'q') {
            printf("Sherlock Holmes' Task Scheduler program ended.\n");
            return 0;
        } else {
            printf("Invalid command. Enter [h]elp for list of commands.\n");
        }

        time_counter++;
        printf("\n");
    }
}