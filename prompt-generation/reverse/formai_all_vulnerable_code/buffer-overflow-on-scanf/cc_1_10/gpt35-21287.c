//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curl/curl.h>//need to include the curl library

#define BUFFER_SIZE 1024//size of received data buffer

//Function to receive response from server.
size_t write_callback(char *buffer, size_t size, size_t nmemb, void *userdata)
{
    size_t actual_size = size * nmemb;
    char* response_buffer = (char*)userdata;

    // use strncat to append the response to the buffer
    strncat(response_buffer, buffer, actual_size);

    return actual_size;
}

int main(void)
{
    CURL *curl;
    CURLcode res;
    struct curl_slist *list = NULL;
    char response_buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char email[BUFFER_SIZE], password[BUFFER_SIZE], server[BUFFER_SIZE];
    int port;

    //prompting user for email, password, server and port
    printf("Enter your email: ");
    scanf("%s", email);

    printf("Enter password: ");
    scanf("%s", password);

    printf("Enter server (e.g. imap.gmail.com): ");
    scanf("%s", server);

    printf("Enter port (e.g. 993): ");
    scanf("%d", &port);

    //setting up the command with the user inputs
    sprintf(command, "LOGIN %s %s\r\n", email, password);

    //initializing curl
    curl = curl_easy_init();

    if(curl)
    {
        //setting options for the curl object
        curl_easy_setopt(curl, CURLOPT_USERNAME, email);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);
        curl_easy_setopt(curl, CURLOPT_URL, server);
        curl_easy_setopt(curl, CURLOPT_PORT, port);

        //login to the server
        list = curl_slist_append(list, command);
        curl_easy_setopt(curl, CURLOPT_MAIL_AUTH, list);

        //receiving server response and printing it to the console
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response_buffer);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

        res = curl_easy_perform(curl);

        printf("Server Response: %s\n", response_buffer);

        //implementing logout
        memset(command, 0, BUFFER_SIZE);
        sprintf(command, "LOGOUT\r\n");

        list = curl_slist_append(list, command);
        curl_easy_setopt(curl, CURLOPT_MAIL_AUTH, list);

        memset(response_buffer, 0, BUFFER_SIZE);
 
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response_buffer);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);    

        res = curl_easy_perform(curl);

        printf("Server Response: %s\n", response_buffer);

        //cleaning up curl
        curl_easy_cleanup(curl);
        curl_slist_free_all(list);
    }

    return 0;
}