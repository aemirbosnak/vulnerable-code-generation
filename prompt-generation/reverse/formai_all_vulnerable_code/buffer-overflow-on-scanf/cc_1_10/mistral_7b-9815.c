//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SurpriseFile {
    char filename[100];
    FILE *file;
} SurpriseFile;

void openSurpriseFile(SurpriseFile *surpriseFile, char *message) {
    surpriseFile->file = fopen(surpriseFile->filename, "r");
    if (surpriseFile->file == NULL) {
        fprintf(stderr, "%s: Error opening file.\n", message);
        surpriseFile->filename[0] = '\0';
        return;
    }
    fprintf(stderr, "%s: File opened successfully!\n", message);
}

void closeSurpriseFile(SurpriseFile *surpriseFile) {
    if (surpriseFile->file != NULL) {
        fclose(surpriseFile->file);
        surpriseFile->filename[0] = '\0';
        fprintf(stderr, "File closed with a surprise!\n");
    }
}

void surpriseReadLine(SurpriseFile *surpriseFile) {
    char line[100];
    size_t len = 0;
    int ch;

    while ((ch = fgetc(surpriseFile->file)) != EOF && len < sizeof(line) - 1) {
        line[len++] = (char)ch;
        line[len] = '\0';

        if (ch == '\n') {
            printf("%s\n", line);
            memset(line, 0, sizeof(line));
            len = 0;
        }
    }

    if (ch == EOF) {
        fprintf(stderr, "End of file reached!\n");
        memset(line, 0, sizeof(line));
    }
}

int main() {
    SurpriseFile surpriseFile;
    char filename[100];

    printf("Enter a filename to surprise you: ");
    scanf("%s", filename);

    strcpy(surpriseFile.filename, filename);
    openSurpriseFile(&surpriseFile, "Opening file...");

    printf("Surprise! Let's read the file line by line:\n");
    while (fgetc(surpriseFile.file) != EOF) {}
    printf("End of the surprise!\n");

    surpriseReadLine(&surpriseFile);
    surpriseReadLine(&surpriseFile);

    closeSurpriseFile(&surpriseFile);

    return 0;
}