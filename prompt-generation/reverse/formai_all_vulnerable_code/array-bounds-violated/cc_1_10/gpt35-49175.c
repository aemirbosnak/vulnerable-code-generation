//FormAI DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PID 32768
#define MAX_PATH 512

/*
 * Function declarations
 */

int is_number(const char* str);
int is_process(const char* pname, int pid);
void process_info(const char* pname, int pid);

/*
 * Main program
 */

int main(int argc, char* argv[])
{
    int pid;
    char pname[MAX_PATH];
    DIR* dirp;
    struct dirent* direntp;

    if (argc > 2)
    {
        fprintf(stderr, "Usage: %s [pid]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (argc == 2)
    {
        if (!is_number(argv[1]))
        {
            fprintf(stderr, "Invalid pid: %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        pid = atoi(argv[1]);
        snprintf(pname, MAX_PATH, "/proc/%d/exe", pid);
        if (!is_process(pname, pid))
        {
            fprintf(stderr, "Process not found: %d\n", pid);
            exit(EXIT_FAILURE);
        }
        process_info(pname, pid);
    }

    if (argc == 1)
    {
        printf("%5s %20s %9s %10s %6s %6s %6s %s\n", "PID", "COMMAND", "STATE", "PPID", "RSS", "VSZ", "%CPU", "%MEM");

        dirp = opendir("/proc");
        if (dirp == NULL)
        {
            perror("opendir");
            exit(EXIT_FAILURE);
        }

        while ((direntp = readdir(dirp)) != NULL)
        {
            if (is_number(direntp->d_name))
            {
                pid = atoi(direntp->d_name);
                snprintf(pname, MAX_PATH, "/proc/%d/exe", pid);
                if (is_process(pname, pid))
                {
                    process_info(pname, pid);
                }
            }
        }

        if (closedir(dirp) == -1)
        {
            perror("closedir");
            exit(EXIT_FAILURE);
        }
    }

    return EXIT_SUCCESS;
}

/*
 * Check if a string is a number
 */
int is_number(const char* str)
{
    while (*str)
    {
        if (!isdigit(*str))
        {
            return 0;
        }
        ++str;
    }
    return 1;
}

/*
 * Check if a process exists
 */
int is_process(const char* pname, int pid)
{
    char buf[MAX_PATH];
    int len;
    len = readlink(pname, buf, sizeof(buf)-1);
    if (len == -1)
    {
        return 0;
    }
    buf[len] = '\0';
    return (strstr(buf, "/bin/") != NULL || strstr(buf, "/sbin/") != NULL || strstr(buf, "/usr/bin/") != NULL || strstr(buf, "/usr/sbin/") != NULL || strstr(buf, "/usr/local/bin/") != NULL || strstr(buf, "/usr/local/sbin/") != NULL);
}

/*
 * Print process information
 */
void process_info(const char* pname, int pid)
{
    char buf[MAX_PATH];
    char state;
    int ppid;
    int rss;
    int vsz;
    float cpu;
    float mem;
    int ret;
    FILE* fp;

    ret = snprintf(buf, MAX_PATH, "/proc/%d/stat", pid);
    if (ret == -1)
    {
        perror("snprintf");
        exit(EXIT_FAILURE);
    }

    fp = fopen(buf, "r");
    if (fp == NULL)
    {
        return;
    }

    ret = fscanf(fp, "%d %s %c %d %*d %*d %*d %*d %*d %*d %*d %*d %*d %d %d", &pid, buf, &state, &ppid, &rss, &vsz);
    if (ret == -1)
    {
        perror("fscanf");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    ret = snprintf(buf, MAX_PATH, "/proc/%d/statm", pid);
    if (ret == -1)
    {
        perror("snprintf");
        exit(EXIT_FAILURE);
    }

    fp = fopen(buf, "r");
    if (fp == NULL)
    {
        return;
    }

    ret = fscanf(fp, "%d %d", &rss, &vsz);
    if (ret == -1)
    {
        perror("fscanf");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    ret = snprintf(buf, MAX_PATH, "/proc/%d/stat", pid);
    if (ret == -1)
    {
        perror("snprintf");
        exit(EXIT_FAILURE);
    }

    fp = fopen(buf, "r");
    if (fp == NULL)
    {
        return;
    }

    ret = fscanf(fp, "%*d %*s %*s %*d %*d %*d %*d %*d %*u %*u %*u %*u %f %f", &cpu, &mem);
    if (ret == -1)
    {
        perror("fscanf");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    printf("%5d %20s %9c %10d %6d %6d %6.2f %6.2lf\n", pid, buf, state, ppid, rss, vsz, cpu, mem);
}