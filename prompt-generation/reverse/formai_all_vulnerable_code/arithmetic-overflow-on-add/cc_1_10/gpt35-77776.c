//FormAI DATASET v1.0 Category: Port Scanner ; Style: Sherlock Holmes
#include<stdio.h>  
#include<sys/socket.h>  
#include<arpa/inet.h>  
#include<netinet/in.h>  
#include<string.h>  
#include<unistd.h>  
#include<stdlib.h>  

#define TIMEOUT 200000

int main(int argc,char *argv[])  
{  
    int i;
    if (argc != 2) {  
        printf("Usage: %s <ip Address>\n",argv[0]);  
        exit(1);  
    }  
    printf("Performing port scanning for IP address: %s\n", argv[1]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);

    char banner[1024];
    for(i=1;i<= 65535;i++)  
    {  
        struct timeval tv;
        tv.tv_sec = 0;
        tv.tv_usec = TIMEOUT;

        target.sin_port = htons(i);
        memset(&(target.sin_zero), '\0', 8);

        int result = connect(sock, (struct sockaddr *)&target, sizeof(struct sockaddr));
        if (result == 0) {  
            printf("Port %d is open\n", i);

            // Get banner info
            send(sock, "GET / HTTP/1.1\r\n\r\n", 16, 0);
            fd_set set;
            FD_ZERO(&set);
            FD_SET(sock, &set);
            int n = sock + 1;
            int rv = select(n, &set, NULL, NULL, &tv);
            if (rv == -1) {
                perror("select"); 
            } else if (rv == 0) {
                printf("Timeout for port %d\n", i);
            } else {
                recv(sock, banner, 1024, 0);
                printf("Banner info for port %d: %s\n", i, banner);
            }
        }  
        close(sock);
        sock = socket(AF_INET, SOCK_STREAM, 0);
    }  
}