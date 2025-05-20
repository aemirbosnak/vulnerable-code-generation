//FormAI DATASET v1.0 Category: Binary Converter ; Style: thoughtful
#include<stdio.h>
#include<string.h>

int binaryToDecimal(int binary_num){
    /*
    This function converts binary to decimal.
    */
    int decimal_num=0, i=0, remainder=0;

    while(binary_num!=0){
        remainder = binary_num%10;  //Extract the last digit.
        binary_num /= 10;  //Remove the last digit.
        decimal_num += remainder*(1<<i);  //Convert the binary to decimal
        i++;  
    }
    return decimal_num;
}

int decimalToBinary(int decimal_num){
    /*
    This function converts decimal to binary.
    */
    int binary_num[32], i=0;

    while(decimal_num>0){
        binary_num[i] = decimal_num%2;  //Extract the remainder when dividing by 2.
        decimal_num /= 2;  //Divide the decimal by 2.
        i++;  
    }
    
    printf("Binary number: ");
    for(int j=i-1;j>=0;j--){
        printf("%d", binary_num[j]);  //Print the binary digits in reverse order.
    }
    printf("\n");
}

int main(){
    int num, choice;
    printf("1. Binary to decimal\n2. Decimal to binary\nEnter your choice: ");
    scanf("%d", &choice);

    //Binary to decimal conversion
    if(choice==1){
        printf("Enter binary number: ");
        scanf("%d", &num);
        int decimal_num = binaryToDecimal(num);
        printf("Decimal number: %d", decimal_num);
    }

    //Decimal to binary conversion
    else if(choice==2){
        printf("Enter decimal number: ");
        scanf("%d", &num);
        decimalToBinary(num);
    }
    return 0;
}