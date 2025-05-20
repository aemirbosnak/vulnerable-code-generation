//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random character
char generate_character() {
    // ASCII codes for characters that can be used in passwords
    int ascii_codes[] = {33, 35, 36, 37, 38, 42, 45, 46, 47, 48, 49, 50, 51, 52, 53,
                         54, 55, 56, 57, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75,
                         76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
                         94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106,
                         107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118,
                         119, 120, 121, 122};

    // Generate a random index to select a random ASCII code from the array
    int index = rand() % 67;

    // Return the corresponding character
    return (char) ascii_codes[index];
}

// Function to generate a secure password of given length
void generate_password(int length) {
    // Seed the random number generator
    srand(time(NULL));

    // Iterate for the given length and generate a random character each time
    for (int i = 0; i < length; i++) {
        printf("%c", generate_character());
    }
    printf("\n");
}

// Main function to execute the program
int main() {
    // Ask the user for the length of the password they want to generate
    int length;
    printf("Enter the length of the password you want to generate: ");
    scanf("%d", &length);

    // Check if the length is valid
    if (length <= 0) {
        printf("Invalid length. Please enter a positive integer.\n");
        exit(1);
    }

    printf("Generating a secure password of length %d...\n", length);

    // Call the function to generate the password
    generate_password(length);

    return 0;
}