//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A POP3 client in the land of surrealism */
int main() {
    printf("Welcome to the world of surreal POP3 clients!\n\n");
    
    /* Connect to server */
    printf("Connecting to server...\n\n");
    
    /* Authenticating user */
    printf("Authenticating user...\n\n");
    char username[50];
    char password[50];
    printf("Please enter your username: ");
    scanf("%s", username);
    printf("Please enter your password: ");
    scanf("%s", password);
    printf("Authenticating user %s with password %s...\n\n", username, password);
    
    /* Retrieving list of emails */
    printf("Retrieving list of emails...\n\n");
    char emails[500];
    strcpy(emails, "1  Surrealism is the best movement!\n2  I dreamt of a melting clock\n3  A lobster phone is a must-have\n");
    printf("List of emails:\n%s\n", emails);
    
    /* Selecting email */
    printf("Enter the number of the email you wish to read: ");
    int email_num;
    scanf("%d", &email_num);
    
    /* Fetching email */
    printf("Fetching email %d...\n\n", email_num);
    char email[1000];
    switch(email_num) {
        case 1:
            strcpy(email, "Subject: Surrealism\nFrom: Salvador Dali <dali@surrealism.com>\nTo: %s\n\nDear %s,\n\nI am writing to you from the land of surrealism, where everything is possible and nothing makes sense. I hope you are enjoying the journey.\n\nBest regards,\nSalvador Dali\n");
            break;
        case 2:
            strcpy(email, "Subject: Melting clocks\nFrom: Rene Magritte <magritte@surrealism.com>\nTo: %s\n\nDear %s,\n\nI am delighted to inform you that your dream of a melting clock has been registered in the surrealism archive. It is a remarkable piece of art.\n\nSincerely,\nRene Magritte\n");
            break;
        case 3:
            strcpy(email, "Subject: Lobster phone\nFrom: Meret Oppenheim <oppenheim@surrealism.com>\nTo: %s\n\nDear %s,\n\nI couldn't agree more with you about the lobster phone. It is a must-have item in any surrealist's collection. If you need any assistance in acquiring one, do not hesitate to contact me.\n\nYours sincerely,\nMeret Oppenheim\n");
            break;
        default:
            printf("Email not found.\n\n");
            exit(0);
    }
    printf(email, username, username);
    
    /* Closing connection */
    printf("\nClosing connection...\n\n");
    
    return 0;
}