//FormAI DATASET v1.0 Category: Binary Converter ; Style: safe
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_LEN 100

int binaryToDecimal(char binary[]){
    int len = strlen(binary);
    int power = len-1;
    int decimal = 0;
    for(int i=0;i<len;i++){
        if(binary[i] == '1'){
            decimal += pow(2,power);
        }
        power--;
    }
    return decimal;
}

void decimalToBinary(int decimal){
    int binary[MAX_LEN];
    int index = 0;
    while(decimal > 0){
        binary[index] = decimal % 2;
        decimal /= 2;
        index++;
    }
    for(int i=index-1;i>=0;i--){
        printf("%d",binary[i]);
    }
}

int main(){
    int choice;
    printf("Enter 1 to convert binary to decimal, 2 to convert decimal to binary: ");
    scanf("%d",&choice);
    if(choice == 1){
        char binary[MAX_LEN];
        printf("Enter a binary number: ");
        scanf("%s",binary);
        int decimal = binaryToDecimal(binary);
        printf("The equivalent decimal number is: %d\n",decimal);
    }
    else if(choice == 2){
        int decimal;
        printf("Enter a decimal number: ");
        scanf("%d",&decimal);
        printf("The equivalent binary number is: ");
        decimalToBinary(decimal);
        printf("\n");
    }
    else{
        printf("Invalid choice!\n");
    }
    return 0;
}