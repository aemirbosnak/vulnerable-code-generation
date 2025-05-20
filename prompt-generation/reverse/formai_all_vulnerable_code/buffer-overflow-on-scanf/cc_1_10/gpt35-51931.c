//FormAI DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email {  // Structure to hold email data.
    char from[50];
    char to[50];
    char subject[100];
    char body[1000];
};

int main() {
    struct email inbox[100];  // Array of emails.
    int inbox_size = 0;  // Current size of inbox.
    
    int option;  // Menu option.
    
    do {
        // Menu options
        printf("Email Client\n");
        printf("1. Compose email\n");
        printf("2. View Inbox\n");
        printf("3. Exit\n");
        printf("Enter option number: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:  // Compose a new email.
                printf("From: ");
                scanf("%s", inbox[inbox_size].from);
                
                printf("To: ");
                scanf("%s", inbox[inbox_size].to);
                
                printf("Subject: ");
                scanf("%s", inbox[inbox_size].subject);
                
                printf("Body: ");
                scanf("%s", inbox[inbox_size].body);
                
                inbox_size++;  // Increase inbox size.
                printf("\nEmail sent!\n");
                break;
            
            case 2:  // View inbox.
                for (int i = 0; i < inbox_size; i++) {
                    printf("=====================\n");
                    printf("From: %s\n", inbox[i].from);
                    printf("To: %s\n", inbox[i].to);
                    printf("Subject: %s\n", inbox[i].subject);
                    printf("Body: %s\n", inbox[i].body);
                    printf("=====================\n");
                }
                break;
                
            case 3:  // Exit program.
                printf("Exiting email client...\n");
                exit(0);
                
            default:  // Invalid option.
                printf("Invalid option. Please try again.\n");
                break;
        }
        
        printf("\n");
    } while (option != 3);
    
    return 0;
}