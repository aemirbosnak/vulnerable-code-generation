//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<ctype.h>

void error(char * message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    printf("Enter the email recipient: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);

    char to_address[256];
    strncpy(to_address, buffer, strlen(buffer)-1);
    to_address[strlen(buffer)-1] = '\0';

    for(int i=0;i<strlen(to_address);i++)
        to_address[i] = tolower(to_address[i]);

    printf("Enter your email address: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);

    char from_address[256];
    strncpy(from_address, buffer, strlen(buffer)-1);
    from_address[strlen(buffer)-1] = '\0';

    for(int i=0;i<strlen(from_address);i++)
        from_address[i] = tolower(from_address[i]);

    printf("Enter your email username: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);

    char username[256];
    strncpy(username, buffer, strlen(buffer)-1);
    username[strlen(buffer)-1] = '\0';

    for(int i=0;i<strlen(username);i++)
        username[i] = tolower(username[i]);

    printf("Enter your email password: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);

    char password[256];
    strncpy(password, buffer, strlen(buffer)-1);
    password[strlen(buffer)-1] = '\0';

    int len;
    char msg[1024];

    len=sprintf(msg,"EHLO localhost\n");
    n = write(sockfd,msg,len);
    if (n < 0) 
         error("ERROR writing to socket");

    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);

    len=sprintf(msg,"AUTH LOGIN\n");
    n = write(sockfd,msg,len);
    if (n < 0) 
         error("ERROR writing to socket");

    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);

    len=sprintf(msg,"%s\n",username);
    n = write(sockfd,msg,len);
    if (n < 0) 
         error("ERROR writing to socket");

    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);

    len=sprintf(msg,"%s\n",password);
    n = write(sockfd,msg,len);
    if (n < 0) 
         error("ERROR writing to socket");

    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);

    len=sprintf(msg,"MAIL FROM: <%s>\n", from_address);
    n = write(sockfd,msg,len);
    if (n < 0) 
         error("ERROR writing to socket");

    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);

    len=sprintf(msg,"RCPT TO: <%s>\n", to_address);
    n = write(sockfd,msg,len);
    if (n < 0) 
         error("ERROR writing to socket");

    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);

    len=sprintf(msg,"DATA\n");
    n = write(sockfd,msg,len);
    if (n < 0) 
         error("ERROR writing to socket");

    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);

    len=sprintf(msg,"SUBJECT: Test Mail\n");
    n = write(sockfd,msg,len);
    if (n < 0) 
         error("ERROR writing to socket");

    len=sprintf(msg,"From: %s\n", from_address);
    n = write(sockfd,msg,len);
    if (n < 0) 
         error("ERROR writing to socket");

    len=sprintf(msg,"To: %s\n", to_address);
    n = write(sockfd,msg,len);
    if (n < 0) 
         error("ERROR writing to socket");

    len=sprintf(msg,"\nThis is a test email from smtp client\n");
    n = write(sockfd,msg,len);
    if (n < 0) 
         error("ERROR writing to socket");

    len=sprintf(msg,".\n");
    n = write(sockfd,msg,len);
    if (n < 0) 
         error("ERROR writing to socket");

    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);

    len=sprintf(msg,"QUIT\n");
    n = write(sockfd,msg,len);
    if (n < 0) 
         error("ERROR writing to socket");

    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);

    close(sockfd);
    return 0;
}