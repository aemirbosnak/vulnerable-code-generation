//FormAI DATASET v1.0 Category: Email Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 587 // SMTP port number
#define MAX_BUFFER_SIZE 512 // maximum buffer size for socket communication
#define MAX_MESSAGE_LENGTH 5000 // maximum length of email message
#define MAX_RECIPIENTS 10 // maximum number of email recipients

int main(int argc, char *argv[]) {
    int sockfd, numbytes, i, j, k, rcpt_count, sent_count;
    char buffer[MAX_BUFFER_SIZE];
    char message[MAX_MESSAGE_LENGTH];
    char from_address[MAX_BUFFER_SIZE];
    char to_address[MAX_RECIPIENTS][MAX_BUFFER_SIZE];
    struct hostent *he;
    struct sockaddr_in their_addr;
    char *hostname;

    if(argc < 2) {
        printf("Usage: %s <SMTP server hostname>\n", argv[0]);
        exit(1);
    }
    hostname = argv[1];

    printf("Enter sender email address: ");
    fgets(from_address, MAX_BUFFER_SIZE, stdin);
    from_address[strcspn(from_address, "\n")] = 0; // remove trailing newline character

    printf("Enter number of recipients (up to %d): ", MAX_RECIPIENTS);
    scanf("%d", &rcpt_count);

    if(rcpt_count > MAX_RECIPIENTS) {
        printf("Error: too many recipients\n");
        exit(1);
    }

    for(i = 0; i < rcpt_count; i++) {
        printf("Enter recipient email address %d: ", i+1);
        scanf("%s", to_address[i]);
    }

    getchar(); // consume trailing newline character

    printf("Enter message text (up to %d characters):\n", MAX_MESSAGE_LENGTH);
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; // remove trailing newline character

    // establish connection with SMTP server
    if ((he=gethostbyname(hostname)) == NULL) {  
        perror("gethostbyname");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    their_addr.sin_family = AF_INET;      
    their_addr.sin_port = htons(PORT);    
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(their_addr.sin_zero), '\0', 8);  

    if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // read initial server response
    numbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    buffer[numbytes] = '\0';
    printf("Server response: %s\n", buffer);

    // send HELO command
    sprintf(buffer, "HELO %s\r\n", hostname);
    send(sockfd, buffer, strlen(buffer), 0);
    numbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    buffer[numbytes] = '\0';
    printf("Server response: %s\n",buffer);

    // send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from_address);
    send(sockfd, buffer, strlen(buffer), 0);
    numbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    buffer[numbytes] = '\0';
    printf("Server response: %s\n",buffer);

    // send RCPT TO command for each recipient
    for(i = 0; i < rcpt_count; i++) {
        sprintf(buffer, "RCPT TO:<%s>\r\n", to_address[i]);
        send(sockfd, buffer, strlen(buffer), 0);
        numbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
        buffer[numbytes] = '\0';
        printf("Server response: %s\n",buffer);
    }

    // send DATA command
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    numbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    buffer[numbytes] = '\0';
    printf("Server response: %s\n",buffer);

    // send message header and body
    sprintf(buffer, "From: <%s>\n", from_address);
    send(sockfd, buffer, strlen(buffer), 0);
    for(i = 0; i < rcpt_count; i++) {
        sprintf(buffer, "To: <%s>\n", to_address[i]);
        send(sockfd, buffer, strlen(buffer), 0);
    }
    sprintf(buffer, "Subject: Test Email\n\n");
    send(sockfd, buffer, strlen(buffer), 0);
    sprintf(buffer, "%s\n.\n", message);
    send(sockfd, buffer, strlen(buffer), 0);
    numbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    buffer[numbytes] = '\0';
    printf("Server response: %s\n",buffer);

    // end message and close connection
    send(sockfd, "QUIT\r\n", 6, 0);
    numbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    buffer[numbytes] = '\0';
    printf("Server response: %s\n",buffer);
    close(sockfd);

    // print success message
    printf("Email sent successfully to %d recipient(s)\n", rcpt_count);

    return 0;
}