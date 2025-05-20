//FormAI DATASET v1.0 Category: Binary Converter ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

int binaryDecimal(char *binary){
    int decimal = 0;
    int position=1;
    for(int i = 7; i>=0; i--){
        if(binary[i]=='1'){
            decimal+=position;
        }
        position*=2;
    }
    return decimal;
}

void decimalBinary(int decimal, char *binary){
    int remainder;
    int i = 7; //8-bit binary number
    while(decimal!=0 && i>=0){
        remainder = decimal % 2;
        if(remainder==1){
            binary[i] = '1';
        }
        else{
            binary[i] = '0';
        }
        i--;
        decimal/=2;
    }
}

int main(){
    char binary[8] = {'0','0','0','0','0','0','0','0'};
    int decimal = 0;
    printf("Enter a binary number (8 bits): ");
    for(int i = 7; i>=0; i--){
        scanf("%c", &binary[i]);
    }
    getchar(); //To clear the buffer
    
    decimal = binaryDecimal(binary);
    printf("In decimal: %d\n", decimal);
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    getchar(); //To clear the buffer
    
    decimalBinary(decimal, binary);
    printf("In binary: ");
    for(int i=0; i<8; i++){
        printf("%c", binary[i]);
    }
    printf("\n");
    return 0;
}