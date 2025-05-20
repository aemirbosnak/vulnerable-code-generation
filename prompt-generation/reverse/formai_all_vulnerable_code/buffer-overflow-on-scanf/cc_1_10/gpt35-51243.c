//FormAI DATASET v1.0 Category: System administration ; Style: bold
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    pid_t pid;
    int fd;
    char cmd[50],file[20],status[7],choice;

    printf("\nWelcome to the System Administration Program!");
    do{
        printf("\nDo you want to Monitor (M) or Manage (m) a process? ");
        scanf(" %c",&choice);

        switch(choice){
            case 'M':
                printf("\nEnter PID: ");
                scanf("%d",&pid);
                sprintf(file,"/proc/%d/status",pid);

                fd=open(file,O_RDONLY);
                if(fd==-1){
                    printf("\nProcess with PID %d does not exist",pid);
                    break;
                }

                lseek(fd,311,SEEK_SET);   //Seek to line with State
                read(fd,&status,7);
                printf("\nProcess with PID %d is currently in %s state",pid,status);
                close(fd);
                break;

            case 'm':
                printf("\nEnter command to execute: ");
                scanf("%s",cmd);
 
                if(fork()!=0) break;    //Parent Process
                setsid();
                if(fork()!=0) exit(0);  //Child Process 1
                umask(0);
                chdir("/");
                close(STDIN_FILENO);
                close(STDOUT_FILENO);
                close(STDERR_FILENO);
                //Redirect All I/O to log file
                open("/var/log/process.log",O_RDWR | O_CREAT | O_APPEND,0600);
                dup(0);
                dup(0);
                system(cmd);
                exit(0);
                break;

            default: printf("\nInvalid choice! Try Again.");
        }

    }while(choice != 'q');

    printf("\nExiting System Administration Program. Bye!");
    return 0;
}