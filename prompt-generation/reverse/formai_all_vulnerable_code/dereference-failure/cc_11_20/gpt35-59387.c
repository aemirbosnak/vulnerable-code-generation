//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: relaxed
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

int main(int argc, char* argv[])
{
    if(argc != 4)
    {
        printf("Usage : %s <server_address> <server_port> <email_address_to_send_to>\n", argv[0]);
        return 0;
    }

    int socket_server = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_server == -1)
    {
        printf("Error creating socket\n");
        return 0;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    server_address.sin_addr.s_addr = inet_addr(argv[1]);

    if(connect(socket_server, (struct sockaddr*)&server_address, sizeof(server_address)) == -1)
    {
        printf("Error connecting to server\n");
        return 0;
    }

    char buffer[1024];
    memset(buffer, 0, 1024);
    int bytes_received = recv(socket_server, buffer, 1024, 0);
    if(bytes_received == -1)
    {
        printf("Error receiving response from server\n");
        return 0;
    }
    printf("%s", buffer);

    char email_address[100];
    printf("Enter your email address: ");
    scanf("%s", email_address);

    char helo_command[100];
    sprintf(helo_command, "HELO %s\r\n", email_address);
    send(socket_server, helo_command, strlen(helo_command), 0);

    memset(buffer, 0, 1024);
    bytes_received = recv(socket_server, buffer, 1024, 0);
    if(bytes_received == -1)
    {
        printf("Error receiving response from server\n");
        return 0;
    }
    printf("%s", buffer);

    char mail_from[100];
    printf("Enter source email address: ");
    scanf("%s", mail_from);
    char mail_from_command[100];
    sprintf(mail_from_command, "MAIL FROM: <%s>\r\n", mail_from);
    send(socket_server, mail_from_command, strlen(mail_from_command), 0);

    memset(buffer, 0, 1024);
    bytes_received = recv(socket_server, buffer, 1024, 0);
    if(bytes_received == -1)
    {
        printf("Error receiving response from server\n");
        return 0;
    }
    printf("%s", buffer);

    char rcpt_to[100];
    printf("Enter destination email address: ");
    scanf("%s", rcpt_to);
    char rcpt_to_command[100];
    sprintf(rcpt_to_command, "RCPT TO: <%s>\r\n", rcpt_to);
    send(socket_server, rcpt_to_command, strlen(rcpt_to_command), 0);

    memset(buffer, 0, 1024);
    bytes_received = recv(socket_server, buffer, 1024, 0);
    if(bytes_received == -1)
    {
        printf("Error receiving response from server\n");
        return 0;
    }
    printf("%s", buffer);

    char data_command[] = "DATA\r\n";
    send(socket_server, data_command, strlen(data_command), 0);

    memset(buffer, 0, 1024);
    bytes_received = recv(socket_server, buffer, 1024, 0);
    if(bytes_received == -1)
    {
        printf("Error receiving response from server\n");
        return 0;
    }
    printf("%s", buffer);

    char message[1024];
    printf("Enter message: \n");
    fgets(message, sizeof(message), stdin);
    fgets(message, sizeof(message), stdin);

    char from_command[100];
    sprintf(from_command, "From: <%s>\r\n", mail_from);
    send(socket_server, from_command, strlen(from_command), 0);

    char to_command[100];
    sprintf(to_command, "To: <%s>\r\n", rcpt_to);
    send(socket_server, to_command, strlen(to_command), 0);

    char subject_command[] = "Subject: SMTP Client\r\n";
    send(socket_server, subject_command, strlen(subject_command), 0);

    char data_message[1024];
    sprintf(data_message, "%s\r\n.\r\n", message);
    send(socket_server, data_message, strlen(data_message), 0);

    memset(buffer, 0, 1024);
    bytes_received = recv(socket_server, buffer, 1024, 0);
    if(bytes_received == -1)
    {
        printf("Error receiving response from server\n");
        return 0;
    }
    printf("%s", buffer);

    char quit_command[] = "QUIT\r\n";
    send(socket_server, quit_command, strlen(quit_command), 0);

    memset(buffer, 0, 1024);
    bytes_received = recv(socket_server, buffer, 1024, 0);
    if(bytes_received == -1)
    {
        printf("Error receiving response from server\n");
        return 0;
    }
    printf("%s", buffer);

    close(socket_server);
    return 0;
}