//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/time.h>

#define TRUE 1 
#define FALSE 0 

int main(int argc, char *argv[]) {

    int sockfd;
    int numbytes;
    char buf[4096];
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];
    char *ip;
    char ipstart[40], ipend[40];
    char *iprange = "-";
    char iprangebuf[128];
    int port;
    struct sockaddr_in their_addr;

    // check command line arguments
    if (argc < 2 || argc > 3) {
        fprintf(stderr,"usage: WirelessNetworkScanner hostname [port]\n");
        return 1;
    }

    if(argc == 3) {
        // parse port number from argv[2]
        if (sscanf(argv[2], "%d", &port) != 1) {
            fprintf(stderr, "wirelessNetworkScanner: invalid port number '%s'\n", argv[2]);
            exit(1);
        }
    } else {
        // default port number
        port = 80;
    }

    // parse IP address range if specified in hostname
    if (strstr(argv[1], iprange) != NULL) {
        strncpy(iprangebuf, argv[1], strlen(argv[1]) - strlen(strstr(argv[1], iprange)));
        iprangebuf[strlen(argv[1]) - strlen(strstr(argv[1], iprange))] = '\0';

        if (inet_pton(AF_INET, strtok(iprangebuf, ""), &their_addr.sin_addr) != 1) {
            fprintf(stderr, "wirelessNetworkScanner: invalid address '%s'\n", argv[1]);
            exit(1);
        }
        strncpy(ipstart, inet_ntoa(their_addr.sin_addr), strlen(inet_ntoa(their_addr.sin_addr)));
        strcpy(ipend, strtok(NULL, ""));
    } else {
        strncpy(ipstart, argv[1], strlen(argv[1]));
        strncpy(ipend, argv[1], strlen(argv[1]));
    }

    // print out IP addresses in the specified range
    printf("Scanning wireless network...\n");
    printf("IP address range: %s%s%s\n", ipstart, iprange, ipend);
    printf("Port: %d\n\n", port);

    // loop through IP addresses to see if they have the specified port open
    char ipcount[40];
    int i, j;
    for (i = atoi(strtok(ipstart, ".")); i <= atoi(strtok(ipend, ".")); i++) {
        for (j = atoi(strtok(NULL, ".")); j <= atoi(strtok(NULL, ".")); j++) {
            sprintf(ipcount, "%d.%d.%d.%d", i, j, atoi(strtok(NULL, ".")), atoi(strtok(NULL, ".")));

            //set the struct info to NULL to clear out garbage data
            memset(&hints, 0, sizeof hints);

            //set info you want to get for a connection
            hints.ai_family = AF_UNSPEC;
            hints.ai_socktype = SOCK_STREAM;

            // get info for each ip address
            if ((rv = getaddrinfo(ipcount, argv[2], &hints, &servinfo)) != 0) {
                continue;
            }

            // loop through all the results and connect to the first we can
            for (p = servinfo; p != NULL; p = p->ai_next) {
                if ((sockfd = socket(p->ai_family, p->ai_socktype,
                        p->ai_protocol)) == -1) {
                    continue;
                }

                if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
                    close(sockfd);
                    continue;
                }

                // print out IP address and port if specified port is open
                printf("%s:%d\n", ipcount, port);
                close(sockfd);
                break;
            }
            freeaddrinfo(servinfo);
        }
    }
    printf("\nWireless network scan complete.\n");
    return 0;
}