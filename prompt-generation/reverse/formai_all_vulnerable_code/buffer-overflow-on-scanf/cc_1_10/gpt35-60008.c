//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/resource.h>
#include<sys/time.h>
#include<sys/types.h>
#include<signal.h>

void process_memory();
void process_cpu_time();

int main()
{
    pid_t pid;
    int option;
    printf("Enter the PID of the process: ");
    scanf("%d", &pid);
    printf("Press 1 to view CPU usage and 2 to view Memory Usage");

    while(1)
    {
      printf("\nEnter your option:");
      scanf("%d", &option);

      switch(option)
      {
          case 1:
            process_cpu_time(pid);
            break;
          
          case 2:
            process_memory(pid);
            break;

          default:
            printf("Invalid option!\n");
            break;
      }
    }
    return 0;
}

void process_cpu_time(pid_t pid)
{
    char file_name[40];
    char buf[100];
    int fd;
    sprintf(file_name, "/proc/%d/stat", pid);
    fd = open(file_name, O_RDONLY);

    while(1){
        sleep(1);
        lseek(fd, 0, SEEK_SET);
        read(fd, buf, sizeof(buf));
        close(fd);
        unsigned long utime, stime, cutime, cstime, starttime, uptime, total_time;
        sscanf(buf, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %lu %lu %lu %lu %*d %*d %*d %*d %*d %lu", &utime, &stime, &cutime, &cstime, &starttime);
        fd = open("/proc/uptime", O_RDONLY);
        read(fd, buf, sizeof(buf));
        sscanf(buf, "%lu", &uptime);
        close(fd);
        total_time = utime + stime + cutime + cstime;
        float cpu_usage = total_time / (float) (uptime * sysconf(_SC_CLK_TCK)) * 100;
        printf("CPU usage: %f%\n", cpu_usage);
    }
}

void process_memory(pid_t pid)
{
        char file_name[40];
        char buf[100];
        int fd;
        sprintf(file_name, "/proc/%d/status", pid);
        fd = open(file_name, O_RDONLY);
        while(1){
        sleep(1);
        lseek(fd, 0, SEEK_SET);
        read(fd, buf, sizeof(buf));
        close(fd);
        unsigned long int vmsize, vmrss;
        sscanf(buf, "%*s %lu %*s %lu", &vmsize, &vmrss);
        printf("Memory usage: %lu KB\n", vmrss);
    }
}