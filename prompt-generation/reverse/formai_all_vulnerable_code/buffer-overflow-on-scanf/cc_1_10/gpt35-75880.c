//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertToHex(char convertedHex[], char inputString[]){
    sprintf(convertedHex, "%02X", inputString[0]);
    for(int i=1; i<strlen(inputString); i++){
        char temp[3];
        sprintf(temp, "%02X", inputString[i]);
        strcat(convertedHex, temp);
    }
}

void convertToString(char inputString[], char hexString[]){
    int i=0, j=0;
    while(hexString[i]){
        char temp[3];
        temp[0] = hexString[i++];
        temp[1] = hexString[i++];
        temp[2] = '\0';
        inputString[j++] = strtol(temp, NULL, 16);
    }
    inputString[j]='\0';
}

int main(){
    char inputString[50];
    char convertedHex[100];
    int choice=0;

    printf("Welcome to Hexadecimal Converter.\n");
    while(1){
        printf("\nChoose the following options:\n");
        printf("1) Convert to hexadecimal\n");
        printf("2) Convert back to string\n");
        printf("3) Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter a string: ");
                scanf(" %[^\n]s", inputString);
                convertToHex(convertedHex, inputString);
                printf("\nHexadecimal representation: %s\n", convertedHex);
                break;
            case 2:
                printf("\nEnter a hexadecimal string: ");
                scanf(" %s", convertedHex);
                convertToString(inputString, convertedHex);
                printf("\nString representation: %s\n", inputString);
                break;
            case 3:
                printf("\nThank you for using Hexadecimal Converter.\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}