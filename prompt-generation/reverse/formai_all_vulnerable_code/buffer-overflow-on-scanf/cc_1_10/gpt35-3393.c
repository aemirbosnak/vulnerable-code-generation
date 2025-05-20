//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<curl/curl.h>

//Function to check website status
int checkStatus(char *url){
    CURL *curl;
    CURLcode res;
    long http_code = 0;
    
    //Initialize CURL library
    curl_global_init(CURL_GLOBAL_ALL);
    
    //Create CURL handle
    curl = curl_easy_init();
    
    //Set URL to check
    curl_easy_setopt(curl, CURLOPT_URL, url);
    
    //Follow redirects
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    
    //Get the HTTP response code
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK){
        printf("\nError occured while performing curl operation: %s", curl_easy_strerror(res));
        return 0;
    }
    
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    
    return http_code;
}

int main(){
    char url[256];
    int checkInterval, retryAttempts, successCount = 0, failCount = 0;
    
    printf("Enter the URL to monitor: ");
    scanf("%s", url);
    
    printf("Enter the interval in seconds to check website status: ");
    scanf("%d", &checkInterval);
    
    printf("Enter the number of retry attempts before marking a failure: ");
    scanf("%d", &retryAttempts);
    
    printf("\nStarting website uptime monitor ...\n");
    
    while(1){
        //Check website status
        int http_code = checkStatus(url);
        
        if(http_code == 0 || http_code == 404 || http_code == 500){
            //Website is down or experiencing errors
            failCount++;
            printf("Website is down! Status Code: %d. Failed Attempts: %d\n", http_code, failCount);
            
            if(failCount >= retryAttempts){
                //Website is not responding
                printf("Website is not responding. Exiting monitoring process ...\n");
                break;
            }
            
            //Wait for specified interval before retrying
            printf("Retrying in %d seconds ...\n", checkInterval);
            sleep(checkInterval);
        }
        else{
            //Website is up and running
            successCount++;
            printf("Website is up and running! Status Code: %d. Successful Attempts: %d\n", http_code, successCount);
            failCount = 0;
            
            //Wait for specified interval before checking status again
            sleep(checkInterval);
        }
    }
    
    return 0;
}