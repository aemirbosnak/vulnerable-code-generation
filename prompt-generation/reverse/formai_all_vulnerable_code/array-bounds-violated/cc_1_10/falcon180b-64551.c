//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char sendData[MAX];
    char recvData[MAX];
    int len;
    int numbytes;
    char *token;
    int i;
    FILE *fp;
    char line[MAX];

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == 0) {
        printf("socket creation failed\n");
        exit(0);
    }

    // fill server information
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8080);

    // connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("connection failed\n");
        exit(0);
    }

    // send data to server
    sprintf(sendData, "GET / HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: close\r\n\r\n");

    if (send(sock, sendData, strlen(sendData), 0) < 0) {
        printf("send failed\n");
        exit(0);
    }

    // receive data from server
    while ((numbytes = recv(sock, recvData, sizeof(recvData), 0)) > 0) {
        recvData[numbytes] = '\0';
        printf("%s", recvData);
    }

    // close connection
    close(sock);

    // open file to save data
    fp = fopen("data.txt", "w");

    if (fp == NULL) {
        printf("File creation failed\n");
        exit(0);
    }

    // write data to file
    for (i = 0; i < strlen(recvData); i++) {
        fprintf(fp, "%c", recvData[i]);
    }

    // close file
    fclose(fp);

    // open file to read data
    fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("File open failed\n");
        exit(0);
    }

    // read data from file
    while (fgets(line, MAX, fp)!= NULL) {
        printf("%s", line);
    }

    // close file
    fclose(fp);

    return 0;
}