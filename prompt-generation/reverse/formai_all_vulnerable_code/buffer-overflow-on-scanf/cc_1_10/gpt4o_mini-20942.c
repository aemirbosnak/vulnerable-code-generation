//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define SMTP_SERVER "smtp://smtp.example.com:587" // Replace with your SMTP server
#define USERNAME "your_email@example.com"          // Replace with your email
#define PASSWORD "your_password"                    // Replace with your password
#define FROM_EMAIL "your_email@example.com"        // Replace with the sender's email
#define TO_EMAIL "recipient@example.com"            // Replace with the recipient's email
#define SUBJECT "Hello from C Email Client"        // Email subject
#define BODY "This is a test email sent by a C program!" // Email body

void send_email(const char* smtp_server, const char* username, const char* password,
                const char* from_email, const char* to_email,
                const char* subject, const char* body) {
    CURL *curl;
    CURLcode res;
    struct curl_slist *recipients = NULL;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, smtp_server);
        curl_easy_setopt(curl, CURLOPT_USERNAME, username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);
        
        // Set the sender's email
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from_email);
        
        // Add the recipient
        recipients = curl_slist_append(recipients, to_email);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        
        // Set the email data
        char email_data[1024];
        snprintf(email_data, sizeof(email_data),
                 "To: %s\r\n"
                 "From: %s\r\n"
                 "Subject: %s\r\n"
                 "\r\n"
                 "%s\r\n", to_email, from_email, subject, body);
        
        curl_easy_setopt(curl, CURLOPT_READDATA, email_data);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        
        // Send the email
        res = curl_easy_perform(curl);
        
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        
        // Cleanup the list of recipients
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }
    
    curl_global_cleanup();
}

void print_menu() {
    printf("Welcome to C Email Client\n");
    printf("=============================\n");
    printf("1. Send Email\n");
    printf("2. Exit\n");
}

int main() {
    int choice;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                send_email(SMTP_SERVER, USERNAME, PASSWORD, FROM_EMAIL, TO_EMAIL, SUBJECT, BODY);
                printf("Email sent successfully!\n");
                break;
            case 2:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}