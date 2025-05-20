//FormAI DATASET v1.0 Category: Color Code Converter ; Style: unmistakable
#include <stdio.h>

int hexToDecimal(char hex[]);
void decimalToBinary(int decimal, int binary[]);

int main()
{
    char hexValue[10];
    int decimalValue, binaryValue[100];
    
    printf("Enter a hexadecimal value: ");
    scanf("%s", hexValue);
    
    decimalValue = hexToDecimal(hexValue);
    
    printf("Decimal value: %d\n", decimalValue);
    
    decimalToBinary(decimalValue, binaryValue);
    
    printf("Binary value: ");
    for(int i=0; i<sizeof(binaryValue)/sizeof(binaryValue[0]); i++){
        printf("%d", binaryValue[i]);
    }
    
    return 0;
}

int hexToDecimal(char hex[])
{
    int decimal = 0, i = 0, rem, len = 0;
    
    while (hex[i] != '\0'){
        len++;
        i++;
    }
    
    i=0;
    while(len>0){
        len--;
        if(hex[i]>='0' && hex[i]<='9'){
            rem = hex[i] - 48;
        } else if(hex[i]>='A' && hex[i]<='F'){
            rem = hex[i] - 55;
        } else if(hex[i]>='a' && hex[i]<='f'){
            rem = hex[i] - 87;
        }
        decimal += rem * pow(16, len);
        i++;
    }
    
    return decimal;
}

void decimalToBinary(int decimal, int binary[]){
    int quotient = decimal, i=1;
    
    while(quotient!=0){
        binary[i++] = quotient%2;
        quotient = quotient/2;
    }
    
    for(int j=i-1; j>=1; j--){
        binary[j-1] = binary[j];
    }
}