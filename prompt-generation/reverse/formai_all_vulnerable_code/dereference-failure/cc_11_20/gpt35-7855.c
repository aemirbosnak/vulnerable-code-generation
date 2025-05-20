//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>

#define MAX_LEN 2048

int main(int argc, char *argv[]) {
    
    if(argc!=4) {
        printf("ERROR: Invalid arguments! Usage: ./imap_client <email> <password> <server>");
        return 1;
    }
    const char *email = argv[1];
    const char *password = argv[2];
    const char *server = argv[3];

    printf("Connecting to %s IMAP server...\n", server);
    sleep(1);
    printf("Establishing connection...\n");
    sleep(2);
    
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct hostent *he;
    struct sockaddr_in addr;

    if((he=gethostbyname(server))==NULL) {
        printf("ERROR: Could not resolve host.\n");
        return 1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr = *((struct in_addr*)he->h_addr_list[0]);
    addr.sin_port = htons(993);

    if(connect(sockfd, (struct sockaddr*)&addr, sizeof(addr))<0) {
        printf("ERROR: Could not connect to server.\n");
        return 1;
    }

    char buffer[MAX_LEN] = {0};
    ssize_t num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);

    if(num_bytes<=0) {
        printf("ERROR: Could not receive data from server.\n");
        return 1;
    }

    printf("%s", buffer);
    sleep(1);

    printf("\nSending login credentials...\n");
    sleep(2);

    char login_cmd[MAX_LEN] = {0};
    sprintf(login_cmd, "a1 LOGIN %s %s\n", email, password);

    if(send(sockfd, login_cmd, strlen(login_cmd), 0)<0) {
        printf("ERROR: Could not send login command.\n");
        return 1;
    }

    memset(buffer, 0, MAX_LEN);
    num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);

    if(num_bytes<=0) {
        printf("ERROR: Could not receive login response from server.\n");
        return 1;
    }

    printf("%s\n", buffer);
    sleep(1);

    printf("Selecting inbox...\n");
    sleep(2);

    char select_cmd[MAX_LEN] = {0};
    sprintf(select_cmd, "a2 SELECT INBOX\n");

    if(send(sockfd, select_cmd, strlen(select_cmd), 0)<0) {
        printf("ERROR: Could not send select command.\n");
        return 1;
    }

    memset(buffer, 0, MAX_LEN);
    num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);

    if(num_bytes<=0) {
        printf("ERROR: Could not receive select response from server.\n");
        return 1;
    }

    printf("%s\n", buffer);
    sleep(1);

    printf("Fetching mailbox status...\n");
    sleep(2);

    char status_cmd[MAX_LEN] = {0};
    sprintf(status_cmd, "a3 STATUS INBOX (MESSAGES UNSEEN)\n");

    if(send(sockfd, status_cmd, strlen(status_cmd), 0)<0) {
        printf("ERROR: Could not send status command.\n");
        return 1;
    }

    memset(buffer, 0, MAX_LEN);
    num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);

    if(num_bytes<=0) {
        printf("ERROR: Could not receive status response from server.\n");
        return 1;
    }

    printf("%s\n", buffer);
    sleep(1);

    printf("Logging out...\n");
    sleep(2);

    char logout_cmd[MAX_LEN] = {0};
    sprintf(logout_cmd, "a4 LOGOUT\n");

    if(send(sockfd, logout_cmd, strlen(logout_cmd), 0)<0) {
        printf("ERROR: Could not send logout command.\n");
        return 1;
    }

    memset(buffer, 0, MAX_LEN);
    num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);

    if(num_bytes<=0) {
        printf("ERROR: Could not receive logout response from server.\n");
        return 1;
    }

    printf("%s\n", buffer);
    sleep(1);

    printf("Closing connection...\n");
    sleep(2);

    close(sockfd);
    printf("Disconnected from %s IMAP server.\n", server);

    return 0;
}