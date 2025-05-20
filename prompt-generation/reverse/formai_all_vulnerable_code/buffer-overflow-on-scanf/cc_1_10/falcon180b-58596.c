//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char **argv){
    char input[100];
    int i, j, k, n, m, count;
    char hex[100];
    char ascii[100];
    char binary[100];
    int bin[100];
    int hex_int;
    int ascii_int;
    int bin_int;
    int decimal;
    int choice;

    printf("Enter a decimal number: ");
    scanf("%s", input);

    printf("Enter the output format:\n");
    printf("1. Hexadecimal\n");
    printf("2. ASCII\n");
    printf("3. Binary\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            for(i=0; i<strlen(input); i++){
                if(isdigit(input[i])){
                    hex_int = input[i] - 48;
                    sprintf(&hex[i*3],"%x", hex_int);
                }else{
                    sprintf(&hex[i*3],"%c", input[i]);
                }
            }
            printf("Hexadecimal: %s\n", hex);
            break;

        case 2:
            for(i=0; i<strlen(input); i++){
                if(isdigit(input[i])){
                    ascii_int = input[i] - 48;
                    sprintf(&ascii[i],"%c", ascii_int);
                }else{
                    sprintf(&ascii[i],"%c", input[i]);
                }
            }
            printf("ASCII: %s\n", ascii);
            break;

        case 3:
            for(i=0; i<strlen(input); i++){
                if(isdigit(input[i])){
                    bin_int = input[i] - 48;
                    sprintf(&binary[i*8],"%b", bin_int);
                }else{
                    sprintf(&binary[i*8],"%c", input[i]);
                }
            }
            printf("Binary: %s\n", binary);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}