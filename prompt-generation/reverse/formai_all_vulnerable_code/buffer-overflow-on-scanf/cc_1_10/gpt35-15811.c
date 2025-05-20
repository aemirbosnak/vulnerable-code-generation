//FormAI DATASET v1.0 Category: Email Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email { 
    char sender[30]; 
    char recipient[30]; 
    char subject[50]; 
    char message[100]; 
}; 

int main() { 
    int choice; 
    struct email inbox[10]; 
    int count = 0; 
    
    while(1) { 
        printf("\nWELCOME TO THE EMAIL CLIENT!\n\n"); 
        printf("1) Compose Message\n"); 
        printf("2) View Inbox\n"); 
        printf("3) Exit\n"); 
        printf("Select an option: "); 
        scanf("%d", &choice); 
        
        switch(choice) { 
            case 1: 
            {   
                struct email new_email; 
                printf("\nCOMPOSE NEW MESSAGE:\n"); 
                printf("Enter sender name: "); 
                scanf("%s", new_email.sender); 
                printf("Enter recipient name: "); 
                scanf("%s", new_email.recipient); 
                printf("Enter subject: "); 
                scanf("%s", new_email.subject); 
                printf("Enter message: "); 
                scanf("%s", new_email.message); 
                inbox[count] = new_email; 
                count++; 
                printf("\nMESSAGE SAVED!\n\n"); 
                break; 
            }
            
            case 2: 
            { 
                if(count == 0) { 
                    printf("\nINBOX EMPTY!\n\n"); 
                    break;
                } 
                printf("\nVIEWING INBOX:\n"); 
                for(int i = 0; i < count; i++) { 
                    printf("\nMessage %d\nSender: %s\nRecipient: %s\nSubject: %s\n%s\n", i+1, inbox[i].sender, inbox[i].recipient, inbox[i].subject, inbox[i].message);
                } 
                break; 
            }
            
            case 3: 
                printf("\nEXITING EMAIL CLIENT...\n\n"); 
                exit(0); 
            
            default: 
                printf("\nINVALID OPTION!\n\n"); 
        }
    }
    return 0; 
}