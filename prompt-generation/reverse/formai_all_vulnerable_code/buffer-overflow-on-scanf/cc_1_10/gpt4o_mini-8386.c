//GPT-4o-mini DATASET v1.0 Category: QR code reader ; Style: recursive
#include <stdio.h>
#include <string.h>

#define MAX_CODES 5
#define QR_CODE_LENGTH 20

const char* qr_codes[MAX_CODES] = {
    "QR Code 1: Welcome to C Programming!",
    "QR Code 2: Learning about QR Codes.",
    "QR Code 3: Recursive Functions are fun!",
    "QR Code 4: Enjoy coding in C.",
    "QR Code 5: OpenAI creates meaningful AI."
};

void printInstructions() {
    printf("Available QR Codes:\n");
    for(int i = 0; i < MAX_CODES; i++) {
        printf("  [%d] %s\n", i + 1, qr_codes[i]);
    }
}

void readQRCode(int choice) {
    if (choice < 1 || choice > MAX_CODES) {
        printf("Invalid choice. Please try again.\n");
        return;
    }
    printf("Reading: %s\n", qr_codes[choice - 1]);
}

void recursiveRead() {
    int choice;
    
    printInstructions();
    printf("Select a QR code to read (1-%d): ", MAX_CODES);
    scanf("%d", &choice);
    
    readQRCode(choice);
    
    char continue_choice;
    printf("Do you want to read another QR code? (y/n): ");
    scanf(" %c", &continue_choice); // Notice the space before %c to consume any leftover newlines
    
    if (continue_choice == 'y' || continue_choice == 'Y') {
        recursiveRead(); // Recursive call for reading another QR code
    } else {
        printf("Thank you for using the QR code reader!\n");
    }
}

int main() {
    printf("Welcome to the QR Code Reader!\n");
    recursiveRead(); // Start the recursive reading process
    return 0;
}