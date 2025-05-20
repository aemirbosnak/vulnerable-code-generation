//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_hex(char *dec);
int hex_to_dec(char hexDigit);

int main(){
    char input[50];
    printf("Enter a decimal number: ");
    scanf("%s", input);
    print_hex(input);
    return 0;
}

/* Function to print hexadecimal representation of a decimal number. */
void print_hex(char *dec){
    int rem, i=0, len = strlen(dec);
    char result[50] = "";
    /* loop through each digit of decimal number */
    while(len--){
        int digit = dec[i++];
        if(isdigit(digit)){ /* if digit is a number */
            /* add digit while keeping track of its place value */
            rem = digit % 16;
            if(rem < 10){
                strncat(result, (char[]){(char)(rem + 48)}, 1);
            }else{
                strncat(result, (char[]){(char)(rem + 55)}, 1);
            }
            digit /= 16;
        }
        else{ /* if digit is an alphabet */
            /* convert its ASCII to decimal and then to hexadecimal */
            int val = hex_to_dec(digit);
            rem = val % 16;
            val /= 16;
            if(val < 10){
                strncat(result, (char[]){(char)(val + 48)}, 1);
            }else{
                strncat(result, (char[]){(char)(val + 55)}, 1);
            }
            if(rem < 10){
                strncat(result, (char[]){(char)(rem + 48)}, 1);
            }else{
                strncat(result, (char[]){(char)(rem + 55)}, 1);
            }
        }
    }
    /* reverse the hexadecimal representation */
    int j=0, rlen = strlen(result);
    char reverse[rlen];
    for(i=rlen-1; i>=0; i--){
        reverse[j++] = result[i];
    }
    printf("Hexadecimal representation: %s\n", reverse);
}

/* Function to convert a hexadecimal digit to its decimal equivalent. */
int hex_to_dec(char hexDigit){
    if(hexDigit >= '0' && hexDigit <= '9'){
        return hexDigit - '0';
    }else if(hexDigit >= 'a' && hexDigit <= 'f'){
        return hexDigit - 'a' + 10;
    }else if(hexDigit >= 'A' && hexDigit <= 'F'){
        return hexDigit - 'A' + 10;
    }else{
        return 0;
    }
}