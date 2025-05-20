//FormAI DATASET v1.0 Category: QR code generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QR_SIZE 21

void printQR(char qr[QR_SIZE][QR_SIZE]) {

    for(int i = 0; i < QR_SIZE; i++) {
        for(int j = 0; j < QR_SIZE; j++) {
            printf("%c ", qr[i][j]);
        }
        printf("\n");
    }
}

void generateQR(char data[], char qr[QR_SIZE][QR_SIZE]) {

    int dataLength = strlen(data);

    // Add length bits to data
    char lengthBits[9];
    sprintf(lengthBits, "%08d", dataLength);
    strcat(data, lengthBits);

    // Add padding to data (if necessary)
    int paddingLength = QR_SIZE * QR_SIZE - strlen(data);
    char padding[paddingLength + 1];
    memset(padding, '.', paddingLength);
    padding[paddingLength] = '\0';
    strcat(data, padding);

    // Generate random pattern
    int pattern[QR_SIZE][QR_SIZE];
    srand(time(NULL));
    for(int i = 0; i < QR_SIZE; i++) {
        for(int j = 0; j < QR_SIZE; j++) {
            pattern[i][j] = rand() % 2;
        }
    }

    // Add timing patterns
    for(int i = 8; i < QR_SIZE - 7; i++) {
        pattern[6][i] = 0;
        pattern[i][6] = 0;
    }

    // Add finder pattern
    for(int i = 0; i < 7; i++) {
        pattern[i][0] = 0;
        pattern[0][i] = 0;
        pattern[i][6] = 0;
        pattern[6][i] = 0;

        pattern[i][QR_SIZE - 1] = 0;
        pattern[QR_SIZE - 1][i] = 0;
        pattern[i][QR_SIZE - 7] = 0;
        pattern[QR_SIZE - 7][i] = 0;

        pattern[QR_SIZE - 7][i + 1] = 0;
        pattern[i + 1][QR_SIZE - 7] = 0;
    }

    // Add alignment patterns
    int alignmentCoords[5][2] = { {10, 10}, {10, QR_SIZE - 11}, {QR_SIZE - 11, 10}, {QR_SIZE - 10, QR_SIZE - 10}, {QR_SIZE - 10, 11} };
    for(int i = 0; i < 5; i++) {
        int xCoord = alignmentCoords[i][0];
        int yCoord = alignmentCoords[i][1];
        pattern[xCoord][yCoord] = 0;
        pattern[xCoord + 1][yCoord] = 0;
        pattern[xCoord][yCoord + 1] = 0;
        pattern[xCoord - 1][yCoord] = 0;
        pattern[xCoord][yCoord - 1] = 0;
    }

    // Add data pattern
    int dataIndex = 0;
    int x = QR_SIZE - 1;
    int y = QR_SIZE - 1;
    int direction = 0; // 0 = up, 1 = left, 2 = down, 3 = right
    while(dataIndex < strlen(data)) {
        // Check if we are at an empty module
        if(pattern[x][y] == -1) {

            // Add data module
            char currData = data[dataIndex];
            if(currData == '0') {
                pattern[x][y] = 0;
            } else if(currData == '1') {
                pattern[x][y] = 1;
            }

            // Move to next module
            dataIndex++;
            if(direction == 0) {
                x--;
            } else if(direction == 1) {
                y--;
            } else if(direction == 2) {
                x++;
            } else if(direction == 3) {
                y++;
            }

            // Check if we need to change direction
            if(x == -1 && y == 0) {
                x = 0;
                y = 0;
                direction++;
            }
            if(x == 0 && y == QR_SIZE && direction == 1) {
                x = 0;
                y = QR_SIZE - 1;
                direction++;
            }
            if(x == QR_SIZE && y == QR_SIZE - 1 && direction == 2) {
                x = QR_SIZE - 1;
                y = QR_SIZE - 1;
                direction++;
            }
            if(x == QR_SIZE - 7 && y == QR_SIZE - 8 && direction == 3) {
                x = QR_SIZE - 7;
                y = QR_SIZE - 7;
                direction = 0;
            }
        } else {
            // Move to next module
            if(direction == 0) {
                x--;
            } else if(direction == 1) {
                y--;
            } else if(direction == 2) {
                x++;
            } else if(direction == 3) {
                y++;
            }

            // Check if we need to change direction
            if(x == -1 && y == 0) {
                x = 0;
                y = 0;
                direction++;
            }
            if(x == 0 && y == QR_SIZE && direction == 1) {
                x = 0;
                y = QR_SIZE - 1;
                direction++;
            }
            if(x == QR_SIZE && y == QR_SIZE - 1 && direction == 2) {
                x = QR_SIZE - 1;
                y = QR_SIZE - 1;
                direction++;
            }
            if(x == QR_SIZE - 7 && y == QR_SIZE - 8 && direction == 3) {
                x = QR_SIZE - 7;
                y = QR_SIZE - 7;
                direction = 0;
            }
        }
    }

    // Copy pattern to QR code
    for(int i = 0; i < QR_SIZE; i++) {
        for(int j = 0; j < QR_SIZE; j++) {
            if(pattern[i][j] == 0) {
                qr[i][j] = ' ';
            } else {
                qr[i][j] = '#';
            }
        }
    }
}

int main() {

    char data[] = "Hello, World!";
    char qr[QR_SIZE][QR_SIZE];
    memset(qr, -1, sizeof(qr));
    generateQR(data, qr);
    printQR(qr);

    return 0;
}