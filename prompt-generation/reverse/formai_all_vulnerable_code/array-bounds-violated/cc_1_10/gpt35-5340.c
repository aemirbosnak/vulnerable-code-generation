//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: automated
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to check if a character is valid ASCII
int is_valid(char c) {
    return (c >= 32 && c <= 126);
}

// Function to convert a character to ASCII art
void char_to_ascii(char c) {
    printf(" ___    ___\n");
    printf("|_%c_|  |_%c_|\n", c, c);
}

// Function to convert a string to ASCII art
void str_to_ascii(char* str) {
    int len = strlen(str);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < len; j++) {
            char c = str[j];
            if (is_valid(c)) {
                switch (i) {
                    case 0: printf("      "); break;
                    case 1: printf(" ___  "); break;
                    case 2: printf("|_%c_| ", c); break;
                    case 3: printf("      "); break;
                    case 4: printf("      "); break;
                }
            } else {
                switch (i) {
                    case 0: printf("          "); break;
                    case 1: printf("          "); break;
                    case 2: printf("    ?    "); break;
                    case 3: printf("          "); break;
                    case 4: printf("          "); break;
                }
            }
        }
        printf("\n");
    }
}

int main() {
    // Read input string
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    int len = strlen(str);
    if (str[len-1] == '\n') {
        str[len-1] = '\0';
    }

    // Print the ASCII art
    printf("ASCII Art:\n");
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (is_valid(c)) {
            char_to_ascii(c);
        } else {
            printf("      _______\n");
            printf("     |       |\n");
            printf("     |   ?   |\n");
            printf("     |_______|\n");
        }
    }

    // Extra: Print the string in reverse
    printf("\nReversed String: ");
    for (int i = len-1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}