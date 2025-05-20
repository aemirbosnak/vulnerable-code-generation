//FormAI DATASET v1.0 Category: Chat server ; Style: irregular
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<pthread.h>

//Defining Port for Socket Server
#define PORT 8000

//Function for handling multiple client requests
void *handle_request(void *client_ptr){
    //Converting Client Pointer back to integer
    int client = *(int*)client_ptr;
    //Initializing Buffer for receiving messages
    char recv_buffer[1024];
    //Loop for receiving and sending messages
    while(1){
        //Receiving message from client
        int bytes_received = recv(client,recv_buffer,1024,0);
        //Checking if client disconnected
        if(bytes_received<=0){
            printf("Client Disconnected. Exiting Thread.\n");
            break;
        }
        //Adding Null Terminator to received message
        recv_buffer[bytes_received] = '\0';
        //Printing Received Message
        printf("Received: %s",recv_buffer);
        //Sending Message to Client
        send(client,recv_buffer,strlen(recv_buffer),0);
    }
    //Closing Client Connection
    close(client);
}

int main(){
    //Initializing Socket Server Variables
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int opt = 1;
    //Creating Socket File Descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        return 1;
    }
    //Setting Socket Server Options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt))){
        perror("setsockopt");
        return 1;
    }
    //Setting Socket Server Parameters
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    //Binding Socket Server to Address and Port
    if (bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0){
        perror("bind failed");
        return 1;
    }
    //Setting Socket Server to Listen for Client Connections
    if (listen(server_fd, 3) < 0){
        perror("listen");
        return 1;
    }
    printf("Listening for Client Connection Requests on Port %d.\n",PORT);
    //Loop for handling Multiple Client Connections
    while(1){
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,(socklen_t*)&addrlen))<0){
            perror("accept");
            return 1;
        }
        printf("New Client Connected: %d\n",new_socket);
        //Creating Thread for Handling Client Request
        pthread_t thread_id;
        if(pthread_create(&thread_id, NULL, handle_request, &new_socket)){
            perror("pthread_create");
            return 1;
        }
        //Detaching Thread
        if(pthread_detach(thread_id)){
            perror("pthread_detach");
            return 1;
        }
    }
    return 0;
}