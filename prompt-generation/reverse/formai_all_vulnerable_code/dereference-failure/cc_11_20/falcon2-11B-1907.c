//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 25
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, retval;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char recv_buf[BUF_SIZE];
    char send_buf[BUF_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: No such host\n");
        exit(1);
    }

    memset((char *)&serv_addr, '\0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    retval = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (retval < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("SMTP client: Connected to %s\n", argv[1]);

    send_buf[0] = 'E';
    send_buf[1] = 'H';
    send_buf[2] = 'O';
    send_buf[3] = 'L';
    send_buf[4] = 'A';
    send_buf[5] = '!';
    send_buf[6] = '\r';
    send_buf[7] = '\n';

    retval = write(sockfd, send_buf, strlen(send_buf));
    if (retval < 0) {
        perror("write failed");
        exit(1);
    }

    printf("SMTP client: Sending HELO command\n");

    memset(recv_buf, '\0', BUF_SIZE);
    retval = read(sockfd, recv_buf, BUF_SIZE);
    if (retval < 0) {
        perror("read failed");
        exit(1);
    }

    printf("SMTP client: Received %s\n", recv_buf);

    send_buf[0] = 'S';
    send_buf[1] = 'T';
    send_buf[2] = 'S';
    send_buf[3] = 'M';
    send_buf[4] = 'A';
    send_buf[5] = 'I';
    send_buf[6] = 'L';
    send_buf[7] = 'E';
    send_buf[8] = '!';
    send_buf[9] = '\r';
    send_buf[10] = '\n';

    retval = write(sockfd, send_buf, strlen(send_buf));
    if (retval < 0) {
        perror("write failed");
        exit(1);
    }

    printf("SMTP client: Sending MAIL FROM command\n");

    memset(recv_buf, '\0', BUF_SIZE);
    retval = read(sockfd, recv_buf, BUF_SIZE);
    if (retval < 0) {
        perror("read failed");
        exit(1);
    }

    printf("SMTP client: Received %s\n", recv_buf);

    send_buf[0] = 'R';
    send_buf[1] = 'C';
    send_buf[2] = 'C';
    send_buf[3] = 'E';
    send_buf[4] = 'I';
    send_buf[5] = 'V';
    send_buf[6] = 'E';
    send_buf[7] = 'D';
    send_buf[8] = '!';
    send_buf[9] = '\r';
    send_buf[10] = '\n';

    retval = write(sockfd, send_buf, strlen(send_buf));
    if (retval < 0) {
        perror("write failed");
        exit(1);
    }

    printf("SMTP client: Sending RCPT TO command\n");

    memset(recv_buf, '\0', BUF_SIZE);
    retval = read(sockfd, recv_buf, BUF_SIZE);
    if (retval < 0) {
        perror("read failed");
        exit(1);
    }

    printf("SMTP client: Received %s\n", recv_buf);

    send_buf[0] = 'D';
    send_buf[1] = 'A';
    send_buf[2] = 'T';
    send_buf[3] = 'A';
    send_buf[4] = '!';
    send_buf[5] = '\r';
    send_buf[6] = '\n';

    retval = write(sockfd, send_buf, strlen(send_buf));
    if (retval < 0) {
        perror("write failed");
        exit(1);
    }

    printf("SMTP client: Sending DATA command\n");

    memset(recv_buf, '\0', BUF_SIZE);
    retval = read(sockfd, recv_buf, BUF_SIZE);
    if (retval < 0) {
        perror("read failed");
        exit(1);
    }

    printf("SMTP client: Received %s\n", recv_buf);

    send_buf[0] = 'C';
    send_buf[1] = 'O';
    send_buf[2] = 'M';
    send_buf[3] = 'M';
    send_buf[4] = 'A';
    send_buf[5] = 'N';
    send_buf[6] = '!';
    send_buf[7] = '\r';
    send_buf[8] = '\n';

    retval = write(sockfd, send_buf, strlen(send_buf));
    if (retval < 0) {
        perror("write failed");
        exit(1);
    }

    printf("SMTP client: Sending command\n");

    send_buf[0] = 'T';
    send_buf[1] = 'H';
    send_buf[2] = 'E';
    send_buf[3] = 'R';
    send_buf[4] = 'A';
    send_buf[5] = 'T';
    send_buf[6] = 'O';
    send_buf[7] = 'R';
    send_buf[8] = '!';
    send_buf[9] = '\r';
    send_buf[10] = '\n';

    retval = write(sockfd, send_buf, strlen(send_buf));
    if (retval < 0) {
        perror("write failed");
        exit(1);
    }

    printf("SMTP client: Sending message\n");

    send_buf[0] = 'M';
    send_buf[1] = 'S';
    send_buf[2] = 'G';
    send_buf[3] = 'I';
    send_buf[4] = 'N';
    send_buf[5] = '!';
    send_buf[6] = '\r';
    send_buf[7] = '\n';
    send_buf[8] = 'A';
    send_buf[9] = 'B';
    send_buf[10] = 'C';
    send_buf[11] = 'C';
    send_buf[12] = 'D';
    send_buf[13] = 'E';
    send_buf[14] = 'F';
    send_buf[15] = 'G';
    send_buf[16] = '!';
    send_buf[17] = '\r';
    send_buf[18] = '\n';

    retval = write(sockfd, send_buf, strlen(send_buf));
    if (retval < 0) {
        perror("write failed");
        exit(1);
    }

    printf("SMTP client: Message sent\n");

    send_buf[0] = 'Q';
    send_buf[1] = 'U';
    send_buf[2] = 'I';
    send_buf[3] = 'T';
    send_buf[4] = '!';
    send_buf[5] = '\r';
    send_buf[6] = '\n';

    retval = write(sockfd, send_buf, strlen(send_buf));
    if (retval < 0) {
        perror("write failed");
        exit(1);
    }

    printf("SMTP client: Sending QUIT command\n");

    close(sockfd);
    return 0;
}