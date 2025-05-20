//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* sanitizeURL(char *url) {
    // Initialize variables
    int i, j, k, len;
    int flag = 0;
    char *newUrl = malloc(sizeof(char)*1024);
    char temp[10];
    int isScheme = 0;

    // Check if the URL starts with a scheme prefix
    char* prefix[] = {"http://", "https://", "ftp://"};
    for(i=0; i<3; i++) {
        if(strncmp(url, prefix[i], strlen(prefix[i])) == 0) {
            isScheme = 1;
            break;
        }
    }

    // If the URL does not start with a scheme prefix, add http:// as the default
    if(!isScheme) {
        strcpy(newUrl, "http://");
        strcat(newUrl, url);
    } else {
        strcpy(newUrl, url);
    }

    len = strlen(newUrl);

    for(i=0; i<len; i++) {
        if(newUrl[i] == ' ') {  // Replace spaces with %20
            strcpy(temp, "20");
            flag = 1;
        }
        else if(newUrl[i] == ':') {  // Check for colon after the scheme
            for(j=i+1; j<len; j++) {  // If there is a double slash after the colon, remove the extra slash
                if(newUrl[j] == '/') {
                    for(k=j+1; k<len; k++) {
                        newUrl[k-1] = newUrl[k];
                    }
                    newUrl[len-1] = '\0';
                    len--;
                } else {
                    break;
                }
            }
            flag = 0;
        }
        else if(flag || !isalnum(newUrl[i])) {  // Check if the character is not alphanumeric or was flagged earlier
            sprintf(temp, "%x", newUrl[i]);
            flag = 1;
        }
        else {
            temp[0] = newUrl[i];
            temp[1] = '\0';
            flag = 0;
        }

        strcat(newUrl, temp);  // Append the encoded or original character to the URL
        len += strlen(temp);
    }

    return newUrl;
}

int main() {
    char url[1024], *sanitizedUrl;
    printf("Enter the URL to be sanitized:\n");
    scanf("%s", url);

    sanitizedUrl = sanitizeURL(url);

    printf("Sanitized URL: %s\n", sanitizedUrl);

    free(sanitizedUrl);

    return 0;
}