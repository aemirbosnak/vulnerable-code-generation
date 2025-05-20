//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitizeURL(char url[]){
    int length = strlen(url);
    char temp[length];
    int j = 0;

    for(int i = 0; i < length; i++){
        if(isalnum(url[i])){
            temp[j] = url[i];
            j++;
        }

        else if(url[i] == '.') {
            temp[j] = url[i];
            j++;
        }

        else if(url[i] == '/' && url[i+1] != '/') {
                temp[j] = url[i];
                j++;
        }

        else if(url[i] == '?' && url[i+1] != '?'){
            temp[j] = url[i];
            j++;
        }

        else if(url[i] == '='){
            temp[j] = url[i];
            j++;
        }
    }

    temp[j] = '\0';
    
    strcpy(url, temp);
}

int main() {
    char url[100];

    printf("Enter a URL to sanitize: ");
    scanf("%[^\n]", url);

    sanitizeURL(url);

    printf("\nSanitized URL: %s", url);

    return 0;
}