//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 1024

// Function to translate a single character to Cat Language
const char* translate_char(char ch) {
    switch (ch) {
        case 'a': return "meow";
        case 'b': return "purr";
        case 'c': return "hiss";
        case 'd': return "mew";
        case 'e': return "yowl";
        case 'f': return "kitten";
        case 'g': return "pounce";
        case 'h': return "feline";
        case 'i': return "whisker";
        case 'j': return "scratch";
        case 'k': return "paw";
        case 'l': return "tail";
        case 'm': return "nap";
        case 'n': return "claw";
        case 'o': return "meowmeow";
        case 'p': return "pawsome";
        case 'q': return "purification";
        case 'r': return "roar";
        case 's': return "snuggle";
        case 't': return "play";
        case 'u': return "cuddle";
        case 'v': return "vocalize";
        case 'w': return "wander";
        case 'x': return "xenon";  // Let's make it a bit unique
        case 'y': return "yarn";
        case 'z': return "zoom";
        default:  return (char[]){ch, '\0'}; // Return as-is for any other character
    }
}

// Function to translate a string to Cat Language
void translate_string(const char* input, char* output) {
    output[0] = '\0'; // Initialize the output string
    for (size_t i = 0; input[i] != '\0'; i++) {
        const char* translated = translate_char(input[i]);
        strcat(output, translated); // Append the translated chunk
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_INPUT_LENGTH * 4]; // Increased size to accommodate translations

    printf("Welcome to the Cat Language Translator!\n");
    printf("Enter text to translate (max %d characters):\n", MAX_INPUT_LENGTH - 1);
    
    // Get the input from the user
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    // Remove trailing newline, if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Translate the input string
    translate_string(input, output);

    // Output the translated string
    printf("Cat Language Translation:\n%s\n", output);

    return EXIT_SUCCESS;
}