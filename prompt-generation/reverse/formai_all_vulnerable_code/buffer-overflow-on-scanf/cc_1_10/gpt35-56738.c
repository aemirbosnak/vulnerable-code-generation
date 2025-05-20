//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>

// Recursive function to monitor website uptime
void monitor_website(char *url, int delay);

// Callback function to write data from curl request to file
static size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main()
{
    char url[100];
    int delay;
    
    printf("Enter URL to monitor: ");
    scanf("%s", url);
    
    printf("Enter delay in seconds: ");
    scanf("%d", &delay);
    
    printf("Monitoring website uptime...\n");
    
    monitor_website(url, delay);
    
    return 0;
}

void monitor_website(char *url, int delay)
{
    int status_code = 0;
    FILE *fp = fopen("temp.html", "wb");
    
    CURL *curl = curl_easy_init();
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);
        curl_easy_cleanup(curl);
    }
    
    fclose(fp);
    
    if(status_code == 200)
    {
        printf("%s is up and running!\n", url);
        sleep(delay);
        monitor_website(url, delay);
    }
    else
    {
        printf("%s is down!\n", url);
    }
    
    remove("temp.html");
}