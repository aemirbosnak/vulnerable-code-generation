//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//--------------------------------------------------------------------------------------------------
// Thou art in the presence of 'Sire Parsing Engine', a noble and valiant system,
// designed to decipher the arcane knowledge hidden within the scrolls of C resumes.
//--------------------------------------------------------------------------------------------------

typedef struct {
    char name[100];
    char title[100];
    char location[100];
    char contact[100];
} Knight_Info;

void parse_resume(FILE *file) {
    char line[256];
    Knight_Info knight;

    // Receiving the initial salutation
    fgets(line, sizeof(line), file);

    // Parsing the knight's name and title
    sscanf(line, "%[^:]: %s", knight.title, knight.name);

    // Continuously parsing the remaining lines
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Location:") != NULL) {
            sscanf(line, "Location: %s", knight.location);
        }
        if (strstr(line, "Contact:") != NULL) {
            sscanf(line, "Contact: %s", knight.contact);
        }
    }

    // Displaying the deciphered knowledge of the noble knight
    printf("Name: %s\nTitle: %s\nLocation: %s\nContact: %s\n", knight.name, knight.title, knight.location, knight.contact);
}

int main(int argc, char *argv[]) {
    // Validating the input and preparing the scroll for deciphering
    if (argc != 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open the resume file.\n");
        return 1;
    }

    parse_resume(file);
    fclose(file);
    return 0;
}