//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: portable
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <arpa/inet.h>
#include <netdb.h> 

#define BUFFER_SIZE 4096 

int main(int argc, char *argv[])  
{  
    if (argc < 2)  
    {  
        fprintf(stderr, "Usage: %s <proxy_port>\n", argv[0]);  
        exit(EXIT_FAILURE);  
    }  

    int proxy_port = atoi(argv[1]);  
    struct sockaddr_in proxy_address, client_address, webserver_address;  
    socklen_t client_address_len = sizeof client_address;  
    bzero(&proxy_address, sizeof proxy_address);  
    bzero(&client_address, sizeof client_address);  
    bzero(&webserver_address, sizeof webserver_address);  

    char buffer[BUFFER_SIZE], url[BUFFER_SIZE], method[BUFFER_SIZE], http_version[BUFFER_SIZE];  
    char host[BUFFER_SIZE], request[BUFFER_SIZE], response[BUFFER_SIZE];  
    int read_bytes, write_bytes;  
    int client_socket_fd, webserver_socket_fd;  

    bzero(&buffer, BUFFER_SIZE);  
    bzero(&request, BUFFER_SIZE);  
    bzero(&response, BUFFER_SIZE);  

    proxy_address.sin_family = AF_INET;  
    proxy_address.sin_addr.s_addr = htonl(INADDR_ANY);  
    proxy_address.sin_port = htons(proxy_port);  

    client_socket_fd = socket(AF_INET, SOCK_STREAM, 0);  
    bind(client_socket_fd, (struct sockaddr*) &proxy_address, sizeof(proxy_address));  
    listen(client_socket_fd, 5);  

    while (1)  
    {  
        webserver_socket_fd = 0;  
        bzero(&url, BUFFER_SIZE);  
        bzero(&method, BUFFER_SIZE);  
        bzero(&http_version, BUFFER_SIZE);  
        bzero(&host, BUFFER_SIZE);  

        int client_connection_fd = accept(client_socket_fd, (struct sockaddr*) &client_address, &client_address_len);  
        if (client_connection_fd == -1)  
        {  
            perror("Error accepting client connection");  
            continue;  
        }  

        while (1)  
        {  
            bzero(&buffer, BUFFER_SIZE);  
            if ((read_bytes = recv(client_connection_fd, buffer, BUFFER_SIZE, 0)) <= 0)  
            {  
                break;  
            }  

            sscanf(buffer, "%s %s %s\nHost: %s\n", method, url, http_version, host);  
            sprintf(request, "%s /%s %s\r\nHost: %s\r\nConnection: close\r\n\r\n", method, url, http_version, host);  

            struct hostent *webserver_host;  
            webserver_host = gethostbyname(host);  

            if (webserver_host == NULL)  
            {  
                fprintf(stderr,"ERROR, no such host as %s\n", host);  
                break;  
            }  

            bzero(&webserver_address, sizeof webserver_address);  
            webserver_address.sin_family = AF_INET;  
            webserver_address.sin_port = htons(80);  
            webserver_address.sin_addr = *((struct in_addr *)webserver_host->h_addr);  

            webserver_socket_fd = socket(AF_INET, SOCK_STREAM, 0);  
            if (connect(webserver_socket_fd, (struct sockaddr*) &webserver_address, sizeof(webserver_address)) < 0)  
            {  
                perror("Error connecting to web server");  
                break;  
            }  

            write_bytes = send(webserver_socket_fd, request, strlen(request), 0);  
            if (write_bytes < 0)  
            {  
                perror("Error writing to web server");  
                break;  
            }  

            bzero(&buffer, BUFFER_SIZE);  
            int total_bytes_read = 0;  
            while ((read_bytes = recv(webserver_socket_fd, buffer, BUFFER_SIZE, 0)) > 0)  
            {  
                total_bytes_read += read_bytes;  
                write_bytes = send(client_connection_fd, buffer, read_bytes, 0);  
                if (write_bytes < read_bytes)  
                {  
                    perror("Error writing to client");  
                    break;  
                }  
                bzero(&buffer, BUFFER_SIZE);  
            }  
            if (read_bytes < 0)  
            {  
                perror("Error reading from web server");  
                break;  
            }  
            close(webserver_socket_fd);  
            webserver_socket_fd = 0;  
            break;  
        }  
        close(client_connection_fd);  
    }  
    return 0;  
}