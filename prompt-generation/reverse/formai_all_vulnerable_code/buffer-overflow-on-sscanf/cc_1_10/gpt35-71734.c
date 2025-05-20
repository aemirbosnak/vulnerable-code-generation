//FormAI DATASET v1.0 Category: Simple Web Server ; Style: active
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <netinet/in.h> 
#include <sys/socket.h>
#include <unistd.h> 

#define SERVER_PORT 8000
#define BUF_SIZE 4096
#define METHOD_LEN 10
#define URI_LEN 255
#define PATH_LEN 512

char* sendHeaders(int client_socket, int status_code, char* contentType){
    char* resp_headers = (char*)malloc(1000 * sizeof(char));
    char respCode[4];
    switch(status_code){
        case 200: strcpy(respCode, "200 OK"); break;
        case 404: strcpy(respCode, "404 NOT FOUND"); break;
        case 500: strcpy(respCode, "500 INTERNAL SERVER ERROR"); break;
        default: strcpy(respCode, "200 OK");
    }

    strcat(resp_headers, "HTTP/1.1 ");
    strcat(resp_headers, respCode);
    strcat(resp_headers, "\nContent-Type: ");
    strcat(resp_headers, contentType);
    strcat(resp_headers, "\n\n");
    send(client_socket, resp_headers, strlen(resp_headers), 0);
    return resp_headers;
}

void handleClient(int client_socket, char* request){
    char method[METHOD_LEN], uri[URI_LEN], protocol[BUF_SIZE], path[PATH_LEN]; 
    sscanf(request, "%s %s %s", method, uri, protocol);
    if(strcmp(method, "GET") != 0){
        sendHeaders(client_socket, 500, "text/html");
        char* error_message = "<html><body><h1>500 Internal Server Error</h1><p>Only GET requests are supported for now!</p></body></html>";
        send(client_socket, error_message, strlen(error_message), 0);
        return;
    }
    sprintf(path, ".%s", uri);
    FILE* file = fopen(path, "r");
    if(file == NULL){
        sendHeaders(client_socket, 404, "text/html");
        char* error_message = "<html><body><h1>404 Not Found</h1><p>The requested resource was not found!</p></body></html>";
        send(client_socket, error_message, strlen(error_message), 0);
        return;
    }
    char* content_type = "text/html";
    if(strstr(uri, ".css")){
        content_type = "text/css";
    }
    if(strstr(uri, ".js")){
        content_type= "application/javascript";
    }
    sendHeaders(client_socket, 200, content_type);
    char file_buffer[BUF_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(file_buffer, 1, BUF_SIZE, file)) > 0) {
        send(client_socket, file_buffer, bytes_read, 0);
    }
    fclose(file);
}

int main() { 
    int server_socket, client_socket; 
    struct sockaddr_in server_addr, client_addr; 
    int addr_len = sizeof(client_addr); 
    char request[BUF_SIZE];
  
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
        perror("socket"); 
        exit(1); 
    } 
  
    memset(&server_addr, 0, sizeof(server_addr)); 
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
    server_addr.sin_port = htons(SERVER_PORT); 
  
    if (bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) { 
        perror("bind"); 
        exit(1); 
    } 
  
    if (listen(server_socket, 16) < 0) { 
        perror("listen"); 
        exit(1); 
    } 
  
    printf("Listening on port %d...\n", SERVER_PORT); 
  
    while (1) { 
        if ((client_socket = accept(server_socket, (struct sockaddr*) &client_addr, &addr_len)) < 0) { 
            perror("accept"); 
            continue; 
        } 
        printf("Connection from %u:%d...\n", client_addr.sin_addr.s_addr, ntohs(client_addr.sin_port)); 
        ssize_t bytes_read = recv(client_socket, request, BUF_SIZE, 0);
        request[bytes_read] = '\0';
        printf("Received request:\n%s\n", request);
        handleClient(client_socket, request);
        close(client_socket);
    } 
    return 0; 
}