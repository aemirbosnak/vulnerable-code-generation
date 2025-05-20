//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 110

int main(int argc, char **argv) {

    if(argc != 3) {
        fprintf(stderr, "Usage: pop3_client <server address> <username>\n");
        exit(1);
    }

    char *server_address = argv[1];
    char *username = argv[2];

    int sock, read_size;
    struct sockaddr_in server;
    char server_reply[2000];
    char user_msg[100], pass_msg[100];

    //Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Could not create socket!\n");
        exit(1);
    }

    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);

    //Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        fprintf(stderr, "Connect failed! Error\n");
        exit(1);
    }

    printf("Connected to server!\n");

    //Receive welcome message
    if(recv(sock, server_reply, 2000, 0) < 0) {
        fprintf(stderr, "Server not responding! Error\n");
        exit(1);
    }

    printf("%s",server_reply);

    //Send username
    snprintf(user_msg,100,"USER %s\r\n",username);
    if(send(sock, user_msg, strlen(user_msg), 0) < 0) {
        fprintf(stderr, "Could not send username! Error\n");
        exit(1);
    }

    //Receive server response
    memset(server_reply, 0, sizeof(server_reply));
    if(recv(sock, server_reply, 2000, 0) < 0) {
        fprintf(stderr, "Server not responding! Error\n");
        exit(1);
    }

    printf("%s",server_reply);

    //Prompt for password
    char *password = getpass("Enter password: ");

    //Send password
    snprintf(pass_msg,100,"PASS %s\r\n",password);
    if(send(sock, pass_msg, strlen(pass_msg), 0) < 0) {
        fprintf(stderr, "Could not send password! Error\n");
        exit(1);
    }

    //Receive server response
    memset(server_reply, 0, sizeof(server_reply));
    if(recv(sock, server_reply, 2000, 0) < 0) {
        fprintf(stderr, "Server not responding! Error\n");
        exit(1);
    }

    printf("%s",server_reply);

    //Send STAT command to retrieve number of messages
    char *stat_msg = "STAT\r\n";
    if(send(sock, stat_msg, strlen(stat_msg), 0) < 0) {
        fprintf(stderr, "Could not send STAT command! Error\n");
        exit(1);
    }

    //Receive server response
    memset(server_reply, 0, sizeof(server_reply));
    if(recv(sock, server_reply, 2000, 0) < 0) {
        fprintf(stderr, "Server not responding! Error\n");
        exit(1);
    }

    printf("%s",server_reply);

    //Parse number of messages
    char *num_messages_str = strtok(server_reply," ");
    num_messages_str = strtok(NULL," ");
    int num_messages = atoi(num_messages_str);

    printf("Number of messages: %d\n",num_messages);

    //Loop through each message
    for(int i=1; i<=num_messages; i++) {

        //Send RETR command to retrieve message
        char retr_msg[100];
        snprintf(retr_msg,100,"RETR %d\r\n",i);
        if(send(sock, retr_msg, strlen(retr_msg), 0) < 0) {
            fprintf(stderr, "Could not send RETR command! Error\n");
            exit(1);
        }

        //Receive message data
        memset(server_reply, 0, sizeof(server_reply));
        do {
            read_size = recv(sock, server_reply, 2000, 0);
            printf("%s", server_reply);
        } while(read_size > 0 && server_reply[strlen(server_reply)-4] != '\r' && server_reply[strlen(server_reply)-3] != '\n');

        printf("\n");
    }

    //Send QUIT command to terminate connection
    char *quit_msg = "QUIT\r\n";
    if(send(sock, quit_msg, strlen(quit_msg), 0) < 0) {
        fprintf(stderr, "Could not send QUIT command! Error\n");
        exit(1);
    }

    //Receive server response
    memset(server_reply, 0, sizeof(server_reply));
    if(recv(sock, server_reply, 2000, 0) < 0) {
        fprintf(stderr, "Server not responding! Error\n");
        exit(1);
    }

    printf("%s",server_reply);

    printf("Connection terminated.\n");

    return 0;
}