//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Metadata {
    char artist[50];
    char album[50];
    char title[50];
    char genre[20];
    int year;
} Metadata;

// Function to extract metadata from file name
Metadata extractMetadata(char* fileName) {
    Metadata data;
    char* token;
    char* str = fileName;
    int count = 0;
    
    token = strtok(str, "-");   // Split file name using hyphen (-)
    while (token != NULL) {
        count++;
        if (count == 1)
            strcpy(data.artist, token);
        else if (count == 2)
            strcpy(data.album, token);
        else if (count == 3)
            strcpy(data.title, token);
        else if (count == 4)
            strcpy(data.genre, token);
        else if (count == 5)
            data.year = atoi(token);
        token = strtok(NULL, "-");
    }
    
    return data;
}

int main() {
    char fileName[100];
    Metadata data;
    
    printf("Enter file name: ");
    scanf("%s", fileName);
    
    data = extractMetadata(fileName);
    
    printf("\nArtist: %s", data.artist);
    printf("\nAlbum: %s", data.album);
    printf("\nTitle: %s", data.title);
    printf("\nGenre: %s", data.genre);
    printf("\nYear: %d", data.year);
    
    return 0;
}