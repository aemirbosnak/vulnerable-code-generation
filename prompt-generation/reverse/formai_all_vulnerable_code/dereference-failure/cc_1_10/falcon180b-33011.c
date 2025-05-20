//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct {
    char *url;
    char *status;
    time_t last_checked;
} website_t;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((char *)userp)[(size_t)0] = '\0';
    return size * nmemb;
}

static int CheckWebsite(website_t *website)
{
    CURL *curl;
    CURLcode res;
    char *response;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &website->status);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    return res == CURLE_OK? 0 : 1;
}

int main()
{
    FILE *file;
    char line[1024];
    website_t *websites = NULL;
    int num_websites = 0;

    file = fopen("websites.txt", "r");
    if(!file) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }

    while(fgets(line, sizeof(line), file)) {
        website_t *website = malloc(sizeof(website_t));
        if(!website) {
            fprintf(stderr, "Error allocating memory.\n");
            exit(1);
        }

        char *url = strtok(line, "\t");
        website->url = strdup(url);

        time_t last_checked = time(NULL);
        website->last_checked = last_checked;
        website->status = NULL;

        num_websites++;
        websites = realloc(websites, num_websites * sizeof(website_t));
        websites[num_websites - 1] = *website;
    }

    fclose(file);

    while(1) {
        time_t current_time = time(NULL);
        for(int i = 0; i < num_websites; i++) {
            website_t *website = &websites[i];

            if(difftime(current_time, website->last_checked) >= 60) {
                CheckWebsite(website);
            }
        }

        sleep(10);
    }

    return 0;
}