//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <curl/curl.h>

#define DOWNLOAD_URL "http://speedtest.tele2.net/10GB.zip"
#define UPLOAD_URL "http://speedtest.tele2.net/upload.php"
#define UPLOAD_DATA "dummy_data"

double download_speed()
{
    double download_speed, total_time;
    CURL *curl;
    CURLcode res;
    struct timeval start_time, end_time;
 
    curl = curl_easy_init();
    if(curl) {
        gettimeofday(&start_time, NULL);   
        curl_easy_setopt(curl, CURLOPT_URL, DOWNLOAD_URL);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
           fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        gettimeofday(&end_time, NULL);
 
        curl_easy_cleanup(curl);

        total_time = (double)(end_time.tv_sec - start_time.tv_sec) +
                     (double)(end_time.tv_usec - start_time.tv_usec) / 1000000;
 
        download_speed = (double) 10000 / total_time / ( 1 << 20);
    }
    return download_speed;
}

double upload_speed()
{
    double upload_speed, total_time;
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers;
    struct timeval start_time, end_time;
 
    curl = curl_easy_init();
    if(curl) {
        gettimeofday(&start_time, NULL);   

        headers = curl_slist_append(NULL, "Content-Type: multipart/form-data");
        curl_easy_setopt(curl, CURLOPT_URL, UPLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, UPLOAD_DATA);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK){
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        gettimeofday(&end_time, NULL);

        curl_easy_cleanup(curl);
      
        total_time = (double)(end_time.tv_sec - start_time.tv_sec) +
                     (double)(end_time.tv_usec - start_time.tv_usec) / 1000000;
 
        upload_speed = (double) 10 / total_time / ( 1 << 20);
    }
    return upload_speed;    
}
 
int main(int argc, char **argv)
{
    double download, upload;
 
    download = download_speed();
    upload = upload_speed();

    printf("Download Speed: %.2f Mb/s\n", download);
    printf("Upload Speed: %.2f Mb/s\n", upload);
 
    return 0;
}