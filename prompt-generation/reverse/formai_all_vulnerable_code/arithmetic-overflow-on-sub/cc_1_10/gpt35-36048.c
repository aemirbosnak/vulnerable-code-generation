//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <regex.h>

// Declarations
static size_t write_data(char *buffer, size_t size, size_t nmemb, void *userp);
static void get_emails(char *response);

int main(void) {
    CURL *curl;
    CURLcode res;
    char url[250];
    char username[50];
    char password[50];
    char rfc822_size[10];
    char buffer[5000];

    printf("Enter IMAP server url: ");
    fgets(url, sizeof url, stdin);

    printf("Enter your username: ");
    fgets(username, sizeof username, stdin);

    printf("Enter your password: ");
    fgets(password, sizeof password, stdin);

    // Remove newlines from input
    url[strcspn(url, "\n")] = '\0';
    username[strcspn(username, "\n")] = '\0';
    password[strcspn(password, "\n")] = '\0';

    sprintf(buffer, "A001 LOGIN %s %s\r\n", username, password);

    curl = curl_easy_init();
    if (curl) {
        // Set URL to IMAP server
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // Set callback function for received data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

        // Set buffer to store received data
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);

        // Set IMAP login request headers
        struct curl_slist *list = NULL;
        list = curl_slist_append(list, "Content-Type: text/xml");
        list = curl_slist_append(list, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:88.0) Gecko/20100101 Firefox/88.0");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);

        // Perform IMAP login request
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Clean up
        curl_easy_cleanup(curl);
    }

    // Extract email count from response
    regex_t regex;
    int reti;
    size_t nmatch = 2;
    regmatch_t pmatch[2];
    char *pattern = ".*\\* (\\d+) EXISTS.*\n";
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(EXIT_FAILURE);
    }
    reti = regexec(&regex, buffer, nmatch, pmatch, 0);
    if (!reti) {
        strncpy(rfc822_size, buffer + pmatch[1].rm_so, pmatch[1].rm_eo - pmatch[1].rm_so);
        rfc822_size[pmatch[1].rm_eo - pmatch[1].rm_so] = '\0';
    }
    else if (reti == REG_NOMATCH) {
        fprintf(stderr, "No match found\n");
    }
    else {
        regerror(reti, &regex, buffer, sizeof buffer);
        fprintf(stderr, "Regex match failed: %s\n", buffer);
        exit(EXIT_FAILURE);
    }

    printf("Number of emails: %s\n", rfc822_size);

    // Get list of emails
    get_emails(buffer);

    // Exit program
    return EXIT_SUCCESS;
}

static size_t write_data(char *buffer, size_t size, size_t nmemb, void *userp) {
    // Store received data in user buffer
    char *ptr = (char*) userp;
    memcpy(ptr, buffer, size * nmemb);
    return size * nmemb;
}

static void get_emails(char *response) {
    printf("\nEmail list:\n");

    // Extract email UID and subject from response
    regex_t regex;
    int reti;
    size_t nmatch = 3;
    regmatch_t pmatch[3];
    char *pattern = ".*\\*(\\d+) FETCH[^\\n]+FLAGS \\(.*UI[^\\n]+(.*)\\n";
    char *next = response;
    while (1) {
        reti = regcomp(&regex, pattern, REG_EXTENDED);
        if (reti) {
            fprintf(stderr, "Could not compile regex\n");
            exit(EXIT_FAILURE);
        }
        reti = regexec(&regex, next, nmatch, pmatch, 0);
        if (!reti) {
            char uid[10];
            strncpy(uid, next + pmatch[1].rm_so, pmatch[1].rm_eo - pmatch[1].rm_so);
            uid[pmatch[1].rm_eo - pmatch[1].rm_so] = '\0';

            char subject[200];
            strncpy(subject, next + pmatch[2].rm_so, pmatch[2].rm_eo - pmatch[2].rm_so);
            subject[pmatch[2].rm_eo - pmatch[2].rm_so] = '\0';

            printf("%s - %s\n", uid, subject);

            next += pmatch[0].rm_eo;
        }
        else if (reti == REG_NOMATCH) {
            break;
        }
        else {
            fprintf(stderr, "Regex match failed\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("\n");
}