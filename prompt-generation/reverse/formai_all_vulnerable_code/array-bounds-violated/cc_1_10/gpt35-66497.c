//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

struct queue{
int val;
int priority;
struct queue *next;
}*head[5],*tail[5];

void addq(int priority, int value, int q_id){
    struct queue *temp;
    temp = (struct queue*)malloc(sizeof(struct queue));
    temp->priority = priority;
    temp->val = value;
    temp->next = NULL;
    if(head[q_id] == NULL){
        head[q_id] = temp;
        tail[q_id] = temp;
    }
    else{
        if(tail[q_id]->priority > priority){
            temp->next = head[q_id];
            head[q_id] = temp;
        }
        else if(head[q_id]->priority < priority){
            tail[q_id]->next = temp;
            tail[q_id] = temp;
        }
        else{
            struct queue *temp2, *temp3;
            temp2 = head[q_id];
            while(temp2->next != NULL && temp2->next->priority <= priority){
                temp2 = temp2->next;
            }
            temp3 = temp2->next;
            temp2->next = temp;
            temp->next = temp3;
        }
    }
}

int deleteq(){
    int val = -1;
    struct queue *temp;
    if(head[4] != NULL){
        temp = head[4];
        val = temp->val;
        head[4] = temp->next;
        free(temp);
    }
    else if(head[3] != NULL){
        temp = head[3];
        val = temp->val;
        head[3] = temp->next;
        free(temp);
    }
    else if(head[2] != NULL){
        temp = head[2];
        val = temp->val;
        head[2] = temp->next;
        free(temp);
    }
    else if(head[1] != NULL){
        temp = head[1];
        val = temp->val;
        head[1] = temp->next;
        free(temp);
    }
    else if(head[0] != NULL){
        temp = head[0];
        val = temp->val;
        head[0] = temp->next;
        free(temp);
    }
    return val;
}

int main(){
    int n, pid[100], arr[100], burst[100], i, time = 0, wait_time = 0, turn_time = 0, q_id, quantum;
    float avg_wait_time, avg_turn_time;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("\nEnter Process ID, Arrival Time and Burst Time of each process\n");
    for(i=0;i<n;i++){
        printf("\nProcess ID: ");
        scanf("%d",&pid[i]);
        printf("Arrival Time: ");
        scanf("%d",&arr[i]);
        printf("Burst Time: ");
        scanf("%d",&burst[i]);
        if(burst[i]<=10){
            q_id = 0;
            quantum = 1;
        }
        else if(burst[i]>10 && burst[i]<=20){
            q_id = 1;
            quantum = 2;
        }
        else if(burst[i]>20 && burst[i]<=30){
            q_id = 2;
            quantum = 3;
        }
        else if(burst[i]>30 && burst[i]<=40){
            q_id = 3;
            quantum = 4;
        }
        else{
            q_id = 4;
            quantum = 5;
        }
        addq(q_id, i, quantum);
    }
    printf("\nThe queue IDs are: 0->Priority 1, 1->Priority 2, 2->Priority 3, 3->Priority 4, 4->Proceses completed\n");
    printf("\n\nExecuting Processes......\n");
    printf("\n| Time |     PID     | Priority | Burst Time | Waiting Time | Turnaround Time |\n");
    printf("------------------------------------------------------------------------------\n");
    while(head[4] == NULL){
        if(head[3] != NULL){
            q_id = 3;
            quantum = 4;
        }
        else if(head[2] != NULL){
            q_id = 2;
            quantum = 3;
        }
        else if(head[1] != NULL){
            q_id = 1;
            quantum = 2;
        }
        else{
            q_id = 0;
            quantum = 1;
        }
        i = deleteq();
        if(i != -1){
            int remain_time = burst[i]-quantum;
            if(remain_time > 0){
                addq(q_id, i, remain_time);
            }
            else{
                printf("|%5d |  Process %2d | Priority %d | %9d | %11d | %15d |",time,pid[i],q_id+1,burst[i],wait_time,arr[i]+wait_time);
                wait_time += time - arr[i];
                turn_time += time - arr[i] + burst[i];
                burst[i] = 0;
                printf("\n");
            }
        }
        time += quantum;
    }
    printf("------------------------------------------------------------------------------\n");
    avg_wait_time = wait_time * 1.0 / n;
    avg_turn_time = turn_time * 1.0 / n;
    printf("\n\nAverage Waiting Time: %f",avg_wait_time);
    printf("\nAverage Turnaround Time: %f\n",avg_turn_time);

    return 0;
}