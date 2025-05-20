//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: Alan Turing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

struct song{
    char name[50];
    char artist[50];
    int duration;
};

struct playlist{
    char name[50];
    int num_songs;
    struct song songs[SIZE];
};

void create_playlist(struct playlist *p){
    printf("Enter playlist name: ");
    scanf("%s",p->name);
    p->num_songs=0;
}

void add_song(struct playlist *p){
    printf("Enter song name: ");
    scanf("%s",p->songs[p->num_songs].name);
    printf("Enter song artist: ");
    scanf("%s",p->songs[p->num_songs].artist);
    printf("Enter song duration (in seconds): ");
    scanf("%d",&p->songs[p->num_songs].duration);
    p->num_songs++;
}

void display_playlist(struct playlist p){
    printf("Playlist name: %s\n",p.name);
    printf("Number of songs: %d\n",p.num_songs);
    for(int i=0;i<p.num_songs;i++){
        printf("Song %d:\n",i+1);
        printf("Name: %s\n",p.songs[i].name);
        printf("Artist: %s\n",p.songs[i].artist);
        printf("Duration: %d seconds\n\n",p.songs[i].duration);
    }
}

int main(){
    struct playlist p;
    create_playlist(&p);
    int choice;
    do{
        printf("\n1. Add song\n2. Display playlist\n3. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_song(&p);
                break;
            case 2:
                display_playlist(p);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!=3);
    return 0;
}