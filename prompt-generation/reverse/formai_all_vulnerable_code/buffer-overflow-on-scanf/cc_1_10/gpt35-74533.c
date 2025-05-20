//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char title[50];
    char artist[50];
    char album[50];
    char year[5];
} SongMetadata;

int main()
{
    FILE *fp;
    char filename[50];
    char line[100];
    int i = 0;
    SongMetadata songmeta;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(fgets(line, 100, fp) != NULL)
    {
        if(strncmp(line, "Title:", 6) == 0)
        {
            strncpy(songmeta.title, line+7, 50);
            songmeta.title[strlen(songmeta.title)-1] = '\0'; // Remove newline character
        }
        else if(strncmp(line, "Artist:", 7) == 0)
        {
            strncpy(songmeta.artist, line+8, 50);
            songmeta.artist[strlen(songmeta.artist)-1] = '\0';
        }
        else if(strncmp(line, "Album:", 6) == 0)
        {
            strncpy(songmeta.album, line+7, 50);
            songmeta.album[strlen(songmeta.album)-1] = '\0';
        }
        else if(strncmp(line, "Year:", 5) == 0)
        {
            strncpy(songmeta.year, line+6, 5);
            songmeta.year[strlen(songmeta.year)-1] = '\0';
        } 
    }

    fclose(fp);

    printf("\nSong metadata:\n");
    printf("Title: %s\n", songmeta.title);
    printf("Artist: %s\n", songmeta.artist);
    printf("Album: %s\n", songmeta.album);
    printf("Year: %s\n", songmeta.year);

    return 0;
}