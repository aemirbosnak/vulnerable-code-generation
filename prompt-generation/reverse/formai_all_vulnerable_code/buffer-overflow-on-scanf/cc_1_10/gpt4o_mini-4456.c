//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_NUM 1024

void toBinary(int num, char *binaryString) {
    int index = 0;
    char temp[32];

    // Prepare the binary string in reverse
    while (num > 0) {
        temp[index++] = (num % 2) + '0'; // Store the bit as a character
        num /= 2;
    }
    temp[index] = '\0';

    // Reverse the string to get the final binary representation
    for (int i = 0; i < index; i++) {
        binaryString[i] = temp[index - 1 - i];
    }
    binaryString[index] = '\0'; // Null-terminate the string
}

void renderTableHeader() {
    printf("=========================================\n");
    printf("|    Decimal    |        Binary       |\n");
    printf("=========================================\n");
}

void renderRow(int decimal, const char *binary) {
    printf("|      %-6d   |       %-10s      |\n", decimal, binary);
}

int main() {
    int num = 0;
    char binaryString[32];

    // Begin the quest for binary conversion
    printf("Hail, brave traveler! Enter the number of knights (up to %d) to convert to the mystical realm of binary:\n", MAX_NUM);
    scanf("%d", &num);

    // Check if the number is within the bounds of the sought realm
    if (num < 0 || num >= MAX_NUM) {
        printf("Alas! Only numbers betwixt 0 and %d may cross into binary.\n", MAX_NUM - 1);
        return 1;
    }

    // Rendering the enchanted table
    renderTableHeader();

    // Convert the number and present it
    for (int i = 0; i <= num; i++) {
        toBinary(i, binaryString);
        renderRow(i, binaryString);
    }

    // End of the quest
    printf("=========================================\n");
    printf("The conversion hath concluded, brave one. Farewell!\n");

    return 0;
}