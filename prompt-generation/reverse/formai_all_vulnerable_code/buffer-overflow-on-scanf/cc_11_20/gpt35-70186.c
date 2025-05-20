//FormAI DATASET v1.0 Category: Music Library Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    int year;
};

int main() {
    int choice, num_songs = 0;
    struct song *songs = NULL;
    FILE *fp;

    while(1) {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add a new song\n");
        printf("2. Display all songs\n");
        printf("3. Save to file\n");
        printf("4. Load from file\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                songs = realloc(songs, (num_songs + 1) * sizeof(struct song));
                printf("\nEnter song title: ");
                scanf("%s", songs[num_songs].title);
                printf("Enter artist name: ");
                scanf("%s", songs[num_songs].artist);
                printf("Enter year of release: ");
                scanf("%d", &songs[num_songs].year);
                num_songs++;
                break;
            case 2:
                if(num_songs == 0) {
                    printf("\nNo songs found. Please add some songs.\n");
                }
                else {
                    printf("\n--- List of songs ---\n");
                    for(int i = 0; i < num_songs; i++) {
                        printf("%d. %s - %s (%d)\n", i + 1, songs[i].title, songs[i].artist, songs[i].year);
                    }
                }
                break;
            case 3:
                if(num_songs == 0) {
                    printf("\nNo songs found. Please add some songs.\n");
                }
                else {
                    fp = fopen("music_library.bin", "wb");
                    fwrite(&num_songs, sizeof(num_songs), 1, fp);
                    fwrite(songs, sizeof(struct song), num_songs, fp);
                    fclose(fp);
                    printf("\nLibrary has been saved to file.\n");
                }
                break;
            case 4:
                fp = fopen("music_library.bin", "rb");
                if(fp == NULL) {
                    printf("\nNo saved data found.\n");
                }
                else {
                    fread(&num_songs, sizeof(num_songs), 1, fp);
                    songs = realloc(songs, num_songs * sizeof(struct song));
                    fread(songs, sizeof(struct song), num_songs, fp);
                    fclose(fp);
                    printf("\nLibrary has been loaded from file.\n");
                }
                break;
            case 5:
                free(songs);
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}