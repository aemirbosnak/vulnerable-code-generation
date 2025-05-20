//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Our secret key, a musical masterpiece
const char KEY[] = {"Do#Re#Mi#Fa#So#La#Ti#Do"};

// Encrypting? Decrypting? Let's get the mode on!
enum Mode { ENCRYPT, DECRYPT };

// Welcome to our encryption extravaganza!
int main(int argc, char **argv) {
    // Let's check if we have all the right ingredients
    if (argc < 3) {
        printf("Oops! You forgot the file and/or mode, my friend!\n");
        printf("Usage: %s [file] [E|D]\n", argv[0]);
        return 1;
    }

    // File and mode at our fingertips
    char *file = argv[1];
    enum Mode mode = (argv[2][0] == 'E') ? ENCRYPT : DECRYPT;

    // File opening - let's peek inside!
    FILE *input = fopen(file, (mode == ENCRYPT) ? "rb" : "r");
    FILE *output = fopen((mode == ENCRYPT) ? "enc_file" : "dec_file", "w");

    // Error handling - we don't want any drama!
    if (!input) {
        printf("Oh no! We can't find that file, mate!\n");
        return 1;
    }
    if (!output) {
        printf("Oops! We couldn't create the output file, buddy!\n");
        return 1;
    }

    // Encryption time! Let's rock 'n' roll!
    if (mode == ENCRYPT) {
        char c;
        int key_index = 0;
        while ((c = fgetc(input)) != EOF) {
            fputc(c ^ KEY[key_index], output);
            key_index = (key_index + 1) % strlen(KEY);
        }
    }

    // Decryption time! Let's unmask the secret!
    else if (mode == DECRYPT) {
        char c;
        int key_index = 0;
        while ((c = fgetc(input)) != EOF) {
            fputc(c ^ KEY[key_index], output);
            key_index = (key_index + 1) % strlen(KEY);
        }
    }

    // Wrapping up - time to close the book!
    fclose(input);
    fclose(output);
    printf("Ta-da! Your file is now %s!\n", (mode == ENCRYPT) ? "encrypted" : "decrypted");
    return 0;
}