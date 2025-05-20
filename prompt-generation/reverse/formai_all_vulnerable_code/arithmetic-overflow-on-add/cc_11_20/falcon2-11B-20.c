//Falcon2-11B DATASET v1.0 Category: Text processing ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char filename[100];
    FILE *inFile, *outFile;
    int wordCount[256];
    int i, j, maxWordCount = 0;

    // Prompt user for input file name
    printf("Enter input file name: ");
    fgets(filename, sizeof(filename), stdin);

    // Open input file for reading
    inFile = fopen(filename, "r");
    if (inFile == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    // Open output file for writing
    sprintf(filename, "%s.txt", filename);
    outFile = fopen(filename, "w");
    if (outFile == NULL) {
        printf("Error: Unable to open output file.\n");
        fclose(inFile);
        return 1;
    }

    // Read input file and count word frequency
    while (!feof(inFile)) {
        fgets(filename, sizeof(filename), inFile);
        for (i = 0; i < sizeof(filename); i++) {
            if (filename[i] == '\n') {
                filename[i] = '\0';
                break;
            }
        }
        strcpy(filename, " ");
        i = 0;
        while (filename[i]!= '\0') {
            wordCount[filename[i]]++;
            i++;
        }
    }

    // Close input file
    fclose(inFile);

    // Sort word frequency array and write to output file
    for (i = 0; i < sizeof(wordCount); i++) {
        if (wordCount[i] > maxWordCount) {
            maxWordCount = wordCount[i];
        }
    }
    for (i = 0; i < sizeof(wordCount); i++) {
        if (wordCount[i] == maxWordCount) {
            for (j = 0; j < sizeof(wordCount); j++) {
                if (wordCount[j] == wordCount[i]) {
                    printf("%s: %d\n", filename, wordCount[i]);
                    fprintf(outFile, "%s: %d\n", filename, wordCount[i]);
                }
            }
        }
    }

    // Close output file
    fclose(outFile);

    // Done!
    printf("Done!\n");
    return 0;
}