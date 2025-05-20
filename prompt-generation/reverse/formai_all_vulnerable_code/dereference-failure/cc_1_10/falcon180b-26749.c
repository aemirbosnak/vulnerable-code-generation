//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIGNATURE "I am a virus"
#define VIRUS_SIGNATURE_LENGTH 13

int is_infected(char* file_content, int file_size) {
    char* signature = (char*) malloc(VIRUS_SIGNATURE_LENGTH * sizeof(char));
    strncpy(signature, VIRUS_SIGNATURE, VIRUS_SIGNATURE_LENGTH);

    int i = 0;
    while (i < file_size - VIRUS_SIGNATURE_LENGTH) {
        if (strncmp(file_content + i, signature, VIRUS_SIGNATURE_LENGTH) == 0) {
            free(signature);
            return 1;
        }
        i++;
    }

    free(signature);
    return 0;
}

int main() {
    FILE* fp;
    char ch;
    int count = 0;

    fp = fopen("example.txt", "r");

    if (fp == NULL) {
        printf("Error in opening file\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        count++;
    }

    char* file_content = (char*) malloc(count * sizeof(char));

    rewind(fp);

    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        file_content[i] = ch;
        i++;
    }

    fclose(fp);

    if (is_infected(file_content, count)) {
        printf("Virus found in the file\n");
    } else {
        printf("File is clean\n");
    }

    free(file_content);
    return 0;
}