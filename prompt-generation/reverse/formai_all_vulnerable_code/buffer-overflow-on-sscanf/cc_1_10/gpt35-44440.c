//FormAI DATASET v1.0 Category: System process viewer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 512

// Function to check if the process folder is valid
int check_process(const char *pid) {
    char buffer[BUF_SIZE];
    struct stat sb;
    snprintf(buffer, BUF_SIZE, "/proc/%s", pid);
    if (stat(buffer, &sb) == 0 && S_ISDIR(sb.st_mode)) {
        return 1;
    }
    return 0;
}

// Function to get process name by process identifier
void get_process_name(const char *pid, char *pname) {
    char buffer[BUF_SIZE], procname[BUF_SIZE];
    FILE *fp;
    snprintf(buffer, BUF_SIZE, "/proc/%s/status", pid);
    if ((fp = fopen(buffer, "r"))) {
        while (fgets(buffer, BUF_SIZE - 1, fp)) {
            sscanf(buffer, "Name:\t%s\n", &procname);
        }
        fclose(fp);
    }
    strcpy(pname, procname);
}

// Function to get process status by process identifier
void get_process_status(const char *pid, char *pstatus) {
    char buffer[BUF_SIZE], procstatus[BUF_SIZE];
    FILE *fp;
    snprintf(buffer, BUF_SIZE, "/proc/%s/status", pid);
    if ((fp = fopen(buffer, "r"))) {
        while (fgets(buffer, BUF_SIZE - 1, fp)) {
            sscanf(buffer, "State:\t%s\n", &procstatus);
        }
        fclose(fp);
    }
    strcpy(pstatus, procstatus);
}

// Function to get process memory usage by process identifier
void get_process_memory(const char *pid, char *pmem) {
    char buffer[BUF_SIZE], procmem[BUF_SIZE];
    FILE *fp;
    snprintf(buffer, BUF_SIZE, "/proc/%s/status", pid);
    if ((fp = fopen(buffer, "r"))) {
        while (fgets(buffer, BUF_SIZE - 1, fp)) {
            sscanf(buffer, "VmSize:\t%s\n", &procmem);
        }
        fclose(fp);
    }
    strcpy(pmem, procmem);
}

// Function to get process command line by process identifier
void get_process_cmdline(const char *pid, char *pcmdline) {
    char buffer[BUF_SIZE];
    FILE *fp;
    snprintf(buffer, BUF_SIZE, "/proc/%s/cmdline", pid);
    if ((fp = fopen(buffer, "r"))) {
        fgets(buffer, BUF_SIZE - 1, fp);
        fclose(fp);
    }
    // Remove null terminators from cmdline and replace with spaces
    for (int i = 0; i < BUF_SIZE; i++) {
        if (buffer[i] == '\0') {
            buffer[i] = ' ';
        }
    }
    strcpy(pcmdline, buffer);
}

// Main function to iterate through processes and print out information
int main() {
    DIR *dirp;
    struct dirent *entry;
    char pid[BUF_SIZE], pname[BUF_SIZE], pstatus[BUF_SIZE], pmem[BUF_SIZE], pcmdline[BUF_SIZE];

    printf("%-10s %-25s %-25s %-10s %-50s\n", "PID", "Process Name", "Status", "Memory", "Command Line");
    dirp = opendir("/proc/");
    if (dirp != NULL) {
        while ((entry = readdir(dirp))) {
            if (isdigit(entry->d_name[0])) {
                strcpy(pid, entry->d_name);
                if (check_process(pid)) {
                    get_process_name(pid, pname);
                    get_process_status(pid, pstatus);
                    get_process_memory(pid, pmem);
                    get_process_cmdline(pid, pcmdline);
                    printf("%-10s %-25s %-25s %-10s %-50s\n", pid, pname, pstatus, pmem, pcmdline);
                }
            }
        }
        closedir(dirp);
    }

    return 0;
}