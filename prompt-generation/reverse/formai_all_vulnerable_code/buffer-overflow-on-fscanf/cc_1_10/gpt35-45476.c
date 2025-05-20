//FormAI DATASET v1.0 Category: System process viewer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PID_LENGTH 6
#define MAX_STAT_LENGTH 1024
#define MAX_NAME_LENGTH 256

// Struct to store process info
typedef struct{
    char pid[MAX_PID_LENGTH];
    char name[MAX_NAME_LENGTH];
    char state;
    int ppid;
    int priority;
} ProcessInfo;

// Function to check if string is numeric
int isNumeric(const char *str){
    while(*str){
        if(!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

// Function to get process info from /proc
ProcessInfo getProcessInfo(const char *pid){
    ProcessInfo info;
    memset(&info, 0, sizeof(ProcessInfo));

    // Get process name
    char name_file_path[256];
    sprintf(name_file_path, "/proc/%s/stat", pid);
    FILE *name_file = fopen(name_file_path, "r");
    if(name_file){
        fscanf(name_file, "%s", info.pid);
        fscanf(name_file, "%s", info.name);
        fclose(name_file);
    }

    // Get process state
    char stat_file_path[256];
    sprintf(stat_file_path, "/proc/%s/status", pid);
    FILE *stat_file = fopen(stat_file_path, "r");
    if(stat_file){
        char line[256];
        while(fgets(line, sizeof(line), stat_file)){
            if(strncmp(line, "State:", 6) == 0){
                info.state = line[7];
                break;
            }
        }
        fclose(stat_file);
    }

    // Get parent process id
    char statm_file_path[256];
    sprintf(statm_file_path, "/proc/%s/stat", pid);
    FILE *statm_file = fopen(statm_file_path, "r");
    if(statm_file){
        char line[MAX_STAT_LENGTH];
        if(fgets(line, sizeof(line), statm_file)){
            char *token = strtok(line, " ");
            int count = 0;
            while(token){
                count++;
                if(count == 3){
                    info.ppid = atoi(token);
                }
                token = strtok(NULL, " ");
            }
        }
        fclose(statm_file);
    }

    // Get process priority
    char prio_file_path[256];
    sprintf(prio_file_path, "/proc/%s/stat", pid);
    FILE *prio_file = fopen(prio_file_path, "r");
    if(prio_file){
        char line[MAX_STAT_LENGTH];
        if(fgets(line, sizeof(line), prio_file)){
            char *token = strtok(line, " ");
            int count = 0;
            while(token){
                count++;
                if(count == 18){
                    info.priority = atoi(token);
                }
                token = strtok(NULL, " ");
            }
        }
        fclose(prio_file);
    }

    return info;
}

int main(){
    // Get directory listing of /proc
    DIR *dir = opendir("/proc");
    if(!dir){
        printf("Could not open /proc directory\n");
        exit(1);
    }

    // Read each directory entry as a process id
    struct dirent *entry;
    while((entry = readdir(dir))){
        if(isNumeric(entry->d_name)){
            ProcessInfo info = getProcessInfo(entry->d_name);
            printf("PID: %s, Name: %s, State: %c, PPID: %d, Priority: %d\n",
                info.pid, info.name, info.state, info.ppid, info.priority);
        }
    }

    closedir(dir);
    return 0;
}