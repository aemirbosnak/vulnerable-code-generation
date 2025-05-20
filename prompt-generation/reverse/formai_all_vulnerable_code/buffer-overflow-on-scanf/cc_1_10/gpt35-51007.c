//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

//function to check the website status
int check_website_status(const char* url){
    CURLcode res;
    CURL* curl = curl_easy_init();
    int status_code;
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK){
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return -1;
        }
        res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);
        curl_easy_cleanup(curl);
        if(res != CURLE_OK){
            fprintf(stderr, "curl_easy_getinfo() failed: %s\n", curl_easy_strerror(res));
            return -1;
        }
    }
    return status_code;
}

int main(){
    FILE* fileptr = NULL;
    int number_of_urls;
    char url[100];
    char file_name[100];
    int frequency;
    time_t start_time, current_time;
    struct tm* timeinfo;
    int total_runtime;
    int status_code;
    int i;

    //reading input from user
    printf("Enter the number of URLs to monitor:\n");
    scanf("%d", &number_of_urls);

    //allocating memory to store URLs
    char** urls = (char**) malloc(number_of_urls * sizeof(char*));
    for(i=0; i<number_of_urls; i++){
        printf("Enter URL %d:\n", i+1);
        scanf("%s", url);
        urls[i] = (char*) malloc(strlen(url) * sizeof(char));
        strcpy(urls[i], url);
    }

    printf("Enter the frequency of monitoring (in minutes):\n");
    scanf("%d", &frequency);

    printf("Enter the total runtime (in minutes):\n");
    scanf("%d", &total_runtime);

    printf("Enter the name of the output file (exclude file extension):\n");
    scanf("%s", file_name);

    //opening the output file
    char file_path[100];
    sprintf(file_path, "%s.txt", file_name);
    fileptr = fopen(file_path, "w");

    //getting start time and converting to local time
    time(&start_time);
    timeinfo = localtime(&start_time);

    //printing start time to console and output file
    printf("Monitoring started at: %s", asctime(timeinfo));
    fprintf(fileptr, "Monitoring started at: %s", asctime(timeinfo));

    //converting frequency and total runtime to seconds
    frequency *= 60;
    total_runtime *= 60;

    //monitoring loop
    while(difftime(current_time, start_time) < total_runtime){
        time(&current_time);
        for(i=0; i<number_of_urls; i++){
            status_code = check_website_status(urls[i]);
            //printing website status and time to console and output file
            printf("[%s]: Status = %d\tTime = %s", urls[i], status_code, asctime(timeinfo));
            fprintf(fileptr, "[%s]: Status = %d\tTime = %s", urls[i], status_code, asctime(timeinfo));
        }
        //waiting for defined frequency before next check
        sleep(frequency);
    }

    //getting end time and printing to console and output file
    time(&current_time);
    timeinfo = localtime(&current_time);
    printf("Monitoring ended at: %s", asctime(timeinfo));
    fprintf(fileptr, "Monitoring ended at: %s", asctime(timeinfo));

    //closing the output file
    fclose(fileptr);

    //freeing allocated memory
    for(i=0; i<number_of_urls; i++){
        free(urls[i]);
    }
    free(urls);

    return 0;
}