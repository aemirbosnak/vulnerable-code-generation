//FormAI DATASET v1.0 Category: Client Server Application ; Style: multivariable
#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 100

int main() {
    int server_fd,client_fd;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    socklen_t sock_size;
    char message[MAX_LENGTH];
    char response[MAX_LENGTH];
    memset(message,0,sizeof(message));
    memset(response,0,sizeof(response));

    //Creating socket file descriptor
    if((server_fd =socket(AF_INET,SOCK_STREAM,0))==0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    //Setting socket options
    int opt =1;
    if(setsockopt(server_fd,SOL_SOCKET,SO_REUSEADDR|SO_REUSEPORT,&opt,sizeof(opt))) {
        perror("setsockopt failure");
        exit(EXIT_FAILURE);
    }

    //Server address structure
    server_address.sin_family =AF_INET;
    server_address.sin_addr.s_addr =INADDR_ANY;
    server_address.sin_port =htons(8080);

    //Binding socket
    if(bind(server_fd,(struct sockaddr*)&server_address,sizeof(server_address))<0) {
        perror("bind failure");
        exit(EXIT_FAILURE);
    }

    //Listening to incoming connections
    if(listen(server_fd,3)<0) {
        perror("listen failure");
        exit(EXIT_FAILURE);
    }

    printf("Server started at port 8080\n");

    //Loop to handle multiple client requests
    while(1) {
        //Accepting incoming connections
        sock_size =sizeof(client_address);
        if((client_fd=accept(server_fd,(struct sockaddr*)&client_address,&sock_size))<0) {
            perror("accept failure");
            exit(EXIT_FAILURE);
        }

        //Read message from client
        read(client_fd,message,MAX_LENGTH);

        //Multivariable operations
        int num1,num2,sum,product,diff;
        sscanf(message,"%d %d",&num1,&num2);
        sum =num1+num2;
        diff =num1-num2;
        product =num1*num2;

        //Sending response to client
        sprintf(response,"Sum: %d\nDifference: %d\nProduct: %d\n",sum,diff,product);
        write(client_fd,response,strlen(response));

        //Closing connection
        close(client_fd);
    }

    return 0;
}