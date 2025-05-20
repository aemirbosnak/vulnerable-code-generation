//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to uppercase
void toUpper(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to read a QR code
int readQRCode(char* input) {
    int len = strlen(input);
    int count = 0;

    // Check if the input string is a valid QR code
    for (int i = 0; i < len; i++) {
        if (!isdigit(input[i])) {
            printf("Invalid QR code\n");
            return 0;
        }
    }

    // Convert the input string to uppercase
    toUpper(input);

    // Check if the QR code is a happy message
    if (strstr(input, "HAPPY")) {
        printf("Happy QR code detected!\n");
        count++;
    }

    // Check if the QR code is a sad message
    if (strstr(input, "SAD")) {
        printf("Sad QR code detected!\n");
        count++;
    }

    // Check if the QR code is a funny message
    if (strstr(input, "FUNNY")) {
        printf("Funny QR code detected!\n");
        count++;
    }

    // Check if the QR code is a love message
    if (strstr(input, "LOVE")) {
        printf("Love QR code detected!\n");
        count++;
    }

    // Check if the QR code is a motivational message
    if (strstr(input, "MOTIVATE")) {
        printf("Motivational QR code detected!\n");
        count++;
    }

    return count;
}

int main() {
    char input[100];

    printf("Enter a QR code to read: ");
    scanf("%s", input);

    int result = readQRCode(input);

    if (result > 0) {
        printf("Happy QR code detected!\n");
    } else {
        printf("No happy message found in the QR code.\n");
    }

    return 0;
}