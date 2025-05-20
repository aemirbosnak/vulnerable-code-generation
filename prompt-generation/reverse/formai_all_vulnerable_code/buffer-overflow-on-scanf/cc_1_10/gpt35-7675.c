//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: futuristic
#include<stdio.h>
//function to convert hex to binary
void hexToBinary(char hex[], char binary[]){
    int i = 0, j = 0;
    while(hex[i]){
        switch(hex[i]){
            case '0': strcat(binary, "0000"); break;
            case '1': strcat(binary, "0001"); break;
            case '2': strcat(binary, "0010"); break;
            case '3': strcat(binary, "0011"); break;
            case '4': strcat(binary, "0100"); break;
            case '5': strcat(binary, "0101"); break;
            case '6': strcat(binary, "0110"); break;
            case '7': strcat(binary, "0111"); break;
            case '8': strcat(binary, "1000"); break;
            case '9': strcat(binary, "1001"); break;
            case 'a': strcat(binary, "1010"); break;
            case 'b': strcat(binary, "1011"); break;
            case 'c': strcat(binary, "1100"); break;
            case 'd': strcat(binary, "1101"); break;
            case 'e': strcat(binary, "1110"); break;
            case 'f': strcat(binary, "1111"); break;
            default: printf("\nInvalid hex character: %c", hex[i]); break;
        }i++;
    }
}
//function to convert binary to decimal
int binaryToDecimal(char binary[]){
    int i = 0, decimal = 0, base = 1;
    for(i=strlen(binary)-1; i>=0; i--){
        if(binary[i]=='1'){
            decimal += base;
        }
        base *= 2;
    }   
    return decimal;
}
//main function
int main(){
    char choice;
    do{
        printf("\nEnter the hexadecimal number: ");
        char hex[20];
        scanf(" %s", hex);
        char binary[100] = "";
        hexToBinary(hex, binary);
        printf("The binary number is: %s\n", binary);
        int decimal = binaryToDecimal(binary);
        printf("The decimal number is: %d\n", decimal);
        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &choice);
    }while(choice=='y' || choice=='Y');
    return 0;
}