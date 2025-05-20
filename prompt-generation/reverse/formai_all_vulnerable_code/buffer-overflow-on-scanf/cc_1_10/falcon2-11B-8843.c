//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to establish an FTP connection
int connect_ftp_server(char *host, char *username, char *password) {
    int sockfd, portno;
    struct sockaddr_in server_addr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        return -1;
    }

    // Convert host and port to network representation
    portno = 21;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portno);
    server_addr.sin_addr.s_addr = inet_addr(host);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        return -1;
    }

    // Send username and password
    char buf[1024];
    sprintf(buf, "USER %s\r\n", username);
    write(sockfd, buf, strlen(buf));
    sprintf(buf, "PASS %s\r\n", password);
    write(sockfd, buf, strlen(buf));

    // Send command to retrieve file
    sprintf(buf, "RETR %s\r\n", "index.html");
    write(sockfd, buf, strlen(buf));

    return sockfd;
}

// Function to retrieve a file from the FTP server
int retrieve_file(int sockfd, char *filename) {
    int n;
    char buf[1024];

    // Send command to retrieve file
    sprintf(buf, "RETR %s\r\n", filename);
    write(sockfd, buf, strlen(buf));

    // Read response from server
    while ((n = read(sockfd, buf, 1024)) > 0) {
        printf("%s", buf);
        buf[n] = '\0';
    }

    // Close the connection
    close(sockfd);
    return 0;
}

int main() {
    char host[100];
    char username[100];
    char password[100];
    char filename[100];

    // Get host, username, password, and filename from user
    printf("Enter host: ");
    scanf("%s", host);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    printf("Enter filename: ");
    scanf("%s", filename);

    // Connect to FTP server
    int sockfd = connect_ftp_server(host, username, password);
    if (sockfd < 0) {
        printf("Error connecting to FTP server\n");
        return -1;
    }

    // Retrieve file from server
    retrieve_file(sockfd, filename);

    return 0;
}