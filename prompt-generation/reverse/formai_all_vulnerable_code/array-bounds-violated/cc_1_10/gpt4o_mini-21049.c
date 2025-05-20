//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MODULE_SIZE 10
#define VERSION 1
#define ERROR_CORRECTION_LEVEL 'L'
#define MAX_DATA_LENGTH 50

// My dear friend, we're on a whimsical journey to generate a QR code!
// This program will put a smile on your face (and maybe some QR codes in your pocket!)

void printQRCode(int qr[VERSION][VERSION]) {
    printf("\nHere's your fancy QR code, don’t scan it too fast!\n");
    for (int r = 0; r < VERSION; r++) {
        for (int c = 0; c < VERSION; c++) {
            if (qr[r][c] == 1) {
                printf("██"); // Filled modules
            } else {
                printf("  "); // Empty modules
            }
        }
        printf("\n");
    }
}

// This function generates a QR code.
// But shhh... it's a series of 1's and 0's that look like a Picasso painting.
void generateQRCode(const char *data, int qr[VERSION][VERSION]) {
    memset(qr, 0, VERSION * VERSION * sizeof(int)); // Clear the QR array

    // Fill in the QR code structure just to stir things up a bit.
    // Please note that this is a very basic version of QR... we’re not on a treasure hunt here!
    for (int r = 0; r < VERSION; r++) {
        for (int c = 0; c < VERSION; c++) {
            if (r % 2 == 0 && c % 2 == 0) {
                qr[r][c] = 1; // Adding some randomness, like my socks on laundry day
            } else {
                qr[r][c] = 0;
            }
        }
    }

    // Now let's embed your data! If only data could make me breakfast...
    int dataLength = strlen(data);
    for (int i = 0; i < dataLength && i < (VERSION * VERSION); i++) {
        // Just throwing the data in there with delightful chaos.
        if (data[i] % 2 == 0) {
            qr[i / VERSION][i % VERSION] = 1;
        }
    }
}

int main() {
    // Gather round, folks... gather round! We need a data input for the QR!
    char data[MAX_DATA_LENGTH];
    
    printf("Welcome to the QR Code Generator! 🥳\n");
    printf("Please enter the most delightful string to encode (max %d characters): ", MAX_DATA_LENGTH);
    
    // Who needs validation? Just *type* it, my friend!
    fgets(data, sizeof(data), stdin);
    
    // Stripping newline (we don’t want that pesky thing ruining our QR)
    size_t ln = strlen(data) - 1;
    if (data[ln] == '\n') {
        data[ln] = '\0';
    }

    // Who knew data could be this much fun? Now, let’s get down to business!
    int qr[VERSION][VERSION];
    generateQRCode(data, qr);
    
    // And voila! The QR code is ready. Kind of like microwave popcorn, but without the burn smell.
    printQRCode(qr);
    
    printf("Scan it if you dare! But remember, it might not go to a million-dollar website...\n");
    printf("Unless you coded it! In which case, kudos!\n");

    return 0;
}