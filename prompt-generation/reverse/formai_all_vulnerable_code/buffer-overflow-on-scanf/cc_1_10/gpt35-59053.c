//FormAI DATASET v1.0 Category: Binary Converter ; Style: optimized
#include<stdio.h>

int convertBinaryToInt(char binary[]){
    int power = 1, result = 0, i;
    for(i=31;i>=0;i--){
        if(binary[i] == '1'){
            result += power;
        }
        power *= 2;
    }
    return result;
}

void convertIntToBinary(int decimal, char binary[]){
    int quotient = decimal, i = 31;
    while(quotient != 0){
        binary[i] = (char)(quotient%2 + '0');
        quotient /= 2;
        i--;
    }
    // Filling up the remaining bits with 0 if necessary
    while(i>=0){
        binary[i] = '0';
        i--;
    }
}

int main(){
    char binary[32];
    int decimal, menuSelection = 0;
    printf("Welcome to the Binary Converter Program\n\n");

    while(menuSelection != 3){
        printf("Select an option from below:\n");
        printf("1. Convert Binary to Decimal\n");
        printf("2. Convert Decimal to Binary\n");
        printf("3. Exit\n");
        scanf("%d", &menuSelection);

        switch(menuSelection){
            case 1:
                printf("Enter the binary number: ");
                scanf("%s", binary);
                decimal = convertBinaryToInt(binary);
                printf("Decimal Equivalent: %d\n\n", decimal);
                break;
            case 2:
                printf("Enter the decimal number: ");
                scanf("%d", &decimal);
                convertIntToBinary(decimal, binary);
                printf("Binary Equivalent: %s\n\n", binary);
                break;
            case 3:
                printf("Exiting Program...Thank you!\n");
                break;
            default:
                printf("Invalid Selection! Please select again.\n\n");
                break;
        }
    }

    return 0;
}