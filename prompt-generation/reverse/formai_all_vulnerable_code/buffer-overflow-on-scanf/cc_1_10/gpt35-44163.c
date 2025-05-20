//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: decentralized
#include <stdio.h>

void hexToDec(char *hex){
    int decimalValue = 0;
    int len = strlen(hex); 
    int base = 1; 
    int i;
  
    for (i=len-1; i>=0; i--)
    {   
        int currentElementValue; 
        if(hex[i]>='0' && hex[i]<='9'){
            currentElementValue = hex[i] - 48; 
        }
        else if(hex[i]>='a' && hex[i]<='f'){
            currentElementValue = hex[i] - 87;  
        }
        else if(hex[i]>='A' && hex[i]<='F'){
            currentElementValue = hex[i] - 55; 
        }
        decimalValue += currentElementValue * base; 
        base *= 16;
    }
    printf("Hexadecimal Value: %s\nDecimal Value: %d", hex, decimalValue);
}

void decToHex(int decimal){
    char hex[50]; 
    int remainder, i=0;
    while(decimal!=0){
        remainder = decimal % 16;
        if(remainder<10){
            hex[i] = remainder + 48; // Add ASCII value to convert to char
        }
        else{
            hex[i] = remainder + 55; // Add ASCII value of 'A' to convert to char
        }
        i++;
        decimal /= 16;
    }
    printf("Decimal Value: %d\nHexadecimal Value: ", decimal);
    for(int j=i-1; j>=0; j--){
        printf("%c", hex[j]);
    }
}

int main(){
    int choice, decimal;
    char hex[50];

    do{
        printf("\nSelect the conversion type.\n");
        printf("1. Hexadecimal to Decimal.\n");
        printf("2. Decimal to Hexadecimal.\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the Hexadecimal Value: ");
                scanf("%s", hex);
                hexToDec(hex);
                break;
            case 2:
                printf("\nEnter the Decimal Value: ");
                scanf("%d", &decimal);
                decToHex(decimal);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);

    return 0;
}