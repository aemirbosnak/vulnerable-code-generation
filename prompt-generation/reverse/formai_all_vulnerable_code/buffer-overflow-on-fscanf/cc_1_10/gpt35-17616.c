//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void printHeader(){
    printf("%10s %10s %10s\n", "USER", "PID", "CMD");
}

void printDetails(char* user, char* pid, char* cmd){
    printf("%10s %10s %10s\n", user, pid, cmd);
}

int main(){
    char memUsage[80];
    char user[10], pid[10], cmd[30];
    FILE* fp;

    printf("Memory Usage Monitor\n");
    printHeader();

    while(1){
        fp = fopen("/proc/meminfo", "r");

        fgets(memUsage, 80, fp);
        printf("Memory Usage: %s", memUsage);

        fclose(fp);

        fp = fopen("/proc/self/status", "r");

        while(fscanf(fp, "%s", user) != EOF){
            if(strcmp(user, "Uid:") == 0){
                fscanf(fp, "%s", user);
                break;
            }
        }

        rewind(fp);

        while(fscanf(fp, "%s", pid) != EOF){
            if(strcmp(pid, "Pid:") == 0){
                fscanf(fp, "%s", pid);
                break;
            }
        }

        fclose(fp);

        fp = fopen("/proc/self/cmdline", "r");

        fgets(cmd, 30, fp);

        fclose(fp);

        printDetails(user, pid, cmd);

        sleep(5);
        system("clear");
    }

    return 0;
}