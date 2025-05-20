//MISTRAL-7B DATASET v1.0 Category: Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define HIDDEN_MESSAGE_LENGTH 50

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int i, j, k;
    int message_found = 0;
    char hidden_message[HIDDEN_MESSAGE_LENGTH];

    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file.");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        for (i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
            if (isalpha(line[i])) {
                for (j = i, k = HIDDEN_MESSAGE_LENGTH - 1; j < strlen(line) && k >= 0; j--, k--) {
                    if (!isalpha(line[j])) {
                        break;
                    }
                    hidden_message[k] = tolower(line[j]);
                }
                if (k < 0) {
                    continue;
                }

                if (strlen(hidden_message) == HIDDEN_MESSAGE_LENGTH) {
                    printf("Hidden message found: %s\n", hidden_message);
                    message_found = 1;
                    break;
                }
            }
        }
        if (message_found) {
            break;
        }
    }

    fclose(file);

    return 0;
}