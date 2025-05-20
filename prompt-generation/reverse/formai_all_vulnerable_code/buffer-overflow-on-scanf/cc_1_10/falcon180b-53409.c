//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curl/curl.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<errno.h>

#define TIMEOUT 5
#define MAX_URL_LEN 2048

// Function to perform a GET request to the given URL
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((char*)userp)[nmemb*size - 1] = '\0';
    return size*nmemb;
}

// Function to check if the website is up or not
int CheckWebsiteStatus(char *url)
{
    CURL *curl;
    CURLcode res;
    char response[MAX_URL_LEN];

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
        {
            printf("Error: %s\n", curl_easy_strerror(res));
            return 0;
        }

        if(strstr(response, "200 OK"))
        {
            printf("Website is up\n");
            return 1;
        }
        else
        {
            printf("Website is down\n");
            return 0;
        }
    }
    else
    {
        printf("Error initializing curl\n");
        return 0;
    }
}

int main()
{
    char url[MAX_URL_LEN];
    int status;

    printf("Enter website URL: ");
    scanf("%s", url);

    status = CheckWebsiteStatus(url);

    if(status == 1)
    {
        printf("Website is up and running.\n");
    }
    else
    {
        printf("Website is down. Please try again later.\n");
    }

    return 0;
}