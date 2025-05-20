//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize_url(char* url) {
    char* temp = malloc(strlen(url) + 1);
    strcpy(temp, url);
    int len = strlen(url);
    
    int i;
    for(i = 0; i < len; i++) {
        // check for any special characters in the URL
        if(temp[i] == '<' || temp[i] == '>' || temp[i] == '\'' || temp[i] == '\"' || temp[i] == '(' || temp[i] == ')' || temp[i] == '{' || temp[i] == '}' || temp[i] == '[' || temp[i] == ']' || temp[i] == '|' || temp[i] == '%' || temp[i] == ';' || temp[i] == ':' || temp[i] == '!' || temp[i] == '#' || temp[i] == '+' || temp[i] == '\\') {
            int j;
            for(j = i; j < len - 1; j++) {
                temp[j] = temp[j + 1];
            }
            temp[len - 1] = '\0';
            len--;
            i--;
        }
        // check for spaces in the URL and replace with "%20"
        else if(temp[i] == ' ') {
            int j;
            for(j = len - 1; j >= i + 1; j--) {
                temp[j + 2] = temp[j];
            }
            temp[i] = '%';
            temp[i + 1] = '2';
            temp[i + 2] = '0';
            len = len + 2;
        }
        // check for the protocol in the URL and add if missing
        else if(i == 0) {
            char* protocol = "http://";
            int p_len = strlen(protocol);
            int j;
            for(j = len - 1; j >= 0; j--) {
                temp[j + p_len] = temp[j];
            }
            for(j = 0; j < p_len; j++) {
                temp[j] = protocol[j];
            }
            len = len + p_len;
            i = i + p_len - 1;
        }
    }
    
    strcpy(url, temp);
    free(temp);
}

int main() {
    char url[1000];
    printf("Enter the URL to sanitize: ");
    scanf("%[^\n]s", url);
    
    sanitize_url(url);
    
    printf("Sanitized URL: %s\n", url);
    return 0;
}