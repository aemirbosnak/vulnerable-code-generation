//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(const char *msg){ // Function to print error message
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char temp[BUFFER_SIZE];
    FILE *fp;
    long filesize;

    if (argc < 3) { // Check if user entered enough arguments
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]); // Convert port number string to integer

    sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create socket

    if (sockfd < 0) 
        error("ERROR opening socket");

    server = gethostbyname(argv[1]); // Get server IP address from hostname

    if (server == NULL) { // Check if host name is valid
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset(&serv_addr,0,sizeof(serv_addr)); // Clear server address structure
    serv_addr.sin_family = AF_INET; // Set address family
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length); // Copy IP address
    serv_addr.sin_port = htons(portno); // Convert port number to network byte order

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) // Connect to server
        error("ERROR connecting");

    printf("Connected to server.\n");

    while(1){ // Loop until user enters "quit"

        printf("Enter command: ");
        fgets(buffer,BUFFER_SIZE,stdin); // Get command input from user

        if(strncmp(buffer,"quit",4) == 0){ // Check if user wants to quit
            printf("Goodbye.\n");
            break;
        }

        char command[BUFFER_SIZE];
        strcpy(temp,buffer);
        sscanf(temp,"%s",command); // Get first word of command 

        if(strncmp(command,"get",3) == 0){ // Check if user wants to download file from server

            send(sockfd,buffer,strlen(buffer),0); // Send command to server

            memset(buffer,0,BUFFER_SIZE); // Clear buffer

            n = recv(sockfd, buffer, BUFFER_SIZE, 0); // Receive filesize from server
            if(n < 0)
                error("ERROR receiving data");

            filesize = atol(buffer); // Convert filesize string to long int

            if(filesize < 0){ // If file does not exist on server
                printf("File not found.\n");
                continue;
            }

            fp = fopen(strtok(buffer,"\n"),"wb"); // Create file to store downloaded data

            printf("Downloading file...\n");

            for(int i=0;i<filesize;i+=n){ // Loop until all data is received

                memset(buffer,0,BUFFER_SIZE); // Clear buffer

                n = recv(sockfd, buffer, BUFFER_SIZE, 0); // Receive data from server

                if(n < 0)
                    error("ERROR receiving data");

                fwrite(buffer,1,n,fp); // Write data to file

                if(i+n >= filesize) // If file transfer is complete
                    printf("File transfer complete.\n");
            }

            fclose(fp); // Close file descriptor

        }else if(strncmp(command,"put",3) == 0){ // Check if user wants to upload file to server

            send(sockfd,buffer,strlen(buffer),0); // Send command to server

            memset(buffer,0,BUFFER_SIZE); // Clear buffer

            if((fp=fopen(strtok(buffer+4,"\n"),"rb"))==NULL){ // Open file for reading
                printf("File not found.\n");
                send(sockfd,"-1",2,0); // Tell server that file is not found
                continue;
            }else{
                fseek(fp,0,SEEK_END);
                filesize = ftell(fp); // Get filesize of file
                fseek(fp,0,SEEK_SET);
                sprintf(buffer,"%ld",filesize); // Convert filesize to string
                send(sockfd,buffer,strlen(buffer),0); // Send filesize to server
            }

            printf("Uploading file...\n");

            for(int i=0;i<filesize;i+=n){ // Loop until all data is sent

                memset(buffer,0,BUFFER_SIZE); // Clear buffer

                n = fread(buffer,1,BUFFER_SIZE,fp); // Read data from file

                send(sockfd,buffer,n,0); // Send data to server

                if(i+n >= filesize) // If file transfer is complete
                    printf("File transfer complete.\n");
            }

            fclose(fp); // Close file descriptor

        }else{ // If command is not get or put
            send(sockfd,buffer,strlen(buffer),0); // Send command to server

            memset(buffer,0,BUFFER_SIZE); // Clear buffer

            n = recv(sockfd, buffer, BUFFER_SIZE, 0); // Receive response from server

            if(n < 0)
                error("ERROR receiving data");

            printf("%s",buffer); // Print response from server
        }

    }

    close(sockfd); // Close socket

    return 0;
}