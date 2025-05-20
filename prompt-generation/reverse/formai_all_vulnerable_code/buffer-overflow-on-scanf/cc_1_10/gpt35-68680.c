//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: peaceful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sanitize(char* url){
    int i, j, len = strlen(url);
    char output[1000];

    for(i = 0, j = 0; i < len; i++){
        if(url[i] == ':' && url[i+1] == '/' && url[i+2] == '/'){
            output[j++] = url[i++];
            output[j++] = url[i++];
            output[j++] = url[i++];

            if(i < len){ //checking if the URL has a valid domain name
                if(url[i] == 'w' && url[i+1] == 'w' && url[i+2] == 'w' && url[i+3] == '.'){
                    output[j++] = url[i++];
                    output[j++] = url[i++];
                    output[j++] = url[i++];
                    output[j++] = url[i++];
                }

                while(i < len && url[i] != '/'){ //copying domain name
                    output[j++] = url[i++];
                }
            }

            if(i == len){ //returning if URL ends with domain name
                output[j] = '\0';
                printf("Sanitized URL: %s\n", output);
                return;
            }
        }else{ //ignoring the rest of the URL until domain name
            continue;
        }
    }

    printf("Invalid URL format!\n");
}

int main(){
    char url[1000];

    printf("Enter the URL to be sanitized: ");
    scanf("%s", url);

    sanitize(url);

    return 0;
}