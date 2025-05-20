//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define DOWNLOAD_URL "http://ipv4.download.thinkbroadband.com/5MB.zip"
#define UPLOAD_URL "https://httpbin.org/post"
#define UPLOAD_FILE "upload.txt"
#define BUFFER_SIZE 1048576  // 1 MB

// This struct will hold the downloaded data
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to write the downloaded data into MemoryStruct
size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *mem) {
    size_t realsize = size * nmemb;
    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        printf("Not enough memory for download!\n");
        return 0;
    }
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = '\0';
    return realsize;
}

// Function for testing download speed
double test_download_speed() {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk = {NULL, 0};
    clock_t start, end;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        start = clock();
        curl_easy_setopt(curl, CURLOPT_URL, DOWNLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
        res = curl_easy_perform(curl);
        end = clock();
        
        if(res != CURLE_OK) {
            fprintf(stderr, "Download failed: %s\n", curl_easy_strerror(res));
            free(chunk.memory);
            curl_easy_cleanup(curl);
            return 0.0;
        }

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // in seconds
        double speed = (chunk.size * 8) / (time_taken * 1024 * 1024); // speed in Mbps
        printf("Download speed: %.2f Mbps\n", speed);
        
        free(chunk.memory);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0.0;
}

// Function for testing upload speed
double test_upload_speed() {
    CURL *curl;
    CURLcode res;
    clock_t start, end;
    FILE *upload_file;

    upload_file = fopen(UPLOAD_FILE, "w");
    if (!upload_file) {
        printf("Unable to create upload file.\n");
        return 0.0;
    }
    for (int i = 0; i < BUFFER_SIZE; ++i) {
        fputc('A', upload_file);
    }
    fclose(upload_file);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        start = clock();
        curl_easy_setopt(curl, CURLOPT_URL, UPLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        upload_file = fopen(UPLOAD_FILE, "rb");
        if(!upload_file) {
            printf("Couldn't open upload file.\n");
            curl_easy_cleanup(curl);
            return 0.0;
        }
        curl_easy_setopt(curl, CURLOPT_READDATA, upload_file);
        res = curl_easy_perform(curl);
        end = clock();
        
        if(res != CURLE_OK) {
            fprintf(stderr, "Upload failed: %s\n", curl_easy_strerror(res));
            fclose(upload_file);
            curl_easy_cleanup(curl);
            return 0.0;
        }

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // in seconds
        double speed = (BUFFER_SIZE * 8) / (time_taken * 1024 * 1024); // speed in Mbps
        printf("Upload speed: %.2f Mbps\n", speed);

        fclose(upload_file);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0.0;
}

int main() {
    printf("Internet Speed Test\n");
    printf("-------------------\n");
    test_download_speed();
    test_upload_speed();
    
    return 0;
}