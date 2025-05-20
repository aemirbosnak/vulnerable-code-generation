//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILENAME_LENGTH 100
#define MAX_KEY_LENGTH 100

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char key[MAX_KEY_LENGTH];
    char line[MAX_LINE_LENGTH];
    FILE *file;
    int key_length;

    // Get filename and key from user
    printf("Enter filename: ");
    scanf("%s", filename);
    printf("Enter key: ");
    scanf("%s", key);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Get key length
    key_length = strlen(key);

    // Read file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Encrypt line
        for (int i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                line[i] = tolower(line[i]);
                line[i] = line[i] + key_length;
                if (isalpha(line[i])) {
                    line[i] = tolower(line[i]);
                } else {
                    line[i] = tolower(line[i]) - 26;
                }
            }
        }

        // Write encrypted line to file
        fprintf(file, "%s", line);
    }

    // Close file
    fclose(file);

    printf("File encrypted successfully\n");
    return 0;
}