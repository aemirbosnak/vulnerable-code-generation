//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024 // Size of the buffer used to transfer files

void error(const char* message){
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]){
    if(argc < 3){
        printf("Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent* server;

    // Create a socket using TCP protocol
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if(sockfd < 0) 
        error("ERROR opening socket");

    
    server = gethostbyname(argv[1]);
    if(server == NULL){
        fprintf(stderr,"ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset((char*)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char*)&(serv_addr.sin_addr.s_addr), (char*)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    char buffer[BUFFER_SIZE];
    int filefd;
    // Loop while waiting for user input
    while(1){

        // Read user input
        printf("ftp> ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Remove trailing newline character from input string
        buffer[strcspn(buffer, "\n")] = 0;

        // Handle quit command
        if(strcmp(buffer, "quit") == 0){
            printf("Exiting FTP client.\n");
            break;
        }

        // Handle put command
        if(strncmp(buffer, "put", 3) == 0){
            // Get the local file path and remote file name
            char* local_file_path = strtok(buffer+4, " ");
            char* remote_file_name = strtok(NULL, " ");
            
            // Open local file for reading
            if((filefd = open(local_file_path, O_RDONLY)) < 0)
                error("ERROR opening local file");

            // Send PUT command to server along with remote file name
            int sent_bytes = write(sockfd, buffer, strlen(buffer));
            if(sent_bytes < 0)
                error("ERROR writing to socket");

            // Get response from server
            memset(buffer, 0, BUFFER_SIZE);
            if(read(sockfd, buffer, BUFFER_SIZE-1) < 0)
                error("ERROR reading from socket");

            // Check if server is ready to receive file
            if(strcmp(buffer, "ready") != 0)
                error("ERROR server not ready to receive file");

            // Transfer file to server
            int bytes_read;
            while((bytes_read = read(filefd, buffer, BUFFER_SIZE)) > 0){
                if(write(sockfd, buffer, bytes_read) < 0)
                    error("ERROR writing to socket");
            }

            close(filefd);

            // Get response from server and print it
            memset(buffer, 0, BUFFER_SIZE);
            if(read(sockfd, buffer, BUFFER_SIZE-1) < 0)
                error("ERROR reading from socket");
            printf("%s", buffer);
            continue;
        }

        // Handle get command
        if(strncmp(buffer, "get", 3) == 0){
            // Get remote file name
            char* remote_file_name = strtok(buffer+4, " ");

            // Send GET command to server along with remote file name
            int sent_bytes = write(sockfd, buffer, strlen(buffer));
            if(sent_bytes < 0)
                error("ERROR writing to socket");

            // Get response from server
            memset(buffer, 0, BUFFER_SIZE);
            if(read(sockfd, buffer, BUFFER_SIZE-1) < 0)
                error("ERROR reading from socket");

            // Check if server sent file size
            int file_size = 0;
            if(sscanf(buffer, "%d", &file_size) != 1)
                error("ERROR invalid response from server");

            // Open local file for writing
            char* local_file_name = strtok(remote_file_name, "/");
            if((filefd = open(local_file_name, O_CREAT|O_WRONLY|O_TRUNC, 0666)) < 0)
                error("ERROR opening local file");

            // Send ready message to server
            if(write(sockfd, "ready", strlen("ready")) < 0)
                error("ERROR writing to socket");

            // Transfer file from server
            int bytes_received = 0, bytes_to_receive = file_size;
            while(bytes_to_receive > 0){
                int bytes_read = read(sockfd, buffer, BUFFER_SIZE);
                if(bytes_read < 0)
                    error("ERROR reading from socket");
                bytes_received += bytes_read;
                if(write(filefd, buffer, bytes_read) < 0)
                    error("ERROR writing local file");
                bytes_to_receive -= bytes_read;
            }

            close(filefd);

            printf("Received %d bytes\n", bytes_received);
            continue;
        }

        // Handle invalid command
        printf("Invalid command. Commands: put, get, quit\n");
    }

    close(sockfd);
    return 0;
}