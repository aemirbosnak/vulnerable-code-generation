//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 256
#define MAX_BODY_LENGTH 1024

typedef struct {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

typedef struct {
    Email emails[MAX_EMAILS];
    int email_count;
} EmailClient;

EmailClient client;

void initialize_client() {
    client.email_count = 0;
}

void display_menu() {
    printf("\n=== Futuristic Email Client ===\n");
    printf("1. Send Email\n");
    printf("2. View Inbox\n");
    printf("3. Send Group Email\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void send_email() {
    if (client.email_count >= MAX_EMAILS) {
        printf("Inbox full! Cannot send more emails.\n");
        return;
    }
    
    Email email;
    printf("Enter sender's email: ");
    scanf("%s", email.sender);
    printf("Enter recipient's email: ");
    scanf("%s", email.recipient);
    
    printf("Enter subject: ");
    getchar(); // clear newline character
    fgets(email.subject, MAX_SUBJECT_LENGTH, stdin);
    email.subject[strcspn(email.subject, "\n")] = 0; // Remove newline
    
    printf("Enter body (max 1024 chars): ");
    fgets(email.body, MAX_BODY_LENGTH, stdin);
    email.body[strcspn(email.body, "\n")] = 0; // Remove newline

    email.timestamp = time(NULL);
    
    // Send email using curl
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_USERNAME, email.sender);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "your_password"); // For simplicity, put your password
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.yourserver.com:587");
        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
        
        const char *payload_text = "To: Recipient <recipient@example.com>\n"
                                   "From: Sender <sender@example.com>\n"
                                   "Subject: Your Subject\n\n"
                                   "Your email body goes here.";

        struct curl_slist *recipients = NULL;
        recipients = curl_slist_append(recipients, email.recipient);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_READDATA, payload_text);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    
    // Store email in the inbox
    client.emails[client.email_count++] = email;
    printf("Email sent successfully!\n");
}

void view_inbox() {
    printf("\n=== Inbox ===\n");
    for (int i = 0; i < client.email_count; i++) {
        printf("Email %d:\n", i + 1);
        printf("From: %s\n", client.emails[i].sender);
        printf("To: %s\n", client.emails[i].recipient);
        printf("Subject: %s\n", client.emails[i].subject);
        printf("Body: %s\n", client.emails[i].body);
        printf("Received: %s", ctime(&client.emails[i].timestamp));
        printf("\n");
    }
}

void send_group_email() {
    if (client.email_count >= MAX_EMAILS) {
        printf("Inbox full! Cannot send more emails.\n");
        return;
    }

    Email email;
    char recipient_list[500];
    
    printf("Enter sender's email: ");
    scanf("%s", email.sender);
    printf("Enter recipient list (comma separated): ");
    getchar();
    fgets(recipient_list, sizeof(recipient_list), stdin);
    recipient_list[strcspn(recipient_list, "\n")] = 0; // Remove newline
    
    printf("Enter subject: ");
    fgets(email.subject, MAX_SUBJECT_LENGTH, stdin);
    email.subject[strcspn(email.subject, "\n")] = 0; // Remove newline
    
    printf("Enter body (max 1024 chars): ");
    fgets(email.body, MAX_BODY_LENGTH, stdin);
    email.body[strcspn(email.body, "\n")] = 0; // Remove newline

    email.timestamp = time(NULL);
    
    // Send email using curl
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_USERNAME, email.sender);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "your_password"); // For simplicity, put your password
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.yourserver.com:587");
        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
        
        const char *payload_text = "To: Recipients\n"
                                   "From: Sender\n"
                                   "Subject: Your Group Email Subject\n\n"
                                   "Your email body goes here.";

        struct curl_slist *recipients = curl_slist_append(NULL, recipient_list);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_READDATA, payload_text);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    
    // Store email in the inbox
    client.emails[client.email_count++] = email;
    printf("Group email sent successfully!\n");
}

int main() {
    initialize_client();
    
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                send_email();
                break;
            case 2:
                view_inbox();
                break;
            case 3:
                send_group_email();
                break;
            case 4:
                printf("Exiting Futuristic Email Client. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please select again.\n");
        }
    }
    return 0;
}