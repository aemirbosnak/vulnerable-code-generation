//MISTRAL-7B DATASET v1.0 Category: Building a POP3 Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <curl/curl.h>

#define MAX_RESPONSE_LENGTH 256
#define BUFFER_SIZE 1024

struct Config {
    char server[64];
    int port;
    char username[32];
    char password[32];
};

void print_usage(void) {
    printf("Usage: pop3_client <config_file>\n");
    printf("Config file format: [server] [port] [username] [password]\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    FILE *config_file = fopen(argv[1], "r");
    if (!config_file) {
        perror("Error opening config file");
        exit(EXIT_FAILURE);
    }

    struct Config config;
    if (fscanf(config_file, "%s %d %s %s", config.server, &config.port, config.username, config.password) != 4) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    fclose(config_file);

    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, curl_slist_append(NULL, config.server));
        curl_easy_setopt(curl, CURLOPT_PORT, config.port);
        curl_easy_setopt(curl, CURLOPT_USERNAME, config.username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, config.password);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}