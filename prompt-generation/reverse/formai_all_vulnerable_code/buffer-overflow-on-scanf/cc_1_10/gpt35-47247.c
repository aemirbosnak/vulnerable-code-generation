//FormAI DATASET v1.0 Category: Browser Plugin ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to convert a string to uppercase
void str_to_upper(char *str){
    int i = 0;
    while(str[i]){
        str[i] = toupper(str[i]);
        i++;
    }
}

// function to check if the current URL is a valid website
int is_valid_website(char *url){
    // check if the URL starts with "https://"
    if(strncmp(url, "https://", 8) != 0){
        return 0;
    }

    // check if the URL contains at least 1 dot after "https://"
    int i=8, dot_count=0;
    while(url[i]){
        if(url[i] == '.'){
            dot_count++;
        }
        i++;
    }
    if(dot_count < 1){
        return 0;
    }

    return 1;
}

// callback function to be called when a new URL is loaded in the browser
int on_url_loaded(char *url){
    // convert the URL to uppercase
    str_to_upper(url);

    // check if the URL is a valid website
    if(!is_valid_website(url)){
        printf("This is not a valid website!\n");
        return 0;
    }

    printf("This is a valid website.\n");
    return 1;
}

// main function
int main(){
    char url[100];

    // simulate a user entering a URL into the address bar
    printf("Enter a URL: ");
    scanf("%s", url);

    // call the on_url_loaded function with the entered URL
    on_url_loaded(url);

    return 0;
}