//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

/* Error messages */
#define ERR_MSG_SOCK "ERROR: Failed to create socket."
#define ERR_MSG_CONN "ERROR: Failed to establish a connection."
#define ERR_MSG_SEND "ERROR: Failed to send data through socket."
#define ERR_MSG_RECV "ERROR: Failed to receive data from socket."

/* Constants */
#define SERVER_PORT 21
#define BUFFER_SIZE 1024

/* FTP Commands */
#define CMD_USER "USER"
#define CMD_PASS "PASS"
#define CMD_SYST "SYST"
#define CMD_PWD "PWD"
#define CMD_TYPE "TYPE"
#define CMD_QUIT "QUIT"
#define CMD_PORT "PORT"
#define CMD_LIST "LIST"

/* Function prototypes */
void send_data(int socketfd, char* data);
char* recv_data(int socketfd);
char* get_server_response(int socketfd);
int create_socket(char* server_ip);
void handle_response(int socketfd);
void send_file_listing_request(int socketfd);
void print_file_listing(int socketfd, char* data);

int main(int argc, char** argv) {

    if(argc < 2) {
        printf("Usage: %s [SERVER IP]\n", argv[0]);
        exit(1);
    }

    /* Create socket and connect to server */
    int socketfd = create_socket(argv[1]);

    /* Log in to server */
    send_data(socketfd, CMD_USER " anonymous");
    handle_response(socketfd);

    send_data(socketfd, CMD_PASS " ");
    handle_response(socketfd);

    /* Get system type */
    send_data(socketfd, CMD_SYST);
    handle_response(socketfd);

    /* Switch to binary mode */
    send_data(socketfd, CMD_TYPE " I");
    handle_response(socketfd);

    /* Get current working directory */
    send_data(socketfd, CMD_PWD);
    handle_response(socketfd);

    /* Send file listing request */
    send_file_listing_request(socketfd);

    /* Wait for response and print file listing */
    char* data = recv_data(socketfd);
    print_file_listing(socketfd, data);

    /* Close socket and exit */
    close(socketfd);
    return 0;
}

void send_data(int socketfd, char* data) {
    int num_bytes = send(socketfd, data, strlen(data), 0);
    if(num_bytes < 0) {
        printf(ERR_MSG_SEND);
        exit(1);
    }
}

char* recv_data(int socketfd) {
    char buffer[BUFFER_SIZE];
    int num_bytes = recv(socketfd, buffer, BUFFER_SIZE - 1, 0);
    if(num_bytes < 0) {
        printf(ERR_MSG_RECV);
        exit(1);
    }
    buffer[num_bytes] = '\0';
    return buffer;
}

char* get_server_response(int socketfd) {
    char* response = recv_data(socketfd);
    printf("%s", response);
    return response;
}

int create_socket(char* server_ip) {
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketfd < 0) {
        printf(ERR_MSG_SOCK);
        exit(1);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server_address.sin_addr);

    if(connect(socketfd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        printf(ERR_MSG_CONN);
        exit(1);
    }

    get_server_response(socketfd);
    return socketfd;
}

void handle_response(int socketfd) {
    char* response = get_server_response(socketfd);
    int response_code = atoi(strtok(response, " "));
    free(response);

    if(response_code >= 400) {
        printf("ERROR: FTP server returned error code %d.\n", response_code);
        exit(1);
    }
}

void send_file_listing_request(int socketfd) {
    /* Create socket for data transfer */
    int data_socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(data_socketfd < 0) {
        printf(ERR_MSG_SOCK);
        exit(1);
    }

    /* Bind data_socket to a random port */
    struct sockaddr_in data_address;
    memset(&data_address, 0, sizeof(data_address));
    data_address.sin_family = AF_INET;
    data_address.sin_port = 0;
    data_address.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(data_socketfd, (struct sockaddr*) &data_address, sizeof(data_address)) < 0) {
        printf("ERROR: Failed to bind data socket.\n");
        exit(1);
    }

    /* Get the chosen port */
    socklen_t data_len = sizeof(data_address);
    if(getsockname(data_socketfd, (struct sockaddr*) &data_address, &data_len) < 0) {
        printf("ERROR: Failed to get data socket port.\n");
        exit(1);
    }
    int data_port = ntohs(data_address.sin_port);

    /* Convert port to FTP format */
    unsigned char port_string[16];
    sprintf(port_string, "%d,%d,%d,%d,%d,%d",
            (data_port >> 8) & 0xff,
            data_port & 0xff,
            (data_port >> 8) & 0xff,
            data_port & 0xff,
            (data_port >> 8) & 0xff,
            data_port & 0xff);

    /* Send PORT command to server */
    char port_command[64];
    sprintf(port_command, CMD_PORT " %s", port_string);
    send_data(socketfd, port_command);
    handle_response(socketfd);

    /* Send LIST command to server */
    send_data(socketfd, CMD_LIST);
    handle_response(socketfd);

    /* Connect to data port */
    struct sockaddr_in data_server_address;
    memset(&data_server_address, 0, sizeof(data_server_address));
    data_server_address.sin_family = AF_INET;
    data_server_address.sin_port = htons(data_port);
    inet_pton(AF_INET, "127.0.0.1", &data_server_address.sin_addr);

    if(connect(data_socketfd, (struct sockaddr*) &data_server_address, sizeof(data_server_address)) < 0) {
        printf("ERROR: Failed to establish data connection.\n");
        exit(1);
    }
}

void print_file_listing(int socketfd, char* data) {
    char buffer[BUFFER_SIZE];
    int num_bytes = 0;

    while((num_bytes = recv(socketfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[num_bytes] = '\0';
        printf("%s", buffer);
    }
}