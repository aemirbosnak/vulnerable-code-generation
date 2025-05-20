//FormAI DATASET v1.0 Category: String manipulation ; Style: irregular
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    // Turn the string into uppercase
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }

    printf("Uppercase: %s\n", str);

    // Count the number of spaces in the string
    int spaces = 0;
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == ' ') {
            spaces++;
        }
    }

    printf("Spaces: %d\n", spaces);

    // Reverse the string
    char reverse[100];
    int j = 0;
    for(int i = strlen(str) - 1; i >= 0; i--) {
        reverse[j++] = str[i];
    }
    reverse[j] = '\0';

    printf("Reverse: %s\n", reverse);

    // Remove vowels from the string
    char no_vowels[100];
    j = 0;
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') {
            no_vowels[j++] = str[i];
        }
    }
    no_vowels[j] = '\0';

    printf("No vowels: %s\n", no_vowels);

    // Shift the string by a user-defined amount
    int shift_amount;
    printf("Enter shift amount: ");
    scanf("%d", &shift_amount);

    char shifted_string[100];
    for(int i = 0; i < strlen(str); i++) {
        shifted_string[i] = str[(i + shift_amount) % strlen(str)];
    }
    shifted_string[strlen(str)] = '\0';

    printf("Shifted: %s\n", shifted_string);

    return 0;
}