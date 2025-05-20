//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define MAX_CPU_USAGE 100
#define MAX_LINES 50

int main()
{
    int i;
    clock_t t;
    char buffer[MAX_LINES];
    float cpuUsage;

    for(i = 0; i < MAX_LINES; i++){
        snprintf(buffer, MAX_LINES, "/proc/stat");
        FILE* fp = fopen(buffer, "r");
        if(fp == NULL){
            printf("Error opening file\n");
            exit(EXIT_FAILURE);
        }
        fgets(buffer, MAX_LINES, fp);
        fclose(fp);

        char *token = strtok(buffer, " ");
        token = strtok(NULL, " ");         // user
        token = strtok(NULL, " ");         // user nice
        token = strtok(NULL, " ");         // system
        token = strtok(NULL, " ");         // idle
        unsigned long long int idleTime = strtoull(token, NULL, 0);
        usleep(1000000);            // sleep for 1 second

        fp = fopen("/proc/stat", "r");
        if(fp == NULL){
            printf("Error opening file\n");
            exit(EXIT_FAILURE);
        }
        fgets(buffer, MAX_LINES, fp);
        fclose(fp);

        token = strtok(buffer, " ");
        token = strtok(NULL, " ");         // user
        token = strtok(NULL, " ");         // user nice
        token = strtok(NULL, " ");         // system
        token = strtok(NULL, " ");         // idle
        unsigned long long int idleTimeNew = strtoull(token, NULL, 0);

        unsigned long long int idleTimeDiff = idleTimeNew - idleTime;
        unsigned long long int totalTimeDiff = (idleTimeNew + strtoull(token, NULL, 0)) - (idleTime + strtoull(token, NULL, 0));
        cpuUsage = 100-((float)idleTimeDiff/(float)totalTimeDiff*100);

        printf("Current CPU usage is: %.2f%%\n", cpuUsage);
    }
    return 0;
}