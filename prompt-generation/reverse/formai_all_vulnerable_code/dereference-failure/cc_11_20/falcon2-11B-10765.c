//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int num_hosts = atoi(argv[1]);
    int num_switches = atoi(argv[2]);
    int num_links = atoi(argv[3]);

    char **hosts = (char **)malloc(num_hosts * sizeof(char *));
    char **switches = (char **)malloc(num_switches * sizeof(char *));
    char **links = (char **)malloc(num_links * sizeof(char *));

    int i;
    for (i = 0; i < num_hosts; i++) {
        hosts[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", hosts[i]);
    }
    for (i = 0; i < num_switches; i++) {
        switches[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", switches[i]);
    }
    for (i = 0; i < num_links; i++) {
        links[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", links[i]);
    }

    int num_hosts_connected = 0;
    int num_switches_connected = 0;
    int num_links_connected = 0;

    for (i = 0; i < num_hosts; i++) {
        int j;
        for (j = 0; j < num_switches; j++) {
            if (strcmp(hosts[i], switches[j]) == 0) {
                num_hosts_connected++;
                break;
            }
        }
    }

    for (i = 0; i < num_switches; i++) {
        int j;
        for (j = 0; j < num_switches; j++) {
            if (strcmp(switches[i], switches[j]) == 0) {
                num_switches_connected++;
                break;
            }
        }
    }

    for (i = 0; i < num_links; i++) {
        int j;
        for (j = 0; j < num_links; j++) {
            if (strcmp(links[i], links[j]) == 0) {
                num_links_connected++;
                break;
            }
        }
    }

    printf("Hosts connected: %d\n", num_hosts_connected);
    printf("Switches connected: %d\n", num_switches_connected);
    printf("Links connected: %d\n", num_links_connected);

    return 0;
}