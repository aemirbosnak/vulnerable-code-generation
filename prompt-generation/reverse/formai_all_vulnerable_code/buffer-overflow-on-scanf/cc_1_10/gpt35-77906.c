//FormAI DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include<stdio.h>
#include<math.h>
#include<string.h>

// function to convert binary number to decimal from 0 to 255
int binary_to_decimal(int binary_number){
    int decimal = 0, i = 0, remainder;
    while(binary_number != 0){
        remainder = binary_number % 10;
        binary_number /= 10;
        decimal += remainder*pow(2, i);
        ++i;
    }
    return decimal;
}

// function to convert decimal number to binary
void decimal_to_binary(int decimal_number){
    int binary_array[8], i=0;
    printf("Binary: ");
    while(decimal_number>0){
        binary_array[i]=decimal_number%2;
        decimal_number=decimal_number/2;
        i++;
    }
    for(int j=i-1;j>=0;j--){
        printf("%d",binary_array[j]);
    }
    printf("\n");
}

int main(){
    // user input
    char binary_input[9];
    printf("Enter binary number (8 bits): ");
    scanf("%s", binary_input);

    if(strlen(binary_input)>8){ // validate input
        printf("Invalid input!");
        return 0;
    }

    // convert binary to decimal
    int decimal_output = binary_to_decimal(atoi(binary_input));

    // print decimal output
    printf("Decimal: %d\n", decimal_output);

    // convert decimal to binary
    decimal_to_binary(decimal_output);

    return 0;
}