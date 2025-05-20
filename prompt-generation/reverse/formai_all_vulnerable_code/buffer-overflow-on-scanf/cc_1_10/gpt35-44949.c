//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT_NO 21

typedef struct {
    char* username;
    char* password;
} LoginDetails;

LoginDetails* getLoginDetails() {
    LoginDetails* loginDetails = malloc(sizeof(LoginDetails));
    printf("Enter FTP username : ");
    scanf("%ms", &loginDetails->username);
    printf("Enter FTP password : ");
    scanf("%ms", &loginDetails->password);
    return loginDetails;
}

void displayMenu() {
    printf("\n******************* MENU *******************\n");
    printf("Please select one of the following options:\n");
    printf("1. List files in current directory\n");
    printf("2. Download a file\n");
    printf("3. Exit\n");
    printf("********************************************\n");
}

void connectToServer(int* controlSockFd, char* serverIP) {
    struct sockaddr_in serverAddr;
    *controlSockFd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serverAddr, 0, sizeof(struct sockaddr_in));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(serverIP);
    serverAddr.sin_port = htons(PORT_NO);
    if (connect(*controlSockFd, (struct sockaddr*) &serverAddr, sizeof(struct sockaddr_in)) == -1) {
        perror("Error connecting to FTP server");
        exit(-1);
    }
}

void login(int controlSockFd, LoginDetails* loginDetails) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    recv(controlSockFd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer);
    sprintf(buffer, "USER %s\r\n", loginDetails->username);
    send(controlSockFd, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(controlSockFd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer);
    sprintf(buffer, "PASS %s\r\n", loginDetails->password);
    send(controlSockFd, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(controlSockFd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer);
}

void executeCommand(int controlSockFd, char* command) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "%s\r\n", command);
    send(controlSockFd, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(controlSockFd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer);
}

void getDataConnection(int controlSockFd, int* dataSockFd, char* command) {
    int dataPort, h1, h2, h3, h4, p1, p2;
    char buffer[BUFFER_SIZE], response[BUFFER_SIZE];
    struct sockaddr_in dataAddr;
    executeCommand(controlSockFd, "PASV");
    sscanf(response, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)", &h1, &h2, &h3, &h4, &p1, &p2);
    dataPort = (p1 * 256) + p2;
    memset(&dataAddr, 0, sizeof(struct sockaddr_in));
    dataAddr.sin_family = AF_INET;
    dataAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    dataAddr.sin_port = htons(dataPort);
    *dataSockFd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(*dataSockFd, (struct sockaddr*) &dataAddr, sizeof(struct sockaddr_in)) == -1) {
        perror("Error connecting to FTP data channel");
        exit(-1);
    }
    executeCommand(controlSockFd, command);
}

void listFiles(int controlSockFd) {
    printf("Getting directory listing...\n");
    int dataSockFd;
    getDataConnection(controlSockFd, &dataSockFd, "LIST");
    char buffer[BUFFER_SIZE];
    int bytesRead;
    while ((bytesRead = recv(dataSockFd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytesRead] = '\0';
        printf("%s", buffer);
    }
    close(dataSockFd);
}

void downloadFile(int controlSockFd) {
    char filename[BUFFER_SIZE];
    printf("Enter filename to download : ");
    scanf("%s", filename);
    int dataSockFd;
    getDataConnection(controlSockFd, &dataSockFd, "RETR ");
    char buffer[BUFFER_SIZE];
    int bytesRead;
    FILE* file = fopen(filename, "wb");
    while ((bytesRead = recv(dataSockFd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        fwrite(buffer, sizeof(char), bytesRead, file);
    }
    printf("File downloaded successfully!\n");
    fclose(file);
    close(dataSockFd);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage : %s <FTP server IP address>\n", argv[0]);
        exit(-1);
    }
    int controlSockFd;
    LoginDetails* loginDetails = getLoginDetails();
    connectToServer(&controlSockFd, argv[1]);
    login(controlSockFd, loginDetails);
    char command[BUFFER_SIZE];
    while (1) {
        displayMenu();
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1:
                executeCommand(controlSockFd, "PWD");
                listFiles(controlSockFd);
                break;
            case 2:
                executeCommand(controlSockFd, "PWD");
                downloadFile(controlSockFd);
                break;
            case 3:
                printf("Exiting...");
                close(controlSockFd);
                exit(0);
                break;
            default:
                printf("Invalid option. Please choose again.");
        }
    }
    return 0;
}