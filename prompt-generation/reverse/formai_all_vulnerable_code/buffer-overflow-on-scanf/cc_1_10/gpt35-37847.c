//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct {
    char *email;
    char *password;
    char *server;
    int port;
} Credentials;

Credentials get_credentials() {
    Credentials cred;
    printf("Enter your email address: ");
    scanf("%s", cred.email);
    printf("Enter your password: ");
    scanf("%s", cred.password);
    printf("Enter your IMAP server address: ");
    scanf("%s", cred.server);
    printf("Enter your IMAP server port number: ");
    scanf("%d", &cred.port);
    return cred;
}

void list_messages(CURL *curl, char *url) {
    char cmd[100];
    sprintf(cmd, "FETCH 1:* ALL\r\n");

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, cmd);

    CURLcode result = curl_easy_perform(curl);
    if (result != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(result));
    }
}

void delete_messages(CURL *curl, char *url) {
    char cmd[100];
    sprintf(cmd, "STORE 1:* +FLAGS \\Deleted\r\n");
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, cmd);
    CURLcode result = curl_easy_perform(curl);
    if (result != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(result));
    }
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "EXPUNGE\r\n");
    result = curl_easy_perform(curl);
    if (result != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(result));
    }
}

int main(void) {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL *curl = curl_easy_init();

    Credentials cred = get_credentials();

    char url[1000];
    sprintf(url, "imaps://%s:%s@%s:%d", cred.email, cred.password, cred.server, cred.port);

    curl_easy_setopt(curl, CURLOPT_USERPWD, cred.email);
    curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "CAPABILITY\r\n");
    curl_easy_setopt(curl, CURLOPT_URL, url);
    CURLcode result = curl_easy_perform(curl);
    if (result != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(result));
    }

    printf("\nLogged in successfully. Choose an action:\n");
    printf("1. List messages\n2. Delete all messages\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1: list_messages(curl, url); break;
        case 2: delete_messages(curl, url); break;
        default: printf("Invalid choice\n"); break;
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return 0;
}