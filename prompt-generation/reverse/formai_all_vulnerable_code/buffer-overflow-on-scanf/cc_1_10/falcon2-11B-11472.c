//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

// Function to send an email
void sendEmail(char* recipient, char* subject, char* body)
{
    char buffer[2048];
    int status = 0;
    FILE *fp;

    sprintf(buffer, "Subject: %s\n\n%s", subject, body);

    fp = fopen("email.txt", "w");
    fputs(buffer, fp);
    fclose(fp);

    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error creating socket\n");
        return;
    }

    // Create a server address structure
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(25);
    server_address.sin_addr.s_addr = inet_addr("localhost");

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Error connecting to the server\n");
        return;
    }

    // Send the email
    int n = send(socket_fd, buffer, strlen(buffer), 0);
    if (n == -1) {
        printf("Error sending email\n");
        return;
    }

    // Close the socket
    close(socket_fd);
}

int main()
{
    char recipient[100];
    char subject[100];
    char body[100];

    printf("Enter recipient's email address: ");
    scanf("%s", recipient);

    printf("Enter subject: ");
    scanf("%s", subject);

    printf("Enter body of the email: ");
    scanf("%s", body);

    sendEmail(recipient, subject, body);

    return 0;
}