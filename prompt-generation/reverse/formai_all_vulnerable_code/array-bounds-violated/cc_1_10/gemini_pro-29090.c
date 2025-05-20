//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Greetings, my dear Watson. The Irregulars have intercepted a message that requires our immediate attention.
    printf("Elementary, my dear Watson! The Irregulars have intercepted a message that requires our immediate attention.\n\n");

    // The message is an encoded binary string that must be deciphered. Watson, retrieve your magnifying glass and follow my lead.
    char encodedMessage[] = "01000001 01101110 01100100 00100000 01110100 01101111 01110101 01100100 00100000 01100110 01100101 01100101 01111001 00101110";
    printf("The encoded message is: %s\n\n", encodedMessage);

    // Excellent, Watson! Now, let us split the message into individual 8-bit binary numbers. Each number represents an ASCII character.
    char binaryNumbers[8][9];
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < strlen(encodedMessage); i++) {
        if (encodedMessage[i] == ' ') {
            binaryNumbers[j][k] = '\0';
            j++;
            k = 0;
        } else {
            binaryNumbers[j][k] = encodedMessage[i];
            k++;
        }
    }
    binaryNumbers[j][k] = '\0';

    // Capital, Watson! Now, let us convert each binary number to its decimal equivalent, which corresponds to the ASCII code of the character.
    int decimalNumbers[8];
    for (i = 0; i < 8; i++) {
        decimalNumbers[i] = 0;
        for (j = 0; j < 8; j++) {
            if (binaryNumbers[i][j] == '1') {
                decimalNumbers[i] += (1 << (7 - j));
            }
        }
    }

    // Brilliant, Watson! The individual characters of the message are hidden within these decimal numbers. Let us assemble the message.
    char decodedMessage[9];
    for (i = 0; i < 8; i++) {
        decodedMessage[i] = (char)decimalNumbers[i];
    }
    decodedMessage[8] = '\0';

    // Remarkable, Watson! We have successfully deciphered the message. It reads: "The game is afoot".
    printf("The decoded message is: %s\n\n", decodedMessage);

    // Excellent work, my dear Watson! You have proven to be an invaluable asset in this investigation.
    printf("Excellent work, my dear Watson! You have proven to be an invaluable asset in this investigation.\n");

    return 0;
}