//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: unmistakable
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

#define BUFF_SIZE 1024

int ftp_connect(char* ip_address, int port_num){
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        fprintf(stderr, "Error creating socket\n");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_num);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1){
        fprintf(stderr, "Error connecting to server\n");
        close(sock);
        return -1;
    }

    char server_response[BUFF_SIZE] = "";
    if(recv(sock, server_response, BUFF_SIZE, 0) == -1){
        fprintf(stderr, "Error receiving response from server\n");
        close(sock);
        return -1;
    }

    printf("Server response: %s\n", server_response);
    return sock;
}

int main(int argc, char* argv[]){
    if(argc != 4){
        printf("Usage: %s <ip_address> <port_number> <filename>\n", argv[0]);
        return -1;
    }

    char* ip_address = argv[1];
    int port_num = atoi(argv[2]);
    char* filename = argv[3];

    int sock = ftp_connect(ip_address, port_num);
    if(sock == -1){
        fprintf(stderr, "Error connecting to server\n");
        return -1;
    }

    // Log in to the server
    char send_buffer[BUFF_SIZE] = "";
    char recv_buffer[BUFF_SIZE] = "";
    printf("Enter username: ");
    scanf("%s", send_buffer);
    strcat(send_buffer, "\r\n");
    send(sock, send_buffer, strlen(send_buffer), 0);
    if(recv(sock, recv_buffer, BUFF_SIZE, 0) == -1){
        fprintf(stderr, "Error receiving response from server\n");
        close(sock);
        return -1;
    }
    printf("Server response: %s\n", recv_buffer);

    memset(send_buffer, 0, BUFF_SIZE);
    printf("Enter password: ");
    scanf("%s", send_buffer);
    strcat(send_buffer, "\r\n");
    send(sock, send_buffer, strlen(send_buffer), 0);
    if(recv(sock, recv_buffer, BUFF_SIZE, 0) == -1){
        fprintf(stderr, "Error receiving response from server\n");
        close(sock);
        return -1;
    }
    printf("Server response: %s\n", recv_buffer);

    // Send command to download file
    memset(send_buffer, 0, BUFF_SIZE);
    sprintf(send_buffer, "RETR %s\r\n", filename);
    send(sock, send_buffer, strlen(send_buffer), 0);

    // Receive file
    FILE* fp = fopen(filename, "wb");
    while(1){
        int bytes_received = recv(sock, recv_buffer, BUFF_SIZE, 0);
        if(bytes_received == -1){
            fprintf(stderr, "Error receiving data from server\n");
            close(sock);
            fclose(fp);
            return -1;
        }
        if(bytes_received == 0) break;
        fwrite(recv_buffer, 1, bytes_received, fp);
    }

    printf("File download complete\n");
    close(sock);
    fclose(fp);
    return 0;
}