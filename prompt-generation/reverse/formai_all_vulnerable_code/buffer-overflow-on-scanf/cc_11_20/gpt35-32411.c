//FormAI DATASET v1.0 Category: Music Library Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char name[50];
    char artist[50];
    char album[50];
    int duration;
};

int main() {
    struct song music[100];
    int choice, i, count = 0;

    do {
        printf("**** MUSIC LIBRARY MANAGEMENT SYSTEM ****\n");
        printf("1. Add a new song\n");
        printf("2. Display all songs in the library\n");
        printf("3. Search for a song\n");
        printf("4. Delete a song\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the name of the song: ");
                scanf("%s", music[count].name);
                printf("Enter the name of the artist: ");
                scanf("%s", music[count].artist);
                printf("Enter the name of the album: ");
                scanf("%s", music[count].album);
                printf("Enter the duration of the song (in seconds): ");
                scanf("%d", &music[count].duration);
                count++;
                printf("\nSong added successfully!\n\n");
                break;
            case 2:
                if(count == 0) {
                    printf("\nThe music library is empty!\n\n");
                } else {
                    printf("\n***** MUSIC LIBRARY *****\n\n");
                    for(i=0; i<count; i++) {
                        printf("Song #%d\n", i+1);
                        printf("Name: %s\n", music[i].name);
                        printf("Artist: %s\n", music[i].artist);
                        printf("Album: %s\n", music[i].album);
                        printf("Duration: %d seconds\n\n", music[i].duration);
                    }
                }
                break;
            case 3:
                if(count == 0) {
                    printf("\nThe music library is empty!\n\n");
                } else {
                    char search[50];
                    int found = 0;
                    printf("\nEnter the name of the song to search: ");
                    scanf("%s", search);
                    for(i=0; i<count; i++) {
                        if(strcmp(music[i].name, search) == 0) {
                            found = 1;
                            printf("\nSong found!\n\n");
                            printf("Name: %s\n", music[i].name);
                            printf("Artist: %s\n", music[i].artist);
                            printf("Album: %s\n", music[i].album);
                            printf("Duration: %d seconds\n\n", music[i].duration);
                        }
                    }
                    if(found == 0) {
                        printf("\nSong not found!\n\n");
                    }
                }
                break;
            case 4:
                if(count == 0) {
                    printf("\nThe music library is empty!\n\n");
                } else {
                    char remove[50];
                    int found = 0, position;
                    printf("\nEnter the name of the song to delete: ");
                    scanf("%s", remove);
                    for(i=0; i<count; i++) {
                        if(strcmp(music[i].name, remove) == 0) {
                            found = 1;
                            position = i;
                        }
                    }
                    if(found == 0) {
                        printf("\nSong not found!\n\n");
                    } else {
                        for(i=position; i<count-1; i++) {
                            music[i] = music[i+1];
                        }
                        count--;
                        printf("\nSong deleted successfully!\n\n");
                    }
                }
                break;
            case 5:
                printf("\nThank you for using the Music Library Management System!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n\n");
        }

    } while(choice != 5);

    return 0;
}