//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char file_name[BUF_SIZE];
    char file_data[BUF_SIZE];
    int file_size;
    
    // Create socket
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("socket() failed");
        exit(1);
    }
    
    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(21);
    
    // Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        exit(1);
    }
    
    // Read welcome message
    char welcome[BUF_SIZE];
    recv(sock, welcome, BUF_SIZE-1, 0);
    printf("%s\n", welcome);
    
    // Send user name
    char user[BUF_SIZE];
    sprintf(user, "USER %s\r\n", "username");
    send(sock, user, strlen(user), 0);
    recv(sock, file_data, BUF_SIZE-1, 0);
    printf("%s\n", file_data);
    
    // Send password
    char pass[BUF_SIZE];
    sprintf(pass, "PASS %s\r\n", "password");
    send(sock, pass, strlen(pass), 0);
    recv(sock, file_data, BUF_SIZE-1, 0);
    printf("%s\n", file_data);
    
    // Send binary mode
    char binary[BUF_SIZE];
    sprintf(binary, "TYPE %s\r\n", "I");
    send(sock, binary, strlen(binary), 0);
    recv(sock, file_data, BUF_SIZE-1, 0);
    printf("%s\n", file_data);
    
    // Enter passive mode
    char pasv[BUF_SIZE];
    sprintf(pasv, "PASV\r\n");
    send(sock, pasv, strlen(pasv), 0);
    recv(sock, file_data, BUF_SIZE-1, 0);
    printf("%s\n", file_data);
    
    // Parse IP and port from passive mode response
    char *ptr = strstr(file_data, "(");
    ptr++;
    int nums[6];
    sscanf(ptr, "%d,%d,%d,%d,%d,%d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4], &nums[5]);
    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    char data_ip[BUF_SIZE];
    sprintf(data_ip, "%d.%d.%d.%d", nums[0], nums[1], nums[2], nums[3]);
    data_addr.sin_addr.s_addr = inet_addr(data_ip);
    int data_port = nums[4]*256 + nums[5];
    data_addr.sin_port = htons(data_port);
    
    // Connect to data socket
    int data_sock;
    if ((data_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("socket() failed");
        exit(1);
    }
    if (connect(data_sock, (struct sockaddr*)&data_addr, sizeof(data_addr)) < 0) {
        perror("connect() failed");
        exit(1);
    }
    
    // Get file size
    sprintf(file_name, "SIZE %s\r\n", "filename");
    send(sock, file_name, strlen(file_name), 0);
    recv(sock, file_data, BUF_SIZE-1, 0);
    printf("%s\n", file_data);
    sscanf(file_data, "%d %s", &file_size, file_data);
    printf("File size: %d\n", file_size);
    
    // Retrieve file
    sprintf(file_name, "RETR %s\r\n", "filename");
    send(sock, file_name, strlen(file_name), 0);
    recv(sock, file_data, BUF_SIZE-1, 0);
    printf("%s\n", file_data);
    
    // Receive file content
    int received = 0;
    int file = open("filename", O_WRONLY|O_CREAT, 0644);
    while (received < file_size) {
        int to_receive = file_size - received;
        if (to_receive > BUF_SIZE) {
            to_receive = BUF_SIZE;
        }
        int bytes_received = recv(data_sock, file_data, to_receive, 0);
        if (bytes_received <= 0) {
            break;
        }
        write(file, file_data, bytes_received);
        received += bytes_received;
    }
    close(file);
    close(data_sock);
    
    // Quit
    char quit[BUF_SIZE];
    sprintf(quit, "QUIT\r\n");
    send(sock, quit, strlen(quit), 0);
    recv(sock, file_data, BUF_SIZE-1, 0);
    printf("%s\n", file_data);
    
    close(sock);
    return 0;
}