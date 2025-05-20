//FormAI DATASET v1.0 Category: QR code generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QR_CODE_SIZE 21

int generateQRCode(char qrCode[QR_CODE_SIZE]);
void printQRCode(char qrCode[QR_CODE_SIZE]);
int checkDuplicates(char qrCode[QR_CODE_SIZE]);

int main(void) {
    char qrCode[QR_CODE_SIZE];
    int numPlayers, i;

    printf("Welcome to the QR Code Multiplayer!!\n");
    printf("Please enter the number of players: ");
    scanf("%d", &numPlayers);

    // Generate unique QR code for each player
    for(i=1; i<=numPlayers; i++) {
        do {
            generateQRCode(qrCode);
        } while(checkDuplicates(qrCode)); // Check if generated QR code already exists
        printf("Player %d's QR code:\n", i);
        printQRCode(qrCode);
        printf("\n");
    }

    return 0;
}

// Generates a unique QR code of size QR_CODE_SIZE
int generateQRCode(char qrCode[QR_CODE_SIZE]) {
    int i;
    srand(time(NULL));
    for(i=0; i<QR_CODE_SIZE; i++) {
        qrCode[i] = 'A' + rand() % 26; // Generate random uppercase alphabet character
    }
    qrCode[QR_CODE_SIZE-1] = '\0'; // Terminate string
    return 0;
}

// Prints a QR code to console
void printQRCode(char qrCode[QR_CODE_SIZE]) {
    int i;
    printf("+=================+\n");
    for(i=0; i<3; i++) {
        printf("|%c%c%c%c%c%c%c%c%c%c|\n", qrCode[0+(i*7)], qrCode[1+(i*7)], qrCode[2+(i*7)],
            qrCode[3+(i*7)], qrCode[4+(i*7)], qrCode[5+(i*7)], qrCode[6+(i*7)], qrCode[7+(i*7)], qrCode[8+(i*7)], qrCode[9+(i*7)]);
    }
    printf("+=================+\n");
}

// Checks if the generated QR code already exists
int checkDuplicates(char qrCode[QR_CODE_SIZE]) {
    static char qrCodes[1000][QR_CODE_SIZE]; // Create static array to store QR codes
    static int numCodes = 0;
    int i;
    for(i=0; i<numCodes; i++) {
        if(strcmp(qrCode, qrCodes[i]) == 0) { // If QR codes match, return true (1)
            return 1;
        }
    }
    strcpy(qrCodes[numCodes], qrCode); // Add new QR code to array
    numCodes++;
    return 0;
}