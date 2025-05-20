//FormAI DATASET v1.0 Category: Music Library Management System ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct song{
    char name[20];
    char artist[20];
    char genre[20];
    int rating;
}Song;

void printMenu();
void addSong(Song*, int*);
void removeSong(Song*, int*);
void displaySongs(Song*, int*);

int main(){
    int choice, numSongs=0;
    Song* library = (Song*) malloc(sizeof(Song)*100);
    do{
        printMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addSong(library, &numSongs);
                break;
            case 2:
                removeSong(library, &numSongs);
                break;
            case 3:
                displaySongs(library, &numSongs);
                break;
            case 4:
                printf("Thank you for using the C Music Library Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }while(choice!=4);

    free(library);
    return 0;
}

void printMenu(){
    printf("\nWelcome to the C Music Library Management System!\n");
    printf("Please select an option:\n");
    printf("1. Add a Song\n");
    printf("2. Remove a Song\n");
    printf("3. Display Songs\n");
    printf("4. Exit\n");
    printf("Your choice: ");
}

void addSong(Song* library, int* numSongs){
    if(*numSongs<100){
        Song newSong;
        printf("\nEnter the following details:\n");
        printf("Name: ");
        scanf("%s", newSong.name);
        printf("Artist: ");
        scanf("%s", newSong.artist);
        printf("Genre: ");
        scanf("%s", newSong.genre);
        printf("Rating (out of 10): ");
        scanf("%d", &newSong.rating);
        library[*numSongs]=newSong;
        (*numSongs)++;
        printf("Song added successfully!\n");
    }
    else{
        printf("Sorry, library is full. Cannot add more songs.\n");
    }
}

void removeSong(Song* library, int* numSongs){
    if(*numSongs>0){
        char name[20], artist[20];
        printf("\nEnter the following details of the song to be removed:\n");
        printf("Name: ");
        scanf("%s", name);
        printf("Artist: ");
        scanf("%s", artist);
        int index=-1;
        for(int i=0; i<*numSongs; i++){
            if(strcmp(library[i].name, name)==0 && strcmp(library[i].artist, artist)==0){
                index=i;
                break;
            }
        }
        if(index!=-1){
            for(int i=index; i<*numSongs-1; i++){
                library[i]=library[i+1];
            }
            (*numSongs)--;
            printf("Song removed successfully!\n");
        }
        else{
            printf("Sorry, could not find the specified song.\n");
        }
    }
    else{
        printf("Sorry, library is empty. Cannot remove any songs.\n");
    }
}

void displaySongs(Song* library, int* numSongs){
    if(*numSongs>0){
        printf("\nSongs in the library:\n");
        printf("%-20s%-20s%-20s%s\n", "Name", "Artist", "Genre", "Rating");
        for(int i=0; i<*numSongs; i++){
            printf("%-20s%-20s%-20s%d\n", library[i].name, library[i].artist, library[i].genre, library[i].rating);
        }
    }
    else{
        printf("Sorry, library is empty. Cannot display any songs.\n");
    }
}