//FormAI DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int sockfd, ret;
    struct sockaddr_in target_addr;
    char target_ip[20];
    int start_port, end_port;
    
    printf("Hello! Welcome to the Port Scanner Program.\n");
    printf("Please enter the IP address of the target system: ");
    scanf("%s", target_ip);
    
    printf("\nGreat! Now, please enter the starting port: ");
    scanf("%d", &start_port);
    
    printf("\nAnd finally, enter the ending port: ");
    scanf("%d", &end_port);
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        printf("Socket could not be created.\n");
        return EXIT_FAILURE;
    }
    
    // Fill in target address information
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(target_ip);
    
    // Scan the ports
    printf("\nScanning ports from %d to %d...\n", start_port, end_port);
    for(int i = start_port; i <= end_port; i++)
    {
        target_addr.sin_port = htons(i);     // Convert to network byte order
        ret = connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr));
        if(ret == 0)
        {
            printf("Port %d is open.\n", i);
        }
    }
    
    // Close the socket
    close(sockfd);
    printf("\nThank you for using our Port Scanner program. Have a nice day!\n");
    
    return EXIT_SUCCESS;
}