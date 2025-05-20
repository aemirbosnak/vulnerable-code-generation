//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: creative
/*********************************************************************
*                   FTP Client using C language                       *
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>

#define SERVER_PORT 21
#define MAX_BUFFER_SIZE 1024

/******************************** Structure ******************************/
typedef struct FTPClient {
    int control_socket;
    char *server;
    char buffer[MAX_BUFFER_SIZE];
} FTPClient;

/******************************** Function Prototypes ************************/
void ftp_connect(FTPClient *client);
void ftp_login(FTPClient *client, char *user, char *password);
void ftp_pasv(FTPClient *client);
void ftp_retr(FTPClient *client, char *file_name);
void ftp_quit(FTPClient *client);

/****************************** Main Program ******************************/

int main(int argc, char **argv) {
    int i;
    char *ftp_server, *ftp_user, *ftp_password, *ftp_file;
    FTPClient client;

    if (argc < 5) {
        printf("Usage: %s ftp_server ftp_user ftp_password ftp_file\n", argv[0]);
        exit(1);
    }

    ftp_server = argv[1];
    ftp_user = argv[2];
    ftp_password = argv[3];
    ftp_file = argv[4];

    /* init FTP client */
    client.server = ftp_server;

    /* connect to server */
    ftp_connect(&client);

    /* login to server */
    ftp_login(&client, ftp_user, ftp_password);

    /* set transfer mode to Passive */
    ftp_pasv(&client);

    /* download file */
    ftp_retr(&client, ftp_file);

    /* cleanup */
    ftp_quit(&client);

    return 0;
}

/********************************* Functions **********************************/

/* Connect to the FTP server */
void ftp_connect(FTPClient *client) {
    struct sockaddr_in server_addr;
    struct hostent *server_host;
    char *server = client->server;
    int control_socket;

    /* create socket */
    if ((control_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Unable to create control socket");
        exit(1);
    }

    /* get server IP address */
    if ((server_host = gethostbyname(server)) == NULL) {
        fprintf(stderr, "Unknown server %s\n", server);
        exit(1);
    }

    /* setup address structure */
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *) server_host->h_addr);

    /* connect to server */
    if (connect(control_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Unable to connect to server");
        exit(1);
    }

    /* store socket descriptor */
    client->control_socket = control_socket;

    /* read welcome message */
    if (recv(client->control_socket, client->buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Unable to read server response");
        exit(1);
    }
    printf("%s", client->buffer);
}

/* Login to FTP server */
void ftp_login(FTPClient *client, char *user, char *password) {
    char message[MAX_BUFFER_SIZE];

    /* send username */
    sprintf(message, "USER %s\r\n", user);
    if (send(client->control_socket, message, strlen(message), 0) < 0) {
        perror("Unable to send message");
        exit(1);
    }

    /* read response */
    if (recv(client->control_socket, client->buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Unable to read server response");
        exit(1);
    }
    printf("%s", client->buffer);

    /* send password */
    sprintf(message, "PASS %s\r\n", password);
    if (send(client->control_socket, message, strlen(message), 0) < 0) {
        perror("Unable to send message");
        exit(1);
    }

    /* read response */
    if (recv(client->control_socket, client->buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Unable to read server response");
        exit(1);
    }
    printf("%s", client->buffer);
}

/* Set transfer mode to Passive */
void ftp_pasv(FTPClient *client) {
    char message[MAX_BUFFER_SIZE];
    char *p1, *p2;
    int port[2], data_socket;
    struct sockaddr_in server_addr;
    socklen_t server_addr_len = sizeof(server_addr);

    /* send passive command */
    sprintf(message, "PASV\r\n");
    if (send(client->control_socket, message, strlen(message), 0) < 0) {
        perror("Unable to send message");
        exit(1);
    }

    /* read response */
    if (recv(client->control_socket, client->buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Unable to read server response");
        exit(1);
    }
    printf("%s", client->buffer);

    /* parse response */
    p1 = strchr(client->buffer, '(') + 1;
    p2 = strchr(client->buffer, ')');
    sscanf(p1, "%d,%d,%d,%d,%d,%d", &port[0], &port[1], &port[2], &port[3], &port[4], &port[5]);

    /* setup data address */
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_port = htons(port[4] * 256 + port[5]);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl((port[0] << 24) | (port[1] << 16) | (port[2] << 8) | port[3]);

    /* create data socket */
    if ((data_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Unable to create data socket");
        exit(1);
    }

    /* connect to data port */
    if (connect(data_socket, (struct sockaddr *) &server_addr, server_addr_len) < 0) {
        perror("Unable to connect to server data port");
        exit(1);
    }

    /* store data socket descriptor */
    client->control_socket = data_socket;
}

/* Download a file from FTP server */
void ftp_retr(FTPClient *client, char *file_name) {
    char message[MAX_BUFFER_SIZE];
    int fd, bytes_read;

    /* open local file */
    fd = open(file_name, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    if (fd < 0) {
        perror("Unable to open local file");
        exit(1);
    }

    /* send retr command */
    sprintf(message, "RETR %s\r\n", file_name);
    if (send(client->control_socket, message, strlen(message), 0) < 0) {
        perror("Unable to send message");
        exit(1);
    }

    /* read response */
    if (recv(client->control_socket, client->buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Unable to read server response");
        exit(1);
    }
    printf("%s", client->buffer);

    /* read file data */
    while ((bytes_read = recv(client->control_socket, client->buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        if (write(fd, client->buffer, bytes_read) < 0) {
            perror("Unable to write to local file");
            exit(1);
        }
    }

    close(fd);
}

/* Logout and quit FTP session */
void ftp_quit(FTPClient *client) {
    char message[MAX_BUFFER_SIZE];

    /* send quit command */
    sprintf(message, "QUIT\r\n");
    if (send(client->control_socket, message, strlen(message), 0) < 0) {
        perror("Unable to send message");
        exit(1);
    }

    /* read response */
    if (recv(client->control_socket, client->buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Unable to read server response");
        exit(1);
    }
    printf("%s", client->buffer);

    /* close control socket */
    close(client->control_socket);
}