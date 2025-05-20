//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

struct _site {
    char *url;
    char *name;
};

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((char *)userp)[(size * nmemb)] = '\0';
    return size * nmemb;
}

int main()
{
    FILE *file;
    char buffer[1024];
    struct _site sites[10];
    int count = 0;
    CURL *curl;
    CURLcode res;

    file = fopen("sites.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to open sites file.\n");
        exit(1);
    }

    while (fgets(buffer, 1024, file)!= NULL) {
        if (count >= 10) {
            printf("Error: Maximum number of sites reached.\n");
            exit(1);
        }

        char *name = strtok(buffer, ",");
        char *url = strtok(NULL, ",");

        sites[count].name = strdup(name);
        sites[count].url = strdup(url);

        count++;
    }

    fclose(file);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        for (int i = 0; i < count; i++) {
            curl_easy_setopt(curl, CURLOPT_URL, sites[i].url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, sites[i].name);

            res = curl_easy_perform(curl);

            if (res!= CURLE_OK) {
                printf("Error: %s\n", curl_easy_strerror(res));
            }
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}