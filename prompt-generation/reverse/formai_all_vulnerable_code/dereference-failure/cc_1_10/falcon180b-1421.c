//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <math.h>

#define MAX_URL_LEN 512
#define MAX_USER_AGENT_LEN 512

typedef struct {
    char *url;
    char *user_agent;
    int response_code;
    double response_time;
    time_t last_checked;
} SiteData;

SiteData *sites = NULL;
int num_sites = 0;

void add_site(char *url, char *user_agent) {
    SiteData *site = malloc(sizeof(SiteData));
    site->url = strdup(url);
    site->user_agent = strdup(user_agent);
    site->response_code = 0;
    site->response_time = 0;
    site->last_checked = 0;
    sites = realloc(sites, sizeof(SiteData) * ++num_sites);
    sites[num_sites - 1] = *site;
    free(site);
}

int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    FILE *config_file = fopen("config.txt", "r");
    char line[MAX_URL_LEN];
    char user_agent[MAX_USER_AGENT_LEN];
    while (fgets(line, MAX_URL_LEN, config_file)) {
        char *url = strtok(line, ":");
        char *user_agent_str = strtok(NULL, ":");
        strcpy(user_agent, user_agent_str);
        add_site(url, user_agent);
    }
    fclose(config_file);
    while (1) {
        time_t now = time(NULL);
        for (int i = 0; i < num_sites; i++) {
            SiteData *site = &sites[i];
            if (site->last_checked + 60 < now) {
                CURL *curl;
                CURLcode res;
                curl_global_init(CURL_GLOBAL_DEFAULT);
                curl = curl_easy_init();
                if (curl) {
                    struct curl_slist *headers = NULL;
                    headers = curl_slist_append(headers, site->user_agent);
                    curl_easy_setopt(curl, CURLOPT_URL, site->url);
                    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
                    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
                    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
                    curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
                    res = curl_easy_perform(curl);
                    if (res!= CURLE_OK) {
                        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                                curl_easy_strerror(res));
                    }
                    long http_code = 0;
                    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
                    double response_time = (double)curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, NULL);
                    site->response_code = http_code;
                    site->response_time = response_time;
                    site->last_checked = now;
                }
                curl_easy_cleanup(curl);
            }
        }
        sleep(60);
    }
    return 0;
}