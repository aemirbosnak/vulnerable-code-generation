//FormAI DATASET v1.0 Category: QR code generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int generateRandom(int max) {
    srand(time(NULL)); // seed the random number generator with the current time
    return rand() % max; // return a random number between 0 and max
}

// Function to generate a QR code
void generateQR(int size, char data[]) {
    int i,j,k,l,m,n;
    char qr[size][size];

    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            qr[i][j] = ' '; // initialize the QR code with spaces
        }
    }

    // Enter data into the QR code
    k = generateRandom(size);
    l = generateRandom(size);
    qr[k][l] = data[0];

    for(m=1; m<strlen(data); m++) {
        do {
            n = generateRandom(4);
            if(n == 0 && k > 0) {
                k--;
            }
            else if(n == 1 && l < size-1) {
                l++;
            }
            else if(n == 2 && k < size-1) {
                k++;
            }
            else if(n == 3 && l > 0) {
                l--;
            }
        } while(qr[k][l] != ' ');
        qr[k][l] = data[m];
    }

    // Print the QR code
    printf("\n");
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            printf("%c", qr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size; 
    char data[50];

    printf("Enter the size of the QR code (minimum 8): ");
    scanf("%d", &size);
    if(size < 8) {
        printf("Size too small!\n");
        return 0;
    }

    printf("Enter the data to be encoded: ");
    scanf("%s", data);

    generateQR(size, data);

    return 0;
}