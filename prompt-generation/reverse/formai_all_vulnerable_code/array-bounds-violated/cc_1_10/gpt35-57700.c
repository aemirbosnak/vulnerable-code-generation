//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MAX_CPU_CORES 16
#define SLEEP_DURATION 2

pthread_mutex_t lock;
int isRunning = 1;

void* cpu_monitor(void* threadID){
    int coreIndex = *(int*)threadID;
    struct sysinfo sys_info;
    unsigned long long lastTotalIdleTime = 0, lastTotalTime = 0;
    unsigned long long idleTime, totalTime, totalIdleTime, totalNonIdleTime;

    while(isRunning){
        if(sysinfo(&sys_info) != 0){
            printf("Failed to read system information.\n");
            return NULL;
        }

        idleTime = sys_info.loads[coreIndex];
        totalTime = idleTime + sys_info.procs + sys_info.loads[3];
        totalIdleTime = idleTime - lastTotalIdleTime;
        totalNonIdleTime = totalTime - lastTotalTime - lastTotalIdleTime;

        pthread_mutex_lock(&lock);
        printf("CPU Core %d Usage: %.2f%%\n", coreIndex + 1, totalNonIdleTime * 100.0 / totalTime);
        pthread_mutex_unlock(&lock);

        lastTotalIdleTime = idleTime;
        lastTotalTime = totalTime;
        sleep(SLEEP_DURATION);
    }

    return NULL;
}

int main(){
    pthread_t threadIDs[MAX_CPU_CORES];
    int coreIDs[MAX_CPU_CORES];
    int numCores = get_nprocs_conf();

    printf("Number of CPU Cores: %d\n", numCores);

    memset(coreIDs, 0, sizeof(coreIDs));
    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < numCores; i++){
        coreIDs[i] = i;
        if(pthread_create(&threadIDs[i], NULL, cpu_monitor, &coreIDs[i]) != 0){
            printf("Failed to create thread for CPU Core %d.\n", i + 1);
            return 1;
        }
    }

    printf("CPU Monitor started.\n");

    while(getchar() != 'q'){
        // Wait for user to input 'q' to quit
    }

    isRunning = 0;

    for(int i = 0; i < numCores; i++){
        pthread_join(threadIDs[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    printf("CPU Monitor stopped.\n");

    return 0;
}