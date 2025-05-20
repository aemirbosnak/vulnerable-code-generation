//FormAI DATASET v1.0 Category: Color Code Converter ; Style: scientific
/*
C Color Code Converter
Author: [Your Name]

Description:
This program converts color codes between hexadecimal, RGB, and CMYK formats.
The program prompts the user to enter the type of color code input and output desired
and then proceeds to convert the input color code to the desired format.

Functions:
1. hexToRGB: Converts a hexadecimal color code to RGB format.
2. RGBToHex: Converts an RGB color code to hexadecimal format.
3. RGBToCMYK: Converts an RGB color code to CMYK format.
4. CMYKToRGB: Converts a CMYK color code to RGB format.
5. hexToCMYK: Converts a hexadecimal color code to CMYK format.
6. CMYKToHex: Converts a CMYK color code to hexadecimal format.

Usage:
1. Compile: gcc -o ColorConverter ColorConverter.c
2. Run: ./ColorConverter

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LEN 10

/* Function: hexToRGB
   Converts a hexadecimal color code to RGB format.
   Parameters:
   - hex: hexadecimal color code string
   - r: pointer to red component of RGB
   - g: pointer to green component of RGB
   - b: pointer to blue component of RGB
*/
void hexToRGB(char *hex, int *r, int *g, int *b){
    int hexValue;
    sscanf(hex, "%x", &hexValue);
    *r = (hexValue >> 16) & 0xff;
    *g = (hexValue >> 8) & 0xff;
    *b = hexValue & 0xff;
}

/* Function: RGBToHex
   Converts an RGB color code to hexadecimal format.
   Parameters:
   - r: red component of RGB
   - g: green component of RGB
   - b: blue component of RGB
   - hex: pointer to hexadecimal color code string
*/
void RGBToHex(int r, int g, int b, char *hex){
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

/* Function: RGBToCMYK
   Converts an RGB color code to CMYK format.
   Parameters:
   - r: red component of RGB
   - g: green component of RGB
   - b: blue component of RGB
   - c: pointer to cyan component of CMYK
   - m: pointer to magenta component of CMYK
   - y: pointer to yellow component of CMYK
   - k: pointer to black component of CMYK
*/
void RGBToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k){
    double red = r/255.0;
    double green = g/255.0;
    double blue = b/255.0;

    double max = red;
    max = (green > max) ? green : max;
    max = (blue > max) ? blue : max;

    *k = 1 - max;
    *c = (*k != 1) ? (1-red-*k)/(1-*k) : 0;
    *m = (*k != 1) ? (1-green-*k)/(1-*k) : 0;
    *y = (*k != 1) ? (1-blue-*k)/(1-*k) : 0;
}

/* Function: CMYKToRGB
   Converts an CMYK color code to RGB format.
   Parameters:
   - c: cyan component of CMYK
   - m: magenta component of CMYK
   - y: yellow component of CMYK
   - k: black component of CMYK
   - r: pointer to red component of RGB
   - g: pointer to green component of RGB
   - b: pointer to blue component of RGB
*/
void CMYKToRGB(double c, double m, double y, double k, int *r, int *g, int *b){
    *r = (int)((1-c) * (1-k) * 255.0);
    *g = (int)((1-m) * (1-k) * 255.0);
    *b = (int)((1-y) * (1-k) * 255.0);
}

/* Function: hexToCMYK
   Converts a hexadecimal color code to CMYK format.
   Parameters:
   - hex: hexadecimal color code string
   - c: pointer to cyan component of CMYK
   - m: pointer to magenta component of CMYK
   - y: pointer to yellow component of CMYK
   - k: pointer to black component of CMYK
*/
void hexToCMYK(char *hex, double *c, double *m, double *y, double *k){
    int r, g, b;
    hexToRGB(hex, &r, &g, &b);
    RGBToCMYK(r, g, b, c, m, y, k);
}

/* Function: CMYKToHex
   Converts a CMYK color code to hexadecimal format.
   Parameters:
   - c: cyan component of CMYK
   - m: magenta component of CMYK
   - y: yellow component of CMYK
   - k: black component of CMYK
   - hex: pointer to hexadecimal color code string
*/
void CMYKToHex(double c, double m, double y, double k, char *hex){
    int r, g, b;
    CMYKToRGB(c, m, y, k, &r, &g, &b);
    RGBToHex(r, g, b, hex);
}

/* Function: isValidHexChar
   Checks if a character is a valid hexadecimal character.
   Parameters:
   - c: character to check
*/
int isValidHexChar(char c){
    return isdigit(c) || (toupper(c) >= 'A' && toupper(c) <= 'F');
}

