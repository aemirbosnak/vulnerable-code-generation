//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <dirent.h>
#include <errno.h>

#define PROC_FS_PATH "/proc/"

// function to list all running processes
void list_processes() {
    printf("All running processes:\n");
    DIR *dir_ptr;
    struct dirent *entry;
    dir_ptr = opendir(PROC_FS_PATH);
    while ((entry = readdir(dir_ptr))!= NULL) {
        if (entry->d_type == DT_DIR) {
            printf("%s\n", entry->d_name);
        }
    }
    closedir(dir_ptr);
}

// function to terminate a specific process
void terminate_process(pid_t pid) {
    if (kill(pid, SIGTERM) == 0) {
        printf("Process %d terminated\n", pid);
    } else {
        printf("Unable to terminate process %d\n", pid);
    }
}

// function to get the process ID of a running process
pid_t get_process_id(const char *process_name) {
    pid_t pid;
    DIR *dir_ptr;
    struct dirent *entry;
    dir_ptr = opendir(PROC_FS_PATH);
    while ((entry = readdir(dir_ptr))!= NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, process_name) == 0) {
                pid = atoi(entry->d_name);
                break;
            }
        }
    }
    closedir(dir_ptr);
    return pid;
}

// function to get the name of a running process
const char *get_process_name(pid_t pid) {
    DIR *dir_ptr;
    struct dirent *entry;
    dir_ptr = opendir(PROC_FS_PATH);
    while ((entry = readdir(dir_ptr))!= NULL) {
        if (entry->d_type == DT_DIR) {
            if (atoi(entry->d_name) == pid) {
                return entry->d_name;
            }
        }
    }
    closedir(dir_ptr);
    return NULL;
}

// function to get the CPU usage of a running process
int get_process_cpu_usage(pid_t pid) {
    FILE *fp;
    char buf[100];
    int i = 0;
    int ret = 0;
    if ((fp = fopen("/proc/stat", "r")) == NULL) {
        perror("Unable to open /proc/stat");
        return -1;
    }
    while (fgets(buf, sizeof(buf), fp)!= NULL) {
        if (strstr(buf, "cpu ")!= NULL) {
            sscanf(buf, "cpu %d %d %d %d", &i, &i, &i, &i);
            if (i == pid) {
                sscanf(buf, "%d %d %d %d", &i, &i, &i, &i);
                ret = i;
                break;
            }
        }
    }
    fclose(fp);
    return ret;
}

// function to get the memory usage of a running process
int get_process_memory_usage(pid_t pid) {
    FILE *fp;
    char buf[100];
    int i = 0;
    int ret = 0;
    if ((fp = fopen("/proc/meminfo", "r")) == NULL) {
        perror("Unable to open /proc/meminfo");
        return -1;
    }
    while (fgets(buf, sizeof(buf), fp)!= NULL) {
        if (strstr(buf, "MemTotal:")!= NULL) {
            sscanf(buf, "MemTotal: %d kB", &i);
            ret += i;
        }
    }
    fclose(fp);
    return ret;
}

// function to get the disk usage of a running process
int get_process_disk_usage(pid_t pid) {
    FILE *fp;
    char buf[100];
    int i = 0;
    int ret = 0;
    if ((fp = fopen("/proc/diskstats", "r")) == NULL) {
        perror("Unable to open /proc/diskstats");
        return -1;
    }
    while (fgets(buf, sizeof(buf), fp)!= NULL) {
        if (strstr(buf, "r/s")!= NULL) {
            sscanf(buf, "%d %d", &i, &i);
            if (i == pid) {
                sscanf(buf, "%d %d", &i, &i);
                ret += i;
            }
        }
    }
    fclose(fp);
    return ret;
}

int main() {
    pid_t pid;
    int choice;
    do {
        printf("\nMenu:\n1. List all running processes\n2. Terminate a specific process\n3. Get the process ID of a running process\n4. Get the name of a running process\n5. Get the CPU usage of a running process\n6. Get the memory usage of a running process\n7. Get the disk usage of a running process\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                list_processes();
                break;
            case 2:
                printf("Enter the PID of the process you want to terminate: ");
                scanf("%d", &pid);
                terminate_process(pid);
                break;
            case 3:
                printf("Enter the name of the process you want to get the ID of: ");
                scanf("%s", &pid);
                pid = get_process_id(pid);
                printf("The process ID is %d\n", pid);
                break;
            case 4:
                pid = get_process_id(pid);
                printf("The process name is %s\n", get_process_name(pid));
                break;
            case 5:
                pid = get_process_id(pid);
                printf("The CPU usage is %d\n", get_process_cpu_usage(pid));
                break;
            case 6:
                pid = get_process_id(pid);
                printf("The memory usage is %d\n", get_process_memory_usage(pid));
                break;
            case 7:
                pid = get_process_id(pid);
                printf("The disk usage is %d\n", get_process_disk_usage(pid));
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice, please try again\n");
        }
    } while (choice!= 8);
    return 0;
}