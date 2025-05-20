//FormAI DATASET v1.0 Category: Email Client ; Style: authentic
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024 // Size of the buffer used for sending/receiving messages
#define MAX_EMAILS 50 // Maximum number of emails that can be stored in the inbox

// Email structure
typedef struct Email {
  char* sender; // Sender email address
  char* recipient; // Recipient email address
  char* subject; // Email subject
  char* message; // Email message
} Email;

// Inbox structure
typedef struct Inbox {
  int count; // Number of emails in inbox
  Email emails[MAX_EMAILS]; // Emails in inbox
} Inbox;

// Function to send an email
void send_email(char* server_ip, int server_port, char* sender, char* recipient, char* subject, char* message) {
  int sock = socket(AF_INET, SOCK_STREAM, 0); // Create socket
  if (sock == -1) {
    perror("Socket error");
    exit(1);
  }
  
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(server_port);
  if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
    perror("Invalid IP address");
    exit(1);
  }
  
  if (connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) { // Connect to server
    perror("Connection error");
    exit(1);
  }
  
  char buf[BUF_SIZE];
  sprintf(buf, "From:%s\nTo:%s\nSubject:%s\n\n%s", sender, recipient, subject, message); // Construct email message
  if (send(sock, buf, strlen(buf), 0) == -1) { // Send email message
    perror("Send error");
    exit(1);
  }
  
  close(sock); // Close socket
}

// Function to receive an email and add it to the inbox
void receive_email(Inbox* inbox, char* server_ip, int server_port, char* recipient) {
  int sock = socket(AF_INET, SOCK_STREAM, 0); // Create socket
  if (sock == -1) {
    perror("Socket error");
    exit(1);
  }
  
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(server_port);
  if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
    perror("Invalid IP address");
    exit(1);
  }
  
  if (connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) { // Connect to server
    perror("Connection error");
    exit(1);
  }
  
  char buf[BUF_SIZE];
  sprintf(buf, "To:%s", recipient); // Construct request message
  if (send(sock, buf, strlen(buf), 0) == -1) { // Send request message
    perror("Send error");
    exit(1);
  }
  
  int bytes_received = recv(sock, buf, BUF_SIZE - 1, 0); // Receive email message
  if (bytes_received == -1) {
    perror("Receive error");
    exit(1);
  }
  buf[bytes_received] = '\0';
  
  Email email;
  email.sender = strtok(buf, "\n") + strlen("From:");
  email.recipient = strtok(NULL, "\n") + strlen("To:");
  email.subject = strtok(NULL, "\n") + strlen("Subject:");
  email.message = strtok(NULL, "\n") + 1;
  
  inbox->emails[inbox->count] = email; // Add email to inbox
  inbox->count++;
  
  close(sock); // Close socket
}

// Function to display the inbox
void display_inbox(Inbox* inbox) {
  printf("You have %d emails in your inbox:\n", inbox->count);
  for (int i = 0; i < inbox->count; i++) {
    printf("Email #%d\n", i + 1);
    printf("Sender: %s\n", inbox->emails[i].sender);
    printf("Recipient: %s\n", inbox->emails[i].recipient);
    printf("Subject: %s\n", inbox->emails[i].subject);
    printf("Message: %s\n", inbox->emails[i].message);
  }
}

int main() {
  Inbox inbox = {0};
  
  while (1) {
    // Display menu
    printf("\nWhat would you like to do?\n");
    printf("1. Send an email\n");
    printf("2. Receive emails\n");
    printf("3. Display inbox\n");
    printf("4. Exit\n");
    
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Read newline character
    
    switch (choice) {
      case 1:
        printf("\nEnter the following details:\n");
        
        char sender[BUF_SIZE], recipient[BUF_SIZE], subject[BUF_SIZE], message[BUF_SIZE];
        printf("Sender email address: ");
        fgets(sender, BUF_SIZE, stdin);
        printf("Recipient email address: ");
        fgets(recipient, BUF_SIZE, stdin);
        printf("Email subject: ");
        fgets(subject, BUF_SIZE, stdin);
        printf("Email message: ");
        fgets(message, BUF_SIZE, stdin);
        
        send_email("127.0.0.1", 8080, sender, recipient, subject, message); // Send email to server
        
        printf("\nEmail sent!\n");
        break;
        
      case 2:
        printf("\nReceiving emails...\n");
        
        receive_email(&inbox, "127.0.0.1", 8080, "youremail@example.com"); // Receive email from server
        
        printf("\nEmail received!\n");
        break;
        
      case 3:
        printf("\nDisplaying inbox...\n");
        
        display_inbox(&inbox); // Display inbox
        
        break;
        
      case 4:
        printf("\nGoodbye!\n");
        exit(0);
        
      default:
        printf("\nInvalid choice. Please try again.\n");
    }
  }
  
  return 0;
}