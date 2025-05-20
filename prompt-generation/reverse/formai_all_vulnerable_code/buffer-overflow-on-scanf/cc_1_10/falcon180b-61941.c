//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

int main(int argc, char *argv[]) {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char url[100];
    char username[100];
    char password[100];
    char folder[100] = "INBOX";
    char message_id[100];
    char search_criteria[100] = "ALL";

    printf("Enter IMAP server URL: ");
    scanf("%s", url);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        printf("Enter folder: ");
        scanf("%s", folder);

        sprintf(url, "imap://%s:%s@%s/%s", username, password, url, folder);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        fp = fopen("output.txt", "wb");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        fclose(fp);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    FILE *fp = (FILE *) userp;
    return fwrite(contents, size, nmemb, fp);
}