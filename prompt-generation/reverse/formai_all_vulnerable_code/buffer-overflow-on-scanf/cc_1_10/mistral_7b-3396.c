//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LENGTH 100

typedef struct Scroll {
    char message[MAX_LENGTH];
    int shift;
} Scroll;

typedef struct Quill {
    int magic;
    Scroll scroll;
} Quill;

void generate_shift(Quill *quill) {
    int seed = time(NULL);
    srand(seed);
    quill->scroll.shift = rand() % 26;
}

void encrypt_message(Quill *quill) {
    int i;
    for (i = 0; i < strlen(quill->scroll.message); i++) {
        if (isalpha(quill->scroll.message[i])) {
            if (islower(quill->scroll.message[i]))
                quill->scroll.message[i] = (char)(((int)quill->scroll.message[i] + quill->scroll.shift - 'a') % 26 + 'a');
            else
                quill->scroll.message[i] = (char)(((int)quill->scroll.message[i] + quill->scroll.shift - 'A') % 26 + 'A');
        }
    }
}

void print_encrypted_scroll(Quill quill) {
    printf("Once upon a time, in a land far, far away,\n");
    printf("There was an enchanted quill that could write,\n");
    printf("Encrypted messages that only the wise could decipher,\n");
    printf("Let me present you the message from this quill: \n");
    printf("\n%s\n", quill.scroll.message);
}

int main() {
    Quill quill;
    char message[MAX_LENGTH];

    printf("Welcome to the Enchanted Quill!\n");
    printf("Please enter a message to be encrypted: ");
    scanf("%s", message);

    generate_shift(&quill);
    strcpy(quill.scroll.message, message);
    encrypt_message(&quill);

    printf("Your encrypted message has been stored in the scroll.\n");
    printf("To view the encrypted message, type 'show' :)\n");

    while (1) {
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "show") == 0) {
            print_encrypted_scroll(quill);
            break;
        }
    }

    return 0;
}