//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int main(){

    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[1024];
    //Create a socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    //Initialize the address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(21);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //Connect to the server
    connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    printf("Connected to server successfully!\n");

    //Read the response from the server
    read(clientSocket, buffer, 1024);
    printf("Server Response: %s\n", buffer);

    //Login credentials for FTP server
    char user[] = "USER ftp_username\r\n";
    char pass[] = "PASS ftp_password\r\n";

    //Send the login credentials to the server
    send(clientSocket, user, strlen(user), 0);
    read(clientSocket, buffer, 1024);
    printf("Server Response: %s\n", buffer);

    send(clientSocket, pass, strlen(pass), 0);
    read(clientSocket, buffer, 1024);
    printf("Server Response: %s\n", buffer);

    //Enter passive mode
    char pasv[] = "PASV\r\n";
    send(clientSocket, pasv, strlen(pasv), 0);

    //Read the server's response
    read(clientSocket, buffer, 1024);
    printf("Server Response: %s\n", buffer);

    //Extracting server address and port from PASV response
    int a1, a2, a3, a4, p1, p2;
    sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)", &a1, &a2, &a3, &a4, &p1, &p2);
    int port = (p1 * 256) + p2;

    //Creating a new socket
    int dataSocket = socket(AF_INET, SOCK_STREAM, 0);

    //Initializing the address for data connection
    struct sockaddr_in dataAddr;
    dataAddr.sin_family = AF_INET;
    dataAddr.sin_port = htons(port);
    char dataIP[20];
    sprintf(dataIP, "%d.%d.%d.%d", a1, a2, a3, a4);
    dataAddr.sin_addr.s_addr = inet_addr(dataIP);

    //Connect to the server using data socket
    connect(dataSocket, (struct sockaddr*)&dataAddr, sizeof(dataAddr));
    printf("Connected to server's data port successfully!\n");

    //List all the files in the current directory of the FTP server
    char list[] = "LIST\r\n";
    send(clientSocket, list, strlen(list), 0);

    //Read the response from the server
    read(clientSocket, buffer, 1024);
    printf("Server Response: %s\n", buffer);

    //Reading the list of file names
    read(dataSocket, buffer, 1024);
    printf("List of files:\n%s", buffer);

    //Close data socket and client socket
    close(dataSocket);
    close(clientSocket);
    printf("Connection closed successfully!\n");

    return 0;
}