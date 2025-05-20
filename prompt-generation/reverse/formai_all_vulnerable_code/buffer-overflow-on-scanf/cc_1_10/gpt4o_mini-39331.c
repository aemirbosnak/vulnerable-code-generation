//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 100
#define MAX_FILES 10
#define VIRUS_SIGNATURE "VIRUS123"
#define BUFFER_SIZE 1024

void greet() {
    printf("🌟 Welcome to the Cheerful C Antivirus Scanner! 🌟\n");
    printf("Let's keep your files safe and sound! 😄\n\n");
}

void check_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("😢 Oh dear! I couldn't open the file: %s\n", filename);
        return;
    }

    char buffer[BUFFER_SIZE];
    int virus_found = 0;

    // Scan the file for the virus signature
    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (strstr(buffer, VIRUS_SIGNATURE)) {
            virus_found = 1;
            break;
        }
    }

    fclose(file);

    if (virus_found) {
        printf("🚨 Warning! A virus was found in: %s 😱\n", filename);
    } else {
        printf("🎉 Hooray! No viruses detected in: %s 😊\n", filename);
    }
}

void scan_files(const char *filenames[], int count) {
    for (int i = 0; i < count; i++) {
        check_file(filenames[i]);
    }
}

int main() {
    greet();

    char *filenames[MAX_FILES];
    int count = 0;

    printf("Please enter the names of the files you want to scan (max %d files):\n", MAX_FILES);
    while (count < MAX_FILES) {
        filenames[count] = (char *)malloc(MAX_FILENAME * sizeof(char));
        printf("Enter filename %d (or type 'done' to finish): ", count + 1);
        scanf("%s", filenames[count]);
        
        if (strcmp(filenames[count], "done") == 0) {
            free(filenames[count]);
            break;
        }
        
        count++;
    }

    printf("\n🌈 Scanning your files ... 🌈\n\n");
    scan_files(filenames, count);

    // Clean up allocated memory
    for (int i = 0; i < count; i++) {
        free(filenames[i]);
    }

    printf("\n🎊 Thank you for using the Cheerful C Antivirus Scanner! 🎊\n");
    printf("Keep smiling and coding! 😃\n");

    return 0;
}