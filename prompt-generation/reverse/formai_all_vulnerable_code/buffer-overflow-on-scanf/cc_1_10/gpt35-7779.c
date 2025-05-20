//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// define struct to store metadata 
struct Metadata {
    char title[100];
    char artist[100];
    char album[100];
    int year;
};

int main() {
    char filename[100];
    printf("Enter filename of audio file: ");
    scanf("%s", filename);
    
    // open file in binary mode
    FILE* file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: Could not open file!\n");
        return 1;
    }

    // read file header to check if it's a valid audio file
    char header[4];
    fread(header, sizeof(char), 4, file);

    if (header[0] != 'I' || header[1] != 'D' || header[2] != '3') {
        printf("Error: File is not a valid MP3 file!\n");
        return 1;
    }

    // skip header size field
    fseek(file, 3, SEEK_CUR);

    // read metadata size field
    char size_bytes[4];
    fread(size_bytes, sizeof(char), 4, file);

    int metadata_size = ((size_bytes[0] & 0x7F) << 21) | ((size_bytes[1] & 0x7F) << 14) | ((size_bytes[2] & 0x7F) << 7) | (size_bytes[3] & 0x7F);

    // allocate buffer for metadata
    char* metadata_buffer = (char*)malloc(sizeof(char) * metadata_size);

    // read metadata into buffer
    fread(metadata_buffer, sizeof(char), metadata_size, file);

    // close file
    fclose(file);

    // extract metadata fields
    struct Metadata metadata;
    int index = 0;

    while (index < metadata_size) {
        char field_id[5];
        strncpy(field_id, metadata_buffer + index, 4);
        field_id[4] = '\0';

        int field_size = *((int*)(metadata_buffer + index + 4));

        char* field_value = (char*)malloc(sizeof(char) * field_size);
        strncpy(field_value, metadata_buffer + index + 10, field_size);

        if (strcmp(field_id, "TIT2") == 0) {
            strncpy(metadata.title, field_value, 99);                
        }
        else if (strcmp(field_id, "TPE1") == 0) {
            strncpy(metadata.artist, field_value, 99);
        }
        else if (strcmp(field_id, "TALB") == 0) {
            strncpy(metadata.album, field_value, 99);
        }
        else if (strcmp(field_id, "TYER") == 0) {
            metadata.year = atoi(field_value);
        }

        free(field_value);

        index += field_size + 10;
    }

    // print metadata fields
    printf("Title: %s\nArtist: %s\nAlbum: %s\nYear: %d\n", metadata.title, metadata.artist, metadata.album, metadata.year);

    // free metadata buffer
    free(metadata_buffer);

    return 0;
}