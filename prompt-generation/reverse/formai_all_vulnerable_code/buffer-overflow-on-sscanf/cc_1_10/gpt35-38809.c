//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_PATH 512

typedef struct {
    char artist[100];
    char title[100];
    char album[100];
    char year[5];
} SongMetadata;

SongMetadata extractMetadata(const char* filePath) {
    FILE *file;
    SongMetadata metadata = {"", "", "", ""};
    char line[256];
    char metadataKey[256];
    char metadataValue[256];
    
    file = fopen(filePath, "r");
    if (file) {
        while (fgets(line, sizeof(line), file)) {
            int length = strlen(line);
            if (line[length - 1] == '\n') {
                line[length - 1] = '\0';
            }
            
            int numFields = sscanf(line, " %[^:]: %[^\r\n]", metadataKey, metadataValue);
            if (numFields == 2) {
                if (strcmp(metadataKey, "ARTIST") == 0) {
                    strncpy(metadata.artist, metadataValue, sizeof(metadata.artist));
                } else if (strcmp(metadataKey, "TITLE") == 0) {
                    strncpy(metadata.title, metadataValue, sizeof(metadata.title));
                } else if (strcmp(metadataKey, "ALBUM") == 0) {
                    strncpy(metadata.album, metadataValue, sizeof(metadata.album));
                } else if (strcmp(metadataKey, "YEAR") == 0) {
                    strncpy(metadata.year, metadataValue, sizeof(metadata.year));
                }
            }
        }
        
        fclose(file);
    }
    
    return metadata;
}

int main(int argc, const char **argv) {
    if (argc != 2) {
        printf("Usage: metadata_extractor <file_path>");
        return 1;
    }
    
    const char *filePath = argv[1];
    SongMetadata metadata = extractMetadata(filePath);
    
    printf("Artist: %s\n", metadata.artist);
    printf("Title: %s\n", metadata.title);
    printf("Album: %s\n", metadata.album);
    printf("Year: %s\n", metadata.year);
    
    return 0;
}