//FormAI DATASET v1.0 Category: QR code generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>  

#define MAX_LENGTH 100

/*
 * Calculates the modulo-2 division of two numbers
 * represented as strings
 */
char* modulo2(char* dividend, char* divisor) {
    char result[MAX_LENGTH] = {'\0'};
    int index = 0;
    int len_divisor = strlen(divisor);

    while (strncmp(dividend, divisor, len_divisor) >= 0) {
        for (int i = 0; i < len_divisor; i++) {
            dividend[i] = ((dividend[i] - '0') ^ (divisor[i] - '0')) + '0';
        }

        while (*dividend == '0') {
            dividend++;
        }

        if (*dividend == '\0') {
            break;
        }

        int len_dividend = strlen(dividend);
        strncpy(&result[index], "0", 1);
        index++;
    }

    strncpy(&result[index], dividend, strlen(dividend));
    return strdup(result);
}

/*
 * Generates the QR code for a given text using the polynomial division algorithm
 */
void generateQRCode(char* text) {
    char generator[] = "10100110111";
    int len_generator = strlen(generator);

    int len_text = strlen(text);
    char* dividend = (char*) malloc((len_text + len_generator) * sizeof(char));
    char* temp = (char*) malloc((len_text + len_generator) * sizeof(char));
    strncpy(dividend, text, len_text);
    strncpy(&dividend[len_text], "00000000000", len_generator);
    strncpy(temp, dividend, len_text + len_generator);

    char* remainder = modulo2(temp, generator);
    strncpy(&dividend[len_text], remainder, len_generator);
    strncpy(temp, dividend, len_text + len_generator);

    remainder = modulo2(temp, generator);
    strncpy(&dividend[len_text + len_generator], remainder, len_generator);
    strncpy(temp, dividend, len_text + 2 * len_generator);

    remainder = modulo2(temp, generator);
    strncpy(&dividend[len_text + 2 * len_generator], remainder, len_generator);

    printf("QR Code: ");
    printf("%s", dividend);
}

int main() {
    char text[MAX_LENGTH] = {'\0'};

    printf("Enter the text to generate QR Code: ");
    scanf("%s", text);
    generateQRCode(text);

    return 0;
}