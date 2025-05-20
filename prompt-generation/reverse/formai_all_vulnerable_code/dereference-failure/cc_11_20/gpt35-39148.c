//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: synchronous
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* sanitize(char* url) {
    const int MAX_LENGTH = 200;
    char* new_url = (char*) malloc(MAX_LENGTH);
    int len = strlen(url);
    int index = 0;
    int has_scheme = 0;
    int scheme_index = 0;
    
    // iterate through original URL
    for (int i=0; i<len; i++) {
        char c = url[i];
        
        // check for scheme
        if (i <= 4 && !has_scheme) {
            if (isalpha(c)) {
                // check if scheme is valid
                if (strncmp(url+i, "http", 4) == 0 || strncmp(url+i, "ftp", 3) == 0) {
                    strncpy(new_url, url+i, 4);
                    new_url[4] = '\0';
                    index = 4;
                    scheme_index = i;
                    has_scheme = 1;
                } else {
                    strcat(new_url, "//");
                    index += 2;
                    has_scheme = 1;
                    scheme_index = i-1;
                }
            }
        }
        
        // check for invalid characters
        if (!isalnum(c) && c != '.' && c != '-' && c != '_' && c != '/' && c != ':' && c != '~' && c != '?' && c != '=' && c != '&' && c != '%' && c != '#') {
            continue;
        }
        
        // check for .. path traversal
        if (i >= 2 && url[i] == '.' && url[i-1] == '.' && url[i-2] == '/') {
            index -= 2;
            int prev_index = index;
            while (prev_index > 0 && new_url[prev_index-1] != '/') {
                prev_index--;
            }
            index = prev_index;
            continue;
        }
        
        // append character to cleaned URL
        new_url[index] = c;
        index++;
    }
    
    // remove any trailing / or ?
    int last_char_index = index-1;
    while (new_url[last_char_index] == '/' || new_url[last_char_index] == '?') {
        last_char_index--;
    }
    new_url[last_char_index+1] = '\0';
    
    // remove any double slashes after scheme
    if (has_scheme) {
        for (int i=scheme_index+3; i<len; i++) {
            if (url[i] == '/' && new_url[i-1] == '/') {
                continue;
            }
            
            new_url[index] = url[i];
            index++;
        }
    }
    
    return new_url;
}

int main() {
    char url[] = "https://example.com///?param=value&param2=value2&&param3=value3";
    char* cleaned_url = sanitize(url);
    printf("Cleaned URL: %s", cleaned_url);
    free(cleaned_url);
    return 0;
}