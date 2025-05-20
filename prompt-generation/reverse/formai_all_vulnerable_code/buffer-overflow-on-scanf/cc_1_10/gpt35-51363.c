//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: secure
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>

//Function to get IP address from hostname
char* resolve_hostname(char* hostname){
    struct hostent* host;
    struct in_addr **addr_list;
    int i;

    if((host = gethostbyname(hostname)) == NULL){
        printf("Could not resolve hostname\n");
        return NULL;
    }

    addr_list = (struct in_addr**) host->h_addr_list;
    char* ip = malloc(INET_ADDRSTRLEN);
    for(i = 0; addr_list[i] != NULL; i++){
        strcpy(ip, inet_ntoa(*addr_list[i]));
    }

    return ip;
}

void send_command(int sockfd, char* command, char* response){

    int bytes_sent = send(sockfd, command, strlen(command), 0);
    if (bytes_sent == -1){
        printf("Error: Failed to send message\n");
        exit(1);
    }

    int bytes_received = recv(sockfd, response, 1024, 0);
    if (bytes_received == -1){
        printf("Error: Failed to receive message\n");
        exit(1);
    }
    response[bytes_received] = '\0';

}

int main(int argc, char* argv[]){

    //check if inputs are valid
    if(argc != 4){
        printf("Usage: %s <hostname> <port> <email>\n", argv[0]);
        return 1;
    }

    //get IP address from hostname
    char* ip = resolve_hostname(argv[1]);
    if(ip == NULL){
        return 1;
    }

    //create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        printf("Error: Failed to create socket\n");
        return 1;
    }

    //connect to server
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(ip);

    if(connect(sockfd, (struct sockaddr*) &server, sizeof(server)) == -1){
        printf("Error: Failed to connect to server\n");
        close(sockfd);
        return 1;
    }

    //receive greeting from server
    char response[1024];
    int bytes_received = recv(sockfd, response, 1024, 0);
    if (bytes_received == -1){
        printf("Error: Failed to receive greeting from server\n");
        close(sockfd);
        return 1;
    }
    response[bytes_received] = '\0';

    printf("%s", response);

    //send email command
    char command[1024];
    sprintf(command, "EHLO %s\r\n", argv[1]);
    send_command(sockfd, command, response);

    printf("%s", response);

    //send login command
   	sprintf(command, "AUTH LOGIN\r\n");
   	send_command(sockfd, command, response);
   	printf("%s", response);

   	char username[1024];
   	printf("Enter email password: ");
   	scanf("%s", username);

   	sprintf(command, "%s\r\n", username);
   	send_command(sockfd, command, response);
   	printf("%s", response);

   	sprintf(command, "%s\r\n", username);
   	send_command(sockfd, command, response);
   	printf("%s", response);

   	//send mail command
   	sprintf(command, "MAIL FROM:<%s>\r\n", argv[3]);
   	send_command(sockfd, command, response);
   	printf("%s", response);

   	sprintf(command, "RCPT TO:<%s>\r\n", argv[3]);
   	send_command(sockfd, command, response);
   	printf("%s", response);

   	//send data command
   	sprintf(command, "DATA\r\n");
   	send_command(sockfd, command, response);
   	printf("%s", response);

   	//enter email body
   	memset(command, 0, sizeof(command));
   	strcpy(command, "Subject: SMTP Client Example\r\n");
   	strcat(command, "From: <");
   	strcat(command, argv[3]);
   	strcat(command, ">\r\n");
   	strcat(command, "To: <");
   	strcat(command, argv[3]);
   	strcat(command, ">\r\n");
   	strcat(command, "This is a test email sent through a SMTP client.\r\n.\r\n");
   	send(sockfd, command, strlen(command), 0);

   	close(sockfd);

   	return 0;
}