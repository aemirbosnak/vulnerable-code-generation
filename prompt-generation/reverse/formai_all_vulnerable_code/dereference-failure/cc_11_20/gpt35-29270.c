//FormAI DATASET v1.0 Category: System process viewer ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>

#define MAX_PATH 1024

int main(int argc, char *argv[]) 
{
    DIR *dir;
    struct dirent *ent;
    char path[MAX_PATH];
    int pid, fd, i;
    char buf[1024];
    char state;
    char process_name[MAX_PATH];
    char exec_path[MAX_PATH];
    char cmdline_path[MAX_PATH];

    printf("Oh, wilt thou leave me so unsatisfied?\n");
    printf("A tool to view processes is what I seek,\n");
    printf("Forsooth, I shall write this program without a leak.\n");

    if(argc == 1) 
    {
        printf("Usage: %s <PID>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid = atoi(argv[1]);

    snprintf(path, MAX_PATH, "/proc/%d/stat", pid);
    fd = open(path, O_RDONLY);
    if(fd == -1) 
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    i = 0;
    while(read(fd, &buf[i], 1) == 1 && buf[i] != ')')
    {
        if(buf[i] == '(') 
        {
            i++;
            while(read(fd, &buf[i], 1) == 1 && buf[i] != ')')
            {
                i++;
            }
            process_name[i] = '\0';
            break;
        }
        i++;
    }
    buf[i+1] = '\0';
    sscanf(&buf[i+2], "%c", &state);

    snprintf(exec_path, MAX_PATH, "/proc/%d/exe", pid);
    if(readlink(exec_path, path, MAX_PATH) == -1) 
    {
        perror("readlink");
        exit(EXIT_FAILURE);
    }
    path[MAX_PATH-1] = '\0';

    snprintf(cmdline_path, MAX_PATH, "/proc/%d/cmdline", pid);
    fd = open(cmdline_path, O_RDONLY);
    if(fd == -1) 
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    i = 0;
    while(read(fd, &buf[i], 1) == 1) 
    {
        if(!buf[i])
        {
            buf[i] = ' ';
        }
        i++;
    }
    buf[i] = '\0';
    close(fd);

    printf("Process Name: %s\n", process_name);
    printf("PID: %d\n", pid);
    printf("State: %c\n", state);
    printf("Executable Path: %s\n", path);
    printf("Command Line: %s\n", buf);

    printf("O, swear not by the moon, the inconstant moon\n");
    printf("But instead, tell me the devices running soon\n");

    dir = opendir("/proc");
    if (dir != NULL) 
    {
        while ((ent = readdir(dir)) != NULL) 
        {
            if (isdigit(*ent->d_name)) 
            {
                int ppid, n;
                snprintf(path, MAX_PATH, "/proc/%s/stat", ent->d_name);
                fd = open(path, O_RDONLY);
                if(fd == -1) 
                {
                    perror("open");
                    exit(EXIT_FAILURE);
                }

                if((n = read(fd, buf, sizeof(buf)-1)) > 0)
                {
                    buf[n] = '\0';
                    sscanf(buf, "%d %s %c %d", &ppid, process_name, &state, &n);
                    if(ppid == pid)
                    {
                        printf("Process ID: %5s ", ent->d_name);
                        printf("Process Name: %s ", process_name);
                        printf("State: %c ", state);
                        printf("\n");
                    }
                }
                close(fd);
            }
        }
        closedir(dir);
    } 
    else 
    {
        perror("");
        return 0;
    }

    return 0;
}