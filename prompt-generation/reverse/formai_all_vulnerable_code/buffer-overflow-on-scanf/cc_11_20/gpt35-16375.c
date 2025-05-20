//FormAI DATASET v1.0 Category: System process viewer ; Style: Cyberpunk
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int main()
{
    DIR *d;
    struct dirent *dir;
    char path[128];
    char cmd[256];
    int pid;

    printf("Welcome to the Cyberpunk Process Viewer!\n\n");
    printf("Enter PID to view detailed information or type 'list' to display all running processes: ");
    scanf("%s", path);

    if (strcmp(path, "list") == 0)
    {
        printf("Current running processes: \n\n");
        
        d = opendir("/proc");
        if (d)
        {
            while ((dir = readdir(d)) != NULL)
            {
                if (dir->d_type == DT_DIR)
                {
                    pid = atoi(dir->d_name);
                    if (pid > 0)
                    {
                        printf("PID: %d\n", pid);

                        sprintf(cmd, "cat /proc/%d/cmdline", pid);
                        FILE *file = popen(cmd, "r");

                        if (file)
                        {
                            fgets(path, sizeof(path), file);
                            printf("Command: %s\n", path);
                            pclose(file);
                        }

                        printf("\n");
                    }
                }
            }
            closedir(d);
        }
    }
    else
    {
        pid = atoi(path);

        sprintf(path, "/proc/%d/status", pid);
        FILE *file = fopen(path, "r");

        if (file)
        {
            while (fgets(path, sizeof(path), file))
            {
                if (strncmp(path, "Name:", 5) == 0)
                {
                    printf("Process Name: %s", path+6);
                }
                else if (strncmp(path, "State:", 6) == 0)
                {
                    printf("Process State: %s", path+7);
                }
                else if (strncmp(path, "VmSize:", 7) == 0)
                {
                    printf("Process Memory Usage: %s", path+8);
                    printf("\n");
                }
            }
            fclose(file);
        }
        else
        {
            printf("Invalid PID entered!");
        }
    }

    return 0;
}