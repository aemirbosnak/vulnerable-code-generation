//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// ASCII art for each character
char* ascii_art[] = {
    "  __  __ _       _            _    \n |  \\/  (_)     (_)          | |   \n | \\  / |_ _ __  _ _ __   ___| |_  \n | |\\/| | | '_ \\| | '_ \\ / _ \\ __| \n | |  | | | | | | | | | |  __/ |_  \n |_|  |_|_|_| |_|_|_| |_|\\___|\\__| \n",
    "     _  \n    | | \n ___| |__  _ __   __ _ _ __ ___   ___ \n/ __| '_ \\| '_ \\ / _` | '_ ` _ \\ / _ \\\n\\__ \\ | | | | | | (_| | | | | | |  __/\n|___/_| |_|_| |_|\\__,_|_| |_| |_|\\___|\n",
    "  ____  _            _    _                 \n / __ \\| |          | |  (_)                \n| |  | | | __ _  ___| | ___ _ __ ___   ___ \n| |  | | |/ _` |/ __| |/ / | '_ ` _ \\ / _ \\\n| |__| | | (_| | (__|   <| | | | | | |  __/\n \\____/|_|\\__,_|\\___|_|\\_\\_|_| |_| |_|\\___|\n",
    " _____ _     _ \n/  ___(_)   | |\n\\ `--. _ ___| |_ ___ _ __\n `--. \\ / __| __/ _ \\ '__|\n/\\__/ /\\__ \\ ||  __/ |\n\\____/ |___/\\__\\___|_|\n",
    " _____          _ _ \n/  __ \\        (_) |\n| /  \\/ ___ __ _| |_ ___  _ __\n| |    / __/ _` | __/ _ \\| '__|\n| \\__/\\ (_| (_| | || (_) | |\n \\____/\\___\\__,_|\\__\\___/|_|\n",
    " _____       _                    _   _ \n/  __ \\     | |                  | | (_)\n| /  \\/ ___ | |_ _ __ ___ _ __   | |_ _  ___  ___\n| |    / _ \\| __| '__/ _ \\ '_ \\  | __| |/ _ \\/ __|\n| \\__/\\ (_) | |_| | |  __/ | | | | |_| |  __/\\__ \\\n \\____/\\___/ \\__|_|  \\___|_| |_|  \\__|_|\\___||___/\n",
    " _   _            _    \n| | | |          | |   \n| |_| |_ ___  ___| |_  \n|  _  | / __|/ _ \\ __| \n| | | | \\__ \\  __/ |_  \n\\_| |_/ |___/\\___|\\__| \n",
    " _______ _______ _     _\n|__   __|__   __| |   | |\n   | |     | |  | |___| |\n   | |     | |  | / __| |\n   | |     | |  | \\__ \\_|\n   |_|     |_|  |_|___(_)\n",
    "  ____         __ _ _\n / __ \\       / _(_) |\n| |  | |_ __ | |_ _| | ___\n| |  | | '_ \\|  _| | |/ _ \\\n| |__| | | | | | | | | |  __/\n \\____/|_| |_|_| |_|_|\\___|\n",
    " __  __                   _       _      \n|  \\/  |                 | |     | |     \n| \\  / | __ _ _ __   __ _| |_ ___| |__   \n| |\\/| |/ _` | '_ \\ / _` | __/ __| '_ \\  \n| |  | | (_| | | | | (_| | || (__| | | | \n|_|  |_|\\__,_|_| |_|\\__,_|\\__\\___|_| |_|\n"
};

// Function to convert character to index of ASCII art array
int char_to_ascii_index(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a';
    } else if (c >= '0' && c <= '9') {
        return c - '0' + 26;
    } else if (c == ' ') {
        return 36;
    } else if (c == '.') {
        return 37;
    } else if (c == ',') {
        return 38;
    } else if (c == ':') {
        return 39;
    } else if (c == ';') {
        return 40;
    } else if (c == '-') {
        return 41;
    } else if (c == '!') {
        return 42;
    } else if (c == '?') {
        return 43;
    } else {
        return -1; // Character not supported
    }
}

int main() {
    char line[MAX_LINE_LENGTH]; // Input line from user
    int ascii_index; // Index of ASCII art array for each character

    printf("Enter a sentence: ");
    fgets(line, MAX_LINE_LENGTH, stdin); // Get user input

    // Convert each character to ASCII art and print to console
    for (int i = 0; i < strlen(line); i++) {
        ascii_index = char_to_ascii_index(line[i]);
        if (ascii_index == -1) { // Character not supported
            printf("\n\nError: Character '%c' not supported\n", line[i]);
            return 0;
        } else {
            printf("%s", ascii_art[ascii_index]);
        }
    }
    printf("\n");

    return 0;
}