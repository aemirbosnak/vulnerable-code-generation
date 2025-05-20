//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: synchronous
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<errno.h>

#define USERNAME "Username" //insert username credentials here
#define PASSWORD "Password" //insert password credentials here

int authenticate(int auth_socket);

int main(void)
{
    int control_socket;
    struct hostent *he;
    struct sockaddr_in server_addr;
    char url[100];
    char buffer[1024];
    int bytes_received;

    printf("Enter the FTP server URL: ");
    scanf("%s", url);

    he = gethostbyname(url);

    if(he == NULL)
    {
        printf("Error: Invalid URL\n");
        exit(1);
    }

    control_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(control_socket == -1)
    {
        perror("Error: Could not create socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(server_addr.sin_zero),'\0', 8);

    if(connect(control_socket, (struct sockaddr *)&server_addr, sizeof(struct sockaddr))==-1)
    {
        perror("Error: Could not connect to server");
        exit(1);
    }

    bytes_received = recv(control_socket, buffer, 1024, 0);

    if(bytes_received == -1)
    {
        perror("Error: Error receiving data from server");
        exit(1);
    }

    buffer[bytes_received] = '\0';

    printf("%s",buffer);

    if(authenticate(control_socket) == 0)
    {
        perror("Error: Authentication failed");
        exit(1);
    }

    close(control_socket);
    printf("Connection closed.\n");
    return 0;
}

int authenticate(int auth_socket)
{
    char buffer[1024];
    int bytes_received;

    bytes_received = recv(auth_socket, buffer, 1024, 0);

    if(bytes_received == -1)
    {
        perror("Error: Error receiving data from server");
        exit(1);
    }

    buffer[bytes_received] = '\0';

    printf("%s",buffer);

    send(auth_socket, USERNAME, strlen(USERNAME), 0);
    send(auth_socket, "\r\n", 2, 0);

    bytes_received = recv(auth_socket, buffer, 1024, 0);

    if(bytes_received == -1)
    {
        perror("Error: Error receiving data from server");
        exit(1);
    }

    buffer[bytes_received] = '\0';

    printf("%s",buffer);

    send(auth_socket, PASSWORD, strlen(PASSWORD), 0);
    send(auth_socket, "\r\n", 2, 0);

    bytes_received = recv(auth_socket, buffer, 1024, 0);

    if(bytes_received == -1)
    {
        perror("Error: Error receiving data from server");
        exit(1);
    }

    buffer[bytes_received] = '\0';

    if(strstr(buffer, "230") == NULL)
        return 0;

    printf("Authentication successful!\n");

    return 1;
}