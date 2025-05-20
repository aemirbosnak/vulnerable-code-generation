//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    FILE *file = (FILE *)userp;
    return fwrite(contents, size, nmemb, file);
}

int main(int argc, char *argv[])
{
    CURL *curl;
    FILE *fp;
    char url[1000];
    char username[100];
    char password[100];
    char command[1000];
    int port;

    printf("Enter IMAP server address: ");
    scanf("%s", url);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    printf("Enter port number: ");
    scanf("%d", &port);

    fp = fopen("imap.log", "w");

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        sprintf(command, "LOGIN %s %s", username, password);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_PORT, port);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, command);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    fclose(fp);
    curl_global_cleanup();

    return 0;
}