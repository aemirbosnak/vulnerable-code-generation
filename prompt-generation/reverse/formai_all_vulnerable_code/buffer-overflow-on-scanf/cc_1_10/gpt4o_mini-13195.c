//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

void love_letters(int num);
void display_binary(char *binary, int length);
void tragic_end(char *message);

int main() {
    // A love story begins
    char *in_fair_verona = "Enter your heart's number: ";
    int num;
    
    printf("%s", in_fair_verona);
    scanf("%d", &num);
    
    // If the heart does not beat
    if (num < 0) {
        tragic_end("Alas, the number is negative! Love cannot exist in darkness.");
        return 1;
    }

    // Love blooms through conversion
    love_letters(num);
    return 0;
}

// In sunset's glow, our lovers seek the binary form
void love_letters(int num) {
    char binary[32];
    int i = 0, j = 0;

    // Whispering one bit at a time
    while (num > 0) {
        binary[i++] = (num % 2) + '0'; // Creating the binary letters
        num /= 2;
    }
    
    // Our tale unwinds, let us reveal
    printf("Binary representation: ");
    display_binary(binary, i); // Calling upon the spirits for display
    printf("\n");
}

// The dance of lovers, turning bits around
void display_binary(char *binary, int length) {
    for (int j = length - 1; j >= 0; j--) {
        putchar(binary[j]);
    }
}

// And thus, a tragic end to love
void tragic_end(char *message) {
    printf("%s\n", message);
    printf("For the heart that beats no more, we shall mourn.\n");
    printf("The nightingale's song fades, as the shadows fall.\n");
}