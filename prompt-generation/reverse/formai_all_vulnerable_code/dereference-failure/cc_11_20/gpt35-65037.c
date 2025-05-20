//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#define BUFFSIZE 1024 

int main(int argc , char *argv[])
{
    if(argc != 3){
        printf("Usage : ./client <IP> <PORT>\n");
        exit(0);
    }
    char *ftp_commands[] = {"USER", "PASS", "SYST", "QUIT", "TYPE"};	// Allowed commands for FTP
    int sockfd, port, i, count = 0;
    struct sockaddr_in server_addr;
    char buffer[BUFFSIZE], command[100];
    
    port = atoi(argv[2]);
   
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0){
        printf("\n Socket creation error \n");
        exit(0);
    }

    bzero(&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if(inet_pton(AF_INET, argv[1], &server_addr.sin_addr)<=0){
        printf("\nInvalid address/ Address not supported \n");
        exit(0);
    }

    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr))<0){
        printf("\nConnection Failed \n");
        exit(0);
    }

    printf("\n**********************************************************");
    printf("\n*** Welcome to FTP client, type HELP for FTP commands list *** ");
    printf("\n**************************************************************");
    printf("\nEnter command : ");

    while(1)
    {
    	if(count == 0)
    	{
    		bzero(command, sizeof(command));
    		strcpy(command, "USER ");
    		printf("\nEnter username : ");
    		scanf("%s", buffer);
    		strcat(command, buffer);
    		strcat(command, "\r\n");
    		write(sockfd, command, strlen(command));
    		bzero(buffer, sizeof(buffer));
    		read(sockfd, buffer, sizeof(buffer));
    		buffer[strcspn(buffer, "\n")] = '\0';
    		printf("%s\n", buffer);
    		count++;
    	}

    	else if(count == 1)
    	{
    		bzero(command, sizeof(command));
    		strcpy(command, "PASS ");
    		printf("\nEnter password : ");
    		scanf("%s", buffer);
    		strcat(command, buffer);
    		strcat(command, "\r\n");
    		write(sockfd, command, strlen(command));
    		bzero(buffer, sizeof(buffer));
    		read(sockfd, buffer, sizeof(buffer));
    		buffer[strcspn(buffer, "\n")] = '\0';
    		printf("%s\n", buffer);
    		count++;
    	}

    	else
    	{
    		printf("\nEnter command : ");
	    	bzero(buffer, sizeof(buffer));
	    	scanf("%s", buffer);
	    	if(strcmp(buffer, "QUIT") == 0)
	    	{
	    		write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
	    		read(sockfd, buffer, sizeof(buffer));
	    		buffer[strcspn(buffer, "\n")] = '\0';
	    		printf("%s\n", buffer);
	    		close(sockfd);
	    		exit(0);
	    	}
	    	if(strcmp(buffer, "HELP") == 0)
	    	{
	    		printf("\nFTP Commands:\n");
	    		for(i = 0; i < 5; i++)
	    		{
	    			printf("%s\n", ftp_commands[i]);
	    		}
	    	}
	    	if(strcmp(buffer, "TYPE") == 0)
	    	{
	    		bzero(command, sizeof(command));
	    		strcpy(command, "TYPE ");
	    		printf("\nEnter transmission type (A for ASCII, I for image/Binary) : ");
	    		scanf("%s", buffer);
	    		strcat(command, buffer);
	    		strcat(command, "\r\n");
	    		write(sockfd, command, strlen(command));
	    		bzero(buffer, sizeof(buffer));
	    		read(sockfd, buffer, sizeof(buffer));
	    		buffer[strcspn(buffer, "\n")] = '\0';
	    		printf("%s\n", buffer);
	    	}
	    	if(strcmp(buffer, "SYST") == 0)
	    	{
	    		write(sockfd, "SYST\r\n", strlen("SYST\r\n"));
	    		bzero(buffer, sizeof(buffer));
	    		read(sockfd, buffer, sizeof(buffer));
	    		buffer[strcspn(buffer, "\n")] = '\0';
	    		printf("%s\n", buffer);
	    	}
    	}
    }
}