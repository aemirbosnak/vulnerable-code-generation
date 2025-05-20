//FormAI DATASET v1.0 Category: System process viewer ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>

int main()
{
    DIR *d;
    struct dirent *dir;
    char taskPath[50], statusPath[50];
    char taskName[20];
    int pid;

    // Open /proc directory
    d = opendir("/proc");
    if (d == NULL)
    {
        printf("Error: Could not open /proc directory");
        return 1;
    }

    printf("%10s %10s %10s %10s %10s\n", "PID", "PPID", "STATE", "UTIME", "STIME");

    // Loop through each process directory
    while ((dir = readdir(d)) != NULL)
    {
        // Check if directory name only contains digits (i.e., is a process directory)
        if (isdigit(dir->d_name[0]))
        {
            pid = atoi(dir->d_name);

            // Get process name
            sprintf(taskPath, "/proc/%d/comm", pid);
            FILE *fp = fopen(taskPath, "r");
            if (fp == NULL)
            {
                printf("Error: Could not open %s", taskPath);
                return 1;
            }
            fgets(taskName, 20, fp);
            strtok(taskName, "\n");

            // Get process status
            sprintf(statusPath, "/proc/%d/status", pid);
            fp = fopen(statusPath, "r");
            if (fp == NULL)
            {
                printf("Error: Could not open %s", statusPath);
                return 1;
            }
            char line[100];
            char state[10];
            char ppid[10];
            int utime, stime;
            while (fgets(line, 100, fp) != NULL)
            {
                if (sscanf(line, "State:%s", state) == 1)
                {
                    continue;
                }
                else if (sscanf(line, "PPid:%s", ppid) == 1)
                {
                    continue;
                }
                else if (sscanf(line, "utime:%d", &utime) == 1)
                {
                    continue;
                }
                else if (sscanf(line, "stime:%d", &stime) == 1)
                {
                    continue;
                }
            }
            fclose(fp);

            // Print process information
            printf("%10d %10s %10s %10d %10d\n", pid, ppid, state, utime, stime);
        }
    }

    closedir(d);
    return 0;
}