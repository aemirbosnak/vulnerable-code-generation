//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: artistic
#include <stdio.h>
#include <string.h>

void printAsciiArt(char* text) {
    int len = strlen(text);
    int i, j, k;

    for (i = 0; i < len; i++) {
        for (j = 0; j < 8; j++) {
            for (k = 0; k < len; k++) {
                switch (text[k]) {
                    case 'a':
                        switch (j) {
                            case 0:
                                printf("   ____   \n");
                                break;
                            case 1:
                                printf("  /    \\  \n");
                                break;
                            case 2:
                                printf(" /  __  \\ \n");
                                break;
                            case 3:
                                printf("/__/  \\__\\\n");
                                break;
                            case 4:
                                printf("|  |--|  |\n");
                                break;
                            case 5:
                                printf("|__|  |__|\n");
                                break;
                            case 6:
                                printf("         \n");
                                break;
                            case 7:
                                printf("         \n");
                                break;
                        }
                        break;
                    case 'b':
                        switch (j) {
                            case 0:
                                printf(" ____  \n");
                                break;
                            case 1:
                                printf("|    \\ \n");
                                break;
                            case 2:
                                printf("| {}  )\n");
                                break;
                            case 3:
                                printf("| {}  )\n");
                                break;
                            case 4:
                                printf("|____/ \n");
                                break;
                            case 5:
                                printf("| \\ \\  \n");
                                break;
                            case 6:
                                printf("|  \\ \\ \n");
                                break;
                            case 7:
                                printf("|__/__/ \n");
                                break;
                        }
                        break;
                    case 'c':
                        switch (j) {
                            case 0:
                                printf("  _____ \n");
                                break;
                            case 1:
                                printf(" / ____\\\n");
                                break;
                            case 2:
                                printf("/ /     \n");
                                break;
                            case 3:
                                printf("\\ \\_____\n");
                                break;
                            case 4:
                                printf(" \\_____\\\n");
                                break;
                            case 5:
                                printf("        \n");
                                break;
                            case 6:
                                printf("        \n");
                                break;
                            case 7:
                                printf("        \n");
                                break;
                        }
                        break;
                    // Add more letters here...
                    default:
                        printf("\n");
                        break;
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char* text = argv[1];
    printAsciiArt(text);

    return 0;
}