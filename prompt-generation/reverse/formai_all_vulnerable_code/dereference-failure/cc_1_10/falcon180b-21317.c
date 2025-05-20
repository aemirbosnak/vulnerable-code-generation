//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Function to check website uptime
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((char*)userp)[size*nmemb] = '\0';
    return size * nmemb;
}

int main()
{
    CURL* curl;
    CURLcode res;

    // Initialize curl
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Set the website URL
    char* url = "https://www.example.com";

    // Set the user agent
    char* user_agent = "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2228.0 Safari/537.36";

    // Set the curl handle
    curl = curl_easy_init();

    // Set the URL to fetch
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set the user agent
    curl_easy_setopt(curl, CURLOPT_USERAGENT, user_agent);

    // Set the write callback function
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

    // Set the write callback data
    char* buffer = malloc(1024);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);

    // Perform the fetch
    res = curl_easy_perform(curl);

    // Check the result
    if (res!= CURLE_OK)
    {
        printf("Error: %s\n", curl_easy_strerror(res));
        exit(1);
    }

    // Check if the website is up
    if (strstr(buffer, "200 OK"))
    {
        printf("Website is up!\n");
    }
    else
    {
        printf("Website is down!\n");
    }

    // Clean up
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    free(buffer);

    return 0;
}