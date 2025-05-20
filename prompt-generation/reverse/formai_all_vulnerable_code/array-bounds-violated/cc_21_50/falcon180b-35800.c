//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char hex[1000];
    char input[1000];
    int i = 0;
    int j = 0;
    int len;
    int flag = 0;

    printf("Enter a hexadecimal number: ");
    fgets(input, sizeof(input), stdin);
    len = strlen(input);

    // Remove leading/trailing whitespace
    while(isspace(input[i])) {
        i++;
    }
    while(isspace(input[len-1])) {
        len--;
    }
    input[len] = '\0';

    // Check if input is valid hexadecimal
    for(i=0; i<len; i++) {
        if(!isxdigit(input[i])) {
            printf("Invalid hexadecimal number.\n");
            return 0;
        }
    }

    // Convert hexadecimal to decimal
    for(i=0; i<len; i++) {
        if(isdigit(input[i])) {
            hex[j] = input[i];
            j++;
        }
        else {
            if(input[i] == 'A' || input[i] == 'a') {
                hex[j] = '10';
            }
            else if(input[i] == 'B' || input[i] == 'b') {
                hex[j] = '11';
            }
            else if(input[i] == 'C' || input[i] == 'c') {
                hex[j] = '12';
            }
            else if(input[i] == 'D' || input[i] == 'd') {
                hex[j] = '13';
            }
            else if(input[i] == 'E' || input[i] == 'e') {
                hex[j] = '14';
            }
            else if(input[i] == 'F' || input[i] == 'f') {
                hex[j] = '15';
            }
            else {
                printf("Invalid hexadecimal number.\n");
                return 0;
            }
            j++;
        }
    }

    // Convert decimal to binary
    for(i=0; i<j; i++) {
        if(isdigit(hex[i])) {
            printf("%d", hex[i] - '0');
        }
        else {
            printf("%c", hex[i]);
        }
    }

    return 0;
}