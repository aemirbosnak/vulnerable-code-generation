//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROC_NAME_LEN 20
#define MAX_PROC_PATH_LEN 50

char* get_process_name_by_pid(int pid);
unsigned long get_process_ram_usage_by_pid(int pid);

int main()
{
    int pid;
    printf("Enter process ID to monitor: ");
    scanf("%d", &pid);
    
    // Get process name
    char* process_name = get_process_name_by_pid(pid);
    if (process_name == NULL){
        printf("Could not retrieve process name for PID %d\n", pid);
        return 1;
    }
    
    // Monitor RAM usage
    int max_ram_usage = 0;
    int current_ram_usage;
    
    printf("Monitoring RAM usage for process %s with PID %d...\n", process_name, pid);
    printf("Press Ctrl+C to exit.\n");
    
    while(1){
        current_ram_usage = get_process_ram_usage_by_pid(pid);
        if (current_ram_usage == -1){
            printf("Could not retrieve RAM usage for process %s with PID %d\n", process_name, pid);
            return 1;
        }
        
        if (current_ram_usage > max_ram_usage){
            max_ram_usage = current_ram_usage;
        }
        
        printf("Current RAM usage for process %s with PID %d: %lu KB\n", process_name, pid, current_ram_usage);
        printf("Max RAM usage for process %s with PID %d: %lu KB\n", process_name, pid, max_ram_usage);
        sleep(5);
    }
    
    free(process_name);
    return 0;
}

char* get_process_name_by_pid(int pid)
{
    char* proc_name = (char*)malloc(MAX_PROC_NAME_LEN * sizeof(char));
    char* proc_path = (char*)malloc(MAX_PROC_PATH_LEN * sizeof(char));
    snprintf(proc_path, MAX_PROC_PATH_LEN, "/proc/%d/status", pid);
    
    FILE* fp = fopen(proc_path, "r");
    if (fp == NULL){
        printf("Could not open file %s\n", proc_path);
        free(proc_name);
        free(proc_path);
        return NULL;
    }
    
    char line[128];
    char* name = NULL;
    while(fgets(line, 128, fp) != NULL){
        if (strncmp(line, "Name:", 5) == 0){
            name = strchr(line, '\t') + 1;
            name[strlen(name) - 1] = '\0';
            break;
        }
    }
    
    if (name == NULL){
        printf("Could not retrieve name for process with PID %d\n", pid);
        free(proc_name);
        free(proc_path);
        return NULL;
    }
    
    strncpy(proc_name, name, MAX_PROC_NAME_LEN);
    fclose(fp);
    free(proc_path);
    return proc_name;
}

unsigned long get_process_ram_usage_by_pid(int pid)
{
    char* proc_path = (char*)malloc(MAX_PROC_PATH_LEN * sizeof(char));
    snprintf(proc_path, MAX_PROC_PATH_LEN, "/proc/%d/status", pid);
    
    FILE* fp = fopen(proc_path, "r");
    if (fp == NULL){
        printf("Could not open file %s\n", proc_path);
        free(proc_path);
        return -1;
    }
    
    char line[128];
    char* vmrss = NULL;
    while(fgets(line, 128, fp) != NULL){
        if (strncmp(line, "VmRSS:", 6) == 0){
            vmrss = strchr(line, ':') + 2;
            break;
        }
    }
    
    if (vmrss == NULL){
        printf("Could not retrieve VmRSS for process with PID %d\n", pid);
        free(proc_path);
        return -1;
    }
    
    unsigned long ram_usage = strtol(vmrss, NULL, 10);
    fclose(fp);
    free(proc_path);
    return ram_usage;
}