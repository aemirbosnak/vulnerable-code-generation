//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define MAX_FILES 1000
#define MAX_FILENAME_LENGTH 256
#define MAX_VIRUS_SIGNATURES 100
#define MAX_SIGNATURE_LENGTH 32

char virusSignatures[MAX_VIRUS_SIGNATURES][MAX_SIGNATURE_LENGTH];
int virusCount = 0;

void readSignaturesFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        char signature[MAX_SIGNATURE_LENGTH];
        while (fscanf(file, "%s", signature) == 1 && virusCount < MAX_VIRUS_SIGNATURES) {
            strcpy(virusSignatures[virusCount++], signature);
        }
        fclose(file);
    }
}

int fileContainsSignature(const char* filename, const char* signature) {
    FILE* file = fopen(filename, "rb");
    if (file != NULL) {
        char buffer[MAX_SIGNATURE_LENGTH];
        int bytesRead;
        while ((bytesRead = fread(buffer, 1, MAX_SIGNATURE_LENGTH, file)) > 0) {
            if (strstr(buffer, signature) != NULL) {
                fclose(file);
                return 1;
            }
        }
        fclose(file);
    }
    return 0;
}

int isFileInfected(const char* filename) {
    int i;
    for (i = 0; i < virusCount; i++) {
        if (fileContainsSignature(filename, virusSignatures[i])) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s [signature file] [file 1] [file 2] ... [file n]\n", argv[0]);
        return 1;
    }
    readSignaturesFromFile(argv[1]);
    int i;
    for (i = 2; i < argc; i++) {
        if (isFileInfected(argv[i])) {
            printf("%s is infected with a virus.\n", argv[i]);
        } else {
            printf("%s is clean.\n", argv[i]);
        }
    }
    return 0;
}