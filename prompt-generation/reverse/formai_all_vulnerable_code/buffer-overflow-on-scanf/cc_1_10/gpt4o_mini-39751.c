//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Function to send email
void send_email(const char *to, const char *from, const char *subject, const char *message) {
    CURL *curl;
    CURLcode res;
    
    struct curl_slist *recipients = NULL;

    curl = curl_easy_init(); // Initialize curl
    if(curl) {
        // Set SMTP server
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://localhost:25");
        
        // Set sender and recipient
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from);
        recipients = curl_slist_append(recipients, to);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        
        // Set the email body
        char email_body[512];
        snprintf(email_body, sizeof(email_body), "To: %s\r\nFrom: %s\r\nSubject: %s\r\n\r\n%s",
                 to, from, subject, message);
        curl_easy_setopt(curl, CURLOPT_READDATA, email_body);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        
        // Perform the request
        res = curl_easy_perform(curl);
        
        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        
        // Cleanup the recipients list
        curl_slist_free_all(recipients);
        
        // Cleanup curl
        curl_easy_cleanup(curl);
    }
}

// Function to display a menu for interaction
void display_menu() {
    printf("=== Simple Email Client ===\n");
    printf("1. Send Email\n");
    printf("2. Exit\n");
    printf("===========================\n");
}

int main() {
    char to[100], from[100], subject[100], message[512];
    int choice;

    while(1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter recipient email: ");
                scanf("%s", to);
                printf("Enter your email: ");
                scanf("%s", from);
                printf("Enter subject: ");
                scanf("%s", subject);
                printf("Enter message: ");
                getchar(); // To consume newline
                fgets(message, sizeof(message), stdin);
                send_email(to, from, subject, message);
                printf("Email sent successfully!\n");
                break;
            case 2:
                printf("Exiting the email client.\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    }

    return 0;
}