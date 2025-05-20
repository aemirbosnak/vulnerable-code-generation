//Code Llama-13B DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structures
typedef struct {
    int id;
    char *name;
    char *description;
    time_t due_date;
    int priority;
} Task;

typedef struct {
    int id;
    char *name;
    char *description;
    time_t start_date;
    time_t end_date;
    int priority;
} Project;

// Function prototypes
void print_task_list(Task *task_list, int num_tasks);
void print_project_list(Project *project_list, int num_projects);
void print_task_schedule(Task *task_list, int num_tasks, Project *project_list, int num_projects);

// Main function
int main() {
    // Initialize task list
    Task task_list[] = {
        {1, "Make breakfast", "Prepare and eat a healthy breakfast", time(NULL) + 600, 3},
        {2, "Exercise", "Go for a morning walk or do some yoga", time(NULL) + 900, 2},
        {3, "Eat lunch", "Prepare and eat a healthy lunch", time(NULL) + 1200, 4},
        {4, "Work on project", "Work on a project for 4 hours", time(NULL) + 1600, 1},
        {5, "Relax", "Take a break and relax", time(NULL) + 2000, 5}
    };
    int num_tasks = sizeof(task_list) / sizeof(task_list[0]);

    // Initialize project list
    Project project_list[] = {
        {1, "Work on project", "Work on a project for 4 hours", time(NULL) + 1600, time(NULL) + 2000, 1},
        {2, "Clean room", "Clean the room and organize the living space", time(NULL) + 800, time(NULL) + 1200, 3},
        {3, "Prepare dinner", "Prepare and eat a healthy dinner", time(NULL) + 1600, time(NULL) + 2000, 2}
    };
    int num_projects = sizeof(project_list) / sizeof(project_list[0]);

    // Print task list
    print_task_list(task_list, num_tasks);

    // Print project list
    print_project_list(project_list, num_projects);

    // Print task schedule
    print_task_schedule(task_list, num_tasks, project_list, num_projects);

    return 0;
}

// Function definitions
void print_task_list(Task *task_list, int num_tasks) {
    printf("Task List:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d. %s (%d)\n", task_list[i].id, task_list[i].name, task_list[i].priority);
    }
    printf("\n");
}

void print_project_list(Project *project_list, int num_projects) {
    printf("Project List:\n");
    for (int i = 0; i < num_projects; i++) {
        printf("%d. %s (%d)\n", project_list[i].id, project_list[i].name, project_list[i].priority);
    }
    printf("\n");
}

void print_task_schedule(Task *task_list, int num_tasks, Project *project_list, int num_projects) {
    printf("Task Schedule:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d. %s (%d) (%s)\n", task_list[i].id, task_list[i].name, task_list[i].priority, task_list[i].description);
    }
    for (int i = 0; i < num_projects; i++) {
        printf("%d. %s (%d) (%s) (%s - %s)\n", project_list[i].id, project_list[i].name, project_list[i].priority, project_list[i].description, ctime(&project_list[i].start_date), ctime(&project_list[i].end_date));
    }
    printf("\n");
}