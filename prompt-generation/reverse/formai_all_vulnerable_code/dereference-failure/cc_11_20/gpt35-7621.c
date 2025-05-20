//FormAI DATASET v1.0 Category: Simple Web Server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, newsockfd, portno, clilen, file_fd, read_size;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE], *response;
    char *mime_type, *file_ext;
    struct stat st;
    FILE *fp;
    const char *status_code, *status_text;
    const char *valid_mime_types[] = {
        "text/html",
        "text/css",
        "text/javascript",
        "image/png",
        "image/gif",
        "image/jpeg",
        "application/javascript",
        "application/x-font-ttf",
        "application/json"
    };

    // Check for proper usage
    if (argc < 2) {
        fprintf(stderr, "ERROR: No port provided\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Clear serv_addr struct
    memset(&serv_addr, 0, sizeof(serv_addr));

    // Set socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("ERROR setting socket options");
        exit(1);
    }

    // Set serv_addr properties
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen on socket
    listen(sockfd, 5);

    // Begin accepting connections and serving content
    while (1) {
        // Accept new connection
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        // Clear buffer
        memset(buffer, 0, BUFFER_SIZE);

        // Read incoming data from client
        read_size = read(newsockfd, buffer, BUFFER_SIZE);

        if (read_size == 0) {
            close(newsockfd);
            continue;
        } else if (read_size < 0) {
            perror("ERROR reading from socket");
            close(newsockfd);
            continue;
        }

        // Extract requested path from buffer
        strtok(buffer, " ");
        char *req_path = strtok(NULL, " ");
        printf("Request received for %s\n", req_path);

        // Open requested file
        mime_type = NULL;
        file_ext = strrchr(req_path, '.');

        if (file_ext == NULL) {
            status_code = "400";
            status_text = "Bad Request";
            response = "Error 400: Bad Request";
        } else {
            fp = fopen(req_path + 1, "r");

            if (fp == NULL) {
                status_code = "404";
                status_text = "Not Found";
                response = "Error 404: File not found";
            } else {
                // Get file status and mimetype
                stat(req_path + 1, &st);
                for (int i = 0; i < sizeof(valid_mime_types)/sizeof(valid_mime_types[0]); i++) {
                    if (strstr(valid_mime_types[i], mime_type) != NULL) {
                        mime_type = valid_mime_types[i];
                        break;
                    }
                }

                status_code = "200";
                status_text = "OK";
                // Load file into response buffer
                response = (char *) malloc(st.st_size + 1);
                fread(response, st.st_size, 1, fp);
            }
        }

        // Write response headers
        char header[BUFFER_SIZE];
        memset(header, 0, BUFFER_SIZE);
        sprintf(header, "HTTP/1.1 %s %s\r\n", status_code, status_text);
        sprintf(header, "%sContent-Type: %s\r\n", header, mime_type);
        sprintf(header, "%sConnection: close\r\n", header);

        // Write response body
        write(newsockfd, header, strlen(header));
        if (status_code == "200") {
            write(newsockfd, response, st.st_size);
        } else {
            write(newsockfd, response, strlen(response));
        }

        // Cleanup
        close(newsockfd);
        if (fp != NULL) {
            fclose(fp);
        }

        free(response);
    }
    return 0;
}