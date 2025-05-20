//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <unistd.h>

#define MAX_URL_LENGTH 200 // maximum URL length
#define MAX_TIME_LENGTH 50 // maximum date and time length
#define MAX_LOG_LENGTH 500 // maximum log message length

// function declarations
void check_website(char* url);
void log_message(char* message);

// main function
int main(void) {
    char url[MAX_URL_LENGTH];
    printf("Enter website URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // remove new line character from URL string
    int url_length = strlen(url);
    if(url[url_length-1] == '\n') {
        url[url_length-1] = '\0';
    }

    while(1) { // infinite loop to check website at specified interval
        check_website(url);
        sleep(30); // check website every 30 seconds
    }

    return 0;
}

// function to check website's status
void check_website(char* url) {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL); // initialize curl
    curl = curl_easy_init(); // create curl instance

    if(curl) {
        // set curl options
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

        // perform curl request
        res = curl_easy_perform(curl);

        // check for errors
        if(res != CURLE_OK) {
            log_message("Error checking website.");
        } else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if(response_code == 200) {
                log_message("Website is up.");
            } else {
                log_message("Website is down.");
            }
        }

        // cleanup curl instance
        curl_easy_cleanup(curl);

    } else {
        log_message("Error initializing curl.");
    }

    curl_global_cleanup(); // cleanup curl
}

// function to log messages to a file
void log_message(char* message) {
    char time_str[MAX_TIME_LENGTH];
    time_t now = time(NULL);
    strftime(time_str, MAX_TIME_LENGTH, "%Y-%m-%d %H:%M:%S", localtime(&now)); // get current date and time

    char log_str[MAX_LOG_LENGTH];
    snprintf(log_str, MAX_LOG_LENGTH, "[%s] %s\n", time_str, message); // format log message

    FILE* fp;
    fp = fopen("website-uptime.log", "a"); // open log file in append mode
    if(fp) {
        fputs(log_str, fp); // write log message to file
        fclose(fp); // close file
    } else {
        printf("Error opening log file.");
    }
}