//Gemma-7B DATASET v1.0 Category: Antivirus scanner ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1024

typedef struct Virus {
    char name[20];
    char description[200];
    int severity;
} Virus;

Virus viruses[] = {
    {"Malaria", "Causes fever and chills.", 3},
    {"Rona", "Causes sore throat and cough.", 2},
    {"Cholera", "Causes diarrhea and vomiting.", 4},
    {"Smallpox", "Causes rash and fever.", 5}
};

int main() {
    char filename[20];
    char file_contents[MAX_FILE_SIZE];
    int file_size;
    int i;

    // Get the filename from the user
    printf("Enter the name of the file to scan: ");
    scanf("%s", filename);

    // Open the file
    FILE *file = fopen(filename, "r");

    // Read the file contents
    if (file) {
        file_size = fread(file_contents, MAX_FILE_SIZE, 1, file);
        fclose(file);
    } else {
        printf("Error opening file.\n");
        return 1;
    }

    // Scan for viruses
    for (i = 0; i < sizeof(viruses) / sizeof(Virus); i++) {
        if (strstr(file_contents, viruses[i].name) != NULL) {
            printf("Virus detected: %s\n", viruses[i].name);
            printf("Description: %s\n", viruses[i].description);
            printf("Severity: %d\n", viruses[i].severity);
            printf("-----------------------------------\n");
        }
    }

    return 0;
}