//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFSIZE 1024

int main(int argc, char *argv[]) {
    // Step 1: Parse command-line arguments
    if (argc != 3) {
        printf("Usage: %s <server_address> <server_port>\n", argv[0]);
        exit(1);
    }
    char *server_address = argv[1];
    int server_port = atoi(argv[2]);

    // Step 2: Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    // Step 3: Connect to server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_address);
    server_addr.sin_port = htons(server_port);
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    // Step 4: Read welcome message from server
    char welcome_msg[BUFFSIZE];
    int num_bytes = recv(sockfd, welcome_msg, BUFFSIZE, 0);
    if (num_bytes < 0) {
        perror("Failed to read from socket");
        exit(1);
    }
    welcome_msg[num_bytes] = '\0';
    printf("%s", welcome_msg);

    // Step 5: Login with username and password
    char username[BUFFSIZE], password[BUFFSIZE];
    printf("Username: ");
    fgets(username, BUFFSIZE, stdin);
    printf("Password: ");
    fgets(password, BUFFSIZE, stdin);
    char login_msg[BUFFSIZE];
    sprintf(login_msg, "USER %sPASS %s", username, password);
    num_bytes = send(sockfd, login_msg, strlen(login_msg), 0);
    if (num_bytes < 0) {
        perror("Failed to write to socket");
        exit(1);
    }

    // Step 6: Receive response from server for login
    char login_resp[BUFFSIZE];
    num_bytes = recv(sockfd, login_resp, BUFFSIZE, 0);
    if (num_bytes < 0) {
        perror("Failed to read from socket");
        exit(1);
    }
    login_resp[num_bytes] = '\0';
    printf("%s", login_resp);

    // Step 7: Enter passive mode
    char pasv_cmd[] = "PASV\r\n";
    num_bytes = send(sockfd, pasv_cmd, strlen(pasv_cmd), 0);
    if (num_bytes < 0) {
        perror("Failed to write to socket");
        exit(1);
    }

    // Step 8: Read response from server for passive mode
    char pasv_resp[BUFFSIZE];
    num_bytes = recv(sockfd, pasv_resp, BUFFSIZE, 0);
    if (num_bytes < 0) {
        perror("Failed to read from socket");
        exit(1);
    }
    pasv_resp[num_bytes] = '\0';
    printf("%s", pasv_resp);

    // Step 9: Parse passive mode response to get IP address and port number
    char *start_ip = strchr(pasv_resp, '(') + 1;
    char *end_ip = strchr(start_ip, ',');
    char ip_str[BUFFSIZE];
    strncpy(ip_str, start_ip, end_ip - start_ip);
    ip_str[end_ip - start_ip] = '\0';
    char *port_str = end_ip + 1;
    for (int i = 0; i < 3; i++) {
        port_str = strchr(port_str, ',') + 1;
    }
    int port_num_1 = atoi(port_str);
    port_str = strchr(port_str, ',') + 1;
    int port_num_2 = atoi(port_str);
    int data_port = port_num_1 * 256 + port_num_2;

    // Step 10: Create data socket and connect to server
    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0) {
        perror("Failed to create socket");
        exit(1);
    }
    struct hostent *he = gethostbyname(server_address);
    struct in_addr **addr_list = (struct in_addr **) he->h_addr_list;
    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = inet_addr(inet_ntoa(*addr_list[0]));
    data_addr.sin_port = htons(data_port);
    if (connect(data_sockfd, (struct sockaddr *) &data_addr, sizeof(data_addr)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    // Step 11: Send list command to server
    char list_cmd[] = "LIST\r\n";
    num_bytes = send(sockfd, list_cmd, strlen(list_cmd), 0);
    if (num_bytes < 0) {
        perror("Failed to write to socket");
        exit(1);
    }

    // Step 12: Read response from server for list command
    char list_resp[BUFFSIZE];
    num_bytes = recv(sockfd, list_resp, BUFFSIZE, 0);
    if (num_bytes < 0) {
        perror("Failed to read from socket");
        exit(1);
    }
    list_resp[num_bytes] = '\0';
    printf("%s", list_resp);

    // Step 13: Read list data from data socket
    char data_buff[BUFFSIZE];
    num_bytes = recv(data_sockfd, data_buff, BUFFSIZE, 0);
    if (num_bytes < 0) {
        perror("Failed to read from socket");
        exit(1);
    }
    data_buff[num_bytes] = '\0';
    printf("%s", data_buff);

    // Step 14: Close data socket
    close(data_sockfd);

    // Step 15: Read response from server for list command
    num_bytes = recv(sockfd, list_resp, BUFFSIZE, 0);
    if (num_bytes < 0) {
        perror("Failed to read from socket");
        exit(1);
    }
    list_resp[num_bytes] = '\0';
    printf("%s", list_resp);

    // Step 16: Enter quit command
    char quit_cmd[] = "QUIT\r\n";
    num_bytes = send(sockfd, quit_cmd, strlen(quit_cmd), 0);
    if (num_bytes < 0) {
        perror("Failed to write to socket");
        exit(1);
    }

    // Step 17: Read response from server for quit command
    char quit_resp[BUFFSIZE];
    num_bytes = recv(sockfd, quit_resp, BUFFSIZE, 0);
    if (num_bytes < 0) {
        perror("Failed to read from socket");
        exit(1);
    }
    quit_resp[num_bytes] = '\0';
    printf("%s", quit_resp);

    // Step 18: Close socket
    close(sockfd);

    return 0;
}