//Code Llama-13B DATASET v1.0 Category: Hexadecimal Converter ; Style: Romeo and Juliet
// Romeo and Juliet Hexadecimal Converter

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char hex_input[100];
    char hex_output[100];
    int i, j;

    // Ask for input
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_input);

    // Convert input to binary
    for (i = 0; i < strlen(hex_input); i++) {
        switch (hex_input[i]) {
            case '0':
                strcat(hex_output, "0000");
                break;
            case '1':
                strcat(hex_output, "0001");
                break;
            case '2':
                strcat(hex_output, "0010");
                break;
            case '3':
                strcat(hex_output, "0011");
                break;
            case '4':
                strcat(hex_output, "0100");
                break;
            case '5':
                strcat(hex_output, "0101");
                break;
            case '6':
                strcat(hex_output, "0110");
                break;
            case '7':
                strcat(hex_output, "0111");
                break;
            case '8':
                strcat(hex_output, "1000");
                break;
            case '9':
                strcat(hex_output, "1001");
                break;
            case 'A':
            case 'a':
                strcat(hex_output, "1010");
                break;
            case 'B':
            case 'b':
                strcat(hex_output, "1011");
                break;
            case 'C':
            case 'c':
                strcat(hex_output, "1100");
                break;
            case 'D':
            case 'd':
                strcat(hex_output, "1101");
                break;
            case 'E':
            case 'e':
                strcat(hex_output, "1110");
                break;
            case 'F':
            case 'f':
                strcat(hex_output, "1111");
                break;
            default:
                printf("Invalid input\n");
                return 1;
        }
    }

    // Print binary output
    printf("Binary representation: ");
    for (j = 0; j < strlen(hex_output); j++) {
        printf("%c", hex_output[j]);
    }
    printf("\n");

    return 0;
}