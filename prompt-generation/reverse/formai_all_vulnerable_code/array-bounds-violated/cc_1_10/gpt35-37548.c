//FormAI DATASET v1.0 Category: Color Code Converter ; Style: mathematical
#include <stdio.h>

//Function to convert hex to decimal
int hexToDec(char hexDigit){
    if (hexDigit >= '0' && hexDigit <= '9') {
        return hexDigit - '0';
    }
    else if (hexDigit >= 'A' && hexDigit <= 'F') {
        return hexDigit - 'A' + 10;
    }
    else if (hexDigit >= 'a' && hexDigit <= 'f') {
        return hexDigit - 'a' + 10;
    }
    else {
        printf("Invalid hex digit\n");
        return -1;
    }
}

//Function to convert decimal to hex
char decToHex(int decDigit){
    if (decDigit >= 0 && decDigit <= 9) {
        return (char)(decDigit + '0');
    }
    else if (decDigit >= 10 && decDigit <= 15) {
        return (char)(decDigit - 10 + 'A');
    }
    else {
        printf("Invalid decimal digit\n");
        return -1;
    }
}

//Function to convert RGB to hex
void rgbToHex(int r, int g, int b){
    char hexCode[7];
    hexCode[0] = '#';
    hexCode[1] = decToHex(r/16);
    hexCode[2] = decToHex(r%16);
    hexCode[3] = decToHex(g/16);
    hexCode[4] = decToHex(g%16);
    hexCode[5] = decToHex(b/16);
    hexCode[6] = decToHex(b%16);
    hexCode[7] = '\0';
    printf("RGB color (%d, %d, %d) is equivalent to hex code %s\n", r, g, b, hexCode);
}

//Function to convert hex to RGB
void hexToRGB(char hexCode[]){
    if (hexCode[0] != '#' || strlen(hexCode) != 7){
        printf("Invalid hex code\n");
        return;
    }
    int r = (hexToDec(hexCode[1]) * 16) + hexToDec(hexCode[2]);
    int g = (hexToDec(hexCode[3]) * 16) + hexToDec(hexCode[4]);
    int b = (hexToDec(hexCode[5]) * 16) + hexToDec(hexCode[6]);
    printf("Hex code %s is equivalent to RGB color (%d, %d, %d)\n", hexCode, r, g, b);
}

//Main function
int main(){
    //Convert RGB to hex example
    printf("Convert RGB to hex:\n");
    int r = 255;
    int g = 102;
    int b = 0;
    rgbToHex(r, g, b);

    //Convert hex to RGB example
    printf("\nConvert hex to RGB:\n");
    char hexCode[] = "#ff6600";
    hexToRGB(hexCode);

    return 0;
}