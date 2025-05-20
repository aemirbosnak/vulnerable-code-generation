//FormAI DATASET v1.0 Category: Binary Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binaryConverter(int decimalValue);

int main(){
    int decimalNum;
    printf("Enter a decimal number to convert to binary: ");
    scanf("%d", &decimalNum);

    binaryConverter(decimalNum);

    return 0;
}

void binaryConverter(int decimalValue){
    int binary[100];
    int i = 0;

    while(decimalValue != 0) {
        binary[i] = decimalValue % 2;
        decimalValue = decimalValue / 2;
        i++;
    }

    printf("The binary equivalent is: ");
    for(int j = i - 1; j >= 0; j--){
        printf("%d", binary[j]);
    }
    printf("\n");

    char message[] = "I'm not sorry for converting your decimal to binary, but here's a puzzle for you to solve. Start by finding the sum of the binary digits: ";
    printf("%s", message);

    int sum = 0;
    for(int k = 0; k < i; k++){
        sum += binary[k];
    }

    printf("%d\n", sum);

    char puzzle[] = "Now, if you take the sum of the digits and subtract it from the length of the message, you will get the missing word from this sentence: I am __________";
    printf("%s", puzzle);

    int lengthMsg = strlen(message);
    int missingChar = lengthMsg - sum;
    char missingWord[] = "";

    switch(missingChar){
        case 5:
            strcpy(missingWord, "smart");
            break;
        case 6:
            strcpy(missingWord, "not");
            break;
        case 7:
            strcpy(missingWord, "sorry");
            break;
        case 8:
            strcpy(missingWord, "evil");
            break;
        case 9:
            strcpy(missingWord, "sneaky");
            break;
        default:
            strcpy(missingWord, "unknown");
            break;
    }

    printf("%s\n", missingWord);
}