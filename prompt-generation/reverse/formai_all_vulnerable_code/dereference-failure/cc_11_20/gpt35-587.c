//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Romeo and Juliet
/* 
* Once upon a time, 
* there was a network fair lady named Juliet.
* She yearned to visit forbidden sites,
* But her ISP set many restrictions and the rules were tight.
*/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

#define MAX_SIZE 4096

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Usage: %s <proxy_port> <destination_port>\n", argv[0]);
        exit(1);
    }
    
    /*
    * Romeo, the clever hacker,
    * Built an HTTP proxy and put forth his desire,
    * To break the boundaries and build a bridge
    * For Juliet to escape and live her life big.
    */
    
    int status, sockfd, new_fd;  
    struct sockaddr_in proxy_addr, client_addr, remote_addr;    
    socklen_t addrlen;
    char buffer[MAX_SIZE], c, request[MAX_SIZE];
    
    // Clear the buffer
    memset(buffer, 0, MAX_SIZE);
    
    /*
    * Romeo made sure that his proxy's heart 
    * Would beat like Juliet's with a listening socket part.
    */
    
    proxy_addr.sin_family = AF_INET;         
    proxy_addr.sin_port = htons(atoi(argv[1]));      
    proxy_addr.sin_addr.s_addr = INADDR_ANY;     
    memset(&(proxy_addr.sin_zero), '\0', 8);
    
    /*
    * Listening for a request from Juliet,
    * Romeo waits with all his heart, eager to get
    * A chance to help her find her way
    * Through the internet's mazy hay.
    */
    
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
    {
        perror("socket failed");
        exit(1);
    }
    
    if((bind(sockfd, (struct sockaddr *)&proxy_addr, sizeof(struct sockaddr))) == -1) 
    {
        perror("bind failed");
        exit(1);
    }
    
    if((listen(sockfd, 5)) == -1) 
    {
        perror("listen failed");
        exit(1);
    }
    
    addrlen = sizeof(struct sockaddr_in);

    while(1)
    {
        /*
        * When Juliet sends him a message,
        * Romeo accepts it with a smile, no less,
        * And starts the journey to traversal
        * To reach the forbidden zone with zeal.
        */
        
        if((new_fd = accept(sockfd, (struct sockaddr *)&client_addr, &addrlen)) == -1) 
        {
            fprintf(stderr, "accept failed: %s, errno: %d\n", strerror(errno), errno);
            continue;
        }
        
        /*
        * Romeo now takes Juliet's message,
        * Analyzes it with his high wits,
        * Extracts the destination and verb,
        * And builds a new request with a fresh vibe.
        */
        
        memset(buffer, 0, MAX_SIZE);
        recv(new_fd, buffer, MAX_SIZE, 0);

        if(strncmp(buffer, "GET", 3) && strncmp(buffer, "get", 3))
        {  
            printf("HTTP Method Not Supported\n");  
            exit(1);  
        }
        
        int dest_port = atoi(argv[2]); //destination port
        
        memset(&remote_addr, 0, sizeof(remote_addr));
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_port = htons(dest_port);
    
        /*
        * Next, Romeo's love changes direction,
        * He takes the new request, the fresh connection,
        * And sends that towards the destination,
        * Building the new connection with a smooth dedication.
        */
        
        int remote_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
        
        if(remote_sock_fd == -1)
        {
            perror("socket failed");
            exit(1);
        }
        
        inet_pton(AF_INET, "127.0.0.1", &remote_addr.sin_addr);
        
        if(connect(remote_sock_fd, (struct sockaddr *)&remote_addr, sizeof(struct sockaddr)) == -1)
        {
            perror("connect failed");
            exit(1);
        }
        
        /*
        * When Juliet's message reaches the destination,
        * The server sends a response, with HTTP information
        * Romeo reads through this with a loving attention
        * And sends it back to his sweetheart without any hesitation.
        */
        
        send(remote_sock_fd, buffer, strlen(buffer), 0);

        int tmpres = 0;

        while((tmpres = recv(remote_sock_fd, buffer, MAX_SIZE, 0)) > 0)
        {
            send(new_fd, buffer, tmpres, 0);
            memset(buffer, 0, MAX_SIZE);
        }
        
        if(tmpres < 0)
        {
            printf("Error receiving data!\n");
        }
    
        close(new_fd);
        close(remote_sock_fd);
    }
    
    /*
    * And thus, Romeo built a bridge for his love,
    * Letting her bypass restrictions and fill her life with calm.
    * Juliet was happy, and Romeo smiled,
    * The two lovers lived a life full of style.
    */
    
    return (0);
}