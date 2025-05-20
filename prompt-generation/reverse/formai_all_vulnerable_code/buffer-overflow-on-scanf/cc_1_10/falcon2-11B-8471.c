//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pwd.h>

void print_process_name(int pid) {
    // Use ps command to print process name
    char command[100];
    sprintf(command, "ps -ef | grep '%d' | awk '{print $2}'\n", pid);
    system(command);
}

int main() {
    int choice;

    do {
        printf("1. List all processes\n2. List a specific process\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Listing all processes...\n");
                print_process_name(getpid());
                break;

            case 2:
                printf("Enter process id: ");
                int pid;
                scanf("%d", &pid);
                print_process_name(pid);
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Invalid input\n");
                break;
        }
    } while (choice!= 3);

    return 0;
}