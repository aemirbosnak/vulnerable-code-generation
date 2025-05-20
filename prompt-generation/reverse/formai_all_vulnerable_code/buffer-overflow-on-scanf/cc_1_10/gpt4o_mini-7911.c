//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024

void print_statistics(int counts[], int size) {
    printf("\nStatistics of the character occurrences:\n");
    for(int i = 0; i < size; i++) {
        if(counts[i] > 0) {
            printf("Character '%c' occurs: %d times\n", (char)i, counts[i]);
        }
    }
}

void encrypt(char *input, char *output, int shift) {
    for (int i = 0; input[i] != '\0'; i++) {
        char current = input[i];

        if (current >= 'a' && current <= 'z') {
            output[i] = (current - 'a' + shift) % 26 + 'a';
        } else if (current >= 'A' && current <= 'Z') {
            output[i] = (current - 'A' + shift) % 26 + 'A';
        } else {
            output[i] = current; // non-alphabet characters remain unchanged
        }
    }
    output[strlen(input)] = '\0'; // null terminate the output string
}

void decrypt(char *input, char *output, int shift) {
    for (int i = 0; input[i] != '\0'; i++) {
        char current = input[i];

        if (current >= 'a' && current <= 'z') {
            output[i] = (current - 'a' - shift + 26) % 26 + 'a';
        } else if (current >= 'A' && current <= 'Z') {
            output[i] = (current - 'A' - shift + 26) % 26 + 'A';
        } else {
            output[i] = current; // non-alphabet characters remain unchanged
        }
    }
    output[strlen(input)] = '\0'; // null terminate the output string
}

void analyze_text(char *text) {
    int counts[256] = {0};

    for (int i = 0; text[i] != '\0'; i++) {
        counts[(unsigned char)text[i]]++;
    }

    print_statistics(counts, 256);
}

int main() {
    char input[MAX_LENGTH], encrypted[MAX_LENGTH], decrypted[MAX_LENGTH];
    int shift;

    printf("Enter a shift value (0-25): ");
    scanf("%d", &shift);

    // Making sure shift is within the valid range
    shift = shift % 26;

    printf("Enter the text to encrypt: ");
    getchar(); // consume the newline from previous input
    fgets(input, MAX_LENGTH, stdin);
    
    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    printf("\nOriginal Text: %s\n", input);

    // Analyze original text
    analyze_text(input);

    // Encrypt the text
    encrypt(input, encrypted, shift);
    printf("Encrypted Text: %s\n", encrypted);

    // Decrypt the text
    decrypt(encrypted, decrypted, shift);
    printf("Decrypted Text: %s\n", decrypted);

    // Analyze decrypted text
    analyze_text(decrypted);

    return 0;
}