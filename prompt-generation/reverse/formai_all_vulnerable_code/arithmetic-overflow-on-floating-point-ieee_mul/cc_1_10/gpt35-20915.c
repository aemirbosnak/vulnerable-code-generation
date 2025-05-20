//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<curl/curl.h>

#define MAX_URL_COUNT 100
#define MAX_RESPONSE_TIME 5000

char *urls[MAX_URL_COUNT] = { "http://www.google.com", "http://www.facebook.com", "http://www.twitter.com" };
int response_times[MAX_URL_COUNT];
int response_count[MAX_URL_COUNT];

int main(int argc, char *argv[])
{
    CURL *curl;
    CURLcode res;

    for(int i=0;i<MAX_URL_COUNT;i++) 
    {
        curl = curl_easy_init();
        if(curl) 
        {
            curl_easy_setopt(curl, CURLOPT_URL, urls[i]);
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
            
            res = curl_easy_perform(curl);
            if(res == CURLE_OK) 
            {
                double response_time;
                curl_easy_getinfo(curl, CURLINFO_CONNECT_TIME, &response_time);
                response_times[i] += (int)(response_time*1000);
                response_count[i]++;
            }
            curl_easy_cleanup(curl);
        }
        sleep(1); //wait for 1 sec before checking next website
    }

    printf("%-30s %20s %20s\n", "Website URL", "Average Response Time", "Success Percentage");
    printf("-------------------------------------------------------------------------\n");

    for(int i=0;i<MAX_URL_COUNT;i++)
    {
        printf("%-30s %20d %18d%%\n", urls[i], (response_times[i]/response_count[i]), ((response_count[i]*100)/MAX_RESPONSE_TIME));
    }

    return 0;
}