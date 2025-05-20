//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int mtu = 1500;
    char hostname[100] = "smtp.gmail.com";
    char username[100] = "example@gmail.com";
    char password[100] = "mypassword";
    char from[100] = "example@gmail.com";
    char to[100] = "recipient@gmail.com";
    char subject[100] = "Testing SMTP Client";
    char message[1000] = "This is a test message.";

    // Convert hostname to IP address
    struct hostent *he;
    struct in_addr **addr_list;
    if((he = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        return 1;
    }
    addr_list = (struct in_addr **) he->h_addr_list;
    if(addr_list[0] == NULL) {
        perror("hostname resolution error");
        return 1;
    }
    char ip[16];
    inet_ntop(AF_INET, addr_list[0], ip, sizeof(ip));
    printf("Resolved %s to IP address: %s\n", hostname, ip);

    // Connect to SMTP server
    int sockfd;
    struct sockaddr_in serv_addr;
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(587);
    if(inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }
    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 1;
    }

    char buffer[1024];
    int bytes_received;

    // Receive greeting message
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send EHLO command
    char ehlo[100];
    sprintf(ehlo, "EHLO %s\r\n", hostname);
    send(sockfd, ehlo, strlen(ehlo), 0);

    // Receive response to EHLO command
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send AUTH LOGIN command
    send(sockfd, "AUTH LOGIN\r\n", 12, 0);

    // Receive response to AUTH LOGIN command
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send username
    char encoded_uname[100];
    memset(encoded_uname, 0, sizeof(encoded_uname));
    int encoded_len = b64_encode(username, encoded_uname);
    encoded_uname[encoded_len] = '\0';
    send(sockfd, encoded_uname, strlen(encoded_uname), 0);
    send(sockfd, "\r\n", 2, 0);

    // Receive response to username
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send password
    char encoded_pwd[100];
    memset(encoded_pwd, 0, sizeof(encoded_pwd));
    encoded_len = b64_encode(password, encoded_pwd);
    encoded_pwd[encoded_len] = '\0';
    send(sockfd, encoded_pwd, strlen(encoded_pwd), 0);
    send(sockfd, "\r\n", 2, 0);

    // Receive response to password
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send MAIL FROM command
    char mail_from[100];
    sprintf(mail_from, "MAIL FROM:<%s>\r\n", from);
    send(sockfd, mail_from, strlen(mail_from), 0);

    // Receive response to MAIL FROM command
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send RCPT TO command
    char rcpt_to[100];
    sprintf(rcpt_to, "RCPT TO:<%s>\r\n", to);
    send(sockfd, rcpt_to, strlen(rcpt_to), 0);

    // Receive response to RCPT TO command
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send DATA command
    send(sockfd, "DATA\r\n", 6, 0);

    // Receive response to DATA command
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send message headers
    char headers[1024];
    sprintf(headers, "From: %s\r\nTo: %s\r\nSubject: %s\r\nMIME-Version: 1.0\r\nContent-Type: text/plain; charset=utf-8\r\nContent-Transfer-Encoding: base64\r\n\r\n", from, to, subject);
    send(sockfd, headers, strlen(headers), 0);

    // Send message body
    char encoded_msg[2000];
    memset(encoded_msg, 0, sizeof(encoded_msg));
    encoded_len = b64_encode(message, encoded_msg);
    encoded_msg[encoded_len] = '\0';
    send(sockfd, encoded_msg, strlen(encoded_msg), 0);

    // Send data termination sequence and receive response
    send(sockfd, "\r\n.\r\n", 5, 0);
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send QUIT command
    send(sockfd, "QUIT\r\n", 6, 0);

    // Receive response to QUIT command
    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}

int b64_encode(const char *input, char *output) {
    const char *b64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int input_len = strlen(input);
    int output_len = 4 * ((input_len + 2) / 3);
    int i, j;

    for(i = 0, j = 0; i < input_len; i += 3, j += 4) {
        uint32_t octet_a = i < input_len ? (unsigned char) input[i] : 0;
        uint32_t octet_b = i + 1 < input_len ? (unsigned char) input[i + 1] : 0;
        uint32_t octet_c = i + 2 < input_len ? (unsigned char) input[i + 2] : 0;

        uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

        output[j + 0] = b64_chars[(triple >> 3 * 6) & 0x3F];
        output[j + 1] = b64_chars[(triple >> 2 * 6) & 0x3F];
        output[j + 2] = b64_chars[(triple >> 1 * 6) & 0x3F];
        output[j + 3] = b64_chars[(triple >> 0 * 6) & 0x3F];
    }

    int padding = input_len % 3;
    if(padding > 0) {
        for(i = 0; i < 3 - padding; i++) {
            output[output_len - 1 - i] = '=';
        }
    }

    return output_len;
}