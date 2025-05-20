//FormAI DATASET v1.0 Category: QR code reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main() {
    char qrCode[50]; // Declare 50-character string to hold QR code data
    int i, numReads = 0; // Declare loop counter and number of successful reads

    printf("Greetings adventurer, before you lies a mysterious QR code. Will you attempt to decode it?\n");

    do {
        printf("\nEnter the QR code (must be 50 characters or less): ");
        scanf("%s", qrCode); // Read user input

        // Check if code is correct length
        if (strlen(qrCode) != 50) {
            printf("Sorry noble sir, the code must be exactly 50 characters!\n");
            continue;
        }

        // Read code character by character and check for validity (only 0-9 and A-F allowed)
        for (i = 0; i < strlen(qrCode); i++) {
            if (!isdigit(qrCode[i]) && (qrCode[i] < 'A' || qrCode[i] > 'F')) {
                printf("Nay, fair adventurer, please enter a valid QR code (must be hexadecimal)!\n");
                break;
            }
        }

        // If we have successfully read a valid QR code, print it out and exit program
        if (i == strlen(qrCode)) {
            printf("Hail, valiant adventurer! Thy brave heart has deciphered the code:\n%s", qrCode);
            return 0;
        }

        numReads++; // Increment number of unsuccessful attempts

        // Print out medieval phrases of encouragement to keep trying
        switch (numReads) {
            case 1:
                printf("Fear not, brave hero! Try again!\n");
                break;
            case 2:
                printf("Thou art so close, goodly knight! Keep trying!\n");
                break;
            case 3:
                printf("Verily, thou art a tenacious warrior, but keep striving!\n");
                break;
            default:
                printf("Alack and alas, thou hast exhausted thy attempts. Farewell!\n");
                return 1; // Return error code to indicate no successful reads
        }
    } while (numReads < 4); // Maximum of 4 attempts allowed

    return 0;
}