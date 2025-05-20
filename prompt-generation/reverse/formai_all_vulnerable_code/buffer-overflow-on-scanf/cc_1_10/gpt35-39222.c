//FormAI DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

void decimalToBinary(int decimal) {
    int* binaryArray = (int*)malloc(sizeof(int)*8);
    int index = 0;
    while(decimal>0) {
        binaryArray[index] = decimal % 2;
        decimal = decimal / 2;
        index++;
    }
    printf("Binary: ");
    for(int i=index-1;i>=0;i--) {
        printf("%d", binaryArray[i]);
    }
    printf("\n");
    free(binaryArray);
}

void binaryToDecimal(char* binary) {
    int length = strlen(binary);
    int decimal = 0;
    for(int i=length-1;i>=0;i--) {
        decimal += (binary[i] - '0') * pow(2,length-i-1);
    }
    printf("Decimal: %d\n", decimal);
}

int main() {
    int choice;
    while(1) {
        printf("1. Decimal to Binary\n2. Binary to Decimal\nEnter choice: ");
        scanf("%d", &choice);
        if(choice==1) {
            int decimal;
            printf("Enter decimal: ");
            scanf("%d", &decimal);
            decimalToBinary(decimal);
        }
        else if(choice==2) {
            char binary[8];
            printf("Enter binary: ");
            scanf("%s", binary);
            binaryToDecimal(binary);
        }
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}