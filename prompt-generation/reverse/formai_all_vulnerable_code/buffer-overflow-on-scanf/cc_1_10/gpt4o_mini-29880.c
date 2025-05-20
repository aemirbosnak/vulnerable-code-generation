//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <pthread.h>

#define SERVER "smtp://smtp.example.com" // Replace with your SMTP server
#define USER "you@example.com" // Your email
#define PASS "yourpassword" // Your password
#define RECIPIENT "recipient@example.com" // Recipient email

typedef struct {
    char *message;
    char *subject;
} email_data;

void *send_email(void *data) {
    CURL *curl;
    CURLcode res;
    email_data *email_info = (email_data *)data;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, SERVER);
        curl_easy_setopt(curl, CURLOPT_USERNAME, USER);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, PASS);
        
        // Set the email parameters
        struct curl_slist *recipients = NULL;
        recipients = curl_slist_append(recipients, RECIPIENT);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        // Construct the email body
        char email_body[256];
        snprintf(email_body, sizeof(email_body), "To: %s\r\nFrom: %s\r\nSubject: %s\r\n\r\n%s", RECIPIENT, USER, email_info->subject, email_info->message);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_READDATA, email_body);
        curl_easy_setopt(curl, CURLOPT_INFILESIZE, (long)strlen(email_body));

        // Perform the request
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }

    free(email_info->message);
    free(email_info->subject);
    free(email_info);
    return NULL;
}

void prompt_and_send_email() {
    email_data *email_info = malloc(sizeof(email_data));
    
    if(!email_info) {
        fprintf(stderr, "Failed to allocate memory for email info\n");
        return;
    }

    email_info->subject = malloc(100); // Allocate memory for subject
    email_info->message = malloc(1024); // Allocate memory for message

    if(!email_info->subject || !email_info->message) {
        fprintf(stderr, "Failed to allocate memory for email subject or message\n");
        free(email_info);
        return;
    }

    printf("Enter email subject: ");
    fgets(email_info->subject, 100, stdin);
    email_info->subject[strcspn(email_info->subject, "\n")] = 0; // Remove newline

    printf("Enter email message: ");
    fgets(email_info->message, 1024, stdin);
    email_info->message[strcspn(email_info->message, "\n")] = 0; // Remove newline

    pthread_t email_thread;
    pthread_create(&email_thread, NULL, send_email, email_info);
    pthread_detach(email_thread);
}

int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    while (1) {
        char choice;
        printf("Do you want to send an email? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Consume newline

        if (choice == 'y' || choice == 'Y') {
            prompt_and_send_email();
        } else if (choice == 'n' || choice == 'N') {
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
    
    curl_global_cleanup();
    return 0;
}