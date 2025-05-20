//FormAI DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_SLOTS 10 //maximum number of scheduled tasks
#define UNUSED 0 //mark slot unused
#define USED 1 //mark slot used
#define ALLOWED_EXEC 2 //allow execution of task

typedef struct {
    char task_name[20];
    time_t time;
    int status;
}Task;

Task task_list[MAX_SLOTS]; //list of all tasks
int current_slot = 0; //slot counter

void display_menu() {
    printf("=============================\n");
    printf("TASK SCHEDULER MENU\n\n");
    printf("1. Add new task\n");
    printf("2. Edit existing task\n");
    printf("3. Delete existing task\n");
    printf("4. Display all tasks\n");
    printf("5. Exit\n");
    printf("=============================\n");
}

int get_next_slot() {
    int i;
    for(i=0; i<MAX_SLOTS; i++) {
        if(task_list[i].status == UNUSED) {
            return i;
        }
    }
    printf("Task scheduler is full!\n");
    return -1;
}

void add_new_task() {
    int slot_index;
    time_t timer;
    double seconds;
    char task_name[20];

    printf("Enter task name: ");
    scanf("%s", task_name);

    printf("Enter time in seconds: ");
    scanf("%lf", &seconds);
    timer = time(NULL) + seconds;

    slot_index = get_next_slot();
    if(slot_index == -1) {
        return;
    }

    strcpy(task_list[slot_index].task_name, task_name);
    task_list[slot_index].time = timer;
    task_list[slot_index].status = USED;

    printf("Task added successfully!\n");
}

void edit_existing_task() {
    int task_index;
    time_t timer;
    double seconds;
    char task_name[20];

    printf("Enter task index to edit: ");
    scanf("%d", &task_index);

    if(task_index >= MAX_SLOTS || task_list[task_index].status == UNUSED) {
        printf("Invalid task index!\n");
        return;
    }

    printf("Enter task name: ");
    scanf("%s", task_name);

    printf("Enter time in seconds: ");
    scanf("%lf", &seconds);
    timer = time(NULL) + seconds;

    strcpy(task_list[task_index].task_name, task_name);
    task_list[task_index].time = timer;

    printf("Task updated successfully!\n");
}

void delete_existing_task() {
    int task_index;

    printf("Enter task index to delete: ");
    scanf("%d", &task_index);

    if(task_index >= MAX_SLOTS || task_list[task_index].status == UNUSED) {
        printf("Invalid task index!\n");
        return;
    }

    task_list[task_index].status = UNUSED;

    printf("Task deleted successfully!\n");
}

void display_all_tasks() {
    int i;

    printf("SCHEDULED TASKS\n\n");
    for(i=0; i<MAX_SLOTS; i++) {
        if(task_list[i].status == USED) {
            printf("%d. %s - %s\n", i, task_list[i].task_name, ctime(&task_list[i].time));
        }
    }
}

void execute_task(int task_index) {
    printf("Executing task: %s\n", task_list[task_index].task_name);

    //Task execution logic here
    //...

    task_list[task_index].status = ALLOWED_EXEC;
}

void handle_scheduled_tasks() {
    int i;

    for(i=0; i<MAX_SLOTS; i++) {
        if(task_list[i].status == USED && time(NULL) >= task_list[i].time) {
            execute_task(i);
        }
    }
}

int main() {
    int user_choice;

    printf("Welcome to Task Scheduler!\n");

    while(1) {
        display_menu();

        printf("Enter your choice: ");
        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1:
                add_new_task();
                break;
            case 2:
                edit_existing_task();
                break;
            case 3:
                delete_existing_task();
                break;
            case 4:
                display_all_tasks();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }

        handle_scheduled_tasks();
    }

    return 0;
}