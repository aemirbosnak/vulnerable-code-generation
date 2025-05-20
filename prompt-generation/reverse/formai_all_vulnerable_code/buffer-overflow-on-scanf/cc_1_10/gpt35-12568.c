//FormAI DATASET v1.0 Category: Task Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void job1(){
    printf("Job 1 is running\n");
    sleep(2);
}

void job2(){
    printf("Job 2 is running\n");
    sleep(1);
}

void job3(){
    printf("Job 3 is running\n");
    sleep(3);
}

void job4(){
    printf("Job 4 is running\n");
    sleep(1);
}

int main(){
    int round, i, j;
    printf("Enter the number of rounds you want the task scheduler to execute: ");
    scanf("%d", &round);
    srand(time(NULL));

    for (i = 1; i <= round; i++){
        printf("\n\nRound %d of Task Scheduler\n", i);
        printf("----------------------------\n");
        int job_list[4] = {1, 2, 3, 4};
        for (j = 0; j < 4; j++){
            int random = rand() % 4;
            int temp = job_list[j];
            job_list[j] = job_list[random];
            job_list[random] = temp;

            switch(job_list[j]){
                case 1:
                    job1();
                    break;
                case 2:
                    job2();
                    break;
                case 3:
                    job3();
                    break;
                case 4:
                    job4();
                    break;
                default:
                    printf("Invalid job number\n");
                    break;
            }
        }
    }

    return 0;
}