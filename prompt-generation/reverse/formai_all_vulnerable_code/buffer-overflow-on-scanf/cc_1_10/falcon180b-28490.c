//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((char*)userp)[strlen((char*)userp)] = '\0';
    return size * nmemb;
}

int main()
{
    CURL* curl;
    CURLcode res;
    char url[1000];
    FILE* file;
    char* response = NULL;
    size_t response_len = 0;

    printf("Enter the URL to fetch: ");
    scanf("%s", url);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        else {
            printf("Response:\n%s\n", response);
            file = fopen("response.txt", "w");
            fprintf(file, "%s", response);
            fclose(file);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}