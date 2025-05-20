//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_BUFFER_SIZE 1024

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *) userp;

    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        printf("Could not allocate memory.\n");
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

int main(void) {
    CURL *curl_handle;
    CURLcode res;

    char user[MAX_BUFFER_SIZE];
    char password[MAX_BUFFER_SIZE];
    char host[MAX_BUFFER_SIZE];
    char mailbox[MAX_BUFFER_SIZE]; 

    printf("Enter User: ");
    scanf("%s", user);

    printf("Enter Password: ");
    scanf("%s", password);

    printf("Enter IMAP Hostname: ");
    scanf("%s", host);

    printf("Enter Mailbox: ");
    scanf("%s", mailbox);

    struct MemoryStruct chunk;

    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_ALL);

    curl_handle = curl_easy_init();
    if(curl_handle) {
        char url[MAX_BUFFER_SIZE];
        char body[MAX_BUFFER_SIZE];

        /* Set username and password */
        curl_easy_setopt(curl_handle, CURLOPT_USERNAME, user);
        curl_easy_setopt(curl_handle, CURLOPT_PASSWORD, password);

        /* Set IMAP URL */
        sprintf(url, "imaps://%s/%s", host, mailbox);
        curl_easy_setopt(curl_handle, CURLOPT_URL, url);

        /* Set option to redirect */
        curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);

        /* Send IMAP command */
        sprintf(body, "SEARCH ALL");
        curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, body);

        /* Write response */
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *) &chunk);

        /* Perform the request */
        res = curl_easy_perform(curl_handle);

        /* Check for errors */
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else {
            printf("%lu bytes retrieved\n", (unsigned long) chunk.size);
            printf("%s\n", chunk.memory);
        }

        /* always cleanup */
        curl_easy_cleanup(curl_handle);
    }

    free(chunk.memory);

    curl_global_cleanup();

    return 0;
}