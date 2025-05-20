//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10)
#define VIRUS_SIGNATURE "I am a virus!"

int main(int argc, char *argv[]) {
    FILE *fp;
    char *buffer;
    int size, i;

    printf("Welcome to the Happy Antivirus Scanner!\n");
    printf("We're going to scan your files for viruses and make sure your computer stays healthy!\n");

    if (argc < 2) {
        printf("Please specify a file to scan.\n");
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    if (size > MAX_FILE_SIZE) {
        printf("File is too large to scan.\n");
        fclose(fp);
        return 1;
    }

    rewind(fp);
    buffer = malloc(size + 1);
    if (buffer == NULL) {
        printf("Out of memory.\n");
        fclose(fp);
        return 1;
    }

    size = fread(buffer, 1, size, fp);
    if (size!= size) {
        printf("Error reading file.\n");
        free(buffer);
        fclose(fp);
        return 1;
    }

    buffer[size] = '\0';
    for (i = 0; i < size - strlen(VIRUS_SIGNATURE); i++) {
        if (memcmp(buffer + i, VIRUS_SIGNATURE, strlen(VIRUS_SIGNATURE)) == 0) {
            printf("Virus found in file %s!\n", argv[1]);
            free(buffer);
            fclose(fp);
            return 1;
        }
    }

    printf("File is clean and healthy!\n");
    free(buffer);
    fclose(fp);
    return 0;
}