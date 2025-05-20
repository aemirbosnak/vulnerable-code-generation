//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

#define MAX_EMAIL_LENGTH 256
#define MAX_SUBJECT_LENGTH 256
#define MAX_BODY_LENGTH 2048

void send_email(const char *smtp_server, const char *username, const char *password, 
                const char *to_address, const char *subject, const char *body) {
    CURL *curl;
    CURLcode res;

    struct curl_slist *recipients = NULL;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, smtp_server);
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, username);

        recipients = curl_slist_append(recipients, to_address);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        
        curl_easy_setopt(curl, CURLOPT_USERNAME, username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);
        
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        
        char buffer[MAX_BODY_LENGTH];
        snprintf(buffer, sizeof(buffer), "To: %s\r\nFrom: %s\r\nSubject: %s\r\n\r\n%s",
                 to_address, username, subject, body);
        
        curl_easy_setopt(curl, CURLOPT_READDATA, buffer);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }
}

void receive_email(const char *imap_server, const char *username, const char *password) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, imap_server);
        curl_easy_setopt(curl, CURLOPT_USERPWD, username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);
        
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }
}

int main() {
    char smtp_server[MAX_EMAIL_LENGTH] = "smtp://smtp.your-email.com:587";
    char imap_server[MAX_EMAIL_LENGTH] = "imap://imap.your-email.com";
    char username[MAX_EMAIL_LENGTH];
    char password[MAX_EMAIL_LENGTH];
    char to_address[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    
    printf("Welcome to Simple C Email Client!\n");
    
    // Input email credentials
    printf("Enter your email username: ");
    fgets(username, MAX_EMAIL_LENGTH, stdin);
    username[strcspn(username, "\n")] = 0; // Strip newline
    
    printf("Enter your email password: ");
    fgets(password, MAX_EMAIL_LENGTH, stdin);
    password[strcspn(password, "\n")] = 0; // Strip newline

    // Email sending loop
    char continue_sending = 'y';
    while (continue_sending == 'y') {
        printf("\n--- Send Email ---\n");
        printf("To: ");
        fgets(to_address, MAX_EMAIL_LENGTH, stdin);
        to_address[strcspn(to_address, "\n")] = 0; // Strip newline
        
        printf("Subject: ");
        fgets(subject, MAX_SUBJECT_LENGTH, stdin);
        subject[strcspn(subject, "\n")] = 0; // Strip newline
        
        printf("Body: ");
        fgets(body, MAX_BODY_LENGTH, stdin);
        body[strcspn(body, "\n")] = 0; // Strip newline
        
        send_email(smtp_server, username, password, to_address, subject, body);
        
        printf("Email sent! Do you want to send another email? (y/n): ");
        scanf(" %c", &continue_sending);
        getchar(); // Clear the newline character from input buffer
    }
    
    // Email receiving
    printf("\n--- Receive Emails ---\n");
    receive_email(imap_server, username, password);

    printf("\nThank you for using Simple C Email Client!\n");
    return 0;
}