//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define SHAPE_COUNT 5
typedef struct {
    const char *shape_name;
    size_t shape_len;
    const char *header_name;
    size_t header_len;
} Shape;

Shape shapes[SHAPE_COUNT] = {
    {"triangle", 7, "X-Shape: triangle", 13},
    {"square", 6, "X-Shape: square", 9},
    {"circle", 6, "X-Shape: circle", 8},
    {"star", 4, "X-Shape: star", 6},
    {"heart", 5, "X-Shape: heart", 7}
};

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    fwrite(contents, size, realsize, stdout);

    return realsize;
}

int main(int argc, char **argv) {
    CURL *curl;
    CURLcode res;
    char url[256];
    int shape_index;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        printf("Enter your shape index (0-%d): ", SHAPE_COUNT - 1);
        scanf("%d", &shape_index);

        snprintf(url, sizeof(url), "http://example.com/%s", shapes[shape_index].shape_name);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, NULL);

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, (struct curl_slist*)curl_slist_append(NULL, shapes[shape_index].header_name));

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}