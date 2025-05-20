//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: post-apocalyptic
// **Wasteland File Backup System**

// **Preamble:**
// In the desolate annals of the post-apocalyptic wasteland, where data preservation is a perilous endeavor, a hardened code has emerged - the Wasteland File Backup System. Through this gnarled and rusty interface, the remnants of humanity can safeguard their digital treasures against the ravages of time and inevitable oblivion.

// **Header Incantations:**
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// **Constants:**
#define MAX_FILES 10
#define MAX_FILENAME_LEN 30
#define MAX_DATA_SIZE 1024

// **Structs:**
typedef struct {
    char filename[MAX_FILENAME_LEN];
    char data[MAX_DATA_SIZE];
    int size;
} File;

// **Global Variables:**
static File files[MAX_FILES];
static int numFiles = 0;

// **Functions:**
// **Acquire Dusty Tome:** Reads a file from the wasteland into memory.
File* acquireDustyTome(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("Failed to acquire dusty tome");
        return NULL;
    }

    File* file = &files[numFiles++];
    strcpy(file->filename, filename);
    file->size = fread(file->data, 1, MAX_DATA_SIZE, fp);
    fclose(fp);

    return file;
}

// **Preserve Ancient Wisdom:** Writes a file to a bunker for future generations.
void preserveAncientWisdom(File* file) {
    FILE* fp = fopen(file->filename, "w");
    if (!fp) {
        perror("Failed to preserve ancient wisdom");
        return;
    }

    fwrite(file->data, 1, file->size, fp);
    fclose(fp);
}

// **Search for Lost Scrolls:** Finds a file in the wasteland based on its name.
File* searchForLostScrolls(char* filename) {
    for (int i = 0; i < numFiles; i++) {
        if (!strcmp(files[i].filename, filename)) {
            return &files[i];
        }
    }

    return NULL;
}

// **Main:**
int main(int argc, char** argv) {
    // **Intro:**
    printf("Welcome to the Wasteland File Backup System, traveler.\n");

    // **Command Loop:**
    while (1) {
        // **Receive Command:**
        char command[30];
        printf("\nEnter command (acquire, preserve, search, list, exit): ");
        scanf("%s", command);

        // **Process Command:**
        if (!strcmp(command, "acquire")) {
            // **Acquire Dusty Tome:**
            char filename[MAX_FILENAME_LEN];
            printf("Enter filename to acquire: ");
            scanf("%s", filename);
            File* file = acquireDustyTome(filename);
            if (file) {
                printf("Acquired dusty tome: %s\n", file->filename);
            }
        }
        else if (!strcmp(command, "preserve")) {
            // **Preserve Ancient Wisdom:**
            char filename[MAX_FILENAME_LEN];
            printf("Enter filename to preserve: ");
            scanf("%s", filename);
            File* file = searchForLostScrolls(filename);
            if (file) {
                preserveAncientWisdom(file);
                printf("Preserved ancient wisdom: %s\n", file->filename);
            }
        }
        else if (!strcmp(command, "search")) {
            // **Search for Lost Scrolls:**
            char filename[MAX_FILENAME_LEN];
            printf("Enter filename to search for: ");
            scanf("%s", filename);
            File* file = searchForLostScrolls(filename);
            if (file) {
                printf("Found lost scroll: %s\n", file->filename);
            } else {
                printf("Lost scroll not found: %s\n", filename);
            }
        }
        else if (!strcmp(command, "list")) {
            // **List Ancient Wisdom:**
            if (numFiles == 0) {
                printf("No ancient wisdom found.\n");
            } else {
                printf("Ancient wisdom in possession:\n");
                for (int i = 0; i < numFiles; i++) {
                    printf("%s\n", files[i].filename);
                }
            }
        }
        else if (!strcmp(command, "exit")) {
            // **Bid Farewell:**
            printf("May the winds of the wasteland guide you, traveler.\n");
            break;
        }
        else {
            // **Unknown Command:**
            printf("Unrecognized command.\n");
        }
    }

    return 0;
}