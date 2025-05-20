//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

/* Global variables */
static unsigned long long cli_tick_interval = 1000000;
static unsigned int max_procs = 100000;

/* Function declaration */
void print_usage(char *prog_name);
long long get_total_ram();
void get_proc_stats(int *num_proc, long long *total_rss);

/* Main function */
int main(int argc, char **argv)
{
    /* Check for correct number of command line arguments */
    if (argc != 2) {
        print_usage(argv[0]);
        return -1;
    }
    
    /* Parse command line arguments */
    cli_tick_interval = atoi(argv[1]);
    
    /* Variable declaration */
    int num_proc;
    long long total_rss;
    float usage;
    
    /* Get total RAM installed */
    long long total_ram = get_total_ram();
    
    /* Infinite loop to monitor RAM usage */
    while (1) {
        /* Get number of current processes and RAM usage */
        get_proc_stats(&num_proc, &total_rss);
        
        /* Calculate RAM usage */
        usage = ((float)total_rss / (float)total_ram) * 100;
        
        /* Print RAM usage */
        printf("Current RAM usage: %.2f%%\n", usage);
        
        /* Wait for specified time interval */
        usleep(cli_tick_interval);
    }
    
    return 0;
}

/* Function definition to print usage instructions */
void print_usage(char *prog_name)
{
    printf("Usage: %s <tick_interval_microseconds>\n", prog_name);
}

/* Function definition to get total RAM installed */
long long get_total_ram()
{
    struct sysinfo mem_info;
    sysinfo(&mem_info);
    return mem_info.totalram;
}

/* Function definition to get number of processes and total RSS */
void get_proc_stats(int *num_proc, long long *total_rss)
{
    char buffer[1024];
    unsigned long long rss;
    long long total_rss_val = 0;
    FILE *fp;
    int pid, n;
    
    /* Open the command for reading. */
    fp = popen("ps aux", "r");
    
    /* Error handling */
    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }
    
    /* Ignore first line containing headers */
    fgets(buffer, sizeof(buffer), fp);
    
    /* Loop through each line of process stats */
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        /* Parse PID */
        n = sscanf(buffer, "%d", &pid);
        if (n == 1) {
            /* Parse RSS */
            n = sscanf(buffer, "%*d %*s %*c %*s %*d %*d %*d %*d %*d %*d %*d %llu %*d", &rss);
            if (n == 1) {
                /* Add current process's RSS value to total RSS */
                total_rss_val += rss;
            }
        }
        
        /* Check if we have exceeded max number of processes */
        if(--max_procs == 0) break;
    }
    
    /* Close the command pipe */
    pclose(fp);
    
    /* Return values */
    *num_proc = max_procs;
    *total_rss = total_rss_val;
}