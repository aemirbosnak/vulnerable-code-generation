//FormAI DATASET v1.0 Category: Music Library Management System ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct MusicLibrary {
    char Title[50];
    char Artist[50];
    char Genre[20];
    int ReleaseYear;
    int TrackLength;
};

typedef struct MusicLibrary Music;

void print_menu() {
    printf("\n\t\t=== Music Library Management System ===\n");
    printf("\n\t\t1. Add New Song to Library");
    printf("\n\t\t2. Display Songs in the Library");
    printf("\n\t\t3. Search for a Song in the Library");
    printf("\n\t\t4. Delete a Song from the Library");
    printf("\n\t\t5. Exit Program");
}

void add_song(Music *library, int *size, int max_size) {
    if (*size == max_size) {
        printf("Your Music Library is Full.\n");
        return;
    }
    
    printf("\nEnter Song Title: ");
    scanf("%s", library[*size].Title);
    printf("Enter Artist Name: ");
    scanf("%s", library[*size].Artist);
    printf("Enter Genre of the Song: ");
    scanf("%s", library[*size].Genre);
    printf("Enter Release Year of the Song: ");
    scanf("%d", &library[*size].ReleaseYear);
    printf("Enter Track Length in seconds: ");
    scanf("%d", &library[*size].TrackLength);
    
    *size += 1;
    printf("\nSong added to Music Library.\n");
}

void display_songs(Music *library, int size) {
    if (size == 0) {
        printf("\nThere are no Songs in the Library.\n");
        return;
    }
    
    printf("\nSong Title\tArtist Name\tGenre\tRelease Year\tTrack Length\n");
    for (int i = 0; i < size; i++) {
        printf("\n%s\t\t%s\t\t%s\t%d\t\t%d", library[i].Title, library[i].Artist, library[i].Genre, library[i].ReleaseYear, library[i].TrackLength);
    }
}

void search_song(Music *library, int size) {
    char search_name[50];
    int found = 0;
    
    printf("\nEnter Song Title to Search: ");
    scanf("%s", search_name);
    
    for (int i = 0; i < size; i++) {
        if (strcmp(search_name, library[i].Title) == 0) {
            found = 1;
            printf("\nSong Found!");
            printf("\nSong Title\tArtist Name\tGenre\tRelease Year\tTrack Length\n");
            printf("\n%s\t\t%s\t\t%s\t%d\t\t%d", library[i].Title, library[i].Artist, library[i].Genre, library[i].ReleaseYear, library[i].TrackLength);
            break;
        }
    }
    
    if (found == 0) {
        printf("\nSong Not Found!\n");
    }
}

void delete_song(Music *library, int *size) {
    char delete_name[50];
    int found = 0;
    
    printf("\nEnter Song Title to Delete: ");
    scanf("%s", delete_name);
    
    for (int i = 0; i < *size; i++) {
        if (strcmp(delete_name, library[i].Title) == 0) {
            found = 1;
            
            for (int j = i; j < *size-1; j++) {
                strcpy(library[j].Title, library[j+1].Title);
                strcpy(library[j].Artist, library[j+1].Artist);
                strcpy(library[j].Genre, library[j+1].Genre);
                library[j].ReleaseYear = library[j+1].ReleaseYear;
                library[j].TrackLength = library[j+1].TrackLength;
            }
            
            *size -= 1;
            printf("\nSong Deleted from Music Library.\n");
            break;
        }
    }
    
    if (found == 0) {
        printf("\nSong Not Found!\n");
    }
}

int main() {
    Music library[50];
    int size = 0, choice, max_size = 50;
    
    while(1) {
        print_menu();
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_song(library, &size, max_size);
                break;
                
            case 2:
                display_songs(library, size);
                break;
                
            case 3:
                search_song(library, size);
                break;
                
            case 4:
                delete_song(library, &size);
                break;
                
            case 5:
                printf("\nThanks for using Music Library Management System. Goodbye!\n");
                exit(0);
                break;
                
            default:
                printf("\nInvalid Choice! Please Try Again.\n");
        }
    }
    
    return 0;
}