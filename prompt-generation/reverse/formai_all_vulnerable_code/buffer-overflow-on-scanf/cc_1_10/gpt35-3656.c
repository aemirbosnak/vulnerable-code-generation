//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>         
#include<sys/socket.h>
#include<arpa/inet.h>
#include<errno.h>
#include<netdb.h>
#include<sys/types.h>
#include<unistd.h>

#define MAXLINE 1024

// function to scan ip addresses of a network and map the topology
void map_network_topology(char *ip_address, int port_number) {
    
    // variables to store socket details, buffer, and other information required
    int sockfd, len = sizeof(struct sockaddr_in), n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr, *ptr = &servaddr;
    struct hostent *h;
    char *hostaddr;
    
    // creating a socket for communication
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error creating socket: %s (errno: %d)\n", strerror(errno), errno);
        return;
    }
    
    // setting up the socket details
    memset(&servaddr, 0, len);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port_number);
    
    // checking if given input is hostname or IP address
    if ((servaddr.sin_addr.s_addr = inet_addr(ip_address)) == INADDR_NONE) {
        if ((h = gethostbyname(ip_address)) == NULL) {
            printf("Error resolving hostname: %s (h_errno: %d)\n", hstrerror(h_errno), h_errno);
            close(sockfd);
            return;
        }
        memcpy(&servaddr.sin_addr, h->h_addr, h->h_length);
        hostaddr = inet_ntoa(*(struct in_addr *)h->h_addr);
    } else {
        servaddr.sin_addr.s_addr = inet_addr(ip_address);
        hostaddr = ip_address;
    }
    
    // establishing connection with the given IP address
    if (connect(sockfd, (struct sockaddr *)&servaddr, len) < 0 ) {
        printf("Error connecting to %s:%d: %s (errno: %d)\n", hostaddr, port_number, strerror(errno), errno);
        close(sockfd);
        return;
    }
    printf("Connected to %s:%d\n", hostaddr, port_number);
    
    // sending request packet to connected device
    char *buffer = "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n";
    write(sockfd, buffer, strlen(buffer));
    printf("\nTopology of the network with IP address %s mapped successfully\n", ip_address);
    
    // closing the socket connection after topology mapping
    close(sockfd);
}

int main(int argc, char **argv) {
    // taking input from user for IP address and port number
    char ip_address[INET_ADDRSTRLEN];
    int port_number, i, j;
    printf("\nEnter the IP address of the network to map topology: ");
    scanf("%s", ip_address);
    printf("Enter the port number to use for communication: ");
    scanf("%d", &port_number);

    // scanning IP addresses of the network
    for (i = 1; i <= 255; i++) {
        char *temp_ip = strtok(ip_address, ".");
        char new_ip_address[INET_ADDRSTRLEN];
        for (j = 0; temp_ip != NULL; j++) {
            if (j == 3) {
                strcpy(new_ip_address + strlen(new_ip_address), i);
            } else {
                strcpy(new_ip_address + strlen(new_ip_address), temp_ip);
            }
            if (j != 3) {
                strcpy(new_ip_address + strlen(new_ip_address), ".");
            }
            temp_ip = strtok(NULL, ".");
        }
        map_network_topology(new_ip_address, port_number);
    }    
    return 0;
}