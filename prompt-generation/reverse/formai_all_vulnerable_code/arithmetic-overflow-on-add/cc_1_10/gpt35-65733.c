//FormAI DATASET v1.0 Category: System process viewer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <time.h>

void displayHeader()
{
    printf("\n\n\t**** Romantic Process Viewer ****\n\n");
}

void displayProcesses()
{   
    DIR* dir = opendir("/proc/");
    
    if (!dir)
    {
        printf("Unable to open \"/proc/\" directory.\n");
        return;
    }
    
    struct dirent* entry;
    char* endptr;
    
    printf("\n\tPID\tName\t\tStatus\n");
    
    while ((entry = readdir(dir)) != NULL)
    {
        if (!isdigit(*entry->d_name))
        {
            continue;
        }
        
        char cmdline_file[64] = {0};
        sprintf(cmdline_file, "/proc/%s/cmdline", entry->d_name);
        
        FILE* fp_cmdline = fopen(cmdline_file, "r");
        if (fp_cmdline)
        {
            char cmdline[256] = {0};
            fgets(cmdline, sizeof(cmdline), fp_cmdline);
            fclose(fp_cmdline);
            
            if (strlen(cmdline) > 0 && cmdline[strlen(cmdline) - 1] == '\n')
            {
                cmdline[strlen(cmdline) - 1] = '\0';
            }
            
            char stat_file[64] = {0};
            sprintf(stat_file, "/proc/%s/stat", entry->d_name);
            
            FILE* fp_stat = fopen(stat_file, "r");
            if (fp_stat)
            {
                char stat[256] = {0};
                fgets(stat, sizeof(stat), fp_stat);
                fclose(fp_stat);
                
                char* p = stat;
                p = strchr(p, '(');
                if (p)
                {
                    char* q = strchr(p + 1, ')');
                    if (q)
                    {
                        *q = '\0';
                    }
                }
                
                printf("\t%s\t%-21s%s\n", entry->d_name, cmdline, p);
            }
        }
    }
    
    closedir(dir);
}

int main()
{
    displayHeader();
    printf("Let me display the running processes for you...\n");
    displayProcesses();
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("\n\n\tThe process viewer was last executed on: %d-%02d-%02d %02d:%02d:%02d\n\n",
           tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    return 0;
}