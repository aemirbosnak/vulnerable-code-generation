//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_HOSTS 100
#define MAX_IP_ADDR_LEN 16

struct host_info {
    char hostname[MAX_HOSTNAME_LEN];
    char ip_addr[MAX_IP_ADDR_LEN];
};

struct host_info host_list[MAX_HOSTS];

int main() {
    int sockfd, num_hosts;
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_in *ipv4;
    struct hostent *he;
    char ip_addr[INET_ADDRSTRLEN];

    // get the hostname of the current machine
    if (gethostname(host_list[0].hostname, MAX_HOSTNAME_LEN) == -1) {
        perror("gethostname");
        exit(1);
    }

    // get the IP address of the current machine
    he = gethostbyname(host_list[0].hostname);
    if (he == NULL) {
        herror("gethostbyname");
        exit(1);
    }
    strcpy(host_list[0].ip_addr, inet_ntoa(*(struct in_addr *)he->h_addr));

    // create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // set up hints for getaddrinfo
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;

    // get a list of address structures
    if (getaddrinfo(NULL, "22", &hints, &servinfo) != 0) {
        perror("getaddrinfo");
        exit(1);
    }

    // loop through the list of address structures
    for (p = servinfo; p != NULL; p = p->ai_next) {
        // get the IP address of the current machine
        ipv4 = (struct sockaddr_in *)p->ai_addr;
        inet_ntop(AF_INET, &(ipv4->sin_addr), ip_addr, INET_ADDRSTRLEN);

        // add the IP address and hostname to the list of hosts
        strcpy(host_list[num_hosts].ip_addr, ip_addr);
        strcpy(host_list[num_hosts].hostname, host_list[0].hostname);
        num_hosts++;
    }

    // close the socket
    close(sockfd);

    // print the list of hosts
    for (int i = 0; i < num_hosts; i++) {
        printf("%s: %s\n", host_list[i].hostname, host_list[i].ip_addr);
    }

    return 0;
}