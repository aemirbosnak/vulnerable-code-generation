//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <time.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80
#define BUFFERSIZE 1024

int main()
{
    struct timeval start, end;
    char ip[INET_ADDRSTRLEN];
    char hostname[BUFFERSIZE];
    char buffer[BUFFERSIZE];
    double download_speed;
    int sockfd, bytes_received, total_bytes = 0;
    struct sockaddr_in serv_addr;
    struct hostent *he = NULL;
    
    printf("Enter the url of the website: ");
    scanf("%s", hostname);

    if ((he = gethostbyname(hostname)) == NULL) {  
        printf("Failed to resolve hostname.\n");  
        return 1;  
    }

    printf("IP address of %s is %s\n", hostname, inet_ntop(AF_INET, he->h_addr_list[0], ip, INET_ADDRSTRLEN));
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Failed to create socket.\n");
        return 1;
    }
    
    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;    
    serv_addr.sin_port = htons(PORT);  
    serv_addr.sin_addr = *((struct in_addr *)he->h_addr_list[0]);
    
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Failed to connect to server.\n");
        return 1;
    }
    
    printf("\nConnected to %s.\n", hostname);
    
    gettimeofday(&start, NULL);
    
    char request[BUFFERSIZE];
    snprintf(request, BUFFERSIZE, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", hostname);
    send(sockfd, request, strlen(request), 0);
    
    while ((bytes_received = recv(sockfd, buffer, BUFFERSIZE, 0)) > 0) {
        total_bytes += bytes_received;
    }
    
    gettimeofday(&end, NULL);
    
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    
    download_speed = total_bytes / time_taken;
    printf("Download speed = %.2f bytes/second (%.2f KB/s)\n", download_speed, download_speed/1024.0);
    
    close(sockfd);
    
    return 0;
}