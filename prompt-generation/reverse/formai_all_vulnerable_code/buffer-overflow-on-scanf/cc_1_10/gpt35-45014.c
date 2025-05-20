//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shape shifting
#include <stdio.h>
#include <string.h>

int main() {
    // user input for text
    char text[100];
    printf("Enter your text to be transformed into ASCII art:\n");
    scanf("%s", text);

    // extracting length of text
    int length = strlen(text);

    // switching between different ASCII art shapes
    for(int i = 0; i < length; i++) {
        switch(i%4) {
            case 0:
                printf("         _______\n");
                printf("        |%c      |\n", text[i]);
                printf("        |       |\n");
                printf("        |       |\n");
                printf("        |_______|\n");
                break;
            case 1:
                printf("         _,-----.\n");
                printf("        (' -   - ')\n");
                printf("        /  a _    \\\n");
                printf("       |   / \\ |  |\n");
                printf("       |  (_ \\|  |\n");
                printf("       `-\'.__`-'_,'\n");
                printf("          \\\\\\|||\n");
                printf("           `~\'~\'\n");
                break;
            case 2:
                printf("         ____________\n");
                printf("         |   _____  |\n");
                printf("        / \\_/     \\_/ \\\n");
                printf("       |   |       |   |\n");
                printf("       |___|       |___|\n");
                printf("      ( o            o )\n");
                printf("       `\\_\\        /_/\n");
                printf("          \\`\\    /`/\n");
                break;
            case 3:
                printf("          _______\n");
                printf("        /        \\\n");
                printf("       /_/|__|\\_\\\n");
                printf("      / / / | \\ \\ \\\n");
                printf("     /_/ /\\_|_/\\ \\_\\\n");
                printf("     |_|/_/_|_\\_\\_|\n");
                printf("     |/_/|/'|`\\|\\_\\|\n");
                printf("      \\_\\|__/\\__|_/\n");
                break;
        }
    }

    return 0;
}