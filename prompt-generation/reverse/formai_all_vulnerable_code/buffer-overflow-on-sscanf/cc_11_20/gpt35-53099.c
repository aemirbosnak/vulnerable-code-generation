//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
 
#define BUFFER_SIZE 1024
 
int ftpClient(char *filename, char *ftpServerIP, char *username, char *password);
 
int main()
{
    char *filename = "example.txt";
    char *ftpServerIP = "192.168.0.1";
    char *username = "anonymous";
    char *password = "password";
 
    int status = ftpClient(filename, ftpServerIP, username, password);
 
    if (status == 0)
    {
        printf("File transfer completed successfully.\n");
    }
    else
    {
        printf("File transfer failed.\n");
    }
 
    return 0;
}
 
int ftpClient(char *filename, char *ftpServerIP, char *username, char *password)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddr;
 
    if (sock < 0)
    {
        perror("Failed to create socket");
        return -1;
    }
 
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(21);
 
    if (inet_pton(AF_INET, ftpServerIP, &serverAddr.sin_addr) <= 0)
    {
        perror("Failed to convert IP address");
        return -1;
    }
 
    if (connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("Failed to connect to server");
        return -1;
    }
 
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("Failed to receive welcome message");
        return -1;
    }
 
    printf("%s", buffer);
 
    char user[100];
    sprintf(user, "USER %s\r\n", username);
    if (send(sock, user, strlen(user), 0) < 0)
    {
        perror("Failed to send USER name");
        return -1;
    }
 
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("Failed to receive USER response");
        return -1;
    }
 
    printf("%s", buffer);
 
    char pass[100];
    sprintf(pass, "PASS %s\r\n", password);
    if (send(sock, pass, strlen(pass), 0) < 0)
    {
        perror("Failed to send password");
        return -1;
    }
 
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("Failed to receive PASS response");
        return -1;
    }
 
    printf("%s", buffer);
 
    char type[100] = "TYPE I\r\n";
    if (send(sock, type, strlen(type), 0) < 0)
    {
        perror("Failed to set transfer type");
        return -1;
    }
 
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("Failed to receive TYPE response");
        return -1;
    }
 
    printf("%s", buffer);
 
    char pasv[100] = "PASV\r\n";
    if (send(sock, pasv, strlen(pasv), 0) < 0)
    {
        perror("Failed to enter passive mode");
        return -1;
    }
 
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("Failed to receive PASV response");
        return -1;
    }
 
    printf("%s", buffer);
 
    unsigned int a, b, c, d, port1, port2;
    sscanf(buffer, "227 Entering Passive Mode (%u,%u,%u,%u,%u,%u)\n", &a, &b, &c, &d, &port1, &port2);
 
    struct sockaddr_in dataAddr;
    memset(&dataAddr, 0, sizeof(dataAddr));
    dataAddr.sin_family = AF_INET;
    char dataServerIP[100];
    sprintf(dataServerIP, "%u.%u.%u.%u", a, b, c, d);
    inet_pton(AF_INET, dataServerIP, &dataAddr.sin_addr);
    dataAddr.sin_port = htons((port1 << 8) + port2);
 
    int dataSock = socket(AF_INET, SOCK_STREAM, 0);
    if (dataSock < 0)
    {
        perror("Failed to create data socket");
        return -1;
    }
 
    if (connect(dataSock, (struct sockaddr *)&dataAddr, sizeof(dataAddr)) < 0)
    {
        perror("Failed to connect to data server");
        return -1;
    }
 
    char retr[100];
    sprintf(retr, "RETR %s\r\n", filename);
    if (send(sock, retr, strlen(retr), 0) < 0)
    {
        perror("Failed to send RETR command");
        return -1;
    }
 
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("Failed to receive RETR response");
        return -1;
    }
 
    printf("%s", buffer);
 
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        perror("Failed to open file for writing");
        return -1;
    }
 
    while (1)
    {
        memset(buffer, 0, BUFFER_SIZE);
        int n = recv(dataSock, buffer, BUFFER_SIZE, 0);
        if (n < 0)
        {
            perror("Failed to receive file data");
            return -1;
        }
        else if (n == 0)
        {
            break;
        }
        else
        {
            fwrite(buffer, 1, n, fp);
        }
    }
 
    fclose(fp);
 
    shutdown(dataSock, SHUT_RDWR);
    close(dataSock);
 
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("Failed to receive RETR complete message");
        return -1;
    }
 
    printf("%s", buffer);
 
    char quit[100] = "QUIT\r\n";
    if (send(sock, quit, strlen(quit), 0) < 0)
    {
        perror("Failed to send QUIT");
        return -1;
    }
 
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("Failed to receive QUIT response");
        return -1;
    }
 
    printf("%s", buffer);
 
    shutdown(sock, SHUT_RDWR);
    close(sock);
 
    return 0;
}