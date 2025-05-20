//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<errno.h>
#include<netdb.h>

#define MAX 65535
#define TRUE 1
#define FALSE 0
#define ERROR -1

typedef struct{
    int sock;
    struct sockaddr_in server;
    int port;
}port_t;

port_t *port_scan(char *ip, int start_port, int end_port)
{
    int i=0;
    port_t *ports = (port_t*)malloc(sizeof(port_t)*(end_port-start_port+1));
    for(i=start_port;i<=end_port;i++)
    {
        ports[i-start_port].port = i;
        memset(&ports[i-start_port].server, 0, sizeof(ports[i-start_port].server));
        ports[i-start_port].server.sin_family = AF_INET;
        ports[i-start_port].server.sin_port = htons(i);
        inet_pton(AF_INET, ip, &ports[i-start_port].server.sin_addr);
    }
    return ports;
}

int connect_port(port_t *port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == ERROR)
    {
        printf("Socket creation failed\n");
        return ERROR;
    }
    if(connect(sock, (struct sockaddr*)&port->server, sizeof(port->server)) == ERROR)
    {
        close(sock);
        printf("Connection failed on port %d\n", port->port);
        return ERROR;
    }
    close(sock);
    printf("Connection successful on port %d\n", port->port);
    return TRUE;
}

int main(int argc, char *argv[])
{
    if(argc<4)
    {
        printf("Usage:./port_scanner <IP Address> <Start Port> <End Port>\n");
        return ERROR;
    }
    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    port_t *ports = port_scan(ip, start_port, end_port);
    int i=0;
    for(i=0;i<(end_port-start_port+1);i++)
    {
        connect_port(&ports[i]);
    }
    free(ports);
    return 0;
}