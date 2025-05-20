//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

typedef struct ProcInfo
{
    pid_t pid;
    char *name;
    time_t start_time;
} ProcInfo;

int compare(const void *a, const void *b)
{
    ProcInfo *proc1 = (ProcInfo *)a;
    ProcInfo *proc2 = (ProcInfo *)b;
    return proc1->start_time > proc2->start_time ? -1 : 1;
}

int main()
{
    DIR *dir = opendir("/proc");
    if (dir == NULL)
    {
        perror("opendir");
        return EXIT_FAILURE;
    }

    int num_procs = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (isdigit(entry->d_name[0]))
        {
            num_procs++;
        }
    }
    closedir(dir);

    ProcInfo *procs = malloc(num_procs * sizeof(ProcInfo));
    if (procs == NULL)
    {
        perror("malloc");
        return EXIT_FAILURE;
    }

    dir = opendir("/proc");
    if (dir == NULL)
    {
        perror("opendir");
        return EXIT_FAILURE;
    }

    int proc_index = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        if (isdigit(entry->d_name[0]))
        {
            ProcInfo proc;
            proc.pid = atoi(entry->d_name);
            char path[256];
            snprintf(path, sizeof(path), "/proc/%s/comm", entry->d_name);
            FILE *file = fopen(path, "r");
            if (file == NULL)
            {
                perror("fopen");
                continue;
            }
            char buf[256];
            if (fgets(buf, sizeof(buf), file) == NULL)
            {
                perror("fgets");
                fclose(file);
                continue;
            }
            fclose(file);
            buf[strlen(buf) - 1] = '\0';
            proc.name = strdup(buf);
            snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
            file = fopen(path, "r");
            if (file == NULL)
            {
                perror("fopen");
                continue;
            }
            char line[1024];
            if (fgets(line, sizeof(line), file) == NULL)
            {
                perror("fgets");
                fclose(file);
                continue;
            }
            fclose(file);
            char *tok = strtok(line, " ");
            for (int i = 0; i < 21; i++)
            {
                tok = strtok(NULL, " ");
            }
            proc.start_time = atol(tok) / sysconf(_SC_CLK_TCK);
            procs[proc_index++] = proc;
        }
    }
    closedir(dir);

    qsort(procs, num_procs, sizeof(ProcInfo), compare);

    printf("PID    Name                 Start Time\n");
    printf("------ --------------------- -----------\n");
    for (int i = 0; i < num_procs; i++)
    {
        char time_str[256];
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&procs[i].start_time));
        printf("%-6d %-20s %s\n", procs[i].pid, procs[i].name, time_str);
        free(procs[i].name);
    }
    free(procs);

    return EXIT_SUCCESS;
}