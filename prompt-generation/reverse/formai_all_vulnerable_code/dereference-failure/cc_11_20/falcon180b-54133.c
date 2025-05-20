//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
    int pid, status;
    pid_t childpid;
    char *command;
    char *args[100];
    int i=0;
    int j=0;
    int k=0;
    int flag=0;
    int fd;
    char ch;
    char buffer[100];
    FILE *fp;
    int count=0;

    if(argc<3){
        printf("Usage:./a.out <process_id> <command>\n");
        exit(1);
    }

    pid = atoi(argv[1]);
    command = argv[2];

    childpid = fork();

    if(childpid<0){
        printf("Error: Process creation failed\n");
        exit(1);
    }
    else if(childpid==0){
        execlp(command, command, NULL);
        exit(1);
    }
    else{
        waitpid(childpid, &status, WUNTRACED);
        if(WIFSTOPPED(status)){
            printf("Process %d stopped\n", pid);
        }
        else{
            printf("Process %d resumed\n", pid);
        }
    }

    while(1){
        flag=0;
        j=0;
        for(i=0; i<100; i++){
            args[i]='\0';
        }
        read(0, &ch, 1);
        if(ch=='\n'){
            break;
        }
        else if(ch!='\r'){
            args[j++] = ch;
        }
    }

    args[j]='\0';

    if(strcmp(args, "pstree")==0){
        system("pstree -p ");
    }
    else if(strcmp(args, "ps")==0){
        system("ps");
    }
    else if(strcmp(args, "top")==0){
        system("top");
    }
    else if(strcmp(args, "kill")==0){
        printf("Enter process id to kill: ");
        scanf("%d", &k);
        kill(k, SIGKILL);
    }
    else{
        printf("Invalid command\n");
    }

    return 0;
}