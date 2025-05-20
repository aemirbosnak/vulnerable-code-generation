//FormAI DATASET v1.0 Category: Binary Converter ; Style: complete
#include<stdio.h>
#include<string.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal_num){
    int binary_num[32];
    int i=0;
    while(decimal_num>0){
        binary_num[i]=decimal_num%2;
        decimal_num=decimal_num/2;
        i++;
    }
    // Displaying the binary number
    printf("Binary Number: ");
    for(int j=i-1;j>=0;j--){
        printf("%d",binary_num[j]);
    }
}

// Function to convert binary to decimal
int binaryToDecimal(int binary_num){
    int decimal_num=0;
    int base=1;
    int temp=binary_num;
    while(temp>0){
        int last_digit=temp%10;
        temp=temp/10;
        decimal_num+=last_digit*base;
        base=base*2;
    }
    return decimal_num;
}

int main(){
    int choice;
    do{
        printf("Welcome to Binary Converter!\n");
        printf("-----------------------------\n");
        printf("Choose an option:\n");
        printf("1. Convert decimal to binary.\n");
        printf("2. Convert binary to decimal.\n");
        printf("3. Exit.\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                int decimal_num;
                printf("Enter the decimal number: \n");
                scanf("%d",&decimal_num);
                decimalToBinary(decimal_num);
                printf("\n");
                break;
            }
            case 2:{
                int binary_num;
                printf("Enter the binary number: \n");
                scanf("%d",&binary_num);
                int decimal_num=binaryToDecimal(binary_num);
                printf("Decimal Number: %d\n",decimal_num);
                printf("\n");
                break;
            }
            case 3:{
                printf("Goodbye!\n");
                break;
            }
            default:{
                printf("Invalid Choice. Please try again.\n");
                break;
            }
        }
    }while(choice!=3);
    return 0;
}