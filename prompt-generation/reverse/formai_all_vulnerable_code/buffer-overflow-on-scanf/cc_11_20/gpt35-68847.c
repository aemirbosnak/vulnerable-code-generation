//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char filename[100];
    char medieval_title[100];
    char medieval_author[100];
    char medieval_date[100];
    char medieval_desc[200];
    
    printf("Greetings traveler! What file would you like me to extract metadata from?\n");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Hark! I cannot find that file. Please verify the name and try again.\n");
        exit(1);
    }
    
    printf("Ah yes, the file '%s'. Let me see what I can find in its metadata...\n\n", filename);
    // Extracting the metadata from file
    char line[200];
    while (fgets(line, 200, file)) {
        if (strstr(line, "Title: ")) {
            strcpy(medieval_title, &line[7]);
            medieval_title[strlen(medieval_title) - 1] = '\0'; // remove newline character
        }
        else if (strstr(line, "Author: ")) {
            strcpy(medieval_author, &line[8]);
            medieval_author[strlen(medieval_author) - 1] = '\0'; // remove newline character
        }
        else if (strstr(line, "Date: ")) {
            strcpy(medieval_date, &line[6]);
            medieval_date[strlen(medieval_date) - 1] = '\0'; // remove newline character
        }
        else if (strstr(line, "Description: ")) {
            strcpy(medieval_desc, &line[13]);
            medieval_desc[strlen(medieval_desc) - 1] = '\0'; // remove newline character
        }
    }
    
    if (medieval_title[0] == '\0' && medieval_author[0] == '\0' && medieval_date[0] == '\0' && medieval_desc[0] == '\0') {
        printf("Alas, no metadata was found in this file!\n");
    }
    else {
        printf("Huzzah! We have uncovered the following metadata for this file:\n\n");
        if (medieval_title[0] != '\0') {
            printf("Title: %s\n", medieval_title);
        }
        if (medieval_author[0] != '\0') {
            printf("Author: %s\n", medieval_author);
        }
        if (medieval_date[0] != '\0') {
            printf("Date: %s\n", medieval_date);
        }
        if (medieval_desc[0] != '\0') {
            printf("Description: %s\n", medieval_desc);
        }
    }
    
    printf("\nFare thee well, traveler!\n");
    return 0;
}