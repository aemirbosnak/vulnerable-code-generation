//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/timeb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_SERVERS 10
#define PING_TIMEOUT 5

struct server {
    char *name;
    char *ip;
    int port;
    int ping;
};

int main() {
    struct server servers[MAX_SERVERS];
    int num_servers = 0;
    char input[BUFFER_SIZE];
    int choice;

    printf("Internet Speed Test Application\n");
    printf("===============================\n");

    while(1) {
        printf("Enter server name (or type 'list' to display servers): ");
        fgets(input, BUFFER_SIZE, stdin);

        if(strcmp(input, "list") == 0) {
            for(int i=0; i<num_servers; i++) {
                printf("%d. %s (%s:%d)\n", i+1, servers[i].name, servers[i].ip, servers[i].port);
            }
        } else {
            char *name = strtok(input, " ");
            char *ip = strtok(NULL, " ");
            int port = atoi(strtok(NULL, " "));

            servers[num_servers].name = strdup(name);
            servers[num_servers].ip = strdup(ip);
            servers[num_servers].port = port;
            servers[num_servers].ping = -1;

            num_servers++;
        }
    }

    return 0;
}