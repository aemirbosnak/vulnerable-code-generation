//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <curl/curl.h>

#define BUFFER_SIZE 1024

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    char *buffer = (char *)malloc(realsize + 1);
    if (buffer == NULL) {
        return 0;
    }
    memcpy(buffer, contents, realsize);
    buffer[realsize] = '\0';
    *(char **)userp = buffer;
    return realsize;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    CURLcode res;
    char *login = "user@example.com";
    char *password = "password";
    char *imap_server = "imap.example.com";
    char *mailbox = "INBOX";
    char *url = NULL;
    char readbuffer[BUFFER_SIZE];
    FILE *fp;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        url = malloc(strlen(imap_server) + strlen(login) + 20);
        if (url == NULL) {
            fprintf(stderr, "Memory Error\n");
            exit(1);
        }
        sprintf(url, "imap://%s:%s@%s:%d/%s", login, password, imap_server, 993, mailbox);
        fp = fopen("output.txt", "w");
        if (fp == NULL) {
            fprintf(stderr, "Error opening file\n");
            exit(1);
        }
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            fprintf(stdout, "Operation completed\n");
        }
        fclose(fp);
        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}