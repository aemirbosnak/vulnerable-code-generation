//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VIRUS_LENGTH 1024

// Function to check if a file contains a virus
int check_file(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    char buffer[MAX_VIRUS_LENGTH];
    char virus[] = "VIRUS";
    int virus_length = strlen(virus);
    int file_size = 0;

    while (fread(buffer, 1, MAX_VIRUS_LENGTH, file) > 0) {
        file_size += MAX_VIRUS_LENGTH;

        char* buffer_lower = malloc(MAX_VIRUS_LENGTH * sizeof(char));
        strcpy(buffer_lower, buffer);
        for (int i = 0; i < MAX_VIRUS_LENGTH; i++) {
            buffer_lower[i] = tolower(buffer_lower[i]);
        }

        int index = 0;
        while ((index < virus_length) && (index < MAX_VIRUS_LENGTH)) {
            if (buffer_lower[index]!= virus[index]) {
                break;
            }
            index++;
        }

        if (index == virus_length) {
            printf("Virus found in file %s\n", filename);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

int main() {
    char filename[256];
    printf("Enter filename to scan: ");
    scanf("%s", filename);

    int result = check_file(filename);

    if (result == 0) {
        printf("No virus found in file %s\n", filename);
    }

    return 0;
}