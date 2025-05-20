//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define TRUE 1
#define FALSE 0

// function prototypes
char *get_website_url();
int get_refresh_rate();
int check_website_status(char *url);

int main()
{
    char *url = NULL;
    int refresh_rate = 0;

    url = get_website_url();
    refresh_rate = get_refresh_rate();

    while (TRUE)
    {
        if (check_website_status(url) == TRUE)
        {
            printf("%s website is up!\n", url);
        }
        else
        {
            printf("%s website is down!\n", url);
        }
        sleep(refresh_rate);
    }

    return 0;
}

// function to get the website url
char *get_website_url()
{
    char *url = malloc(100 * sizeof(char));
    memset(url, 0, 100);

    printf("Enter the website url to monitor: ");
    scanf("%s", url);

    return url;
}

// function to get the refresh rate (in seconds)
int get_refresh_rate()
{
    int refresh_rate = 0;

    printf("Enter the refresh rate (in seconds): ");
    scanf("%d", &refresh_rate);

    return refresh_rate;
}

// function to check the website status
int check_website_status(char *url)
{
    CURL *curl_handle;
    CURLcode res;

    curl_handle = curl_easy_init();
    if (curl_handle)
    {
        curl_easy_setopt(curl_handle, CURLOPT_URL, url);
        curl_easy_setopt(curl_handle, CURLOPT_NOBODY, 1L);

        res = curl_easy_perform(curl_handle);

        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl_handle);

        if (res == CURLE_OK)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
}