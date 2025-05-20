//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {

    char mem[1024];
    double cpu;
    FILE *fp;
    int idle1, idle2, work1, work2;
    char *token;

    while(1) {
        if((fp = fopen("/proc/stat","r")) == NULL){
            perror("fopen");
            exit(EXIT_FAILURE);
        }
        fgets(mem, 1024, fp);
        fclose(fp);
        token = strtok(mem, " ");
        int i = 0;
        int cpuStats[10];
        while(token != NULL){
            token = strtok(NULL, " ");
            if(token != NULL){
                cpuStats[i] = atoi(token);
                i++;
            }
        }
        idle1 = cpuStats[3];
        work1 = cpuStats[0]+cpuStats[1]+cpuStats[2]+cpuStats[4]+cpuStats[5]+cpuStats[6]+cpuStats[7]+cpuStats[8]+cpuStats[9];
        sleep(1);

        if((fp = fopen("/proc/stat","r")) == NULL){
            perror("fopen");
            exit(EXIT_FAILURE);
        }
        fgets(mem, 1024, fp);
        fclose(fp);
        token = strtok(mem, " ");
        i = 0;
        while(token != NULL){
            token = strtok(NULL, " ");
            if(token != NULL){
                cpuStats[i] = atoi(token);
                i++;
            }
        }
        idle2 = cpuStats[3];
        work2 = cpuStats[0]+cpuStats[1]+cpuStats[2]+cpuStats[4]+cpuStats[5]+cpuStats[6]+cpuStats[7]+cpuStats[8]+cpuStats[9];

        cpu = (double)(work2 - work1) / (double)((work2 + idle2) - (work1 + idle1));

        printf("CPU Usage: %.2f%%\n", cpu*100);
    }

    return 0;
}