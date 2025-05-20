//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: relaxed
#include<stdio.h>
#include<string.h>

//function to check if character is safe character
int isSafe(char ch){
    if(ch >= 'a' && ch <= 'z')
        return 1;
    if(ch >= 'A' && ch <= 'Z')
        return 1;
    if(ch >= '0' && ch <= '9')
        return 1;
    if(ch == '-' || ch == '_' || ch == '.' || ch == '~')
        return 1;
    return 0;
}

//function to convert hexadecimal value to integer
int hexToInt(char ch){
    if(ch >= '0' && ch <= '9')
        return ch - '0';
    if(ch >= 'a' && ch <= 'f')
        return ch - 'a' + 10;
    if(ch >= 'A' && ch <= 'F')
        return ch - 'A' + 10;
    return -1;
}

//function to sanitize URL
void sanitize(char *url){
    int len = strlen(url);
    int i = 0, j = 0;
    char temp[3];
    temp[2] = '\0';
    while(i < len){
        if(isSafe(url[i])){
            url[j] = url[i];
            i++;
            j++;
        }
        else if(url[i] == '%'){
            temp[0] = url[i+1];
            temp[1] = url[i+2];
            i += 3;
            int val = (hexToInt(temp[0]) << 4) + hexToInt(temp[1]);
            if(isSafe(val)){
                url[j] = val;
                j++;
            }
        }
        else{
            i++;
        }
    }
    url[j] = '\0';
}

//driver function
int main(){
    char url[100];
    printf("Enter URL to sanitize:\n");
    gets(url);
    sanitize(url);
    printf("Sanitized URL is:\n%s\n", url);
    return 0;
}