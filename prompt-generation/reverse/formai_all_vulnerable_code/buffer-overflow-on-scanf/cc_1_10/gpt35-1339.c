//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to encode URL special characters
char* url_encode(char* str) {
    char *pstr = str, *buf = malloc(strlen(str) * 3 + 1), *pbuf = buf;

    while (*pstr) {
        if (*pstr == ' ') {
            *pbuf++ = '+';
        } else if ((*pstr < '0' && *pstr != '-' && *pstr != '.') || (*pstr < 'A' && *pstr > '9') || (*pstr > 'Z' && *pstr < 'a' && *pstr != '_') || (*pstr > 'z')) {
            pbuf += sprintf(pbuf, "%%%02X", (unsigned int) *pstr);
        } else {
            *pbuf++ = *pstr;
        }
        pstr++;
    }
    *pbuf = '\0';

    return buf;
}

//function to decode URL special characters
char* url_decode(char* str) {
    char *pstr = str, *buf = malloc(strlen(str) + 1), *pbuf = buf;
    int c;

    while (*pstr) {
        if (*pstr == '%') {
            if (sscanf(pstr + 1, "%2x", &c) != 1)
                c = '?';
            *pbuf++ = c;
            pstr += 3;
        } else if (*pstr == '+') {
            *pbuf++ = ' ';
            pstr++;
        } else {
            *pbuf++ = *pstr++;
        }
    }
    *pbuf = '\0';

    return buf;
}

int main() {
    printf("Welcome to URL Sanitizer!\n");

    //get user input
    char input[500];
    printf("Enter your URL: ");
    scanf("%[^\n]", input);

    //sanitize URL
    char* sanitized_url = url_encode(input);

    //print sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    //decode URL
    char* decoded_url = url_decode(sanitized_url);

    //print decoded URL
    printf("Decoded URL: %s\n", decoded_url);

    return 0;
}