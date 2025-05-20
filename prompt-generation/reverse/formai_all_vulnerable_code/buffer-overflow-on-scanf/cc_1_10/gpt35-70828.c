//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd, len, pid, i = 0;
    char str[512], cpu_str[128], prev_cpu_str[128], command[128];
    float cpu = 0.0, prev_cpu = 0.0;
    FILE *fp;

    printf("Enter the process ID: ");
    scanf("%d", &pid);

    sprintf(command, "ps -p %d -o %%cpu", pid);
    fp = popen(command, "r");

    if (fp == NULL)
    {
        printf("Failed to execute command\n");
        exit(1);
    }

    fgets(prev_cpu_str, sizeof(prev_cpu_str), fp);
    prev_cpu = atof(prev_cpu_str);

    while (i < 10)
    {
        sprintf(cpu_str, "/proc/%d/stat", pid);
        fd = open(cpu_str, O_RDONLY);

        if (fd == -1)
        {
            printf("Failed to open stat file\n");
            exit(1);
        }

        len = read(fd, str, sizeof(str));

        if (len == -1)
        {
            printf("Failed to read stat file\n");
            exit(1);
        }

        close(fd);

        strtok(str, " ");
        strtok(NULL, " ");
        strtok(NULL, " ");
        strtok(NULL, " ");
        strtok(NULL, " ");
        strtok(NULL, " ");
        strtok(NULL, " ");
        strtok(NULL, " ");
        strtok(NULL, " ");
        strtok(NULL, " ");
        strtok(NULL, " ");
        strtok(NULL, " ");
        strtok(NULL, " ");
        strtok(NULL, " ");

        cpu = atof(strtok(NULL, " ")) / sysconf(_SC_CLK_TCK);

        if (cpu - prev_cpu <= 0.0)
        {
            printf("Process is idle\n");
        }
        else
        {
            printf("Process is using %.2f%% of CPU\n", (cpu - prev_cpu) * 100);
        }

        prev_cpu = cpu;
        sleep(1);
        i++;
    }

    pclose(fp);

    return 0;
}