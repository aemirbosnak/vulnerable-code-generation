//FormAI DATASET v1.0 Category: System process viewer ; Style: Dennis Ritchie
#include <stdio.h>      /* For standard I/O operations */
#include <dirent.h>     /* For directory operations */
#include <string.h>     /* For string operations */
#include <stdlib.h>     /* For dynamic memory allocation */

/* Struct to hold process information */
struct ProcessInfo {
    int pid;
    char name[20];
    char status;
    int parent_pid;
};

/* Function to parse information from /proc/[pid]/stat file */
void parse_proc_stat(FILE *file, struct ProcessInfo *p_info) {
    fscanf(file, "%d %s %c %d", &p_info->pid, p_info->name, &p_info->status, &p_info->parent_pid);
}

/* Function to get process information for a single process */
void get_process_info(const char *pid, struct ProcessInfo *p_info) {
    char filename[20];
    FILE *file;
    sprintf(filename, "/proc/%s/stat", pid);
    file = fopen(filename, "r");
    if (file) {
        parse_proc_stat(file, p_info);
        fclose(file);
    }
}

/* Function to get the list of processes */
int get_proc_list(struct ProcessInfo **proc_list) {
    DIR *dir;
    struct dirent *entry;
    char pid[10];
    int i = 0;
    dir = opendir("/proc");
    if (dir) {
        *proc_list = (struct ProcessInfo *) malloc(sizeof(struct ProcessInfo));
        while ((entry = readdir(dir)) != NULL) {
            /* Check if the entry is a directory and has a number for a name */
            if (entry->d_type == DT_DIR && strtol(entry->d_name, NULL, 10)) {
                get_process_info(entry->d_name, &((*proc_list)[i++]));
                *proc_list = (struct ProcessInfo *) realloc(*proc_list, sizeof(struct ProcessInfo) * (i+1));
            }
        }
        closedir(dir);
        /* Return the number of processes found */
        return i;
    } else {
        return -1;
    }
}

/* Function to display the process information */
void display_proc_info(struct ProcessInfo *proc_list, int num_procs) {
    printf("%-10s%-20s%-8s%s\n", "PID", "NAME", "STATUS", "PARENT_PID");
    for (int i = 0; i < num_procs; i++) {
        printf("%-10d%-20s%-8c%d\n", proc_list[i].pid, proc_list[i].name, proc_list[i].status, proc_list[i].parent_pid);
    }
}

int main() {
    struct ProcessInfo *proc_list;
    int num_procs;
    printf("Dennis Ritchie-style System Process Viewer\n");
    printf("------------------------------------------\n");
    num_procs = get_proc_list(&proc_list);
    if (num_procs < 0) {
        printf("Error getting process list!\n");
        return 1;
    }
    display_proc_info(proc_list, num_procs);
    free(proc_list);
    return 0;
}