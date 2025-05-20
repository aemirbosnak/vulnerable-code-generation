//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: brave
#include <stdio.h>

// Function to convert decimal to hexadecimal
void decimalToHex(int decimal, char hex[]) {
    int i = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[i++] = 48 + remainder; // 48 is ASCII for '0'
        } else {
            hex[i++] = 55 + remainder; // 55 is ASCII for 'A'
        }
        decimal /= 16;
    }
    hex[i] = '\0';
    
    // Reverse hex string
    for (int j = 0; j < i / 2; ++j) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }
}

// Function to display the adventure of the conversion
void adventureDisplay(int decimal, const char hex[]) {
    printf("\n🌟 Welcome Brave Adventurer! 🌟\n");
    printf("You have chosen to convert the mystical number: %d\n", decimal);
    printf("As you embark on this coding quest, the number transforms...\n");
    printf("🤔 The secret hexadecimal representation is: %s\n", hex);
    printf("Now you possess the power of hexadecimal! Use it wisely!\n");
}

int main() {
    int number;
    char hex[20];

    printf("🧚‍♂️ Enter a decimal number to convert to hexadecimal: ");
    while (scanf("%d", &number) == 1 && number >= 0) {
        decimalToHex(number, hex);
        adventureDisplay(number, hex);
        printf("\n🔄 Enter another decimal number to continue or a negative number to exit: ");
    }
    
    if (number < 0) {
        printf("👋 Farewell, brave adventurer! Until we meet again!\n");
    } else {
        printf("🧾 Invalid input! Please enter a valid decimal number.\n");
    }

    return 0;
}