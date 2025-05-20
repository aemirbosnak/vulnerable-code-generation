//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int create_data_socket(int s) {
    int port;
    char buffer[BUFFER_SIZE];
    int bytes_recv = 0;
    struct sockaddr_in sin;
    int s_data;

   // Send the PASV command to the FTP server
    send(s, "PASV\r\n", 6, 0);
    bytes_recv = recv(s, buffer, BUFFER_SIZE, 0);
    buffer[bytes_recv] = '\0';

    // Parse the port number from the server's response
    char *start, *end;
    start = strchr(buffer, '(') + 1;
    end = strchr(buffer, ')');
    *end = '\0';

    int a, b, c, d;
    sscanf(start, "%d,%d,%d,%d,%d,%d", &a, &b, &c, &d, &port, &port);

    // Open the data socket
    s_data = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port * 256 + port);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect the data socket to the server
    if (connect(s_data, (struct sockaddr *)&sin, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    return s_data;
}

int main(int argc, char *argv[]) {
    // Check for command line arguments
    if (argc != 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        exit(1);
    }

    int s;
    struct sockaddr_in sin;
    char buffer[BUFFER_SIZE];
    int bytes_recv = 0;
    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    int s_data;

    // Create a socket
    if ((s = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the address struct
    memset((char *)&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(server);
    sin.sin_port = htons(21);

    // Connect to the server
    if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) == -1) {
        perror("connect");
        exit(1);
    }

    // Login with the given username and password
    sprintf(buffer, "USER %s\r\n", username);
    send(s, buffer, strlen(buffer), 0);

    bytes_recv = recv(s, buffer, BUFFER_SIZE, 0);
    buffer[bytes_recv] = '\0';

    sprintf(buffer, "PASS %s\r\n", password);
    send(s, buffer, strlen(buffer), 0);

    bytes_recv = recv(s, buffer, BUFFER_SIZE, 0);
    buffer[bytes_recv] = '\0';

    // Switch to binary file transfer mode
    send(s, "TYPE I\r\n", 8, 0);
    bytes_recv = recv(s, buffer, BUFFER_SIZE, 0);
    buffer[bytes_recv] = '\0';

    // Enter passive mode and get the data socket
    s_data = create_data_socket(s);

    // Download a file
    send(s, "RETR sample.txt\r\n", 17, 0);
    bytes_recv = recv(s, buffer, BUFFER_SIZE, 0);
    buffer[bytes_recv] = '\0';

    FILE *file;
    file = fopen("sample.txt", "wb");

    while ((bytes_recv = recv(s_data, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, bytes_recv, 1, file);
    }

    fclose(file);
    close(s_data);

    // Quit the FTP session
    send(s, "QUIT\r\n", 6, 0);
    bytes_recv = recv(s, buffer, BUFFER_SIZE, 0);
    buffer[bytes_recv] = '\0';

    // Close the control socket
    close(s);

    return 0;
}