//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFERSIZE 4096
#define MAX_MAILS 100

int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi(argv[2]));
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

    if(connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buffer[BUFFERSIZE];

    while(1) {
        memset(buffer, 0, BUFFERSIZE);
        if(recv(sockfd, buffer, BUFFERSIZE-1, 0) <= 0) break;

        int i;
        int lineCount = 0;
        int startLine = 0;
        int endLine = 0;
        int inMail = 0;
        int mailCount = 0;
        char mails[MAX_MAILS][BUFFERSIZE];
        for(i=0;i<BUFFERSIZE-1;i++) {
            if(buffer[i] == '\n') {
                lineCount++;
                if(lineCount == 1) {
                    startLine = i;
                } else if(lineCount > 1 && buffer[i-1] == '\r' && buffer[i-2] == '\n') {
                    endLine = i;
                    inMail = 0;
                }
            }
            if(inMail) {
                mails[mailCount][i-startLine-2] = buffer[i];
            }
            if(lineCount == 4) {
                inMail = 1;
                mailCount++;
            }
        }

        for(i=0;i<mailCount;i++) {
            printf("%s\n", mails[i]);
        }
    }

    close(sockfd);
    return 0;
}