//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input_url[500], output_url[500];
    printf("Enter a URL to sanitize: ");
    scanf("%s", &input_url);

    char domain_name[500];
    char path[500];
    char* query_string = NULL;

    int i, j, k, domain_found = 0;

    for (i = 0; i < strlen(input_url); i++) {
        //Look for the domain name
        if (input_url[i] == '/') {
            if (i > 6) { //If https:// or http:// found
                j = i+2;
                k = 0;
                while (input_url[j] != '/') {
                    domain_name[k] = input_url[j];
                    j++;
                    k++;
                }
                domain_name[k] = '\0';
                domain_found = 1;
            } else {
                j = i+1;
            }
            break;
        }
    }

    if (domain_found == 0) { //If domain name not found
        printf("Invalid URL: Domain name not found!\n");
        return 0;
    }

    k = 0;
    for (i = j; i < strlen(input_url); i++) { //Get the path
        if (input_url[i] == '?') { //If query string found
            query_string = (char*) malloc(strlen(input_url)-i+1);
            for (j = i; j < strlen(input_url); j++) {
                query_string[k] = input_url[j];
                k++;
            }
            query_string[k] = '\0';
            break;
        }
        path[k] = input_url[i];
        k++;
    }
    path[k] = '\0';

    //Sanitize domain name
    for (i = 0; i < strlen(domain_name); i++) {
        if (domain_name[i] == ' ') {
            printf("\nError: URL contains whitespace characters!\n");
            return 0;
        }
        if (domain_name[i] >= 'A' && domain_name[i] <= 'Z') {
            domain_name[i] += 32;
        }
    }

    //Sanitize path
    for (i = 0; i < strlen(path); i++) {
        if (path[i] >= 'A' && path[i] <= 'Z') {
            path[i] += 32;
        }
    }

    //Sanitize query string
    if (query_string != NULL) {
        for (i = 0; i < strlen(query_string); i++) {
            if (query_string[i] == ' ') {
                printf("\nError: URL contains whitespace characters!\n");
                return 0;
            }
            if (query_string[i] >= 'A' && query_string[i] <= 'Z') {
                query_string[i] += 32;
            }
        }
    }

    //Reconstruct the sanitized URL
    strcat(output_url, "https://");
    strcat(output_url, domain_name);
    strcat(output_url, "/");
    strcat(output_url, path);
    strcat(output_url, query_string);

    printf("\nSanitized URL: %s\n", output_url);
    return 0;
}