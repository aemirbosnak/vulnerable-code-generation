//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: surprised
#include <stdio.h> //Standard Input Output Library
#include <stdlib.h> //Standard Library 
#include <sys/socket.h> //Socket Library
#include <netinet/in.h> //Internet Library
#include <arpa/inet.h> //Address Resolution Protocol Library

int main() //Main function
{
    printf("Welcome to the SMTP Client Program!\n"); //Welcome Message
    printf("Please enter the IP address of the SMTP server: \n"); //Prompt for IP Address
    char ip_address[20]; //Initialize a character array to store IP Address
    scanf("%s",ip_address); //Scan the user input IP Address
    printf("Please enter the port number of the SMTP server: \n"); //Prompt for Port Number
    int port_number; //Initialize a variable to store Port Number
    scanf("%d",&port_number); //Scan the user input Port Number

    struct sockaddr_in server_address; //Declare a structure to hold the server address
    server_address.sin_family = AF_INET; //Specify Address Family
    server_address.sin_port = htons(port_number); //Specify Port Number

    if(inet_pton(AF_INET, ip_address, &server_address.sin_addr)<=0) //Check for IP Address Validity
    {
        printf("\nInvalid address/ Address not supported \n"); //Invalid IP Address
        return -1; //Exit Program
    }

    int client_socket; //Declare Client Socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) //Create Socket
    {
        printf("\n Socket creation error \n"); //Socket Creation Error
        return -1; //Exit Program
    }

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) //Connect to Server
    {
        printf("\nConnection Failed \n"); //Connection Error
        return -1; //Exit Program
    }

    printf("Connection Established Successfully!\n"); //Connection Successful Message

    char username[20], password[20], from[20], to[20], subject[100], body[500]; 
    printf("Please enter your email address: \n");
    scanf("%s",from);
    printf("Please enter your email password: \n");
    scanf("%s",password);
    printf("Please enter the recipient's email address: \n");
    scanf("%s",to);
    printf("Please enter the email subject: \n");
    scanf("%s",subject);
    printf("Please enter the email body: \n");
    scanf("%s",body);

    char email[1000];
    sprintf(email, "From: %s\nTo: %s\nSubject: %s\n\n%s", from, to, subject, body);

    char message[1024] = {0};
    char *quit = "QUIT\r\n";
    char *auth_login = "AUTH LOGIN\r\n";
    char *mail_from = "MAIL FROM:<%s>\r\n";
    char *rcpt_to = "RCPT TO:<%s>\r\n";
    char *data = "DATA\r\n";
    char *end_data = "\r\n.\r\n";

    send(client_socket,auth_login,strlen(auth_login),0);
    recv(client_socket, message, 1024, 0);

    char encoded_username[20];
    char encoded_password[20];
    sprintf(encoded_username, "%s", username);
    sprintf(encoded_password, "%s", password);
    send(client_socket, encoded_username, strlen(encoded_username), 0);
    send(client_socket, "\r\n", 2, 0);

    recv(client_socket, message, 1024, 0);
    send(client_socket, encoded_password, strlen(encoded_password), 0);
    send(client_socket, "\r\n", 2, 0);

    recv(client_socket, message, 1024, 0);
    sprintf(message, mail_from, from);
    send(client_socket, message, strlen(message), 0);
    recv(client_socket, message, 1024, 0);

    sprintf(message, rcpt_to, to);
    send(client_socket, message, strlen(message), 0);
    recv(client_socket, message, 1024, 0);

    send(client_socket, data, strlen(data), 0);
    recv(client_socket, message, 1024, 0);

    send(client_socket, email, strlen(email), 0);
    send(client_socket, end_data, strlen(end_data), 0);
    recv(client_socket, message, 1024, 0);

    send(client_socket, quit, strlen(quit), 0);
    recv(client_socket, message, 1024, 0);

    printf("Email Sent Successfully!"); //Email Sent Successfully Message
    return 0; //Exit Program
}