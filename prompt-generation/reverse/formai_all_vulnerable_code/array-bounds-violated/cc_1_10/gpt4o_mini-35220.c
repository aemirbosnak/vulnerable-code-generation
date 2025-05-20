//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID3V1_TAG_SIZE 128

typedef struct {
    char title[30];
    char artist[30];
    char album[30];
    char year[5];
    char comment[28];
    unsigned char genre;
} ID3v1Tag;

void print_metadata(ID3v1Tag *tag) {
    printf("Title: %s\n", tag->title);
    printf("Artist: %s\n", tag->artist);
    printf("Album: %s\n", tag->album);
    printf("Year: %s\n", tag->year);
    printf("Comment: %s\n", tag->comment);
    printf("Genre: %u\n", tag->genre);
}

int read_id3v1_tag(const char *filename, ID3v1Tag *tag) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return -1;
    }

    // Seek to the end minus 128 bytes to reach ID3v1 tag
    fseek(file, -ID3V1_TAG_SIZE, SEEK_END);
    
    char tag_buffer[ID3V1_TAG_SIZE];
    fread(tag_buffer, sizeof(char), ID3V1_TAG_SIZE, file);
    
    // Check if it contains "TAG"
    if (strncmp(tag_buffer, "TAG", 3) != 0) {
        fprintf(stderr, "Error: No ID3v1 tag found in file %s\n", filename);
        fclose(file);
        return -2;
    }

    // Extract metadata from the tag buffer
    strncpy(tag->title, tag_buffer + 3, 30);
    strncpy(tag->artist, tag_buffer + 33, 30);
    strncpy(tag->album, tag_buffer + 63, 30);
    strncpy(tag->year, tag_buffer + 93, 4);
    strncpy(tag->comment, tag_buffer + 97, 28);
    tag->genre = (unsigned char)(tag_buffer[127]);

    // Null-terminate strings appropriately
    tag->title[29] = '\0';
    tag->artist[29] = '\0';
    tag->album[29] = '\0';
    tag->year[4] = '\0';
    tag->comment[27] = '\0';

    fclose(file);
    return 0;
}

const char *get_genre_name(unsigned char genre) {
    const char *genres[] = {
        "Blues", "Classic Rock", "Country", "Dance", "Disco", 
        "Funk", "Grunge", "Hip-Hop", "Jazz", "Metal", 
        "New Age", "Oldies", "Other", "Pop", "R&B", 
        "Rap", "Reggae", "Rock", "Techno", "Industrial", 
        "Alternative", "Ska", "Death Metal", "Pranks", "Soundtrack", 
        "Euro-Techno", "Ambient", "Trip-Hop", "Vocal", "Jazz+Funk", 
        "Fusion", "Trance", "Classical", "Instrumental", "Acid", 
        "House", "Game", "Sound Clip", "Gospel", "Noise", 
        "AlternRock", "Bass", "Soul", "Punk", "Space", 
        "Meditative", "Instrumental Pop", "Instrumental Rock", "Ethnic", "Gothic", 
        "Darkwave", "Techno-Industrial", "Electronic", "Pop-Folk", "Eurodance", 
        "Dream", "Southern Rock", "Comedy", "Cult", "Gangsta", 
        "Hardcore", "Terror", "Indie", "Brittany", "Polka", 
        "Retro", "Musical", "Rock & Roll", "", "Hard Rock", 
        "Unknown"
    };

    if (genre < 256) {
        return genres[genre];
    }
    return "Unknown";
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ID3v1Tag tag;
    int result = read_id3v1_tag(argv[1], &tag);
    if (result != 0) {
        return EXIT_FAILURE;
    }

    print_metadata(&tag);
    printf("Genre: %s\n", get_genre_name(tag.genre));

    return EXIT_SUCCESS;
}