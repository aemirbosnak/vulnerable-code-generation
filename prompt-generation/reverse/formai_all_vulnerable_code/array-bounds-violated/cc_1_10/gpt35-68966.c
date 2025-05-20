//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER "smtp.example.com"
#define PORT 25

// function to send data to the SMTP server
void send_data(int sock, const char* data)
{
    int bytes_sent = send(sock, data, strlen(data), 0);
    if (bytes_sent == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

int main()
{
    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // get server IP address
    struct hostent* hp = gethostbyname(SERVER);
    if (hp == NULL) {
        fprintf(stderr, "unknown host %s\n", SERVER);
        exit(EXIT_FAILURE);
    }

    struct in_addr** addr_list = (struct in_addr**) hp->h_addr_list;
    char* server_ip = inet_ntoa(*addr_list[0]);

    // setup server address structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    // connect to server
    if (connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // receive server greeting message
    char buffer[1024];
    int bytes_received = recv(sock, buffer, 1024, 0);
    if (bytes_received == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // send HELO message
    send_data(sock, "HELO example.com\r\n");
    bytes_received = recv(sock, buffer, 1024, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // send MAIL FROM message
    send_data(sock, "MAIL FROM: <sender@example.com>\r\n");
    bytes_received = recv(sock, buffer, 1024, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // send RCPT TO message
    send_data(sock, "RCPT TO: <recipient@example.com>\r\n");
    bytes_received = recv(sock, buffer, 1024, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // send DATA message
    send_data(sock, "DATA\r\n");
    bytes_received = recv(sock, buffer, 1024, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // send message body
    char* message_body = "Subject: Test SMTP Message\r\n\r\nThis is a test message sent via SMTP.\r\n.\r\n";
    send_data(sock, message_body);
    bytes_received = recv(sock, buffer, 1024, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // send QUIT message
    send_data(sock, "QUIT\r\n");
    bytes_received = recv(sock, buffer, 1024, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // close socket
    close(sock);

    return 0;
}