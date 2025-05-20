//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 256

/* Function to sanitize the input URL */
void sanitize_url(char *url) {

    char temp_url[MAX_URL_LENGTH];
    int i, j = 0;

    /* Loop through each character in URL */
    for (i = 0; i < strlen(url); i++) {

        /* Check if character is alphanumeric, or a period, or a forward slash */
        if (isalnum(url[i]) || url[i] == '.' || url[i] == '/') {

            /* If yes, add it to the temporary URL */
            temp_url[j++] = url[i];

        }

    }

    /* Add null terminator to end of temporary URL */
    temp_url[j] = '\0';

    /* Copy the sanitized URL back into original URL */
    strcpy(url, temp_url);

}

int main() {

    char input_url[MAX_URL_LENGTH];

    /* Get input URL from user */
    printf("Enter a URL to sanitize: ");
    fgets(input_url, MAX_URL_LENGTH, stdin);

    /* Check if input URL has a newline character at the end and remove it */
    if (input_url[strlen(input_url)-1] == '\n') {
        input_url[strlen(input_url)-1] = '\0';
    }

    /* Sanitize the input URL */
    sanitize_url(input_url);

    /* Display the sanitized URL */
    printf("Sanitized URL: %s\n", input_url);

    return 0;
}