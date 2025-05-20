//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

struct imap_client {
    char* host;
    char* username;
    char* password;
    CURL* curl;
};

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    char* buffer = (char*)malloc(size * nmemb);
    strncpy(buffer, (char*)contents, size * nmemb);
    printf("%s", buffer);
    return size * nmemb;
}

int imap_client_login(struct imap_client* client) {
    char* url = malloc(strlen(client->host) + strlen("imap://") + 1);
    strcpy(url, "imap://");
    strcat(url, client->host);

    curl_easy_setopt(client->curl, CURLOPT_URL, url);
    curl_easy_setopt(client->curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(client->curl, CURLOPT_USERNAME, client->username);
    curl_easy_setopt(client->curl, CURLOPT_PASSWORD, client->password);

    CURLcode res = curl_easy_perform(client->curl);
    if (res!= CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        return 1;
    }

    return 0;
}

int main() {
    struct imap_client client;
    client.host = "imap.gmail.com";
    client.username = "example@gmail.com";
    client.password = "password";

    client.curl = curl_easy_init();
    if (client.curl == NULL) {
        fprintf(stderr, "curl_easy_init() failed\n");
        return 1;
    }

    imap_client_login(&client);

    curl_easy_cleanup(client.curl);
    free(client.host);
    free(client.username);
    free(client.password);

    return 0;
}