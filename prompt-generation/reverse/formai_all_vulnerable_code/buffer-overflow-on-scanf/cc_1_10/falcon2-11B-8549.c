//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/wait.h>

// Function to send email
void send_email(char* email_addr, char* subject, char* body) {
    struct addrinfo hints, *servinfo, *p;
    int status;
    int sockfd;
    int n;
    char buffer[2048];
    char* message = "Subject: ";
    char* body_msg = "\r\n\r\n";
    char* subject_msg = subject;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    // Resolve the server address and port
    status = getaddrinfo(email_addr, "smtp", &hints, &servinfo);
    if (status!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }
        break;
    }

    if (p == NULL || sockfd == -1) {
        fprintf(stderr, "Failed to create socket\n");
        exit(1);
    }

    n = connect(sockfd, p->ai_addr, p->ai_addrlen);
    if (n == -1) {
        close(sockfd);
        fprintf(stderr, "Connect failed\n");
        exit(1);
    }

    n = write(sockfd, subject_msg, strlen(subject_msg));
    if (n == -1) {
        close(sockfd);
        fprintf(stderr, "Failed to write to socket\n");
        exit(1);
    }

    n = write(sockfd, body_msg, strlen(body_msg));
    if (n == -1) {
        close(sockfd);
        fprintf(stderr, "Failed to write to socket\n");
        exit(1);
    }

    n = write(sockfd, buffer, strlen(buffer));
    if (n == -1) {
        close(sockfd);
        fprintf(stderr, "Failed to write to socket\n");
        exit(1);
    }

    close(sockfd);
}

// Function to receive email
void receive_email(char* email_addr) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent* server;
    char buffer[2048];
    char* line = NULL;
    size_t len = 0;
    ssize_t n;

    if ((server = gethostbyname(email_addr)) == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char*)&serv_addr.sin_addr.s_addr, (char*)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(25);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Failed to create socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        fprintf(stderr, "Connect failed\n");
        exit(1);
    }

    while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
        line = strsep(&buffer, "\r\n");
        if (line!= NULL) {
            printf("%s", line);
        }
    }

    close(sockfd);
}

int main() {
    char email_addr[256];
    char subject[256];
    char body[4096];

    printf("Enter email address: ");
    scanf("%s", email_addr);

    printf("Enter subject: ");
    scanf("%s", subject);

    printf("Enter body: ");
    scanf("%s", body);

    send_email(email_addr, subject, body);

    receive_email(email_addr);

    return 0;
}