//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: statistical
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define PORT 8085

int main(){
    int serverSocket, clientSocket, bytesRead;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrSize = sizeof(struct sockaddr_in);;
    int opt = 1, maxClients = 3, activity, socketDesc, i;
    int clientSockets[maxClients], max_sd;
    fd_set readfds;

    // Creating a Server Socket 
    if((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting Socket Options 
    if(setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0){
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Setting Server Address Configuration 
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Binding Socket to Server Address 
    if(bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for Incoming Clients
    if(listen(serverSocket, 3) < 0){
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accepting Multiple Clients
    for(i = 0; i < maxClients; i++){
        clientSockets[i] = 0;
    }

    while(1){
        // Clearing the Socket Set 
        FD_ZERO(&readfds);

        FD_SET(serverSocket, &readfds);
        max_sd = serverSocket;

        for(i = 0; i < maxClients; i++){

            socketDesc = clientSockets[i];

            if(socketDesc > 0){
                FD_SET(socketDesc, &readfds);
            }

            if(socketDesc > max_sd){
                max_sd = socketDesc;
            }
        }

        // Checking for I/O Activity
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
 
        if(FD_ISSET(serverSocket, &readfds)){

            if((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addrSize)) < 0){
                perror("accept failed");
                exit(EXIT_FAILURE);
            }

            printf("New connection at socket %d\n", clientSocket);

            for(i = 0; i < maxClients; i++){
                if(clientSockets[i] == 0){
                    clientSockets[i] = clientSocket;
                    break;
                }
            }
        }

        for(i = 0; i < maxClients; i++){

            socketDesc = clientSockets[i];

            if(FD_ISSET(socketDesc, &readfds)){

                char buffer[1024] = {0};

                if((bytesRead = read(socketDesc, buffer, 1024)) == 0){
                    printf("Socket %d has disconnected\n", socketDesc);
                    close(socketDesc);
                    clientSockets[i] = 0;
                }else{
                    printf("%s\n", buffer);
                    send(socketDesc, buffer, strlen(buffer), 0);
                }
            }
        }
    }

    return 0;
}