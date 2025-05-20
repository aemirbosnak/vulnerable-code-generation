//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to parse resume
int parseResume(char* filename) {
    // Open file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read each line
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // Check if line starts with "Experience:"
        if (strstr(line, "Experience:")!= NULL) {
            // Get experience details
            char experience[1000];
            fgets(experience, sizeof(experience), file);

            // Extract years and position
            char position[50];
            char years[10];
            char* pos_ptr = strtok(experience, ", ");
            strcpy(position, pos_ptr);
            pos_ptr = strtok(NULL, ", ");
            strcpy(years, pos_ptr);

            // Print experience details
            printf("%s: %s (%s)\n", position, years, experience);
        }
    }

    // Close file
    fclose(file);

    return 0;
}

int main() {
    char filename[100];
    printf("Enter resume filename: ");
    scanf("%s", filename);

    // Call parseResume function
    int result = parseResume(filename);
    if (result == 0) {
        printf("Resume parsed successfully!\n");
    } else {
        printf("Error parsing resume!\n");
    }

    return 0;
}