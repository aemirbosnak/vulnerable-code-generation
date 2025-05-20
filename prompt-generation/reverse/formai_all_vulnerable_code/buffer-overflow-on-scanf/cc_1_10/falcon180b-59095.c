//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100];
    int decimal = 0, i = 0, j = 0, k = 0, rem;
    char binary[100];
    char hex[100];

    printf("Enter a decimal number: ");
    scanf("%s", input);

    for(i=0; input[i]!= '\0'; i++){
        if(!isdigit(input[i])){
            printf("Invalid input! Please enter a valid decimal number.\n");
            return 0;
        }
    }

    decimal = atoi(input);

    while(decimal!= 0){
        rem = decimal % 2;
        binary[j] = rem + '0';
        j++;
        decimal /= 2;
    }

    for(i=j-1; i>=0; i--){
        printf("%c", binary[i]);
    }

    printf("\n");

    for(i=0; i<strlen(binary); i++){
        if(binary[i] == '0'){
            hex[k] = '0';
        }
        else{
            hex[k] = '1';
        }
        k++;
    }

    printf("Binary: %s\n", binary);
    printf("Hexadecimal: %s\n", hex);

    return 0;
}