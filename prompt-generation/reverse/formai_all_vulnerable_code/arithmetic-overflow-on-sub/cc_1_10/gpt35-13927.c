//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <sys/sysinfo.h>

#define KB 1024
#define MB (1024 * KB)
#define GB (1024 * MB)

void displayMemoryUsage(long totalMem, long freeMem, long usedMem){
    printf("Total Memory: %ld GB\n", totalMem/GB);
    printf("Free Memory: %ld GB\n", freeMem/GB);
    printf("Used Memory: %ld GB\n", usedMem/GB);

    printf("\n");
}

void monitorRAM(){
    struct sysinfo memoryInfo;

    if(sysinfo(&memoryInfo) == -1){
        printf("Error getting system information.\n");
        exit(EXIT_FAILURE);
    }

    long totalMem = memoryInfo.totalram * memoryInfo.mem_unit;
    long freeMem = memoryInfo.freeram * memoryInfo.mem_unit;
    long usedMem = totalMem - freeMem;

    while(1){
        system("clear"); //clear terminal window for every iteration

        displayMemoryUsage(totalMem, freeMem, usedMem);

        sleep(5); //sleep for 5 seconds before repeating
        if(sysinfo(&memoryInfo) == -1){
            printf("Error getting system information.\n");
            exit(EXIT_FAILURE);
        }

        freeMem = memoryInfo.freeram * memoryInfo.mem_unit;
        usedMem = totalMem - freeMem;
    }

}

int main()
{
    printf("Welcome to our RAM usage monitor\n");
    printf("Press CTRL+C to terminate this program\n\n");
    
    monitorRAM(); //start monitoring the RAM usage

    return 0; 
}