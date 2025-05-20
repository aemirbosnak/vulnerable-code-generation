//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: surrealist
#include <stdio.h>
#include <string.h>

/* Surreal C URL Sanitizer */

int main() {
    char url[1000];
    printf("Enter a URL to be sanitized: ");
    gets(url);

    printf("\n\nSanitizing URL...\n\n");

    // Loop through each character of the URL
    for(int i = 0; i < strlen(url); i++) {

        // Reverse the order of the characters
        if(i % 2 == 0) {
            char temp = url[i];
            url[i] = url[strlen(url) - i - 1];
            url[strlen(url) - i - 1] = temp;
        }

        // Change all vowels to numbers
        if(url[i] == 'a' || url[i] == 'A') {
            url[i] = '4';
        } else if(url[i] == 'e' || url[i] == 'E') {
            url[i] = '3';
        } else if(url[i] == 'i' || url[i] == 'I') {
            url[i] = '1';
        } else if(url[i] == 'o' || url[i] == 'O') {
            url[i] = '0';
        } else if(url[i] == 'u' || url[i] == 'U') {
            url[i] = '6';
        }

        // Replace all slashes with exclamation points
        if(url[i] == '/' || url[i] == '\\') {
            url[i] = '!';
        }

        // Add a random letter before each period
        if(url[i] == '.') {
            int random_num = rand() % 26;
            char random_char = 'a' + random_num;
            printf("%c", random_char);
        }

        // Convert all uppercase letters to lowercase
        if(url[i] >= 'A' && url[i] <= 'Z') {
            url[i] = url[i] + 32;
        }
    }

    printf("\n\nSanitized URL: %s\n", url);

    return 0;
}