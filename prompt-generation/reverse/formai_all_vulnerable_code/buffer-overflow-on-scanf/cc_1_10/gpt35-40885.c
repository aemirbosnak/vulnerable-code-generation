//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: scalable
#include<stdio.h>
#include<math.h>
#include<string.h>

//Function to convert hexadecimal to decimal
int hexToDec(char hex[]){
    int len = strlen(hex);
    int base = 1;
    int dec = 0;
    for(int i=len-1; i>=0; i--){
        if(hex[i]>='0' && hex[i]<='9'){
            dec += (hex[i] - 48) * base;
            base *= 16;
        }
        else if(hex[i]>='a' && hex[i]<='f'){
            dec += (hex[i] - 87) * base;
            base *= 16;
        }
        else if(hex[i]>='A' && hex[i]<='F'){
            dec += (hex[i] - 55) * base;
            base *= 16;
        }
    }
    return dec;
}

//Function to convert decimal to hexadecimal
void decToHex(int dec){
    char hex[50];
    int i=0;
    while(dec!=0){
        int temp = 0;
        temp = dec % 16;
        if(temp<10){
            hex[i] = temp + 48;
            i++;
        }
        else{
            hex[i] = temp + 55;
            i++;
        }
        dec = dec/16;
    }
    printf("\nHexadecimal Equivalent: ");
    for(int j=i-1; j>=0; j--){
        printf("%c", hex[j]);
    }
}

int main(){
    char hex[50];
    printf("Enter hexadecimal number: ");
    scanf("%s", hex);
    int dec = hexToDec(hex);
    printf("Decimal Equivalent: %d", dec);
    decToHex(dec);
    return 0;
}