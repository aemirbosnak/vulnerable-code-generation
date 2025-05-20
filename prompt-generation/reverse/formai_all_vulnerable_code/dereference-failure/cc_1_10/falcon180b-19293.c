//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Function to calculate the checksum
unsigned int calculateChecksum(char *data, int length) {
    unsigned int sum = 0;
    unsigned char c;
    for (int i = 0; i < length; i++) {
        c = toupper(data[i]);
        if (isdigit(c)) {
            sum += c - '0';
        } else {
            sum += c - 'A' + 10;
        }
    }
    return (sum % 11);
}

// Function to validate the checksum
int validateChecksum(char *data, int length) {
    unsigned int calculatedChecksum = calculateChecksum(data, length - 1);
    unsigned int expectedChecksum = data[length - 1] - '0';
    if (calculatedChecksum == expectedChecksum) {
        return 1;
    } else {
        return 0;
    }
}

// Function to generate a random string of specified length
char *generateRandomString(int length) {
    char *string = (char *) malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = rand() % 26 + 'A';
    }
    string[length] = '\0';
    return string;
}

// Function to generate a random checksum for the given string
char generateRandomChecksum(char *string) {
    int length = strlen(string);
    unsigned int checksum = calculateChecksum(string, length - 1);
    return (char) (checksum + '0');
}

int main() {
    srand(time(NULL));
    char *string = generateRandomString(10);
    printf("Random string: %s\n", string);
    char checksum = generateRandomChecksum(string);
    printf("Random checksum: %c\n", checksum);
    if (validateChecksum(string, strlen(string))) {
        printf("Checksum is valid.\n");
    } else {
        printf("Checksum is invalid.\n");
    }
    return 0;
}