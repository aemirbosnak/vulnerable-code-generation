//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<errno.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 80
int main() {

    int sockfd, ret, i;
    struct sockaddr_in target;
    char ip[16], ip_range[20];
    char *ptr;

    printf("Enter the IP Range you want to scan (e.g. 192.168.1.1-254): ");
    scanf("%s",ip_range);

    ptr = strtok(ip_range, "-");

    while(ptr != NULL) {

        strcpy(ip, ptr);

        for(i = 2; i <= 254; i++) {

            sprintf(ip + strlen(ip), ".%d", i);

            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if(sockfd < 0) {

                printf("[x] Error creating socket: %s\n", strerror(errno));
                return -1;

            }

            target.sin_family = AF_INET;
            target.sin_port = htons(PORT);
            target.sin_addr.s_addr = inet_addr(ip);

            ret = connect(sockfd, (struct sockaddr *)&target, sizeof(target));
            if(ret < 0) {

                printf("[.] %s - Port %d is closed.\n", ip, PORT);

            } else {

                printf("[+] %s - Port %d is open.\n", ip, PORT);
            }

            close(sockfd);

        }

        ptr = strtok(NULL, "-");

    }
    return 0;
}