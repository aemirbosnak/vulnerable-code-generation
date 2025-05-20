//FormAI DATASET v1.0 Category: System process viewer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_BUF_LENGTH 1024

/* Define the process status struct */
typedef struct {
    pid_t pid;
    long rss;
    char status;
    char name[MAX_BUF_LENGTH];
} proc_status;

/* Get the process name from /proc/pid/status file */
void get_proc_name(char *proc_dir, proc_status *p) {
    FILE *fp;
    char filepath[MAX_PATH_LENGTH];

    snprintf(filepath, MAX_PATH_LENGTH, "%s/%s", proc_dir, "status");
    fp = fopen(filepath, "r");

    if(fp == NULL) {
        perror("Error opening process status file:");
        exit(1);
    }

    char line[MAX_BUF_LENGTH];
    char name[MAX_BUF_LENGTH];

    while(fgets(line, MAX_BUF_LENGTH, fp) != NULL) {
        if(strncmp(line, "Name:\t", 6) == 0) {
            strncpy(name, line + 6, MAX_BUF_LENGTH);
            name[strlen(name) - 1] = '\0';
            break;
        }
    }

    strcpy(p->name, name);
    fclose(fp);
    return;
}

/* Get the process rss from /proc/pid/smaps file */
void get_proc_rss(char *proc_dir, proc_status *p) {
    FILE *fp;
    char filepath[MAX_PATH_LENGTH];

    snprintf(filepath, MAX_PATH_LENGTH, "%s/%s", proc_dir, "smaps");
    fp = fopen(filepath, "r");

    if(fp == NULL) {
        perror("Error opening smaps file:");
        exit(1);
    }

    char line[MAX_BUF_LENGTH];

    while(fgets(line, MAX_BUF_LENGTH, fp) != NULL) {
        if(strncmp(line, "Rss:", 4) == 0) {
            char *tok = strtok(line + 4, " ");
            p->rss += strtol(tok, NULL, 10);
        }
    }

    fclose(fp);
    return;
}

/* Get the process status character from /proc/pid/status file */
void get_proc_status(char *proc_dir, proc_status *p) {
    FILE *fp;
    char filepath[MAX_PATH_LENGTH];

    snprintf(filepath, MAX_PATH_LENGTH, "%s/%s", proc_dir, "status");
    fp = fopen(filepath, "r");

    if(fp == NULL) {
        perror("Error opening process status file:");
        exit(1);
    }

    char line[MAX_BUF_LENGTH];

    while(fgets(line, MAX_BUF_LENGTH, fp) != NULL) {
        if(strncmp(line, "State:\t", 7) == 0) {
            char *tok = strtok(line + 7, "\t");
            p->status = toupper(tok[0]);
            break;
        }
    }

    fclose(fp);
    return;
}

/* Get the list of pids from /proc directory */
int get_pid_list(proc_status **procs) {
    DIR *dir;
    struct dirent *entry;
    int num_procs = 0;
    char proc_dir[MAX_PATH_LENGTH];
    proc_status *p;

    dir = opendir("/proc");

    if(dir == NULL) {
        perror("Error opening proc directory:");
        exit(1);
    }

    while((entry = readdir(dir)) != NULL) {
        if(isdigit(entry->d_name[0])) {
            num_procs++;
        }
    }

    closedir(dir);

    *procs = (proc_status*) malloc(sizeof(proc_status) * num_procs);

    if(*procs == NULL) {
        perror("Error allocating memory:");
        exit(1);
    }

    dir = opendir("/proc");

    if(dir == NULL) {
        perror("Error opening proc directory:");
        exit(1);
    }

    while((entry = readdir(dir)) != NULL) {
        if(isdigit(entry->d_name[0])) {
            p = *procs;
            snprintf(proc_dir, MAX_PATH_LENGTH, "/proc/%s", entry->d_name);
            p->pid = strtol(entry->d_name, NULL, 10);
            get_proc_name(proc_dir, p);
            get_proc_rss(proc_dir, p);
            get_proc_status(proc_dir, p);
            p++;
        }
    }

    closedir(dir);

    return num_procs;
}

/* Print the process information */
void print_procs(proc_status *procs, int num_procs) {
    printf("%-6s %-20s %-10s\n", "PID", "NAME", "RSS(kB)");
    for(int i = 0; i < num_procs; i++) {
        printf("%-6d %-20s %-10ld %c\n", procs[i].pid, procs[i].name, procs[i].rss, procs[i].status);
    }
}

int main() {
    proc_status *procs;
    int num_procs = get_pid_list(&procs);
    print_procs(procs, num_procs);
    free(procs);
    return 0;
}