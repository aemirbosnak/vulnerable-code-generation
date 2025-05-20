//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Virus Signature Database
#define VIRUS_SIGNATURE_COUNT 10
char virusSignatures[VIRUS_SIGNATURE_COUNT][100] = {
    "This program will",
    "delete all your",
    "files and your",
    "computer will",
    "explode. Sorry",
    "about that.",
    "I'm just",
    "following orders.",
    "Have a nice day!",
    "Regards, your",
    "favorite virus."
};

int main(int argc, char *argv[]) {
    char fileName[100];
    FILE *file;

    // Get file name from user
    printf("Enter file name to scan: ");
    scanf("%s", fileName);

    // Open file for reading
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file '%s'!\n", fileName);
        return 1;
    }

    // Scan file for viruses
    char line[1000];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *virusSignature;
        for (int i = 0; i < VIRUS_SIGNATURE_COUNT; i++) {
            virusSignature = virusSignatures[i];
            if (strstr(line, virusSignature)) {
                printf("Virus detected! '%s'\n", virusSignature);
                fclose(file);
                return 0;
            }
        }
    }

    // No viruses found
    fclose(file);
    printf("No viruses found!\n");

    return 0;
}