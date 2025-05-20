//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>

#define MAX_REQUEST_SIZE 1024
#define MAX_RESPONSE_SIZE 4096

#define TRUE 1
#define FALSE 0

/* function to create a socket and connect to the given server and port */
int create_socket(char *server, int port){
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock < 0){
        printf("Unable to create socket\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if(inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0){
        printf("Invalid address given\n");
        exit(EXIT_FAILURE);
    }

    if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        printf("Unable to connect to server\n");
        exit(EXIT_FAILURE);
    }

    return sock;
}

/* function to send the HTTP request to the server */
int send_request(int sock, char *request){
    int sent_bytes = send(sock, request, strlen(request), 0);
    if(sent_bytes < 0){
        printf("Unable to send request\n");
        exit(EXIT_FAILURE);
    }

    return sent_bytes;
}

/* function to receive the HTTP response from the server */
char* receive_response(int sock){
    char *response = (char*)malloc(MAX_RESPONSE_SIZE * sizeof(char));
    memset(response, 0, MAX_RESPONSE_SIZE);

    int recv_bytes = recv(sock, response, MAX_RESPONSE_SIZE, 0);
    if(recv_bytes < 0){
        printf("Unable to receive response\n");
        exit(EXIT_FAILURE);
    }

    return response;
}

/* function to parse the URL to get the server name and port */
void parse_url(char *url, char **server, int *port){
    char *ptr = strstr(url, "://");
    if(ptr != NULL){
        *server = ptr + 3;
    }
    else{
        *server = url;
    }

    ptr = strchr(*server, '/');
    if(ptr != NULL){
        *ptr = '\0';
    }

    *port = 80;
    ptr = strchr(*server, ':');
    if(ptr != NULL){
        sscanf(ptr+1, "%d", port);
        *ptr = '\0';
    }
}

/* function to build the HTTP request */
char* build_request(char *url){
    char *server = NULL;
    int port;

    /* parse the URL to get the server name and port */
    parse_url(url, &server, &port);

    /* create the socket and connect to the server */
    int sock = create_socket(server, port);

    /* build the HTTP request */
    char *request = (char*)malloc(MAX_REQUEST_SIZE * sizeof(char));
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s:%d\r\nUser-Agent: Mozilla/5.0    (X11; Ubuntu; Linux x86_64; rv:84.0) Gecko/20100101 Firefox/84.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\nAccept-Language: en-US,en;q=0.5\r\nAccept-Encoding: gzip, deflate, br\r\nConnection:     keep-alive\r\nUpgrade-Insecure-Requests: 1\r\n\r\n", server, port);

    /* send the HTTP request to the server */
    send_request(sock, request);

    /* receive the HTTP response from the server */
    char *response = receive_response(sock);

    /* close the socket */
    close(sock);

    return response;
}

int main(){
    char url[1024];
    char *response;

    printf("Enter the URL to fetch:\n");
    scanf("%s", url);

    /* build the HTTP request and receive the response */
    response = build_request(url);

    /* print the HTTP response */
    printf("%s\n", response);

    free(response);

    return 0;
}