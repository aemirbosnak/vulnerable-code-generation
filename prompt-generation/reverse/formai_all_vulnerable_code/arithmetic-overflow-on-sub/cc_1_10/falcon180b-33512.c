//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    FILE *fp = (FILE *)userp;
    return fwrite(contents, size, nmemb, fp);
}

long int SpeedTest(char* server_name) {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    double download_speed = 0.0;
    struct curl_slist *headers = NULL;
    char readBuffer[1024];
    long int file_size = 0;
    long int start_time, end_time;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        headers = curl_slist_append(headers, "Range: bytes=0-");
        sprintf(readBuffer, "http://%s", server_name);
        curl_easy_setopt(curl, CURLOPT_URL, readBuffer);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "HEAD");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        else {
            curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &file_size);
            fp = fopen("speedtest.bin", "wb");
            if(fp!= NULL) {
                start_time = clock();
                curl_easy_setopt(curl, CURLOPT_URL, readBuffer);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
                res = curl_easy_perform(curl);
                if(res!= CURLE_OK) {
                    fprintf(stderr, "curl_easy_perform() failed: %s\n",
                            curl_easy_strerror(res));
                }
                else {
                    end_time = clock();
                    download_speed = (double)file_size / (double)(end_time - start_time);
                    printf("Download Speed: %.2f KB/s\n", download_speed);
                }
                fclose(fp);
            }
        }
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }
    curl_global_cleanup();
    return 0;
}

int main() {
    char server_name[100];
    printf("Enter server name: ");
    scanf("%s", server_name);
    SpeedTest(server_name);
    return 0;
}