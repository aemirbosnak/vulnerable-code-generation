//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: energetic
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#define BUF_SIZE 4096

void error_handling(const char * message);

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char buf[BUF_SIZE+1];

    if(argc!=3) {
        printf("Usage : %s <IP> <PORT>\n", argv[0]);
        return 1;
    }

    sock=socket(PF_INET, SOCK_STREAM, 0);
    if(sock==-1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
    serv_addr.sin_port=htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
        error_handling("connect() error!");

    sprintf(buf, "USER anonymous\r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUF_SIZE, 0);
    printf("[RECV] %s", buf);

    sprintf(buf, "PASS \r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUF_SIZE, 0);
    printf("[RECV] %s", buf);

    sprintf(buf, "PASV\r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUF_SIZE, 0);
    printf("[RECV] %s", buf);

    int h1, h2, h3, h4, p1, p2;
    sscanf(strchr(strchr(strchr(buf, '(')+1, '(')+1, '(')+1,
            "%d,%d,%d,%d,%d,%d", &h1, &h2, &h3, &h4, &p1, &p2);
    sprintf(buf, "TYPE I\r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUF_SIZE, 0);
    printf("[RECV] %s", buf);

    sprintf(buf, "RETR index.html\r\n");
    send(sock, buf, strlen(buf), 0);

    int data_sock;
    data_sock=socket(PF_INET, SOCK_STREAM, 0);
    if(data_sock==-1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=htonl((h1<<24)+(h2<<16)+(h3<<8)+h4);
    serv_addr.sin_port=htons((p1<<8)+p2);

    if(connect(data_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
        error_handling("connect() error!");

    while(1) {
        int length=recv(data_sock, buf, BUF_SIZE, 0);
        if(length<=0) break;
        buf[length]=0;
        printf("%s", buf);
    }

    close(data_sock);
    close(sock);
    return 0;
}

void error_handling(const char * message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}