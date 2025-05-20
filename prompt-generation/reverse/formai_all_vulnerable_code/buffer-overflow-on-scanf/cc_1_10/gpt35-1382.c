//FormAI DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX_TASKS 10      // Maximum number of tasks that can be created
#define MAX_TASK_TIME 10  // Maximum time limit for each task

// Structure for a single task
struct Task{
    int taskID;
    int startTime;
    int endTime;
    int priority;
    char taskName[20];
};

int numTasks = 0;        // Global variable to keep count of total number of tasks created
struct Task taskList[MAX_TASKS];  // Array of Task structures to store all tasks created

// Function to create and add a new task
void createTask(){
    if(numTasks == MAX_TASKS){
        printf("\n Error: Task limit exceeded!\n");
        return;
    }
    printf("\nEnter task name: ");
    scanf("%s", taskList[numTasks].taskName);
    printf("Enter task priority(1-5): ");
    scanf("%d", &taskList[numTasks].priority);
    srand((unsigned int)time(NULL));  // Setting seed for random start and end time
    taskList[numTasks].startTime = rand() % 24;   // Random start time within 24hrs
    taskList[numTasks].endTime = taskList[numTasks].startTime + (rand() % MAX_TASK_TIME) + 1;  // Random end time
    taskList[numTasks].taskID = numTasks + 1;     // Task ID is assigned based on its position in the array
    numTasks++;  // Incrementing total number of tasks
    printf("\n Task created successfully! \n");
}

// Function to remove a task by ID
void removeTask(){
    int taskID, i, found = 0;
    printf("\n Enter task ID to remove: ");
    scanf("%d", &taskID);
    for(i=0;i<numTasks;i++){
        if(taskList[i].taskID == taskID){
            found = 1;
            break;
        }
    }
    if(found){
        for(i=i;i<numTasks-1;i++){
            taskList[i] = taskList[i+1];  // Shifting tasks to fill the gap
        }
        numTasks--;  // Decrementing total number of tasks
        printf("\n Task removed successfully! \n");
    }
    else{
        printf("\n Error: Task not found!\n");
    }
}

// Function to print all tasks
void printAllTasks(){
    if(numTasks == 0){
        printf("\n No tasks found!\n");
        return;
    }
    printf("\n========== TASK LIST ==========\n\n");
    printf("ID\tPriority\tStart Time\tEnd Time\tTask Name\n");
    int i;
    for(i=0;i<numTasks;i++){
        printf("%d\t%d\t\t%02d:00\t\t%02d:00\t\t%s\n", taskList[i].taskID, taskList[i].priority, taskList[i].startTime, taskList[i].endTime, taskList[i].taskName);
    }
    printf("\n================================\n");
}

// Main function
int main()
{
    int choice = 0;
    while(choice != 4){
        printf("\n=========== MENU ============\n\n");
        printf("1. Create Task\n");
        printf("2. Remove Task\n");
        printf("3. Display All Tasks\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: createTask();
                    break;
            case 2: removeTask();
                    break;
            case 3: printAllTasks();
                    break;
            case 4: printf("Exiting...Thank You!\n\n");
                    break;
            default: printf("\nInvalid choice, please try again!\n");
                     break;
        }
    }
    return 0;
}