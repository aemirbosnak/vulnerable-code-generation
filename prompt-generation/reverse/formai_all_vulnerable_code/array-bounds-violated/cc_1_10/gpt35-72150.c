//FormAI DATASET v1.0 Category: Client Server Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

void *connection_handler(void *);

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_t thread_id;
  
    //Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
      
    //Bind socket to address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
      
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
      
    //Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d\n", PORT);
      
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        printf("New connection received from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
        
        if (pthread_create(&thread_id, NULL, connection_handler, (void *)&new_socket) < 0) {
            perror("Thread creation failed");
            return 1;
        }
    }
    return 0;
}

void *connection_handler(void *socket_desc) {
    int sock = *(int*)socket_desc;
    int read_size;
    char message[2000];
    char server_reply[2000];
     
    while( (read_size = recv(sock , message , 2000 , 0)) > 0 ) {
        message[read_size] = '\0';
        printf("Client message received: %s", message);

        // Send message to the client
        sprintf(server_reply, "Hello from server, you sent me: %s", message);
        if (write(sock , server_reply , strlen(server_reply)) < 0) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }
    }
     
    if(read_size == 0) {
        printf("Client disconnected\n");
        fflush(stdout);
    } else if(read_size == -1) {
        perror("Received error");
    }
         
    close(sock);
    return 0;
}