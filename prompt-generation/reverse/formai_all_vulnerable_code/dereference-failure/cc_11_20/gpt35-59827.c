//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: all-encompassing
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <errno.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <arpa/inet.h>  
#include <netdb.h>  
  
// Define the maximum length of request/response  
#define MAX_BUF_LEN 2048  
  
// Define the listening port number  
#define LISTEN_PORT 8888  
  
// Define the remote server and port  
#define REMOTE_SERVER_IP "www.example.com"  
#define REMOTE_SERVER_PORT 80  
  
int main(void)  
{  
    int listen_sockfd, conn_sockfd;  
    struct sockaddr_in listen_addr, remote_addr;  
    char recv_buf[MAX_BUF_LEN] = { 0 };  
  
    listen_sockfd = socket(AF_INET, SOCK_STREAM, 0);  
    if (listen_sockfd == -1)  
    {  
        printf("Create socket error: %s(errno: %d)\n", strerror(errno), errno);  
        return -1;  
    }  
  
    memset(&listen_addr, 0, sizeof(listen_addr));  
    listen_addr.sin_family = AF_INET;  
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);  
    listen_addr.sin_port = htons(LISTEN_PORT);  
  
    if (bind(listen_sockfd, (struct sockaddr*)&listen_addr, sizeof(listen_addr)) == -1)  
    {  
        printf("Bind socket error: %s(errno: %d)\n", strerror(errno), errno);  
        return -1;  
    }  
  
    if (listen(listen_sockfd, 10) == -1)  
    {  
        printf("Listen socket error: %s(errno: %d)\n", strerror(errno), errno);  
        return -1;  
    }  
  
    printf("Simple HTTP proxy started on port %d...\n", LISTEN_PORT);  
    
    while (1)  
    {  
        conn_sockfd = accept(listen_sockfd, NULL, NULL);  
        if (conn_sockfd == -1)  
        {  
            printf("Accept socket error: %s(errno: %d)\n", strerror(errno), errno);  
            continue;  
        }  
          
        printf("Connection accepted\n");  
          
        pid_t pid = fork();  
        if (pid == 0) // Child process  
        {  
            close(listen_sockfd);  
  
            // Set up a connection to the remote server  
            int remote_sockfd = socket(AF_INET, SOCK_STREAM, 0);  
            if (remote_sockfd == -1)  
            {  
                printf("Create remote socket error: %s(errno: %d)\n", strerror(errno), errno);  
                return -1;  
            }  
  
            memset(&remote_addr, 0, sizeof(remote_addr));  
            remote_addr.sin_family = AF_INET;  
            remote_addr.sin_port = htons(REMOTE_SERVER_PORT);  
            if (inet_pton(AF_INET, REMOTE_SERVER_IP, &remote_addr.sin_addr) <= 0)  
            {  
                printf("Invalid address: %s\n", REMOTE_SERVER_IP);  
                return -1;  
            }  
  
            if (connect(remote_sockfd, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) == -1)  
            {  
                printf("Connect remote server error: %s(errno: %d)\n", strerror(errno), errno);  
                return -1;  
            }  
            printf("Connected to remote server %s:%d\n", REMOTE_SERVER_IP, REMOTE_SERVER_PORT);  
  
            while (1)  
            {  
                memset(recv_buf, 0, MAX_BUF_LEN);  
                ssize_t recv_len = recv(conn_sockfd, recv_buf, MAX_BUF_LEN, 0);  
                if (recv_len == -1)  
                {  
                    printf("Receive client request error: %s(errno: %d)\n", strerror(errno), errno);  
                    return -1;  
                }  
                if (recv_len == 0)  
                {  
                    printf("Client disconnected\n");  
                    break;  
                }  
  
                printf("Received client request:\n%s\n", recv_buf);  
  
                // Send the request to the remote server  
                if (send(remote_sockfd, recv_buf, recv_len, 0) == -1)  
                {  
                    printf("Send request to remote server error: %s(errno: %d)\n", strerror(errno), errno);  
                    return -1;  
                }  
  
                // Receive response from the remote server  
                while (1)  
                {  
                    memset(recv_buf, 0, MAX_BUF_LEN);  
                    ssize_t recv_len = recv(remote_sockfd, recv_buf, MAX_BUF_LEN, 0);  
                    if (recv_len == -1)  
                    {  
                        printf("Receive response from remote server error: %s(errno: %d)\n", strerror(errno), errno);  
                        return -1;  
                    }  
                    if (recv_len == 0)  
                    {  
                        printf("Remote server disconnected\n");  
                        break;  
                    }  
  
                    printf("Received response from remote server:\n%s\n", recv_buf);  
  
                    // Send the response to the client  
                    if (send(conn_sockfd, recv_buf, recv_len, 0) == -1)  
                    {  
                        printf("Send response to client error: %s(errno: %d)\n", strerror(errno), errno);  
                        return -1;  
                    }  
                }  
            }  
            close(remote_sockfd);  
            close(conn_sockfd);  
            return 0;  
        }  
        else if (pid > 0) // Parent process  
        {  
            close(conn_sockfd);  
        }  
        else // Error  
        {  
            printf("Fork error: %s(errno: %d)\n", strerror(errno), errno);  
            return -1;  
        }  
    }  
    return 0;  
}