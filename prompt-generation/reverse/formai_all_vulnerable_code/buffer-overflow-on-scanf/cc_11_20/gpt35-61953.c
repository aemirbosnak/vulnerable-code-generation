//FormAI DATASET v1.0 Category: Task Scheduler ; Style: mind-bending
#include<stdio.h>

int main()
{
    printf("Initializing Mind-Bending Task Scheduler\n\n");
    
    int numTasks;
    printf("Enter the number of tasks to be scheduled: ");
    scanf("%d", &numTasks);

    char taskNames[numTasks][30];
    int taskPriorities[numTasks];
    int taskDurations[numTasks];
    int taskDependencies[numTasks];

    for(int i=0; i<numTasks; i++)
    {
        printf("\nEnter the name of task %d: ", i+1);
        scanf("%s", taskNames[i]);

        printf("Enter the priority of task %d (1-10): ", i+1);
        scanf("%d", &taskPriorities[i]);

        printf("Enter the duration of task %d (in minutes): ", i+1);
        scanf("%d", &taskDurations[i]);

        printf("Enter the number of tasks on which task %d depends: ", i+1);
        scanf("%d", &taskDependencies[i]);

        if(taskDependencies[i] > 0)
        {
            printf("Enter the names of tasks on which task %d depends: ", i+1);
            for(int j=0; j<taskDependencies[i]; j++)
            {
                char dependency[30];
                scanf("%s", dependency);
                printf("%s depends on %s\n", taskNames[i], dependency);
            }
        }
    }

    printf("\n\nTask Scheduler Initialized!\n");

    int startTime = 0;
    while(numTasks > 0)
    {
        printf("\n\nCurrent time is %d minutes\n", startTime);
        int currentTask = -1;
        int maxPriority = -1;
        int taskEndTimes[numTasks];
        int endTime = -1;
        for(int i=0; i<numTasks; i++)
        {
            if(taskDependencies[i] > 0)
            {
                continue;
            }

            if(taskEndTimes[i] > startTime)
            {
                continue;
            }

            if(taskPriorities[i] > maxPriority)
            {
                currentTask = i;
                maxPriority = taskPriorities[i];
            }
        }

        if(currentTask == -1)
        {
            startTime++;
            continue;
        }

        printf("Running Task: %s\n", taskNames[currentTask]);
        endTime = startTime + taskDurations[currentTask];
        taskEndTimes[currentTask] = endTime;

        for(int i=0; i<numTasks; i++)
        {
            if(taskDependencies[i] > 0)
            {
                for(int j=0; j<taskDependencies[i]; j++)
                {
                    if(strcmp(taskNames[i], taskNames[currentTask]) == 0)
                    {
                        taskDependencies[i]--;
                    }
                }
            }
        }

        for(int i=currentTask; i<numTasks-1; i++)
        {
            strcpy(taskNames[i], taskNames[i+1]);
            taskPriorities[i] = taskPriorities[i+1];
            taskDurations[i] = taskDurations[i+1];
            taskDependencies[i] = taskDependencies[i+1];
        }

        numTasks--;
    }

    printf("\n\nAll tasks completed in %d minutes!\n", startTime);

    return 0;
}