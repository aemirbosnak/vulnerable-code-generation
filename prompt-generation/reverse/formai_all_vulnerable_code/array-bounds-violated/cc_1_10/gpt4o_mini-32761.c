//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 256
#define MAX_OUTPUT 1024
#define ASCII_WIDTH 64
#define ASCII_HEIGHT 6

const char* ascii_pixels[ASCII_HEIGHT] = {
    "        .--.       .--.     .-._.-.  .--.       .--.    .-..-.      ",
    "      .'    '.   .'    '.  |   |   ||    '.   .'    '.  | || |  _.-.|",
    "     /   _  _ \\ /   _  _ \\ |   |   ||  _  _ \\ /   _  _ \\ | || | (   ||",
    "    |   (o)(o) |   (o)(o) ||   |   || (o)(o) |   (o)(o) ||_||_| .-. ||",
    "    |  .-._.-.  |  .-._.-. ||   |   ||  .-._.-.  |  .-._.-.   |   | | ||",
    "     \\ '.___.' / \\ '.___.' / |   |   || '.___.' / \\ '.___.' /   |   |_|/",
    "      '._     _.'   '._     _.'|   |   '._     _.'   '._     _.'        ",
    "         |   |        |   |    |   |        |   |        |   |         ",
    "         |___|        |___|    '._.'        |___|        |___|         "
};

void display_intro() {
    printf("\033[1;36m");
    printf("   ┌─────────────────────────────────────────┐\n");
    printf("   │            CYBERPUNK ASCII            │\n");
    printf("   │         TEXT TO ASCII ART TOOL        │\n");
    printf("   │                                         │\n");
    printf("   └─────────────────────────────────────────┘\n");
    printf("\033[0m");
    printf("\033[1;35m");
    printf("   [Input some text to see it converted to ASCII art!]\n");
    printf("\033[0m");
}

void convert_to_ascii_art(const char* input, char* output) {
    char temp[MAX_OUTPUT];
    memset(temp, ' ', sizeof(temp));
    
    for (int i = 0; i < strlen(input); i++) {
        if (isprint(input[i])) {
            int ascii_value = input[i] - 32; // Convert printable ASCII to index
            for (int j = 0; j < ASCII_HEIGHT; j++) {
                if (ascii_value < ASCII_WIDTH) {
                    int start_pos = (i * ASCII_WIDTH) + (ascii_value * (ASCII_WIDTH / 2));
                    temp[start_pos + j] = ascii_pixels[j][ascii_value];
                }
            }
        }
    }
    // Copy temp to output with trimming
    strcpy(output, temp);
}

void print_ascii_art(const char* ascii_art) {
    printf("\n\033[1;32m");
    printf("   ┌────────────────────────────┐\n");
    for (int j = 0; j < ASCII_HEIGHT; j++) {
        printf("   │ %s │\n", ascii_art + (j * (MAX_OUTPUT + 1)));
    }
    printf("   └────────────────────────────┘\n");
    printf("\033[0m");
}

int main() {
    display_intro();

    char input[MAX_INPUT];
    char ascii_art[MAX_OUTPUT];

    while (1) {
        printf("\n   Enter your text (or 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);
        
        // Remove trailing newline
        input[strcspn(input, "\n")] = 0;

        if (strcasecmp(input, "exit") == 0) {
            break;
        }

        convert_to_ascii_art(input, ascii_art);
        print_ascii_art(ascii_art);
    }

    printf("\n\033[1;31m   Thanks for using the CYBERPUNK ASCII ART tool! Goodbye!\n\033[0m");
    return 0;
}