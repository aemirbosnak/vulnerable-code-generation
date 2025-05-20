//FormAI DATASET v1.0 Category: Email Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Function to validate email address format
bool is_valid_email(char* email) {
    int at_index = -1;
    int dot_index = -1;
    
    // Find the index of @ and .
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            at_index = i;
        } else if (email[i] == '.') {
            dot_index = i;
        }
    }
    
    // Check if @ and . are in correct positions
    if (at_index == -1 || dot_index == -1 || at_index > dot_index) {
        return false;
    }
    
    // Check if there are any spaces in the email
    for (int i = 0; i < strlen(email); i++) {
        if (isspace(email[i])) {
            return false;
        }
    }
    
    return true;
}

// Function to send email
void send_email(char* sender, char* recipient, char* subject, char* body) {
    // Validate email addresses
    if (!is_valid_email(sender)) {
        printf("Invalid sender email address!\n");
        return;
    }
    
    if (!is_valid_email(recipient)) {
        printf("Invalid recipient email address!\n");
        return;
    }
    
    // Send email using SMTP protocol
    printf("Sending email...\n");
    printf("From: %s\n", sender);
    printf("To: %s\n", recipient);
    printf("Subject: %s\n", subject);
    printf("---\n%s\n---\n", body);
}

int main() {
    // Get input from user
    char sender[100], recipient[100], subject[100], body[1000];
    printf("Enter sender email address: ");
    scanf("%s", sender);
    printf("Enter recipient email address: ");
    scanf("%s", recipient);
    printf("Enter subject: ");
    scanf("%s", subject);
    printf("Enter body: ");
    scanf(" %[^\n]s", body);
    
    // Send email
    send_email(sender, recipient, subject, body);
    
    return 0;
}