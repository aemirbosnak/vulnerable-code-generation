//FormAI DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

//define global variables
char symbol[10];
char url[1024];
char response[4096];
char* data_pointer = NULL;
long http_code;

//callback function for curl request
size_t get_response_callback(void* ptr, size_t size, size_t nmemb, void* stream) {
    size_t total_size = size * nmemb;
    data_pointer = realloc(data_pointer, total_size);
    if(data_pointer == NULL) {
        printf("Failed to allocate memory for response data!");
        exit(EXIT_FAILURE);
    }
    strcat(data_pointer, (char*) ptr);
    return total_size;
}

int main() {

    //set up curl
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();

    //prompt user for stock symbol input
    printf("Enter stock symbol: ");
    scanf("%s", symbol);

    //construct url for curl request
    sprintf(url, "https://api.iextrading.com/1.0/stock/%s/quote", symbol);

    //make curl request
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, get_response_callback);
    res = curl_easy_perform(curl);

    //check for curl errors
    if(res != CURLE_OK) {
        printf("Error occurred during curl request: %s\n", curl_easy_strerror(res));
        exit(EXIT_FAILURE);
    }

    //parse JSON response
    char* ptr;
    ptr = strtok(data_pointer, ",");
    while(ptr != NULL) {
        if(strstr(ptr, "latestPrice")) {
            char* price_ptr;
            price_ptr = strtok(ptr, ":");
            price_ptr = strtok(NULL, ":");
            printf("Latest Price: %s\n", price_ptr);
        }
        if(strstr(ptr, "change")) {
            char* change_ptr;
            change_ptr = strtok(ptr, ":");
            change_ptr = strtok(NULL, ":");
            printf("Change: %s\n", change_ptr);
        }
        ptr = strtok(NULL, ",");
    }

    //get HTTP response code
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    printf("HTTP Response Code: %ld\n", http_code);

    //clean up resources
    curl_easy_cleanup(curl);
    free(data_pointer);
    return 0;
}