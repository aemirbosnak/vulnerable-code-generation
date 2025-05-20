//FormAI DATASET v1.0 Category: Email Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curl/curl.h>

#define MAX_EMAILS 100

struct Email {
    char *subject;
    char *sender;
    char *recipient;
    char *body;
};

typedef struct Email Email;

typedef struct {
    char *username;
    char *password;
    char *server_url;
} EmailClient;

size_t write_response_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    char **response_ptr = userp;

    *response_ptr = realloc(*response_ptr, strlen(*response_ptr) + realsize + 1);
    if (*response_ptr == NULL) {
        return 0;
    }

    memcpy(*response_ptr + strlen(*response_ptr), contents, realsize);
    (*response_ptr)[strlen(*response_ptr) + realsize] = '\0';

    return realsize;
}

Email *parse_email_response(char *response) {
    char *str = strtok(response, "\n");
    Email *email = malloc(sizeof(Email));

    while (str != NULL) {
        if (strncmp(str, "Subject:", 8) == 0) {
            email->subject = strdup(str + 9);
        } else if (strncmp(str, "From:", 5) == 0) {
            email->sender = strdup(str + 6);
        } else if (strncmp(str, "To:", 3) == 0) {
            email->recipient = strdup(str + 4);
        } else if (strncmp(str, "\r\n", 2) == 0) {
            email->body = strdup(str + 2);
            break;
        }

        str = strtok(NULL, "\n");
    }

    return email;
}

bool send_email(EmailClient *client, Email *email) {
    CURL *curl;
    CURLcode res;
    char *url;
    char *response = malloc(1);
    size_t response_len = 0;

    if (email->subject == NULL || email->sender == NULL ||
        email->recipient == NULL || email->body == NULL) {
        return false;
    }

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {
        char *escaped_sender, *escaped_recipient, *escaped_subject, *escaped_body;
        escaped_sender = curl_easy_escape(curl, email->sender, 0);
        escaped_recipient = curl_easy_escape(curl, email->recipient, 0);
        escaped_subject = curl_easy_escape(curl, email->subject, 0);
        escaped_body = curl_easy_escape(curl, email->body, 0);

        asprintf(&url, "%s?username=%s&password=%s&sender=%s&recipient=%s&subject=%s&body=%s",
                 client->server_url, client->username, client->password, escaped_sender, escaped_recipient,
                 escaped_subject, escaped_body);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_response_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "Failed to send email: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return false;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    Email *sent_email = parse_email_response(response);

    if (sent_email->subject == NULL || sent_email->sender == NULL ||
        sent_email->recipient == NULL || sent_email->body == NULL) {
        return false;
    }

    printf("Email sent:\n");
    printf("From: %s", sent_email->sender);
    printf("To: %s", sent_email->recipient);
    printf("Subject: %s", sent_email->subject);
    printf("Body: %s", sent_email->body);

    free(response);
    free(url);
    free(sent_email);

    return true;
}

void print_menu() {
    printf("1. Compose email\n");
    printf("2. Inbox\n");
    printf("3. Sent\n");
    printf("4. Quit\n");
}

int main() {
    EmailClient client = { "johndoe", "password", "http://localhost:3000/send_email" };
    Email inbox[MAX_EMAILS];
    Email sent_mail[MAX_EMAILS];
    int inbox_count = 0, sent_count = 0;
    int choice;

    while (true) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            Email email;
            char buffer[1024];

            printf("Enter recipient: ");
            scanf("%s", buffer);
            email.recipient = strdup(buffer);

            printf("Enter subject: ");
            scanf("%s", buffer);
            email.subject = strdup(buffer);

            printf("Enter message: ");
            scanf("%s", buffer);
            email.body = strdup(buffer);

            email.sender = strdup(client.username);

            if (send_email(&client, &email)) {
                sent_mail[sent_count++] = email;
            }

            break;
        }

        case 2: {
            printf("%d emails in inbox:\n", inbox_count);

            for (int i = 0; i < inbox_count; i++) {
                printf("From: %s", inbox[i].sender);
                printf("Subject: %s", inbox[i].subject);
                printf("Body: %s", inbox[i].body);
            }

            break;
        }

        case 3: {
            printf("%d emails sent:\n", sent_count);

            for (int i = 0; i < sent_count; i++) {
                printf("To: %s", sent_mail[i].recipient);
                printf("Subject: %s", sent_mail[i].subject);
                printf("Body: %s", sent_mail[i].body);
            }

            break;
        }

        case 4:
            return 0;

        default:
            printf("Invalid choice.");
            break;
        }

        printf("\n");
    }

    return 0;
}