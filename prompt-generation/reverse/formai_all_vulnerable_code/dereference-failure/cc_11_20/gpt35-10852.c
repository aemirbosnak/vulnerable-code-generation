//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <ifaddrs.h>

#define PORT 80
#define MAX_RECEIVED_SIZE 1024

int main(int argc,char **argv){
    int sockfd, received_size, enable=1, i;
    char *request;
    char response[MAX_RECEIVED_SIZE];
    char *ip_address;
    struct sockaddr_in target;
    struct hostent *host_entry;
    struct ifaddrs *ifaddr, *ifa;
    
    if (getifaddrs(&ifaddr) == -1) { //Error checking for getifaddrs function
        perror("getifaddrs");
        return -1;
    }
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) continue;
        int family = ifa->ifa_addr->sa_family;
        if (family == AF_INET) {
            printf("%s\n", ifa->ifa_name); //Printing network interface name
            struct sockaddr_in* address = (struct sockaddr_in*)ifa->ifa_addr;
            char* hostname = malloc(NI_MAXHOST);
            int res = getnameinfo((struct sockaddr*)address, sizeof(struct sockaddr_in), hostname, NI_MAXHOST, NULL, 0, 0);
            if (res != 0) {
                printf("Error: %s", gai_strerror(res));
                continue;
            }
            printf("\t%s\n", hostname); //Printing IP address of the network interface
        }
    }
    freeifaddrs(ifaddr); // Free the getifaddrs linked list
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        return -1;
    }
    
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) == -1){ //Set socket options
        perror("setsockopt");
        return -1;
    }
    
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(PORT);
    
    if (argc != 2) {
        printf("Usage: ./a.out <ip_address>\n"); //Check for correct number of command line arguments
        return -1;
    }
    
    ip_address = argv[1];
    
    if (inet_pton(AF_INET, ip_address, &target.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n"); //Check for valid IP address
        return -1;
    }
    
    if (connect(sockfd, (struct sockaddr *)&target , sizeof(target)) < 0) {
        perror("Error in connect");
        return -1;
    }
    
    request = "GET / HTTP/1.1\r\nHost: 127.0.0.1\r\n\r\n"; //HTTP GET request string
    
    if (send(sockfd, request, strlen(request), 0) == -1) { //Send HTTP GET request
        perror("Error sending request");
        return -1;
    }
    
    received_size = recv(sockfd, response, MAX_RECEIVED_SIZE, 0); //Receive response from server
    if (received_size == -1) {
        perror("Error receiving response");
        return -1;
    }
    
    printf("%.*s\n", received_size, response); //Print the response
    
    close(sockfd);
    
    return 0;
}