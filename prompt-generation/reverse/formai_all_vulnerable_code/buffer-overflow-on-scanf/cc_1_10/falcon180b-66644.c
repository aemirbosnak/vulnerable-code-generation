//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOSTS 10
#define MAX_HOST_NAME_LEN 100

typedef struct {
    char hostname[MAX_HOST_NAME_LEN];
    int port;
} host_t;

void get_hosts(host_t hosts[MAX_HOSTS]) {
    int num_hosts = 0;
    char input[MAX_HOST_NAME_LEN];

    // Get user input for hosts
    printf("Enter hostnames and ports (separated by spaces): ");
    scanf("%s", input);

    // Parse user input for hosts
    char *token = strtok(input, " ");
    while (token!= NULL) {
        if (num_hosts >= MAX_HOSTS) {
            printf("Error: Too many hosts.\n");
            exit(1);
        }

        strcpy(hosts[num_hosts].hostname, token);
        hosts[num_hosts].port = atoi(strtok(NULL, " "));
        num_hosts++;

        token = strtok(NULL, " ");
    }
}

int main() {
    host_t hosts[MAX_HOSTS];
    get_hosts(hosts);

    int num_hosts = 0;
    for (int i = 0; i < MAX_HOSTS; i++) {
        if (hosts[i].hostname[0]!= '\0') {
            num_hosts++;
        }
    }

    if (num_hosts == 0) {
        printf("Error: No hosts entered.\n");
        exit(1);
    }

    // Test internet speed for each host
    for (int i = 0; i < num_hosts; i++) {
        char url[100];
        sprintf(url, "http://%s:%d/speedtest.php", hosts[i].hostname, hosts[i].port);

        FILE *fp = fopen(url, "r");
        if (fp == NULL) {
            printf("Error: Could not connect to %s:%d.\n", hosts[i].hostname, hosts[i].port);
            continue;
        }

        char result[100];
        fscanf(fp, "%s", result);
        fclose(fp);

        if (strcmp(result, "OK") == 0) {
            printf("Host %s:%d is reachable.\n", hosts[i].hostname, hosts[i].port);
        } else {
            printf("Host %s:%d is not reachable.\n", hosts[i].hostname, hosts[i].port);
        }
    }

    return 0;
}