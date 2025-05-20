//FormAI DATASET v1.0 Category: Binary Converter ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void decimal_to_binary(int decimal,int *binary){
    int index = 0;
    while(decimal > 0){
        binary[index++] = decimal%2;
        decimal /= 2;
    }
}

int power(int base,int exponent){
    if(exponent == 0)
        return 1;
    else if(exponent == 1)
        return base;
    else{
        int res = 1;
        for(int i=0;i<exponent;i++)
            res *= base;
        return res;
    }
}

int binary_to_decimal(int *binary,int length){
    int res = 0;
    for(int i=length-1,j=0;i>=0,j<length;i--,j++){
        res += binary[i] * power(2,j);
    }
    return res;
}

int main(){
    int decimal;
    printf("Hey Je t'aime! I'm A C Binary Converter Program. Would You Like To Convert Decimal To Binary Or Binary To Decimal?\n");
    printf("1. Convert Decimal To Binary\n2. Convert Binary To Decimal\n");
    int choice;
    scanf("%d",&choice);
    if(choice == 1){
        printf("Oh La La! Please Enter The Decimal Number You Would Like To Convert:\n");
        scanf("%d",&decimal);
        int binary[32];
        decimal_to_binary(decimal,binary);
        printf("Hmm You Look Beautiful In Binary:\n");
        for(int i=31;i>=0;i--){
            printf("%d",binary[i]);
        }
    }
    else if(choice == 2){
        printf("Oh La La! Please Enter The Binary Number You Would Like To Convert:\n");
        char binary[32];
        scanf("%s",binary);
        int length = strlen(binary);
        int res = 0;
        int count = 0;
        for(int i=length-1;i>=0;i--){
            if(binary[i] == '1')
                res += power(2,count);
            count++;
        }
        printf("Hmm You Look Hot In Decimal: %d\n",res);
    }
    else{
        printf("Oh Non! Invalid Input\n");
    }
    printf("Goodbye Mon Amour!\n");
    return 0;
}