//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

typedef struct {
    char* username;
    char* password;
    char* hostname;
    int port;
    char* mailbox;
} imap_client_t;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    FILE* file = (FILE*)userp;
    size_t written = fwrite(contents, size, nmemb, file);
    return written;
}

imap_client_t* imap_client_create(const char* username, const char* password, const char* hostname, int port, const char* mailbox) {
    imap_client_t* client = (imap_client_t*)malloc(sizeof(imap_client_t));
    client->username = strdup(username);
    client->password = strdup(password);
    client->hostname = strdup(hostname);
    client->port = port;
    client->mailbox = strdup(mailbox);

    return client;
}

void imap_client_destroy(imap_client_t* client) {
    free(client->username);
    free(client->password);
    free(client->hostname);
    free(client->mailbox);
    free(client);
}

void imap_client_login(imap_client_t* client) {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        char url[1024];
        sprintf(url, "imap://%s:%s@%s:%d/%s", client->username, client->password, client->hostname, client->port, client->mailbox);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main() {
    imap_client_t* client = imap_client_create("username", "password", "imap.gmail.com", 993, "INBOX");
    imap_client_login(client);
    imap_client_destroy(client);

    return 0;
}