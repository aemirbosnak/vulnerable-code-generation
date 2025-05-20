//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: satisfied
#include <stdio.h>
#include <curl/curl.h>
#include <time.h>

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *data) {
    (void)data;
    size_t written = fwrite(ptr, size, nmemb, stdout);
    return written;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file-size>\n", argv[0]);
        return 1;
    }

    size_t file_size = atoi(argv[1]);

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
        headers = curl_slist_append(headers, "Connection: keep-alive");
        headers = curl_slist_append(headers, "Host: www.google.com");

        curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        struct timeval start, end;
        gettimeofday(&start, NULL);

        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
        res = curl_easy_perform(curl);

        gettimeofday(&end, NULL);

        if (res!= CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
            return 1;
        }

        printf("Download speed: %.2f KB/s\n", (double)(file_size * 1024) / ((double)(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0));
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return 0;
    }
    return 1;
}