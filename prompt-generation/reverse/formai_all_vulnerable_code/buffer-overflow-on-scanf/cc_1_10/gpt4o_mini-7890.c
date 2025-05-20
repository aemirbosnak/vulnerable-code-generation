//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include <stdio.h>

void printHex(int n);
void convertToHex(int n, char hex[]);

int main() {
    int userInput;
    
    printf("Greetings, noble traveler!\n");
    printf("Enter a decimal number to unveil its hexadecimal counterpart: ");
    scanf("%d", &userInput);
    
    if (userInput < 0) {
        printf("Alas! The realm of negative numbers is forbidden!\n");
        return 1;
    }
    
    printf("The decimal number %d, in the ancient language of hex, is:\n", userInput);
    printHex(userInput);
    
    return 0;
}

void printHex(int n) {
    char hex[20];
    convertToHex(n, hex);
    printf("Hexadecimal: %s\n", hex);
}

void convertToHex(int n, char hex[]) {
    int remainder, i = 0;
    
    while (n != 0) {
        remainder = n % 16;
        if (remainder < 10) {
            hex[i] = remainder + '0'; // '0' to '9'
        } else {
            hex[i] = remainder - 10 + 'A'; // 'A' to 'F'
        }
        n = n / 16;
        i++;
    }
    
    hex[i] = '\0'; // Null terminate the string
    
    // Now hex contains the hexadecimal in reverse order
    // We need to reverse it to get correct representation
    int len = i;
    for (int j = 0; j < len / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[len - j - 1];
        hex[len - j - 1] = temp;
    }
}