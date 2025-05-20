//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char letter;
    int frequency;
} Freq;

typedef struct {
    char original;
    char cipher;
} CipherLetter;

// function to count the frequency of each character in a string
void countFreq(char* message, Freq* frequency) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (message[i] == frequency[j].letter) {
                frequency[j].frequency++;
                break;
            }
            if (j == len-1) {
                frequency[i].letter = message[i];
                frequency[i].frequency++;
                break;
            }
        }
    }
}

// function to sort characters based on frequency
void sortFreq(Freq* frequency, int len) {
    for (int i = 0; i < len-1; i++) {
        for (int j = i+1; j < len; j++) {
            if (frequency[j].frequency > frequency[i].frequency) {
                Freq temp = frequency[i];
                frequency[i] = frequency[j];
                frequency[j] = temp;
            }
        }
    }
}

// function to create a cipher key based on sorted frequency
void createCipher(Freq* frequency, int len, CipherLetter* cipher) {
    for (int i = 0; i < len; i++) {
        cipher[i].original = frequency[i].letter;
        cipher[i].cipher = 'A' + i;
    }
}

// function to encode a message using a given cipher
void encodeMessage(char* message, CipherLetter* cipher, char* encoded) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 26; j++) {
            if (message[i] == cipher[j].original) {
                encoded[i] = cipher[j].cipher;
                break;
            }
            if (j == 25) {
                encoded[i] = message[i];
                break;
            }
        }
    }
}

int main() {
    char message[1000];
    printf("What message would you like to encode?");
    scanf("%[^\n]", message);

    Freq frequency[strlen(message)];
    countFreq(message, frequency);

    sortFreq(frequency, strlen(message));

    CipherLetter cipher[26];
    createCipher(frequency, strlen(message), cipher);

    char encoded[strlen(message)];
    encodeMessage(message, cipher, encoded);

    printf("Original message: %s\n", message);
    printf("Encoded message: %s", encoded);

    return 0;
}