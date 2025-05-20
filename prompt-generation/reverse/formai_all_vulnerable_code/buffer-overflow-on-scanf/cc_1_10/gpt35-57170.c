//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LENGTH 20

struct Task {
    char name[MAX_TASK_NAME_LENGTH];
    int duration;
    time_t scheduled_time;
};

int num_tasks = 0;
struct Task task_list[MAX_TASKS];

int get_random_number(int limit) {
    time_t t;
    srand((unsigned) time(&t));
    return rand() % limit;
}

void add_task() {
    if(num_tasks >= MAX_TASKS) {
        printf("Sorry, task list is full.\n");
        return;
    }

    printf("Enter task name: ");
    scanf("%s", task_list[num_tasks].name);
    printf("Enter task duration (in minutes): ");
    scanf("%d", &task_list[num_tasks].duration);

    int random_offset = get_random_number(60);
    task_list[num_tasks].scheduled_time = time(NULL) + random_offset * 60;
    
    printf("Task '%s' scheduled for %d minutes from %s\n", 
           task_list[num_tasks].name, task_list[num_tasks].duration, 
           ctime(&task_list[num_tasks].scheduled_time));
    
    num_tasks++;
}

void remove_task() {
    if(num_tasks == 0) {
        printf("Sorry, no tasks to remove.\n");
        return;
    }
    
    printf("Removing task '%s'...\n", task_list[0].name);
    for(int i=0; i<num_tasks-1; i++) {
        task_list[i] = task_list[i+1];
    }
    num_tasks--;
}

void print_task_list() {
    if(num_tasks == 0) {
        printf("No tasks scheduled.\n");
        return;
    }

    printf("Task\t\tDuration\tScheduled Time\n");
    for(int i=0; i<num_tasks; i++) {
        printf("%s\t\t%d\t\t%s", task_list[i].name, task_list[i].duration, 
               ctime(&task_list[i].scheduled_time));
    }
}

int main() {
    int choice;

    while(1) {      
        printf("Task Scheduler\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. View Task List\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_task();
                break;
            case 2:
                remove_task();
                break;
            case 3:
                print_task_list();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}