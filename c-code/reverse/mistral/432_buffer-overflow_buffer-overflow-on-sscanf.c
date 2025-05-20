#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    char buffer[10];
    char *response = "227 Entering Passive Mode (192,168,1,1,123,456)\n";
    int ip[6];
    int port;

    sscanf(response, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d),%d", &ip[0], &ip[1], &ip[2], &ip[3], &ip[4], &ip[5], &port);

    char ip_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &ip, ip_str, INET_ADDRSTRLEN);
    printf("IP: %s\n", ip_str);
    printf("Port: %d\n", port);

    char overflow[100];
    strcpy(overflow, ip_str);
    strcat(overflow, "A" /* more data */ );

    return 0;
}
