//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAXLINE 1024
#define MAXSERVER 100
#define MAXUSER 100

int port = 143; // default imap port
char server[MAXLINE], username[MAXLINE], password[MAXLINE];
int sock;
int tag = 0;

void connect_server();
void send_command(char *command);
void receive_response();
void login();
void list_mailbox();
void select_mailbox(char *mailbox);
void fetch_mail(int mail_number);

int main()
{
    printf("Enter server: ");
    fgets(server, MAXSERVER, stdin);
    server[strlen(server)-1] = '\0'; // remove newline character
    
    printf("Enter username: ");
    fgets(username, MAXUSER, stdin);
    username[strlen(username)-1] = '\0'; // remove newline character
    
    printf("Enter password: ");
    fgets(password, MAXLINE, stdin);
    password[strlen(password)-1] = '\0'; // remove newline character
    
    connect_server();
    login();
    list_mailbox();
    
    char mailbox[MAXLINE];
    printf("Enter mailbox name to select: ");
    fgets(mailbox, MAXLINE, stdin);
    mailbox[strlen(mailbox)-1] = '\0'; // remove newline character
    
    select_mailbox(mailbox);
    
    int mail_number;
    printf("Enter mail number to fetch: ");
    scanf("%d", &mail_number);
    getchar(); // consume newline character left by scanf
    
    fetch_mail(mail_number);
    
    return 0;
}

void connect_server()
{
    struct sockaddr_in servaddr;
    struct hostent *host;
    
    if ((host = gethostbyname(server)) == NULL) {
        printf("Error: Host not found\n");
        exit(1);
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Cannot create socket\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr = *((struct in_addr *)host->h_addr);
    
    if (connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error: Cannot connect to server\n");
        exit(1);
    }
    
    receive_response();
}

void send_command(char *command)
{
    dprintf(sock, "%d %s\r\n", ++tag, command);
}

void receive_response()
{
    char response[MAXLINE];
    int len;
    
    while (1) {
        len = read(sock, response, MAXLINE-1);
        if (len < 0) {
            printf("Error: Cannot read response from server\n");
            exit(1);
        }
        
        response[len] = '\0';
        printf("%s", response);
        
        if (response[0] == tag+'0' && response[1] == ' ') {
            break;
        }
    }
}

void login()
{
    char command[MAXLINE];
    
    // send LOGIN command
    sprintf(command, "LOGIN %s %s", username, password);
    send_command(command);
    receive_response();
}

void list_mailbox()
{
    send_command("LIST \"\" *");
    receive_response();
}

void select_mailbox(char *mailbox)
{
    char command[MAXLINE];
    
    // send SELECT command
    sprintf(command, "SELECT %s", mailbox);
    send_command(command);
    receive_response();
}

void fetch_mail(int mail_number)
{
    char command[MAXLINE];
    
    // send FETCH command
    sprintf(command, "FETCH %d FULL", mail_number);
    send_command(command);
    receive_response();
}