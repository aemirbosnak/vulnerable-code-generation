//FormAI DATASET v1.0 Category: Task Scheduler ; Style: lively
#include<stdio.h>
#include<stdlib.h>

typedef struct {
      int taskID;
      int priority;
      int burstTime;
      int arrivalTime;
      int waitingTime;
      int turnaroundTime;
}Task;

int numOfTasks;
Task* taskList;

void printTable()
{
      printf("Task ID | Priority | Burst Time | Arrival Time | Waiting Time | Turnaround Time\n");
      for(int i=0;i<numOfTasks;i++)
      {
            printf("%7d|%10d|%12d|%14d|%13d|%17d\n",taskList[i].taskID,taskList[i].priority,taskList[i].burstTime,taskList[i].arrivalTime,taskList[i].waitingTime,taskList[i].turnaroundTime);
      }
}

void sortTasksByArrivalTime()
{
      Task temp;
      for(int i=0;i<numOfTasks-1;i++)
      {
            for(int j=i+1;j<numOfTasks;j++)
            {
                  if(taskList[i].arrivalTime>taskList[j].arrivalTime)
                  {
                        temp=taskList[i];
                        taskList[i]=taskList[j];
                        taskList[j]=temp;
                  }
            }
      }
}

void sortTasksByPriority()
{
      Task temp;
      for(int i=0;i<numOfTasks-1;i++)
      {
            for(int j=i+1;j<numOfTasks;j++)
            {
                  if(taskList[i].priority>taskList[j].priority && taskList[i].arrivalTime<=taskList[j].arrivalTime)
                  {
                        temp=taskList[i];
                        taskList[i]=taskList[j];
                        taskList[j]=temp;
                  }
            }
      }
}

void completionTime()
{
      int currentTime=taskList[0].arrivalTime+taskList[0].burstTime;
      for(int i=1;i<numOfTasks;i++)
      {
            if(currentTime>=taskList[i].arrivalTime)
            {
                  taskList[i].waitingTime=currentTime-taskList[i].arrivalTime;
                  currentTime+=taskList[i].burstTime;
            }
            else
            {
                  currentTime=taskList[i].arrivalTime+taskList[i].burstTime;
            }
            taskList[i].turnaroundTime=taskList[i].burstTime+taskList[i].waitingTime;
      }
}

float averageWaitingTime()
{
      int sum=0;
      for(int i=0;i<numOfTasks;i++)
      {
            sum+=taskList[i].waitingTime;
      }
      return sum/(float)numOfTasks;
}


float averageTurnaroundTime()
{
      int sum=0;
      for(int i=0;i<numOfTasks;i++)
      {
            sum+=taskList[i].turnaroundTime;
      }
      return sum/(float)numOfTasks;
}

int main()
{
      // Reading Input
      printf("Enter the number of tasks: ");
      scanf("%d",&numOfTasks);

      printf("\nEnter task ID, Priority, Burst Time and Arrival Time\n");
      taskList=(Task*)malloc(sizeof(Task)*numOfTasks);

      for(int i=0;i<numOfTasks;i++)
      {
            printf("\nTask %d ",(i+1));
            scanf("%d%d%d%d",&taskList[i].taskID,&taskList[i].priority,&taskList[i].burstTime,&taskList[i].arrivalTime);
      }

      printf("\n\nTask Details\n");
      printTable();

      sortTasksByArrivalTime();

      printf("\n\nTask Details sorted by arrival time\n");
      printTable();

      sortTasksByPriority();

      printf("\n\nTask Details sorted by priority\n");
      printTable();

      completionTime();

      printf("\n\nTask Details after completion\n");
      printTable();
    
      printf("\n\nAverage Waiting Time = %.2f\n",averageWaitingTime());
      printf("\nAverage Turnaround Time = %.2f\n",averageTurnaroundTime());

      return 0;
}