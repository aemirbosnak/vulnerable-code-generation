//FormAI DATASET v1.0 Category: QR code reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the structure for a QR code */
typedef struct qrcode {
    int id;
    char data[50];
} QRCode;

/* Function to read a QR code */
void readQRCode(QRCode *code) {
    printf("Enter the QR code ID: ");
    scanf("%d", &code->id);
    printf("Enter the QR code data: ");
    scanf("%s", code->data);
}

/* Function to print the QR code data */
void printQRCode(QRCode code) {
    printf("QR code ID: %d\n", code.id);
    printf("QR code data: %s\n", code.data);
}

/* Function to compare two QR codes for equality */
int isEqual(QRCode code1, QRCode code2) {
    if (code1.id == code2.id && strcmp(code1.data, code2.data) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    QRCode codes[10]; // create an array of QR code structures

    printf("Welcome to the QR code scanner!\n");

    int choice;
    do {

        // show menu options
        printf("\nMenu:\n");
        printf("1. Scan a QR code\n");
        printf("2. View scanned QR codes\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1: // scan a QR code
                {
                    QRCode newCode;
                    readQRCode(&newCode);

                    // check if the code is already in the array
                    int found = 0;
                    for (int i = 0; i < 10; i++) {
                        if (isEqual(codes[i], newCode)) {
                            printf("This QR code has already been scanned!\n");
                            found = 1;
                            break;
                        }
                    }

                    // if the code is new, add it to the array
                    if (!found) {
                        for (int i = 0; i < 10; i++) {
                            if (codes[i].id == 0) {
                                codes[i] = newCode;
                                printf("QR code scanned and saved!\n");
                                break;
                            }
                        }
                    }

                    break;
                }

            case 2: // view scanned QR codes
                {
                    // check if there are any scanned codes
                    int found = 0;
                    for (int i = 0; i < 10; i++) {
                        if (codes[i].id != 0) {
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("No QR codes have been scanned yet!\n");
                    } else {
                        printf("Scanned QR codes:\n");
                        for (int i = 0; i < 10; i++) {
                            if (codes[i].id != 0) {
                                printQRCode(codes[i]);
                            }
                        }
                    }

                    break;
                }

            case 3: // quit
                printf("Exiting program. Goodbye!\n");
                break;

            default: // invalid choice
                printf("Invalid choice!\n");
                break;
        }

    } while (choice != 3);

    return 0;
}