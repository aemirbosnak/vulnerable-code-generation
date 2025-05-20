//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>

#define MAX_PLAYERS 10
#define DELAY 1 // time in seconds to wait between updates

int main(int argc, char **argv) {
    if(argc!= 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    int num_players = 1;
    int player_pids[MAX_PLAYERS];
    player_pids[0] = pid;

    while(1) {
        int status;
        int i;
        for(i=0; i<num_players; i++) {
            waitpid(player_pids[i], &status, WNOHANG);
            if(WIFEXITED(status)) {
                num_players--;
                for(int j=i; j<num_players; j++) {
                    player_pids[j] = player_pids[j+1];
                }
                break;
            }
        }

        for(i=0; i<num_players; i++) {
            struct rusage usage;
            if(getrusage(RUSAGE_CHILDREN, &usage) == -1) {
                perror("getrusage");
                exit(1);
            }

            double cpu_usage = (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000;
            cpu_usage += (double)usage.ru_stime.tv_sec + (double)usage.ru_stime.tv_usec / 1000000;
            cpu_usage /= (double)DELAY;

            printf("Player %d CPU usage: %.2f%%\n", player_pids[i], cpu_usage*100);
        }

        sleep(DELAY);
    }

    return 0;
}