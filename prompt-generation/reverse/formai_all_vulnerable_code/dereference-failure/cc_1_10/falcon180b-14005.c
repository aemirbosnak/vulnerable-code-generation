//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_HOST_NAME 256
#define MAX_PORT_NUMBER 6
#define MAX_IP_ADDRESS 16
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
    char hostname[MAX_HOST_NAME];
    char ip_address[MAX_IP_ADDRESS];
    char port_number[MAX_PORT_NUMBER];
    char line[MAX_LINE_LENGTH];
    char *token;
    FILE *fp;
    int sockfd, port;
    struct hostent *host;
    struct sockaddr_in server_addr;
    int addrlen;
    int ret;

    if (argc!= 2)
    {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);

    // Get IP address of the hostname
    host = gethostbyname(hostname);
    if (host == NULL)
    {
        printf("Error: Host %s not found\n", hostname);
        exit(1);
    }
    strcpy(ip_address, inet_ntoa(*(struct in_addr *)host->h_addr));

    // Get the port number
    fp = fopen("/etc/services", "r");
    if (fp == NULL)
    {
        printf("Error: /etc/services not found\n");
        exit(1);
    }
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL)
    {
        token = strtok(line, " ");
        if (strcmp(token, hostname) == 0)
        {
            strcpy(port_number, strtok(NULL, " "));
            break;
        }
    }
    fclose(fp);

    // Convert the port number from string to integer
    port = atoi(port_number);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Error: Socket creation failed\n");
        exit(1);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    // Connect to the server
    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1)
    {
        printf("Error: Connection failed\n");
        exit(1);
    }

    // Send data to the server
    sprintf(line, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", hostname);
    ret = send(sockfd, line, strlen(line), 0);
    if (ret == -1)
    {
        printf("Error: Data send failed\n");
        exit(1);
    }

    // Receive data from the server
    memset(line, 0, MAX_LINE_LENGTH);
    ret = recv(sockfd, line, MAX_LINE_LENGTH, 0);
    if (ret == -1)
    {
        printf("Error: Data receive failed\n");
        exit(1);
    }

    // Close socket
    close(sockfd);

    printf("Data received from server:\n%s", line);

    return 0;
}