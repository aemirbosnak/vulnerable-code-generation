//FormAI DATASET v1.0 Category: QR code generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_CODE_DIM 21     // Total dimensions of the QR Code (21x21)
#define QUIET_ZONE 4       // Size of quiet zone required around the QR Code
#define MAX_DATA_SIZE 250  // Maximum data limit that can fit in QR Code

/* Function to generate the QR code */
void generateQRCode(const char* data, int dataSize)
{
   int i, j, k, bitPos, row, col;
   char qrCode[QR_CODE_DIM][QR_CODE_DIM];
   memset(qrCode, ' ', sizeof(qrCode));   // Set all elements to blank space

   /* Set Position Detection Pattern (PDP) */
   for (i = 0; i < 7; i++) {
      qrCode[i][0] = qrCode[0][i] = qrCode[6][i] = qrCode[i][6] = qrCode[QR_CODE_DIM-1][6-i] = qrCode[6-i][QR_CODE_DIM-1] = '#';
   }
   qrCode[1][1] = qrCode[1][5] = qrCode[5][1] = '#';

   /* Set Timing Pattern */
   for (i = 8; i < QR_CODE_DIM-QUIET_ZONE; i++) {
      qrCode[i][6] = (i % 2) ? '#' : ' ';
      qrCode[6][i] = (i % 2) ? '#' : ' ';
   }

   /* Set Version Information */
   if (dataSize > MAX_DATA_SIZE) {
      printf("Error: Data size exceeded. Maximum data that can be fitted in QR Code is %d\n", MAX_DATA_SIZE);
      return;
   }

   /* Set Data bits */
   bitPos = 0;
   for (i = QR_CODE_DIM - QUIET_ZONE - 1; i >= 0 && bitPos < dataSize; i--) {
      if (i == 6) { i--; }   // Skip over timing pattern
      for (j = QR_CODE_DIM - QUIET_ZONE - 1; j >= 0 && bitPos < dataSize; j -= 2) {
         qrCode[i][j-1] = (data[bitPos] & 1) ? '#' : ' ';
         qrCode[i][j] = (data[bitPos] & 2) ? '#' : ' ';
         qrCode[i-1][j-1] = (data[bitPos] & 4) ? '#' : ' ';
         qrCode[i-1][j] = (data[bitPos] & 8) ? '#' : ' ';
         bitPos++;
      }
   }

   /* Set Quiet Zone */
   for (i = 0; i < QR_CODE_DIM; i++) {
      qrCode[i][QR_CODE_DIM-1] = qrCode[QR_CODE_DIM-1][i] = ' ';
   }

   /* Print QR Code */
   printf("\nQR Code:\n\n");
   for (row = 0; row < QR_CODE_DIM; row++) {
      for (col = 0; col < QR_CODE_DIM; col++) {
         printf("%c ", qrCode[row][col]);
      }
      printf("\n");
   }
}

int main()
{
   const char* data = "Hello World!";
   generateQRCode(data, strlen(data));
   return 0;
}