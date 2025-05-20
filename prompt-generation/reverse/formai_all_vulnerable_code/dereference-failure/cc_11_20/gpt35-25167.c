//FormAI DATASET v1.0 Category: Simple Web Server ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int port;
    if (argc != 2) {
        printf("Usage: ./a.out <port_number>\n");
        exit(0);
    }
    port = atoi(argv[1]);
    if (port <= 1024) {
        printf("Port number should be greater than 1024\n");
        exit(0);
    }
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *welcome_msg = "<html><body><h1>Welcome to my web server!</h1></body></html>";
    char *not_found_msg = "<html><body><h1>404 Page not found</h1></body></html>";
    char *helmet_msg = "<html><body><h1>You have just entered the danger zone!</h1></body></html>";
    char *time_msg = "<html><body><h1>The current date and time is: ";
    char *response;
    time_t now;
    struct tm *local;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        valread = read(new_socket, buffer, 1024);
        if (strstr(buffer, "GET / HTTP/1.1") || strstr(buffer, "GET /index.html") || strstr(buffer, "GET /welcome.html")) {
            response = welcome_msg;
        } else if (strstr(buffer, "GET /time.html")) {
            now = time(NULL);
            local = localtime(&now);
            strcat(time_msg, asctime(local));
            strcat(time_msg, "</h1></body></html>");
            response = time_msg;
        } else if (strstr(buffer, "GET /danger.html")) {
            response = helmet_msg;
        } else {
            response = not_found_msg;
        }
        write(new_socket, response, strlen(response));
        close(new_socket);
    }
    return 0;
}