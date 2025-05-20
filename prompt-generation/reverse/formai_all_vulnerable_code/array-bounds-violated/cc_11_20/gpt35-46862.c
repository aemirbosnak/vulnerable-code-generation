//FormAI DATASET v1.0 Category: Simple Web Server ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8000 // Port number to listen on
#define RESPONSE_MAX_SIZE 2048 // Maximum size of a response message

void serve_client(int client_socket_fd);

int main()
{
    int server_socket_fd, client_socket_fd;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);

    // Create TCP server socket
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket_fd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind server socket to server address
    if(bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Error binding socket to address");
        exit(1);
    }

    // Listen for incoming connections
    if(listen(server_socket_fd, 5) < 0)
    {
        perror("Error listening for connections");
        exit(1);
    }

    // Accept and serve incoming client connections
    while(1)
    {
        printf("Waiting for incoming connections...\n");

        // Accept client connection
        client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_address, &client_address_length);
        if(client_socket_fd < 0)
        {
            perror("Error accepting connection");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Serve client request
        serve_client(client_socket_fd);

        // Close client connection
        close(client_socket_fd);
    }

    // Close server socket
    close(server_socket_fd);

    return 0;
}

void serve_client(int client_socket_fd)
{
    char request_buffer[512], response_buffer[RESPONSE_MAX_SIZE];
    ssize_t bytes_received, bytes_sent;

    // Receive client request
    bytes_received = recv(client_socket_fd, request_buffer, sizeof(request_buffer) - 1, 0);
    if(bytes_received < 0)
    {
        perror("Error receiving request");
        return;
    }

    // Null-terminate request string
    request_buffer[bytes_received] = '\0';

    // Extract requested resource path from GET request
    char *resource_path = strtok(request_buffer, " ");
    resource_path = strtok(NULL, " ");

    if(resource_path == NULL)
    {
        strcpy(response_buffer, "HTTP/1.1 400 Bad Request\r\n\r\n");
    }
    else
    {
        // Serve resource file
        char *filename = resource_path + 1; // Skip leading slash
        FILE *file = fopen(filename, "rb");

        if(file == NULL)
        {
            strcpy(response_buffer, "HTTP/1.1 404 Not Found\r\n\r\n");
        }
        else
        {
            char content_type[64], content_length[32];
            fseek(file, 0L, SEEK_END);
            int file_size = ftell(file);
            fseek(file, 0L, SEEK_SET);

            // Set content type based on file extension
            if(strstr(filename, ".html") != NULL)
            {
                strcpy(content_type, "text/html");
            }
            else if(strstr(filename, ".css") != NULL)
            {
                strcpy(content_type, "text/css");
            }
            else if(strstr(filename, ".js") != NULL)
            {
                strcpy(content_type, "application/javascript");
            }
            else if(strstr(filename, ".jpg") != NULL || strstr(filename, ".jpeg") != NULL)
            {
                strcpy(content_type, "image/jpeg");
            }
            else if(strstr(filename, ".png") != NULL)
            {
                strcpy(content_type, "image/png");
            }
            else if(strstr(filename, ".gif") != NULL)
            {
                strcpy(content_type, "image/gif");
            }
            else if(strstr(filename, ".ico") != NULL)
            {
                strcpy(content_type, "image/x-icon");
            }
            else
            {
                strcpy(content_type, "application/octet-stream");
            }

            // Construct response header
            sprintf(response_buffer, "HTTP/1.1 200 OK\r\nContent-Type: %s\r\nContent-Length: %d\r\n\r\n", content_type, file_size);

            // Send response header
            bytes_sent = send(client_socket_fd, response_buffer, strlen(response_buffer), 0);
            if(bytes_sent < 0)
            {
                perror("Error sending response header");
                fclose(file);
                return;
            }

            // Send response body (file contents)
            int bytes_read;
            while((bytes_read = fread(response_buffer, 1, RESPONSE_MAX_SIZE, file)) > 0)
            {
                bytes_sent = send(client_socket_fd, response_buffer, bytes_read, 0);
                if(bytes_sent < 0)
                {
                    perror("Error sending response body");
                    fclose(file);
                    return;
                }
            }

            fclose(file);
        }
    }

    // Send response
    bytes_sent = send(client_socket_fd, response_buffer, strlen(response_buffer), 0);
    if(bytes_sent < 0)
    {
        perror("Error sending response");
        return;
    }
}