/* Function: isValidHexCode
   Checks if a string is a valid hexadecimal color code.
   Parameters:
   - hex: string to check
*/
int isValidHexCode(char *hex){
    int len = strlen(hex);
    if(len != 7 || hex[0] != '#'){
        return 0;
    }
    for(int i = 1; i < len; i++){
        if(!isValidHexChar(hex[i])){
            return 0;
        }
    }
    return 1;
}

/* Function: isValidRGBCode
   Checks if a string is a valid RGB color code.
   Parameters:
   - rgb: string to check
*/
int isValidRGBCode(char *rgb){
    int r, g, b;
    if(sscanf(rgb, "%d,%d,%d", &r, &g, &b) != 3){
        return 0;
    }
    if(r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255){
        return 0;
    }
    return 1;
}

/* Function: isValidCMYKCode
   Checks if a string is a valid CMYK color code.
   Parameters:
   - cmyk: string to check
*/
int isValidCMYKCode(char *cmyk){
    double c, m, y, k;
    if(sscanf(cmyk, "%lf,%lf,%lf,%lf", &c, &m, &y, &k) != 4){
        return 0;
    }
    if(c < 0 || c > 1 || m < 0 || m > 1 || y < 0 || y > 1 || k < 0 || k > 1){
        return 0;
    }
    return 1;
}

/* Function: toUpperCase
   Converts a string to uppercase.
   Parameters:
   - str: string to convert
*/
void toUpperCase(char *str){
    for(int i = 0; str[i]; i++){
        str[i] = toupper(str[i]);
    }
}

int main(){
    /* Initialize variables */
    char inputColor[MAX_INPUT_LEN], outputColor[MAX_INPUT_LEN];
    char inputFormat[MAX_INPUT_LEN], outputFormat[MAX_INPUT_LEN];
    int r, g, b;
    double c, m, y, k;

    /* Prompt user for input color code */
    printf("Enter input color code: ");
    fgets(inputColor, MAX_INPUT_LEN, stdin);
    inputColor[strcspn(inputColor, "\n")] = 0; // Remove trailing newline

    /* Determine input format */
    printf("Enter input format (Hex, RGB, CMYK): ");
    fgets(inputFormat, MAX_INPUT_LEN, stdin);
    inputFormat[strcspn(inputFormat, "\n")] = 0; // Remove trailing newline
    toUpperCase(inputFormat);

    /* Check validity of input */
    if(strcmp(inputFormat, "HEX") == 0){
        if(!isValidHexCode(inputColor)){
            printf("Invalid input color code\n");
            return 1;
        }
        hexToRGB(inputColor, &r, &g, &b);
    }
    else if(strcmp(inputFormat, "RGB") == 0){
        if(!isValidRGBCode(inputColor)){
            printf("Invalid input color code\n");
            return 1;
        }
        sscanf(inputColor, "%d,%d,%d", &r, &g, &b);
    }
    else if(strcmp(inputFormat, "CMYK") == 0){
        if(!isValidCMYKCode(inputColor)){
            printf("Invalid input color code\n");
            return 1;
        }
        sscanf(inputColor, "%lf,%lf,%lf,%lf", &c, &m, &y, &k);
        CMYKToRGB(c, m, y, k, &r, &g, &b);
    }
    else{
        printf("Invalid input format\n");
        return 1;
    }

    /* Prompt user for output format */
    printf("Enter output format (Hex, RGB, CMYK): ");
    fgets(outputFormat, MAX_INPUT_LEN, stdin);
    outputFormat[strcspn(outputFormat, "\n")] = 0; // Remove trailing newline
    toUpperCase(outputFormat);

    /* Convert color code */
    if(strcmp(outputFormat, "HEX") == 0){
        RGBToHex(r, g, b, outputColor);
    }
    else if(strcmp(outputFormat, "RGB") == 0){
        sprintf(outputColor, "%d,%d,%d", r, g, b);
    }
    else if(strcmp(outputFormat, "CMYK") == 0){
        RGBToCMYK(r, g, b, &c, &m, &y, &k);
        sprintf(outputColor, "%.2lf,%.2lf,%.2lf,%.2lf", c, m, y, k);
    }
    else{
        printf("Invalid output format\n");
        return 1;
    }

    /* Print result */
    printf("%s (%s) converted to %s format is: %s (%s)\n", inputColor, inputFormat, outputFormat, outputColor, outputFormat);

    return 0;
}