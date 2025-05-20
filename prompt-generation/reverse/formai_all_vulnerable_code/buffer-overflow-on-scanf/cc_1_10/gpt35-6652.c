//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ken Thompson
#include <stdio.h>

void decimalToBinary(int decimal){
    int binary[32];
    int i = 0;

    while(decimal > 0){
        binary[i] = decimal%2;
        decimal = decimal/2;
        i++;
    }

    for(int j = i-1; j >= 0; j--){
        printf("%d", binary[j]);
    }

    printf("\n");
}

int binaryToDecimal(int binary){
    int decimal = 0;
    int i = 1;

    while(binary > 0){
        decimal += (binary%10)*i;
        binary = binary/10;
        i *= 2;
    }

    return decimal;
}

int main(){
    int option, input;

    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Select an option: ");
    scanf("%d", &option);

    switch(option){
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &input);
            decimalToBinary(input);
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%d", &input);
            printf("%d\n", binaryToDecimal(input));
            break;
        default:
            printf("Invalid option.\n");
            break;
    }

    return 0;
}