//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: funny
#include<stdio.h>

int main(){
    printf("Welcome to the C CPU Scheduling Algorithms program! \n");
    printf("We're going to have some fun with these algorithms, so buckle up! \n");
    
    int num_processes, i;
    printf("Please enter the number of processes: \n");
    scanf("%d", &num_processes);
    
    int burst_time[num_processes], priority[num_processes], wait_time[num_processes], turn_around_time[num_processes], completion_time[num_processes];
    float avg_wait_time = 0, avg_turn_around_time = 0;
    
    printf("Great! Now let's enter the burst time and priority for each process: \n");
    
    for(i = 0; i < num_processes; i++){
        printf("Process %d: \n", i+1);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
    }
    
    // First Come First Serve Algorithm
    printf("Let's start with the First Come First Serve Algorithm! \n");
    
    wait_time[0] = 0;
    completion_time[0] = burst_time[0];
    turn_around_time[0] = completion_time[0];
    
    for(i = 1; i < num_processes; i++){
        wait_time[i] = completion_time[i-1];
        completion_time[i] = wait_time[i] + burst_time[i];
        turn_around_time[i] = completion_time[i] - wait_time[i];
    }
    
    printf("Process\t\tBurst Time\tWaiting Time\tTurn Around Time\n");
    
    for(i = 0; i < num_processes; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], wait_time[i], turn_around_time[i]);
        avg_wait_time += wait_time[i];
        avg_turn_around_time += turn_around_time[i];
    }
    
    avg_wait_time /= num_processes;
    avg_turn_around_time /= num_processes;
    
    printf("Average Waiting Time: %f\n", avg_wait_time);
    printf("Average Turn Around Time: %f\n", avg_turn_around_time);
    
    // Shortest Job First Algorithm
    printf("Next up is the Shortest Job First Algorithm. Get ready! \n");

    int remaining_burst_time[num_processes];
    int smallest_burst_time_index = 0;
    remaining_burst_time[0] = burst_time[0];
    
    for(i = 1; i < num_processes; i++){
        remaining_burst_time[i] = burst_time[i];
        if(burst_time[i] < burst_time[smallest_burst_time_index]){
            smallest_burst_time_index = i;
        }
    }

    int time = 0;
    int done = 0;

    while(done != num_processes){
        int prev_index = smallest_burst_time_index;
        smallest_burst_time_index = -1;

        for(i = 0; i < num_processes; i++){
            if(remaining_burst_time[i] > 0 && (smallest_burst_time_index == -1 || remaining_burst_time[i] < remaining_burst_time[smallest_burst_time_index])){
                smallest_burst_time_index = i;
            }
        }

        if(prev_index != smallest_burst_time_index){
            printf("Time %d: Process %d executed \n", time, smallest_burst_time_index + 1);
        }

        remaining_burst_time[smallest_burst_time_index]--;

        if(remaining_burst_time[smallest_burst_time_index] == 0){
            printf("Time %d: Process %d finished \n", time+1, smallest_burst_time_index + 1);
            completion_time[smallest_burst_time_index] = time+1;
            wait_time[smallest_burst_time_index] = completion_time[smallest_burst_time_index] - burst_time[smallest_burst_time_index];
            turn_around_time[smallest_burst_time_index] = wait_time[smallest_burst_time_index] + burst_time[smallest_burst_time_index];
            avg_wait_time += wait_time[smallest_burst_time_index];
            avg_turn_around_time += turn_around_time[smallest_burst_time_index];
            done++;
        }

        time++;
    }

    avg_wait_time /= num_processes;
    avg_turn_around_time /= num_processes;

    printf("Process\t\tBurst Time\tWaiting Time\tTurn Around Time\n");

    for(i = 0; i < num_processes; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], wait_time[i], turn_around_time[i]);
    }

    printf("Average Waiting Time: %f\n", avg_wait_time);
    printf("Average Turn Around Time: %f\n", avg_turn_around_time);
    
    // Round Robin Algorithm
    printf("Last but not least, the Round Robin Algorithm! This one always makes me dizzy. \n");

    int time_quantum, j;
    printf("Please enter the time quantum: \n");
    scanf("%d", &time_quantum);

    int remaining_time[num_processes];
    for(i = 0; i < num_processes; i++){
        remaining_time[i] = burst_time[i];
    }

    int time2 = 0;
    int flag = 0;

    while(1){
        flag = 0;

        for(i = 0; i < num_processes; i++){
            if(remaining_time[i] > 0){
                flag = 1;

                if(remaining_time[i] > time_quantum){
                    time2 += time_quantum;
                    remaining_time[i] -= time_quantum;
                    printf("Time %d: Process %d executed \n", time2, i+1);
                }
                else{
                    time2 += remaining_time[i];
                    completion_time[i] = time2;
                    wait_time[i] = completion_time[i] - burst_time[i];
                    turn_around_time[i] = completion_time[i] - wait_time[i];
                    printf("Time %d: Process %d finished \n", time2, i+1);
                    avg_wait_time += wait_time[i];
                    avg_turn_around_time += turn_around_time[i];
                    remaining_time[i] = 0;
                }
            }
        }

        if(flag == 0){
            break;
        }
    }

    avg_wait_time /= num_processes;
    avg_turn_around_time /= num_processes;

    printf("Process\t\tBurst Time\tWaiting Time\tTurn Around Time\n");

    for(i = 0; i < num_processes; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], wait_time[i], turn_around_time[i]);
    }

    printf("Average Waiting Time: %.2f\n", avg_wait_time);
    printf("Average Turn Around Time: %.2f\n", avg_turn_around_time);
    
    printf("That's all, folks! Thanks for using our C CPU Scheduling Algorithms program. We hope you had as much fun as we did. \n");
    
    return 0;
}