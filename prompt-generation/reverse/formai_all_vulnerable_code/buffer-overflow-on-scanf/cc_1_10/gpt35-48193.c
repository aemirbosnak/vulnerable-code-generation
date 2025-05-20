//FormAI DATASET v1.0 Category: Music Library Management System ; Style: shape shifting
#include<stdio.h>
#include<string.h>
#define MAX 100

int count, i;
struct music_library{
    char song_name[MAX];
    char artist[MAX];
    char album[MAX];
    int year;
    float rating;
}music[MAX];

void insert_song(){
    if(count==MAX){
        printf("Music library is full.\n");
        return;
    }
    printf("Enter the song name:");
    scanf("%s", music[count].song_name);
    printf("Enter the artist name:");
    scanf("%s", music[count].artist);
    printf("Enter the album name:");
    scanf("%s", music[count].album);
    printf("Enter the year:");
    scanf("%d", &music[count].year);
    printf("Enter rating(0-10):");
    scanf("%f", &music[count].rating);
    count++;
}

void display_song(){
    if(count==0){
        printf("Music library is empty.\n");
        return;
    }
    printf("Song name\tArtist\tAlbum\tYear\tRating\n");
    for(i=0;i<count;i++){
        printf("%s\t%s\t%s\t%d\t%0.2f\n", music[i].song_name, music[i].artist, music[i].album, music[i].year, music[i].rating);
    }
}

void search_song(){
    char song_name[MAX];
    printf("Enter the song name to search:");
    scanf("%s", song_name);
    for(i=0;i<count;i++){
        if(strcmp(music[i].song_name, song_name)==0){
            printf("Song name\tArtist\tAlbum\tYear\tRating\n");
            printf("%s\t%s\t%s\t%d\t%0.2f\n", music[i].song_name, music[i].artist, music[i].album, music[i].year, music[i].rating);
            return;
        }
    }
    printf("Song not found.\n");
}

void delete_song(){
    char song_name[MAX];
    int pos, j;
    printf("Enter the song name to delete:");
    scanf("%s", song_name);
    for(i=0;i<count;i++){
        if(strcmp(music[i].song_name, song_name)==0){
            pos=i;
            for(j=pos;j<count-1;j++){
                music[j]=music[j+1];
            }
            count--;
            printf("Song '%s' deleted successfully.\n", song_name);
            return;
        }
    }
    printf("Song not found.\n");
}

int main(){
    int choice;
    while(1){
        printf("\nMusic Library Management System\n");
        printf("1. Insert a song\n");
        printf("2. Display all songs\n");
        printf("3. Search a song\n");
        printf("4. Delete a song\n");
        printf("5. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insert_song();
                break;
            case 2:
                display_song();
                break;
            case 3:
                search_song();
                break;
            case 4:
                delete_song();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}