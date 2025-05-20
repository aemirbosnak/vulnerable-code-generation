//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

void apocalypse_warning(void);
char* hex_to_binary(char* hex);
int binary_to_decimal(char* binary);
void print_binary(char* binary);
void print_decimal(int decimal);

int main(void) {
    apocalypse_warning();
    
    char hex[10];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    
    char* binary = hex_to_binary(hex);
    printf("The equivalent binary number is: ");
    print_binary(binary);
    
    int decimal = binary_to_decimal(binary);
    printf("The equivalent decimal number is: ");
    print_decimal(decimal);
    
    return 0;
}

void apocalypse_warning(void) {
    printf("*** WARNING: THIS PROGRAM WAS WRITTEN IN A POST-APOCALYPTIC WORLD AND MAY CONTAIN ERRORS OR INEFFICIENCIES DUE TO THE LACK OF TECHNOLOGICAL RESOURCES ***\n\n");
}

char* hex_to_binary(char* hex) {
    char* binary = malloc(sizeof(char) * 40);
    int i;
    for (i = 0; hex[i] != '\0'; i++) {
        switch(hex[i]) {
            case '0':
                strcat(binary, "0000");
                break;
            case '1':
                strcat(binary, "0001");
                break;
            case '2':
                strcat(binary, "0010");
                break;
            case '3':
                strcat(binary, "0011");
                break;
            case '4':
                strcat(binary, "0100");
                break;
            case '5':
                strcat(binary, "0101");
                break;
            case '6':
                strcat(binary, "0110");
                break;
            case '7':
                strcat(binary, "0111");
                break;
            case '8':
                strcat(binary, "1000");
                break;
            case '9':
                strcat(binary, "1001");
                break;
            case 'A':
                strcat(binary, "1010");
                break;
            case 'B':
                strcat(binary, "1011");
                break;
            case 'C':
                strcat(binary, "1100");
                break;
            case 'D':
                strcat(binary, "1101");
                break;
            case 'E':
                strcat(binary, "1110");
                break;
            case 'F':
                strcat(binary, "1111");
                break;
            default:
                printf("Invalid hexadecimal input\n");
                exit(0);
        }
    }
    return binary;
}

int binary_to_decimal(char* binary) {
    int decimal = 0;
    int i;
    for (i = 0; binary[i] != '\0'; i++) {
        decimal = decimal * 2 + (binary[i] - '0');
    }
    return decimal;
}

void print_binary(char* binary) {
    int i;
    for (i = 0; binary[i] != '\0'; i++) {
        printf("%c", binary[i]);
        if ((i + 1) % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

void print_decimal(int decimal) {
    printf("%d\n", decimal);
}