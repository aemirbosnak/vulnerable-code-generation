//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define MAX_ROUTERS 10

struct router {
    char name[64];
    int signal_strength;
};

int main() {
    FILE *file;
    char line[BUFFER_SIZE];
    int count = 0;
    struct router routers[MAX_ROUTERS];

    file = fopen("routers.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, BUFFER_SIZE, file)!= NULL) {
        if (count >= MAX_ROUTERS) {
            printf("Maximum number of routers reached\n");
            break;
        }

        char *name = strtok(line, ",");
        int signal_strength = atoi(strtok(NULL, ","));

        strcpy(routers[count].name, name);
        routers[count].signal_strength = signal_strength;

        count++;
    }

    fclose(file);

    for (int i = 0; i < count; i++) {
        printf("Router %d: %s (%d)\n", i+1, routers[i].name, routers[i].signal_strength);
    }

    return 0;
}