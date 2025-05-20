//FormAI DATASET v1.0 Category: Music Library Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song{
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

void add_song(struct song library[], int *songs_count);
void delete_song(struct song library[], int *songs_count);
void search_song(struct song library[], int songs_count);
void display_songs(struct song library[], int songs_count);

int main(){
    struct song library[100];
    int songs_count = 0;
    int choice;
    do{
        printf("1. Add a song\n");
        printf("2. Delete a song\n");
        printf("3. Search for a song\n");
        printf("4. Display songs in the library\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_song(library, &songs_count);
                break;
            case 2:
                delete_song(library, &songs_count);
                break;
            case 3:
                search_song(library, songs_count);
                break;
            case 4:
                display_songs(library, songs_count);
                break;
            case 5:
                printf("Thank you for using the Music Library Management System.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }while(1);
    return 0;
}

void add_song(struct song library[], int *songs_count){
    if(*songs_count < 100){
        printf("Enter song title: ");
        scanf(" %[^\n]", library[*songs_count].title);
        printf("Enter artist name: ");
        scanf(" %[^\n]", library[*songs_count].artist);
        printf("Enter album name: ");
        scanf(" %[^\n]", library[*songs_count].album);
        printf("Enter year of release: ");
        scanf("%d", &(library[*songs_count].year));
        (*songs_count)++;
        printf("Song added to the library.\n");
    }
    else{
        printf("Library is full, cannot add more songs.\n");
    }
}

void delete_song(struct song library[], int *songs_count){
    char title[50];
    int i, j;
    if(*songs_count == 0){
        printf("Library is empty, cannot delete any songs.\n");
        return;
    }
    printf("Enter the title of the song to be deleted: ");
    scanf(" %[^\n]", title);
    for(i=0; i<*songs_count; i++){
        if(strcmp(title, library[i].title) == 0){
            for(j=i+1; j<*songs_count; j++){
                library[j-1] = library[j];
            }
            (*songs_count)--;
            printf("Song deleted from the library.\n");
            return;
        }
    }
    printf("Song not found in the library.\n");
}

void search_song(struct song library[], int songs_count){
    char keyword[50];
    int i, found=0;
    printf("Enter the keyword to search for: ");
    scanf(" %[^\n]", keyword);
    printf("Search results:\n");
    for(i=0; i<songs_count; i++){
        if(strstr(library[i].title, keyword) != NULL || strstr(library[i].artist, keyword) != NULL || strstr(library[i].album, keyword) != NULL){
            printf("%s, %s, %s, %d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
            found = 1;
        }
    }
    if(!found){
        printf("No songs found in the library matching the given keyword.\n");
    }
}

void display_songs(struct song library[], int songs_count){
    int i;
    if(songs_count == 0){
        printf("Library is empty, cannot display any songs.\n");
        return;
    }
    for(i=0; i<songs_count; i++){
        printf("%s, %s, %s, %d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
    }
}