//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

void sanitize_url(char *url, size_t size);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s URL\n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;
    char *response = NULL;
    size_t response_size = 0;
    struct curl_slist *headers = NULL;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &headers);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Received data:\n%s\n", response);
            sanitize_url(response, strlen(response) + 1);
            printf("Sanitized URL: %s\n", response);
        }

        curl_easy_cleanup(curl);
        free(response);
    }

    curl_slist_free_all(headers);
    return 0;
}

void sanitize_url(char *url, size_t size) {
    size_t i = 0;
    for (; i < size; ++i) {
        if ((url[i] < 'A' || url[i] > 'Z') && // uppercase letters
            (url[i] < 'a' || url[i] > 'z') && // lowercase letters
            (url[i] < '0' || url[i] > '9') && // digits
            url[i] != '-' && url[i] != '_' && url[i] != '.' && url[i] != '/' && url[i] != '?' && url[i] != '&' && url[i] != '=' && url[i] != '+' && url[i] != ';' && url[i] != ':' && url[i] != '@') {
            // remove any other special characters
            memmove(&url[i], &url[i + 1], size - i);
            --size;
            i--;
        }
    }
}