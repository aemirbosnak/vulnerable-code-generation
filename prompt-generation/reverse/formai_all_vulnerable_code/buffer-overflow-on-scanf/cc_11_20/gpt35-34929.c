//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_ascii(char c) {
    if (c == 'a') {
        return "    /\\   \n   /  \\  \n  / /\\ \\ \n / ____ \\\n/_/    \\_\\\n";
    } else if (c == 'b') {
        return " _____  \n/ ___ `\\\n\\_/\\___/\n   \\_\`\\ \n  /_/  \\\\_\\\n";
    } else if (c == 'c') {
        return "  _____ \n / ___ `\\\n/\\_/  > \\\n\\___,_/\\_\\\n        \\/\n";
    } else if (c == 'd') {
        return " _____  \n/\\___ `\\\n\\_/  > /\n  / /_/\n  \\____\\\n";
    } else if (c == 'e') {
        return " ______ \n/ ____ `\\\n'  \\_/\\_/\n   ___`-\n  /`___\\ \n /_/    \\\\_\\\n";
    } else if (c == 'f') {
        return " ______ \n/ ____ `\\\n'  \\_/\\_/\n'   /\\ \n/\\_/  \\\n\\ \\____/\n \\_____\\\n";
    } else if (c == 'g') {
        return "  _____ \n / ___ `\\\n|_/___) |\n,'____.'\n\\____|\\\\n";
    } else if (c == 'h') {
        return " __  __ \n/ / / `\\\n\\ \\/'/'/\n \\ , <  \n  \\_\\`\\_\\\n";
    } else if (c == 'i') {
        return " _____ \n/_   _\\\n  | |  \n  | |  \n _| |_ \n/_____\\\n";
    } else if (c == 'j') {
        return "     __ \n    /  |\n    `| |\n     | |\n _`\\__/ /\n/_____/\n";
    } else if (c == 'k') {
        return " __  __ \n/ / / `\\\n\\ \\/'/'/\n>  <   \n\\_`\\_\\/\n";
    } else if (c == 'l') {
        return " _____ \n/ ___ `\\\n\\_/\\__/ \n  /\\___\\\n  \\____/\n";
    } else if (c == 'm') {
        return "/\\      /\\\n\\ \\    / /\\\n \\ \\  / / /\n  \\ \\/ / / \n   \\  / /  \n    \\/_/   \n";
    } else if (c == 'n') {
        return " __   __\n/\\ \"-.\\ \\\n\\ \\ \\-'\\ \n \\ \\_\\ \\\\n  \\/_/_/\n";
    } else if (c == 'o') {
        return "  _____ \n / ___ `\\\n|_/___) |\n'___`-' \n(   \\ \n\\__/\\\\\\\n";
    } else if (c == 'p') {
        return " _____  \n/\\__/ `\\\n\\ \\__\\_/ \n \\/ __`\\\n  /\\ \\L\\\n  \\ \\____\\\n   \\/____/\n";
    } else if (c == 'q') {
        return "  _____ \n / ___ `\\\n|_/___) |\n'____.-`\n \\_\\    \n   \\\\__\\\n";
    } else if (c == 'r') {
        return " _____  \n/\\__/ `\\\n\\ \\__\\_/ \n \\/ __`\\\n /\\ \\_\\ \\\n \\ \\____/\n  \\/___/\n";
    } else if (c == 's') {
        return " ______ \n/\\____ `\\\n\\|___/  /\n   /  / \n _/  /__\n/\\______\\\n";
    } else if (c == 't') {
        return "_______ \n\\___   \\\n    \\ \\ \n     \\ \\\n     / / \n     \\/  \n";
    } else if (c == 'u') {
        return " __   __\n/\\\"-./  \\\n\\ \\ \\-./\\\n \\ \\_\\ \\_\\\n  \\/_/\\/_/\n";
    } else if (c == 'v') {
        return "__    __\n/\\ \\  / /\n\\ \\ \\/'/'\\\n \\ \\ , < \n  \\ \\_\\`\\_\\\n   \\/_/\\/_/\n";
    } else if (c == 'w') {
        return "__       __\n/\\ \\     / /\\\n\\ \\ \\___/ / / \n \\ \\  _ ___/ \n  \\ \\ \\__/\\\n   \\ \\_____\\ \n    \\/____/\n";
    } else if (c == 'x') {
        return "__  __\n\\ \\/ /\\\n \\  /'\\\n /  \\ \\\n/_/\\_\\ \\\n\\ \\/__/\n \\/__/ \n";
    } else if (c == 'y') {
        return "__   __\n/\\ \\ / /\n\\ \\ \\/'\\\n \\ \\ ,< \n  \\ \\_\\\\\n   \\/_/ \n";
    } else if (c == 'z') {
        return " ______\n/_  __/\n / /   \n/< <    \n\\/_/\\_\\\n  \\/_/\n";
    } else {
        return "";
    }
}

int main()
{
    char input[100];

    printf("Enter a word: ");
    scanf("%s", input);

    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        char* ascii = get_ascii(input[i]);

        if (strlen(ascii) > 0) {
            printf("%s", ascii);
        } else {
            printf(" ");
        }
    }

    return 0;
}