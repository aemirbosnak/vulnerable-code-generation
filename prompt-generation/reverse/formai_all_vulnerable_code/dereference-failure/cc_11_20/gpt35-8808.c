//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Alan Touring
// IMAP Client Example Program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s server_address username\n", argv[0]);
        exit(1);
    }

    // Step 1: Establish a TCP connection to the IMAP server using port 143
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: No such host %s\n", argv[1]);
        exit(1);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(143);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Step 2: Login to the server using the specified username and password
    char username[MAX_BUFFER_SIZE];
    strcpy(username, argv[2]);

    char password[MAX_BUFFER_SIZE];
    printf("Please enter your password: ");
    fgets(password, MAX_BUFFER_SIZE, stdin);

    char login_command[MAX_BUFFER_SIZE];
    sprintf(login_command, "1 LOGIN %s %s\n", username, password);

    write(sockfd, login_command, strlen(login_command));

    char response[MAX_BUFFER_SIZE];
    read(sockfd, response, MAX_BUFFER_SIZE);
    if (strstr(response, "OK") == NULL) {
        printf("Error: Invalid username or password\n");
        exit(1);
    }

    // Step 3: Fetch the list of all mailboxes on the server
    char list_command[MAX_BUFFER_SIZE];
    sprintf(list_command, "2 LIST \"\" *\n");

    write(sockfd, list_command, strlen(list_command));

    memset(response, 0, sizeof(response));
    read(sockfd, response, MAX_BUFFER_SIZE);

    char *mailbox_list = strstr(response, "* LIST");
    while (mailbox_list != NULL) {
        char *end_of_line = strchr(mailbox_list, '\n');
        if (end_of_line == NULL) {
            break;
        }
        *end_of_line = '\0';
        printf("%s\n", mailbox_list);
        mailbox_list = strstr(end_of_line + 1, "* LIST");
    }

    // Step 4: Select a mailbox to examine
    printf("Please enter the name of the mailbox you want to examine: ");
    char mailbox_name[MAX_BUFFER_SIZE];
    fgets(mailbox_name, MAX_BUFFER_SIZE, stdin);

    char select_command[MAX_BUFFER_SIZE];
    sprintf(select_command, "3 SELECT \"%s\"\n", mailbox_name);

    write(sockfd, select_command, strlen(select_command));

    memset(response, 0, sizeof(response));
    read(sockfd, response, MAX_BUFFER_SIZE);
    if (strstr(response, "OK") == NULL) {
        printf("Error: Invalid mailbox name\n");
        exit(1);
    }

    // Step 5: Fetch the list of all messages in the selected mailbox
    char search_command[MAX_BUFFER_SIZE];
    sprintf(search_command, "4 UID SEARCH ALL\n");

    write(sockfd, search_command, strlen(search_command));

    memset(response, 0, sizeof(response));
    read(sockfd, response, MAX_BUFFER_SIZE);

    char *uid_list = strstr(response, "* SEARCH");
    while (uid_list != NULL) {
        char *end_of_line = strchr(uid_list, '\n');
        if (end_of_line == NULL) {
            break;
        }
        *end_of_line = '\0';

        char fetch_command[MAX_BUFFER_SIZE];
        sprintf(fetch_command, "5 UID FETCH %s (BODY[HEADER.FIELDS (SUBJECT DATE FROM)])\n", uid_list);
        write(sockfd, fetch_command, strlen(fetch_command));

        memset(response, 0, sizeof(response));
        read(sockfd, response, MAX_BUFFER_SIZE);
        printf("%s\n", response);

        uid_list = strstr(end_of_line + 1, "* SEARCH");
    }

    // Step 6: Logout from the server
    char logout_command[MAX_BUFFER_SIZE];
    sprintf(logout_command, "6 LOGOUT\n");

    write(sockfd, logout_command, strlen(logout_command));

    close(sockfd);
    return 0;
}