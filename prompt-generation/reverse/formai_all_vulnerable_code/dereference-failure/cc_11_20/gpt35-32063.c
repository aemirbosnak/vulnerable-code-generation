//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MAX_LEN 1024

int main(int argc, char** argv){
    int interval = 1;
    int duration = 10;
    int num_cores = get_nprocs();
    if (argc > 1){
        interval = atoi(argv[1]);
        if (argc > 2){
            duration = atoi(argv[2]);
        }
    }

    int** cpu_stat = (int**) malloc(num_cores * sizeof(int*));
    for (int i=0; i<num_cores; i++){
        cpu_stat[i] = (int*) malloc(10 * sizeof(int));
        for(int j=0; j<10; j++){
            cpu_stat[i][j] = 0;
        }
    }

    int time_elapsed = 0;

    while(time_elapsed < duration){
        struct sysinfo info;
        if(sysinfo(&info) != 0) {
            perror("sysinfo()");
            exit(EXIT_FAILURE);
        }
        FILE* fp;
        char buffer[MAX_LEN];
        fp = fopen("/proc/stat","r");
        if(fp == NULL){
            perror("fopen()");
            exit(EXIT_FAILURE);
        }

        char cpu[10];
        int user, nice, system, idle, iowait, irq, softirq, steal;
        int core_num = 0;
        for (int i=0; i<num_cores+1; i++){
            fgets(buffer, MAX_LEN, fp);
            if(i>0){
                sscanf(buffer, "%s %d %d %d %d %d %d %d %d", cpu, &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
                int total = user + nice + system + idle + iowait + irq + softirq + steal;
                if(strcmp(cpu, "cpu") == 0){
                    int total_usage = 0;
                    for(int j=0; j<10; j++){
                        total_usage += cpu_stat[core_num][j];
                    }
                    int current_usage = 100 - ((idle - cpu_stat[core_num][0]) * 100 / (total - total_usage));
                    printf("CPU: %d, Usage: %d%%\n", core_num, current_usage);
                    for(int j=1; j<9; j++){
                        cpu_stat[core_num][j-1] = cpu_stat[core_num][j];
                    }
                    cpu_stat[core_num][9] = idle;
                    core_num++;
                }
            }
        }
        fclose(fp);
        sleep(interval);
        time_elapsed += interval;
    }

    for (int i=0; i<num_cores; i++){
        free(cpu_stat[i]);
    }
    free(cpu_stat);

    return 0;
}