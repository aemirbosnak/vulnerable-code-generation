//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int ftp_connect(char*, char*);
int ftp_login(int, char*, char*);
int ftp_close(int);
int ftp_retr(int, char*, char*);
int ftp_list(int, char*);
void ftp_quit(int);

int ftp_connect(char* server, char* port)
{
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(port));

    inet_pton(AF_INET, server, &servaddr.sin_addr);

    connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr));

    return sockfd;
}

int ftp_login(int sockfd, char* username, char* password)
{
    char buffer[1024];

    recv(sockfd, buffer, sizeof(buffer), 0);

    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    if(buffer[0] == '5')
    {
        printf("Login failed!\n");
        return -1;
    }

    printf("Login successful!\n");

    return 0;
}

int ftp_close(int sockfd)
{
    char buffer[1024];

    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    close(sockfd);

    return 0;
}

int ftp_retr(int sockfd, char* remote_file, char* local_file)
{
    char buffer[1024];
    FILE* f;
    int nbytes;

    sprintf(buffer, "TYPE I\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    sprintf(buffer, "SIZE %s\r\n", remote_file);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    if(buffer[0] == '5')
    {
        printf("File does not exist!\n");
        return -1;
    }

    sscanf(buffer, "%d", &nbytes);

    sprintf(buffer, "RETR %s\r\n", remote_file);
    send(sockfd, buffer, strlen(buffer), 0);

    f = fopen(local_file, "w");
    if(f == NULL)
    {
        printf("Could not save file locally!\n");
        return -1;
    }

    while(nbytes > 0)
    {
        nbytes -= recv(sockfd, buffer, sizeof(buffer), 0);
        fwrite(buffer, 1, sizeof(buffer), f);
    }

    fclose(f);

    return 0;
}

int ftp_list(int sockfd, char* directory)
{
    char buffer[1024];
    int nbytes;

    sprintf(buffer, "LIST %s\r\n", directory);
    send(sockfd, buffer, strlen(buffer), 0);

    nbytes = recv(sockfd, buffer, sizeof(buffer), 0);

    while(nbytes > 0)
    {
        fwrite(buffer, 1, nbytes, stdout);
        nbytes = recv(sockfd, buffer, sizeof(buffer), 0);
    }

    return 0;
}

void ftp_quit(int sockfd)
{
    ftp_close(sockfd);
}


int main(void)
{
    char* server = "ftp.server.com";
    char* port = "21";
    char* username = "user";
    char* password = "password";
    char* remote_file = "/path/to/remote/file";
    char* local_file = "local_file.dat";
    char* directory = "/path/to/remote/directory";

    int sockfd;

    sockfd = ftp_connect(server, port);

    ftp_login(sockfd, username, password);

    ftp_retr(sockfd, remote_file, local_file);

    ftp_list(sockfd, directory);

    ftp_quit(sockfd);

    return 0;
}