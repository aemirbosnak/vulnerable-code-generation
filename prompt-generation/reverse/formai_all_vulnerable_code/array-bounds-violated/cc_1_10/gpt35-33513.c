//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_ROWS 8

void printArt(char** rows, int len) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < len; j++) {
            printf("%s", rows[i] + (j * MAX_ROWS));
        }
        printf("\n");
    }
}

int main() {
    char input[MAX_LENGTH];
    char* art[] = {
        "  _____ _   _ ______ _      _____          _______ ____  ",
        " / ____| \\ | |  ____| |    / ____|   /\\   |__   __/ __ \\ ",
        "| |  __|  \\| | |__  | |___| |  __   /  \\     | | | |  | |",
        "| | |_ | . ` |  __| | / __| | |_ | / /\\ \\    | | | |  | |",
        "| |__| | |\\  | |____| \\__ \\ |__| |/ ____ \\   | | | |__| |",
        " \\_____|_| \\_|______|_|___/\\_____/_/    \\_\\  |_|  \\____/",
        "\n",
    };

    printf("Enter some text to convert to ASCII Art:\n");
    fgets(input, MAX_LENGTH, stdin);
    input[strlen(input) - 1] = '\0';

    printf("\n");

    for (int i = 0; i < sizeof(art)/sizeof(char*); i++) {
        printf("%s", art[i]);
    }

    char* rows[MAX_ROWS];
    for (int i = 0; i < MAX_ROWS; i++) {
        rows[i] = (char*) malloc(sizeof(char) * (strlen(input) + 1));
        memset(rows[i], ' ', sizeof(char) * (strlen(input) + 1));
    }

    for (int i = 0; i < strlen(input); i++) {
        int ch = (int) input[i];
        for (int j = 0; j < MAX_ROWS; j++) {
            rows[j][i * MAX_ROWS + (j/2)] = (int) ch > 32 && (int) ch < 127 ? ch : ' ';
        }
    }

    printArt(rows, strlen(input));

    for (int i = 0; i < MAX_ROWS; i++) {
        free(rows[i]);
    }

    return 0;
}