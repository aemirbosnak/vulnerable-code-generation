//FormAI DATASET v1.0 Category: Task Scheduler ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<time.h>

#define MAXTASKS 10     // max number of tasks
#define INTERVAL 1      // default interval in seconds
#define MAXDELAY 10     // maximum delay for task execution in seconds

int taskcount = 0;      // keeps track of the number of tasks added
pid_t taskpid[MAXTASKS];// array to store the pid of each task
char taskname[MAXTASKS][20];// array to store the name of each task

// function to add a task to the scheduler
void addtask(char* task, int delay)
{
    pid_t pid = fork();     // create a new process for the task
    if(pid == 0)            // if pid == 0, this is the child process
    {
        sleep(delay);       // delay execution of the task
        printf("\nTask %s started\n",task);
        execl(task,0);      // execute the task
    }
    else if(pid > 0)        // if pid > 0, this is the parent process
    {
        taskpid[taskcount] = pid;// store the pid of the task
        strcpy(taskname[taskcount],task);// store the name of the task
        taskcount++;        // increment taskcount
    }
    else                    // if pid < 0, error
    {
        printf("\nError adding task\n");
    }
}

// function to remove a task from the scheduler
void removetask(int task)
{
    kill(taskpid[task],SIGKILL);    // kill the task process
    for(int i = task; i < taskcount-1; i++)    // shift elements of the arrays
    {
        taskpid[i] = taskpid[i+1];
        strcpy(taskname[i],taskname[i+1]);
    }
    taskcount--;            // decrement taskcount
}

int main(int argc, char *argv[])
{
    int choice;
    char task[20];
    int delay;
    int status;
    time_t t;
    srand((unsigned) time(&t));    // initialize random number generator

    printf("\nC Task Scheduler\n");

    while(1)
    {
        printf("\nMenu\n");
        printf("1. Add task\n");
        printf("2. Remove task\n");
        printf("3. List tasks\n");
        printf("4. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                if(taskcount >= MAXTASKS)    // check if max number of tasks reached
                {
                    printf("\nMaximum number of tasks added. Remove a task to add new task.\n");
                    break;
                }
                printf("\nEnter task name: ");
                scanf("%s",task);
                delay = rand() % MAXDELAY + 1;  // generate random delay
                printf("\nTask %s will execute after %d second(s)\n",task,delay);
                addtask(task,delay);
                break;

            case 2:
                if(taskcount == 0)
                {
                    printf("\nNo tasks added.\n");
                    break;
                }
                printf("\nTasks:\n");
                for(int i = 0; i < taskcount; i++)
                {
                    printf("%d. %s\n",i+1,taskname[i]);
                }
                printf("\nEnter task number to remove: ");
                scanf("%d",&choice);
                if(choice > taskcount || choice < 1)
                {
                    printf("\nInvalid choice.\n");
                    break;
                }
                printf("\nRemoving task %s\n",taskname[choice-1]);
                removetask(choice-1);
                break;

            case 3:
                if(taskcount == 0)
                {
                    printf("\nNo tasks added.\n");
                    break;
                }
                printf("\nTasks:\n");
                for(int i = 0; i < taskcount; i++)
                {
                    printf("%d. %s\n",i+1,taskname[i]);
                }
                break;

            case 4:
                printf("\nExiting...\n");
                for(int i = 0; i < taskcount; i++)
                {
                    kill(taskpid[i],SIGKILL);  // kill all task processes
                }
                exit(0);

            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}