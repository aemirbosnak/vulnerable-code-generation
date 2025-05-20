//FormAI DATASET v1.0 Category: System process viewer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

void process_info(char* pid);

int main() {
    
    DIR* d;
    struct dirent* dir;
    char* path = "/proc/";
    
    d = opendir(path);
    if (d == NULL) {
        perror("Couldn't open the directory");
        exit(1);
    }

    printf("%-10s%-20s%-20s%-20s\n", "PID", "Name", "Status", "Memory");
    printf("--------------------------------------------------\n");
    
    while ((dir = readdir(d)) != NULL) {
        if (isdigit(*dir->d_name)) {
            process_info(dir->d_name);
        }
    }
    
    closedir(d);
    return 0;
}

void process_info(char* pid) {
    char filename[50], name[50], status[50], mem[50];
    FILE* fp;
    
    sprintf(filename, "/proc/%s/status", pid);
    fp = fopen(filename, "r");
    
    if (fp == NULL) {
        return;
    }
    
    while (fscanf(fp, "%s", name) != EOF) {
        if (strcmp(name, "Name:") == 0) {
            fscanf(fp, "%s", name);
        }
        if (strcmp(name, "State:") == 0) {
            fscanf(fp, "%s", status);
        }
        if (strcmp(name, "VmRSS:") == 0) {
            fscanf(fp, "%s", mem);
        }
    }
    
    fclose(fp);
    
    printf("%-10s%-20s%-20s%-20s\n", pid, name, status, mem);
}