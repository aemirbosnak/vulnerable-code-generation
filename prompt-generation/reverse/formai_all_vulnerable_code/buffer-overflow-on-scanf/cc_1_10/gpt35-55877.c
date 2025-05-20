//FormAI DATASET v1.0 Category: Color Code Converter ; Style: complex
#include <stdio.h>
#include <string.h>

//Function to convert hexadecimal to decimal
int hextodecimal(char hex[]) {
    int decimal = 0, len = strlen(hex);
    for(int i=0; hex[i]!='\0'; i++){
        if(hex[i]>='0' && hex[i]<='9')
            decimal += (hex[i] - 48) * pow(16, len-i-1);
        else if(hex[i]>='a' && hex[i]<='f')
            decimal += (hex[i] - 87) * pow(16, len-i-1);
        else if(hex[i]>='A' && hex[i]<='F')
            decimal += (hex[i] - 55) * pow(16, len-i-1);
    }
    return decimal;
}

//Function to convert decimal to hexadecimal
void decimaltohex(int decimal, char hex[]){
    int temp, i=0;
    while(decimal!=0){
        temp = decimal % 16;
        if(temp<10)
            hex[i++] = temp + 48;
        else
            hex[i++] = temp + 87;
        decimal /= 16;
    }
    hex[i] = '\0';
}

//Main function
int main() {
    int choice, red, green, blue, decimal;
    char hex[100], rgbhex[7];
    
    //Menu
    printf("1. RGB to HEX\n");
    printf("2. HEX to RGB\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    //RGB to HEX conversion
    if(choice==1){
        printf("Enter RGB code in format R,G,B(0-255): ");
        scanf("%d,%d,%d", &red, &green, &blue);
        sprintf(rgbhex, "%02X%02X%02X", red, green, blue);
        printf("HEX code: #%s", rgbhex);
    }
    
    //HEX to RGB conversion
    else if(choice==2){
        printf("Enter HEX code: ");
        scanf("%s", hex);
        if(hex[0]=='#')
            strcpy(hex, &hex[1]);
        decimal = hextodecimal(hex);
        red = (decimal >> 16) & 255;
        green = (decimal >> 8) & 255;
        blue = decimal & 255;
        printf("RGB code: %d,%d,%d", red, green, blue);
    }
    
    //Invalid Choice
    else{
        printf("Invalid Choice!");
        return 0;
    }
    return 0;
}