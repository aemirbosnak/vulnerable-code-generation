//FormAI DATASET v1.0 Category: System process viewer ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define PROC_PATH "/proc"

typedef struct{
    char name[100];
    int pid;
    long unsigned int vm_size;
    long unsigned int vm_rss;
}Process;

int is_number(char *str){
    size_t len = strlen(str);
    for(int i=0; i<len; i++){
        if(!isdigit(str[i])) return 0;
    }
    return 1;
}

void print_header(){
    printf("%-30s  %-10s  %-20s %-20s\n", "PROCESS NAME", "PID", "VIRTUAL MEMORY SIZE", "RESIDENT SET SIZE");
}

void print_process(Process p){
    printf("%-30s  %-10d  %-20lu %-20lu\n", p.name, p.pid, p.vm_size, p.vm_rss);
}

void print_err(char *msg){
    fprintf(stderr, "%s", msg);
}

void get_process_info(char *pid_str, Process *process){
    char stat_file_path[100], cmd_file_path[100], status_file_path[100];
    FILE *stat_file, *cmd_file, *status_file;
    sprintf(stat_file_path, "%s/%s/stat", PROC_PATH, pid_str);

    stat_file = fopen(stat_file_path, "r");
    if(!stat_file){
        print_err("Error: Could not read stat file\n");
        return;
    }

    if(fscanf(stat_file, "%d %s ", &(process->pid), process->name) < 2){
        print_err("Error: Could not parse stat file\n");
        fclose(stat_file);
        return;
    }
    fclose(stat_file);

    sprintf(cmd_file_path, "%s/%s/cmdline", PROC_PATH, pid_str);

    cmd_file = fopen(cmd_file_path, "r");
    if(!cmd_file){
        print_err("Error: Could not read cmdline file\n");
        return;
    }
    if(fscanf(cmd_file, "%s", process->name) < 1){
        print_err("Error: Could not parse cmdline file\n");
        fclose(cmd_file);
        return;
    }
    fclose(cmd_file);

    sprintf(status_file_path, "%s/%s/status", PROC_PATH, pid_str);
    status_file = fopen(status_file_path, "r");
    if(!status_file) return;

    char line[100], key[100], value[100];

    while(fgets(line, sizeof(line), status_file) != NULL){
        sscanf(line, "%s %s", key, value);
        if(strcmp(key, "VmSize:") == 0) process->vm_size = atoi(value);
        if(strcmp(key, "VmRSS:") == 0) process->vm_rss = atoi(value);
    }

    fclose(status_file);
}

void list_processes(){
    DIR *dir;
    struct dirent *entry;
    char *name;
    Process process;
    char pid_str[10];
    dir = opendir(PROC_PATH);

    if (!dir) {
        print_err("Error: Could not open /proc\n");
        return;
    }

    print_header();
    while((entry = readdir(dir)) != NULL){
        name = entry->d_name;
        if(is_number(name)){
            strcpy(pid_str, name);
            get_process_info(pid_str, &process);
            if(process.pid != 0){
                print_process(process);
            }
        }
    }
    closedir(dir);
}

int main(){
    list_processes();
    return 0;
}