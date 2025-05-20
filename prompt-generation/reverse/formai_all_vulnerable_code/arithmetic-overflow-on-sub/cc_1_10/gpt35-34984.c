//FormAI DATASET v1.0 Category: System process viewer ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROC 32768 //maximum pid assumed
#define MAX_PATH 1024 //maximum path length assumed

char* get_pid_cmdline(const char* pid_str) {
    char* cmdline_path = malloc(MAX_PATH*sizeof(char));
    sprintf(cmdline_path, "/proc/%s/cmdline", pid_str);
    FILE* cmdline_file = fopen(cmdline_path, "r");
    if (cmdline_file == NULL) {
        perror("Error opening cmdline file");
        return NULL;
    }
    char* cmdline = malloc(MAX_PATH*sizeof(char));
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&cmdline, &len, cmdline_file)) != -1) {
        cmdline[read-1] = ' '; //replace terminating null char with a space
    }
    fclose(cmdline_file);
    cmdline[strlen(cmdline)-1] = '\0'; //remove the space at the end
    return cmdline;
}

int main() {
    DIR* proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Error opening proc directory");
        return -1;
    }
    
    struct dirent* dp;
    while ((dp = readdir(proc_dir)) != NULL) {
        if (isdigit(dp->d_name[0])) { //filter out non-pid directories
            char* cmdline = get_pid_cmdline(dp->d_name);
            if (cmdline == NULL) {
                continue;
            }
            printf("%s:\t%s\n", dp->d_name, cmdline);
            free(cmdline);
        }
    }
    
    closedir(proc_dir);
    return 0;
}