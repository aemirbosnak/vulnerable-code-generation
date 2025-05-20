//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <math.h>

// A tale of two lovers forever entwined in a binary dance.
// Verona betwixt the strings and bits, where numbers breathe,
// And the essence of life doth transform in the realm of code.

void convertToBinary(int num) {
    // A tale told with the passion of those
    // Who love in secrecy, in shadows cast long.
    char binary[32];
    int index = 0;

    // Let us journey through this enchanted loop,
    // Where each bit song is practiced and refined.
    while (num > 0) {
        binary[index++] = (num % 2) + '0'; // Convert int to char
        num = num / 2; // Divide the number by two
    }

    // As stars above twinkle for their beloved,
    // We shall reverse this binary tale of love.
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }
    binary[index] = '\0'; // Null-terminate the string

    // And we declare the dream, the vision realized,
    // The binary heart of the number—forever immortalized.
    printf("The binary representation doth render: %s\n", binary);
}

void displayBinaryTable(int n) {
    // Like the fateful meeting at the Capulet ball,
    // A grand gathering of numbers and their loving forms.
    printf("Number\tBinary Representation\n");
    printf("-------------------------------\n");

    for (int i = 0; i <= n; i++) {
        printf("%d\t", i);
        convertToBinary(i);
    }
}

int main() {
    // Beneath the moonlit Verona, the time hath come,
    // To unravel the secrets of the mystical binary realm.
    int number;

    printf("Oh, gentle bard, tell me thy number to transform: ");
    scanf("%d", &number);

    // With whispered words of affection, we set our sights,
    // A table of shimmering binaries under the celestial lights.
    displayBinaryTable(number);

    // As the curtain falls on our lover’s plight,
    // A final farewell, but their story lives on eternally.
    printf("Thus, we have danced through bits and bytes.\n");
    printf("A felicitous evening we shared in binary delight.\n");

    return 0;
}