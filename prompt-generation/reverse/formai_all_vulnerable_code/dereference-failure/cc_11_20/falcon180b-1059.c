//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main(int argc, char *argv[]) {
    char hex[MAX_LENGTH] = { 0 };
    char dec[MAX_LENGTH] = { 0 };
    int i = 0, j = 0, length = 0;
    int is_hex = 1;
    int is_dec = 1;

    // Check if the number of arguments is correct
    if(argc!= 3) {
        printf("Invalid number of arguments. Please provide a hexadecimal number and a conversion type (hex or dec).\n");
        return 1;
    }

    // Get the hexadecimal number from the command line argument
    strcpy(hex, argv[1]);

    // Get the conversion type from the command line argument
    strcpy(dec, argv[2]);

    // Check if the hexadecimal number is valid
    for(i = 0; hex[i]!= '\0'; i++) {
        if(!isxdigit(hex[i])) {
            printf("Invalid hexadecimal number.\n");
            return 1;
        }
    }

    // Convert the hexadecimal number to decimal
    if(strcmp(dec, "hex") == 0) {
        printf("The decimal representation of %s is: ", hex);
        while(is_hex) {
            if(i >= strlen(hex)) {
                is_hex = 0;
            }
            else {
                if(isxdigit(hex[i])) {
                    if(isdigit(hex[i])) {
                        dec[j] = hex[i] - '0';
                    }
                    else {
                        dec[j] = hex[i] - 'A' + 10;
                    }
                    j++;
                }
                else {
                    is_hex = 0;
                }
            }
        }
        printf("%s\n", dec);
    }

    // Convert the decimal number to hexadecimal
    else if(strcmp(dec, "dec") == 0) {
        printf("The hexadecimal representation of %d is: ", atoi(hex));
        while(is_dec) {
            if(j >= strlen(dec)) {
                is_dec = 0;
            }
            else {
                if(isdigit(dec[j])) {
                    dec[j] = (dec[j] - '0' + 16) % 16 + (isdigit(dec[j])? '0' : 'A');
                }
                else {
                    dec[j] = (dec[j] - 'A' + 10) % 16 + 'A';
                }
                j++;
            }
        }
        printf("%s\n", dec);
    }

    // Invalid conversion type
    else {
        printf("Invalid conversion type. Please provide hex or dec.\n");
        return 1;
    }

    return 0;
}