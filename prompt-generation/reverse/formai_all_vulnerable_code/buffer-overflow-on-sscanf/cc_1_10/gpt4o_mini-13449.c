//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 993
#define BUFFER_SIZE 4096

void print_bunny() {
    printf("  \\(\\\n");
    printf("  ( -_-\n");
    printf("  ( >_<\n");
    printf("   _|_||_\n");
    printf("  (__|__|__)\n");
}

void display_help() {
    printf("Welcome to the Hilariously Unprofessional IMAP Client!\n");
    printf("1. HELP - Show this message\n");
    printf("2. CONNECT <host> - Connect to your email server (Yes, like magic!)\n");
    printf("3. LIST - List your mailboxes (Hold your horses!)\n");
    printf("4. FETCH <mailbox> - Fetch emails (Don't get lost in there!)\n");
    printf("5. LOGOUT - Log out (Don't let the door hit you on the way out!)\n");
    printf("6. EXIT - Exit (Don't let the bunny bite!)\n");
}

int main() {
    char buf[BUFFER_SIZE];
    char command[ BUFFER_SIZE ];
    int sockfd;
    struct sockaddr_in server_addr;

    print_bunny();
    display_help();
    
    while(1) {
        printf("\nEnter your command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0'; // remove newline

        if (strncmp(command, "HELP", 4) == 0) {
            display_help();
        } 
        else if (strncmp(command, "CONNECT", 7) == 0) {
            char host[BUFFER_SIZE];
            sscanf(command + 8, "%s", host); // Extract host name
            printf("Attempting to connect to %s...\n", host);

            // Creating socket
            if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                perror("Socket creation failed");
                exit(EXIT_FAILURE);
            }

            memset(&server_addr, 0, sizeof(server_addr));
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(PORT);
            
            // Convert IPv4 and IPv6 addresses from text to binary form
            if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
                printf("Invalid address/ Address not supported \n");
                continue;
            }

            // Connecting to server
            if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
                perror("Connection failed");
                continue;
            }
            printf("Connected to %s! What a way to start the day!\n", host);
        } 
        else if (strncmp(command, "LIST", 4) == 0) {
            printf("Listing mailboxes:\n");
            // Example dummy mailboxes
            printf("- Inbox (Where junk goes to play)\n");
            printf("- Sent (When you really want someone to see your chocolate cake recipe)\n");
            printf("- Spam (A curious case of misplaced squirrels)\n");
        } 
        else if (strncmp(command, "FETCH", 5) == 0) {
            char mailbox[BUFFER_SIZE];
            sscanf(command + 6, "%s", mailbox); // Extract mailbox name
            printf("Fetching emails from %s...\n", mailbox);
            // Here's where the magic happens... Or not.
            printf("Oh dear! It seems your inbox is as empty as my heart.\n");
        } 
        else if (strncmp(command, "LOGOUT", 6) == 0) {
            printf("Logging out... If only life had a logout button!\n");
            close(sockfd);
            break;
        } 
        else if (strncmp(command, "EXIT", 4) == 0) {
            printf("Exiting with a poof and a puff...\n");
            if (sockfd) close(sockfd);
            break;
        } 
        else {
            printf("Invalid command! Try again or consult the bunny!\n");
        }
    }
    
    printf("Thank you for using the Hilariously Unprofessional IMAP Client!\n");
    print_bunny();
    return 0;
}