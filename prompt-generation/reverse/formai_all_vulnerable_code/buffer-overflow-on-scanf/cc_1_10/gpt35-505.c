//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER 2048
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_EMAIL_FOLDER_NAME_LENGTH 50
#define MAX_EMAIL_UID_LENGTH 50

/* Function to read user input */
void readInput(char* input) {
    printf("> ");
    fgets(input, MAX_BUFFER, stdin);
    // Replace newline character with null character
    input[strcspn(input, "\n")] = '\0';
}

/* Function to connect to IMAP server */
int connectToServer(char* serverHost, int serverPort) {
    int sock = 0;
    struct sockaddr_in serverAddr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serverAddr, '0', sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);

    if (inet_pton(AF_INET, serverHost, &serverAddr.sin_addr) <= 0) {
        printf("\n Invalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        printf("\n Connection Failed \n");
        return -1;
    }

    return sock;
}

/* Function to login to IMAP server */
int login(int sock, char* username, char* password) {
    char buffer[MAX_BUFFER];

    // Receive server greeting
    recv(sock, buffer, MAX_BUFFER, 0);

    // Send login command
    sprintf(buffer, "LOGIN %s %s\r\n", username, password);
    send(sock, buffer, strlen(buffer), 0);

    // Receive server response
    recv(sock, buffer, MAX_BUFFER, 0);

    if (strstr(buffer, "OK") != NULL) {
        return 1;
    } else {
        return 0;
    }
}

/* Function to select email folder */
int selectFolder(int sock, char* folderName) {
    char buffer[MAX_BUFFER];

    // Send select command
    sprintf(buffer, "SELECT \"%s\"\r\n", folderName);
    send(sock, buffer, strlen(buffer), 0);

    // Receive server response
    recv(sock, buffer, MAX_BUFFER, 0);

    if (strstr(buffer, "OK") != NULL) {
        return 1;
    } else {
        return 0;
    }
}

/* Function to fetch email */
void fetchEmail(int sock, char* uid) {
    char buffer[MAX_BUFFER];

    // Send fetch command
    sprintf(buffer, "FETCH %s BODY[TEXT]\r\n", uid);
    send(sock, buffer, strlen(buffer), 0);

    // Receive server response
    recv(sock, buffer, MAX_BUFFER, 0);

    // Parse email content
    char* emailStartPtr = strstr(buffer, "Content-Type: text/plain;");
    printf("%s\n", emailStartPtr);
}

/* Function to list email folders */
void listFolders(int sock) {
    char buffer[MAX_BUFFER];

    // Send list command
    sprintf(buffer, "LIST \"\" \"*\"\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Receive server response
    recv(sock, buffer, MAX_BUFFER, 0);

    // Parse folder names
    char* folderNameStartPtr = strstr(buffer, "\"/\"");
    while (folderNameStartPtr != NULL) {
        char* folderNameEndPtr = strchr(folderNameStartPtr+1, '\"');
        char folderName[MAX_EMAIL_FOLDER_NAME_LENGTH];
        strncpy(folderName, folderNameStartPtr+2, folderNameEndPtr-folderNameStartPtr-2);
        folderName[folderNameEndPtr-folderNameStartPtr-2] = '\0';
        printf("%s\n", folderName);
        folderNameStartPtr = strstr(folderNameEndPtr+1, "\"/\"");
    }
}

int main() {
    char serverHost[MAX_BUFFER];
    int serverPort;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter server host: ");
    readInput(serverHost);

    printf("Enter server port: ");
    scanf("%d", &serverPort);

    printf("Enter username: ");
    readInput(username);

    printf("Enter password: ");
    readInput(password);

    // Connect to server
    int sock = connectToServer(serverHost, serverPort);
    if (sock == -1) {
        exit(EXIT_FAILURE);
    }

    // Login to server
    if (!login(sock, username, password)) {
        printf("Login failed\n");
        exit(EXIT_FAILURE);
    }

    // List email folders
    listFolders(sock);

    char folderName[MAX_EMAIL_FOLDER_NAME_LENGTH];
    printf("Enter folder name: ");
    readInput(folderName);

    // Select email folder
    if (!selectFolder(sock, folderName)) {
        printf("Folder selection failed\n");
        exit(EXIT_FAILURE);
    }

    char uid[MAX_EMAIL_UID_LENGTH];
    printf("Enter email UID: ");
    readInput(uid);

    // Fetch email
    fetchEmail(sock, uid);

    return 0;
}