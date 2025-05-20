//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main() {
    char if_name[IFNAMSIZ]; // variable to store interface name
    int sockfd; // socket descriptor
    int ret_val; // return value

    printf("Enter interface name: ");
    scanf("%s", if_name);

    // create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket() error");
        exit(EXIT_FAILURE);
    }
    
    // turn off interface before scanning
    struct ifreq ifr;
    strncpy(ifr.ifr_name, if_name, IFNAMSIZ);
    ret_val = ioctl(sockfd, SIOCGIFFLAGS, &ifr);
    if (ret_val == -1) {
        perror("ioctl() error");
        exit(EXIT_FAILURE);
    }
    ifr.ifr_flags &= ~IFF_UP;
    ret_val = ioctl(sockfd, SIOCSIFFLAGS, &ifr);
    if (ret_val == -1) {
        perror("ioctl() error");
        exit(EXIT_FAILURE);
    }

    // scan for wireless networks
    ifr.ifr_flags |= IFF_UP;
    ret_val = ioctl(sockfd, SIOCSIFFLAGS, &ifr); // turn interface back on
    if (ret_val == -1) {
        perror("ioctl() error");
        exit(EXIT_FAILURE);
    }

    // buffer to store output from command
    char buff[BUFF_SIZE];
    // command to get wireless networks
    char command[] = "sudo iwlist ";
    strcat(command, if_name);
    strcat(command, " scan | grep ESSID");

    // run command and store output in buffer
    FILE* f = popen(command, "r");
    if (!f) {
        perror("popen() error");
        exit(EXIT_FAILURE);
    }
    while (fgets(buff, BUFF_SIZE, f)) {
        printf("%s", buff);
    }
    // close file pointer
    ret_val = pclose(f);
    if (ret_val == -1) {
        perror("pclose() error");
        exit(EXIT_FAILURE);
    }

    // turn off interface after scanning
    ifr.ifr_flags &= ~IFF_UP;
    ret_val = ioctl(sockfd, SIOCSIFFLAGS, &ifr);
    if (ret_val == -1) {
        perror("ioctl() error");
        exit(EXIT_FAILURE);
    }

    // close socket
    close(sockfd);
    
    return 0;
}