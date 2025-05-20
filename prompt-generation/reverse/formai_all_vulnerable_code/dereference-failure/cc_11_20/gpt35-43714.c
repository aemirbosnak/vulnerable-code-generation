//FormAI DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#define SIZE 1024

typedef struct{
    char pid[SIZE];
    char name[SIZE];
    char status[SIZE];
    char memory[SIZE];
} ProcessInfo;

int main(){
    DIR* dir = opendir("/proc");
    struct dirent* item;

    ProcessInfo procInfo[SIZE];
    int size = 0;

    while((item = readdir(dir)) != NULL){
        if(item->d_type != DT_DIR)
            continue;

        char path[SIZE];
        strcpy(path, "/proc/");
        strcat(path, item->d_name);
        strcat(path, "/status");

        FILE* file = fopen(path, "r");
        if(file == NULL)
            continue;

        char line[SIZE];
        fgets(line, SIZE, file);

        while(!feof(file)){
            if(sscanf(line, "Name: %s", procInfo[size].name) == 1){
                strcpy(procInfo[size].pid, item->d_name);
                break;
            }
            fgets(line, SIZE, file);
        }
        fclose(file);

        strcpy(path, "/proc/");
        strcat(path, item->d_name);
        strcat(path, "/statm");  

        file = fopen(path, "r");
        if(file == NULL)
            continue;

        fgets(line, SIZE, file);
        sscanf(line, "%s", procInfo[size].memory);
        fclose(file);

        strcpy(path, "/proc/");
        strcat(path, item->d_name);
        strcat(path, "/status"); 
        file = fopen(path, "r");

        if(file == NULL)
            continue;

        fgets(line, SIZE, file);
        while(!feof(file)){
            if(sscanf(line, "State: %s", procInfo[size].status) == 1)
                break;
            fgets(line, SIZE, file);
        }
        fclose(file);

        size++;
    }
    closedir(dir);

    printf("%10s %20s %10s %20s\n", "PID", "Name", "Status", "Memory");

    for(int i = 0; i < size; i++){
        printf("%10s %20s %10s %20s\n", procInfo[i].pid, procInfo[i].name, procInfo[i].status, procInfo[i].memory);
    }

    return 0;
}