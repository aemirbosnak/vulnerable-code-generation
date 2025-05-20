//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<curl/curl.h>

#define MAX_URL_LENGTH 256
#define MAX_FILE_LENGTH 256

int main()
{
    char url[MAX_URL_LENGTH], filename[MAX_FILE_LENGTH], cmd[MAX_FILE_LENGTH + 50], output[MAX_FILE_LENGTH];
    int response_code;
    CURL *curl;

    // Prompt user to enter URL and filename
    printf("Enter the URL you want to monitor: ");
    scanf("%s", url);
    printf("Enter the file name you want to save the output: ");
    scanf("%s", filename);

    // initiate curl
    curl = curl_easy_init();

    // set curl options
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 15L);

    // perform curl request
    CURLcode result = curl_easy_perform(curl);

    if(result == CURLE_OK){
        // Get HTTP response code
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

        if(response_code == 200){
            printf("%s is up!\n", url);
        }
        else{
            printf("%s is down!\n", url);
        }
    }
    else{
        // Handle errors
        printf("Error: %s\n", curl_easy_strerror(result));
    }

    // Save output to file
    sprintf(cmd, "echo %s >> %s", url, filename);
    system(cmd);

    // Clean up curl
    curl_easy_cleanup(curl);

    return 0;
}