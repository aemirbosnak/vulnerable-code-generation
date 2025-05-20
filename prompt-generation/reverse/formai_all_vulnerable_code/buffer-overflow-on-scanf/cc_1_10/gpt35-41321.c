//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

int connect_to_pop3_server(char* server_address, int port){
    struct sockaddr_in server;
    int sock;

    //create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1){
        perror("Could not create socket");
        return -1;
    }

    //set server address and port
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    //connect to server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0){
        perror("Could not connect to server");
        return -1;
    }

    return sock;
}

int receive_response(int sock, char* response){
    char buffer[MAX_BUF_SIZE];

    ssize_t read_size = recv(sock, buffer, sizeof(buffer), 0);
    if (read_size < 0){
        perror("Could not receive response from server");
        return -1;
    }
    buffer[read_size] = '\0';

    strcpy(response, buffer);

    return 0;
}

int send_command(int sock, char* command){
    if (send(sock, command, strlen(command), 0) < 0){
        perror("Could not send command to server");
        return -1;
    }

    return 0;
}

int authenticate(int sock, char* username, char* password){
    char response[MAX_BUF_SIZE];
    char command[MAX_BUF_SIZE];

    sprintf(command, "USER %s\r\n", username);
    if (send_command(sock, command) != 0){
        return -1;
    }
    if (receive_response(sock, response) != 0){
        return -1;
    }
    //check if username was accepted
    if (!strstr(response, "+OK")){
        printf("Invalid username\n");
        return -1;
    }

    sprintf(command, "PASS %s\r\n", password);
    if (send_command(sock, command) != 0){
        return -1;
    }
    if (receive_response(sock, response) != 0){
        return -1;
    }
    //check if password was accepted
    if (!strstr(response, "+OK")){
        printf("Invalid password\n");
        return -1;
    }

    printf("Authentication successful\n");

    return 0;
}

int download_emails(int sock){
    char response[MAX_BUF_SIZE];
    char command[MAX_BUF_SIZE];

    //retrieve number of emails in mailbox
    if (send_command(sock, "STAT\r\n") != 0){
        return -1;
    }
    if (receive_response(sock, response) != 0){
        return -1;
    }
    int num_emails;
    sscanf(response, "+OK %d", &num_emails);
    printf("Number of emails: %d\n", num_emails);

    //iterate over each email to retrieve message
    for (int i = 1; i <= num_emails; i++){
        sprintf(command, "RETR %d\r\n", i);
        if (send_command(sock, command) != 0){
            return -1;
        }
        if (receive_response(sock, response) != 0){
            return -1;
        }
        printf("Email %d:\n%s\n", i, response);
    }

    return 0;
}

int main(){
    char server_address[MAX_BUF_SIZE];
    int port;
    char username[MAX_BUF_SIZE];
    char password[MAX_BUF_SIZE];

    //get user input
    printf("Enter POP3 server address: ");
    scanf("%s", server_address);
    printf("Enter server port: ");
    scanf("%d", &port);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    //connect to server
    int sock = connect_to_pop3_server(server_address, port);
    if (sock == -1){
        return -1;
    }

    //authenticate user
    if (authenticate(sock, username, password) != 0){
        return -1;
    }

    //download emails
    if (download_emails(sock) != 0){
        return -1;
    }

    close(sock);
    return 0;
}