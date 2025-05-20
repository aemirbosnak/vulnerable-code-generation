//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void convert_to_hex(char* input, char* output){

    char hex[100];
    char* token;
    int r, g, b;

    // take input string and tokenize it based on ","
    token = strtok(input, ",");
    r = atoi(token);
    token = strtok(NULL, ",");
    g = atoi(token);
    token = strtok(NULL, ",");
    b = atoi(token);

    // convert decimal values to hex values
    sprintf(hex, "%02X%02X%02X", r, g, b);

    // copy hex string to output buffer
    strcpy(output, hex);

}

void convert_to_dec(char* input, char* output){

    char dec[100];
    int r = 0, g = 0, b = 0;
    int i = 0, j= 0;

    // convert hex values to decimal values
    for(i = 0; input[i]; i++){
        char c = toupper(input[i]);
        if(c >= '0' && c <= '9'){
            j++;
            if(j == 1) r = r * 16 + (c - '0');
            if(j == 2) g = g * 16 + (c - '0');
            if(j == 3) b = b * 16 + (c - '0');
        }
        else if(c >= 'A' && c <= 'F'){
            j++;
            if(j == 1) r = r * 16 + (c - 'A' + 10);
            if(j == 2) g = g * 16 + (c - 'A' + 10);
            if(j == 3) b = b * 16 + (c - 'A' + 10);
        }
    }

    // copy decimal values to output buffer
    sprintf(dec, "%d,%d,%d", r, g, b);
    strcpy(output, dec);

}

int main(){

    char input[100];
    char output[100];
    int choice = 0;

    // prompt user for input color values and conversion selection
    printf("Enter RGB color values separated by commas (e.g. 255,128,0):\n");
    gets(input);
    printf("Select conversion method:\n");
    printf("1. RGB to HEX\n");
    printf("2. HEX to RGB\n");
    scanf("%d", &choice);
    getchar(); // consume newline character

    // perform selected conversion and display output
    if(choice == 1){
        convert_to_hex(input, output);
        printf("HEX color value: #%s\n", output);
    }
    else if(choice == 2){
        convert_to_dec(input, output);
        printf("RGB color value: %s\n", output);
    }
    else{
        printf("Invalid selection!\n");
    }

    return 0;
}