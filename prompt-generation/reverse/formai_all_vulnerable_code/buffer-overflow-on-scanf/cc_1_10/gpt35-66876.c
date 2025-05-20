//FormAI DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Song{
    char name[100];
    char artist[100];
    char album[100];
    int year;
};

void add_song(struct Song* songs, int* count){
    printf("Enter Song Name: ");
    scanf("%s", songs[*count].name);

    printf("Enter Artist Name: ");
    scanf("%s", songs[*count].artist);

    printf("Enter Album Name: ");
    scanf("%s", songs[*count].album);

    printf("Enter Release Year: ");
    scanf("%d", &songs[*count].year);

    printf("\nSong added successfully!\n");
    (*count)++;
}

void display_all_songs(struct Song* songs, int count){
    printf("All Songs\n");
    for(int i=0; i<count; i++){
        printf("%d. %s - %s [%s] (%d)\n", i+1, songs[i].name, songs[i].artist, songs[i].album, songs[i].year);
    }
}

void search_by_name(struct Song* songs, int count){
    char name[100];
    printf("Enter Name to Search: ");
    scanf("%s", name);
    
    for(int i=0; i<count; i++){
        if(strcmp(songs[i].name, name)==0){
            printf("%s - %s [%s] (%d)\n", songs[i].name, songs[i].artist, songs[i].album, songs[i].year);
        }
    }
}

void search_by_artist(struct Song* songs, int count){
    char artist[100];
    printf("Enter Artist Name to Search: ");
    scanf("%s", artist);

    for(int i=0; i<count; i++){
        if(strcmp(songs[i].artist, artist)==0){
            printf("%s - %s [%s] (%d)\n", songs[i].name, songs[i].artist, songs[i].album, songs[i].year);
        }
    }
}

int main(){
    int count = 0;  // initial count of songs
    int choice;

    printf("C Music Library Management System\n");

    struct Song songs[100];

    while(1){
        printf("\n---MENU---\n");
        printf("1. Add Song\n");
        printf("2. Display All Songs\n");
        printf("3. Search by Name\n");
        printf("4. Search by Artist\n");
        printf("5. Exit\n");
        printf("Enter Choice (1-5): ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_song(songs, &count);
                break;

            case 2:
                display_all_songs(songs, count);
                break;
            
            case 3:
                search_by_name(songs, count);
                break;

            case 4:
                search_by_artist(songs, count);
                break;

            case 5:
                printf("\nExiting C Music Library Management System\n");
                exit(0);

            default:
                printf("\nInvalid Choice! Please enter choice between 1 to 5.\n");
        }
    }
    return 0;
}