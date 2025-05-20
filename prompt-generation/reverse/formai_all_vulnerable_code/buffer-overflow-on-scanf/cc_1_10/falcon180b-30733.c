//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct music{
    char title[50];
    char artist[50];
    int year;
    char genre[20];
    float duration;
    int track_number;
};

void add_music(struct music *music_library[], int *size){
    char choice;
    printf("Enter the choice:\n1.Add music\n2.Exit\n");
    scanf("%c",&choice);
    if(choice=='1'){
        printf("Enter the title of the music: ");
        scanf("%s",music_library[*size]->title);
        printf("Enter the artist of the music: ");
        scanf("%s",music_library[*size]->artist);
        printf("Enter the year of release of the music: ");
        scanf("%d",&music_library[*size]->year);
        printf("Enter the genre of the music: ");
        scanf("%s",music_library[*size]->genre);
        printf("Enter the duration of the music (in seconds): ");
        scanf("%f",&music_library[*size]->duration);
        printf("Enter the track number of the music: ");
        scanf("%d",&music_library[*size]->track_number);
        (*size)++;
    }
    else{
        exit(0);
    }
}

void display_music(struct music music_library[], int size){
    int i;
    printf("\nThe music library contains the following music:\n");
    for(i=0;i<size;i++){
        printf("\nTitle: %s\nArtist: %s\nYear: %d\nGenre: %s\nDuration: %.2f seconds\nTrack number: %d\n\n",music_library[i].title,music_library[i].artist,music_library[i].year,music_library[i].genre,music_library[i].duration,music_library[i].track_number);
    }
}

int main(){
    struct music music_library[MAX];
    int size=0;
    int choice;

    do{
        printf("Enter the choice:\n1.Add music\n2.Display music library\n3.Exit\n");
        scanf("%c",&choice);
        switch(choice){
            case '1':
                add_music(music_library,&size);
                break;
            case '2':
                display_music(music_library,size);
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }while(1);

    return 0;
}