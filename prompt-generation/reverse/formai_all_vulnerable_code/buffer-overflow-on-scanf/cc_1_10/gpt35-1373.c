//FormAI DATASET v1.0 Category: Music Library Management System ; Style: protected
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct song{
    char name[30];
    char artist[30];
    char album[30];
    int year;
};

void addSong(struct song *songs, int *num_songs);
void searchSong(struct song *songs, int num_songs);
void deleteSong(struct song *songs, int *num_songs);

int main(){
    int num_songs = 0;
    struct song songs[100];

    int choice;
    do{
        printf("-----C Music Library Management System-----\n");
        printf("1. Add song\n");
        printf("2. Search song\n");
        printf("3. Delete song\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addSong(songs, &num_songs);
                break;
            case 2:
                searchSong(songs, num_songs);
                break;
            case 3:
                deleteSong(songs, &num_songs);
                break;
            case 4:
                printf("Thank you for using the system!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

    }while(choice != 4);

    return 0;
}

void addSong(struct song *songs, int *num_songs){
    printf("Enter the following information about the song:\n");
    printf("Name: ");
    scanf("%s", (songs + *num_songs)->name);
    printf("Artist: ");
    scanf("%s", (songs + *num_songs)->artist);
    printf("Album: ");
    scanf("%s", (songs + *num_songs)->album);
    printf("Year: ");
    scanf("%d", &(songs + *num_songs)->year);

    printf("Song added successfully!\n");
    (*num_songs)++;
}

void searchSong(struct song *songs, int num_songs){
    char name[30];
    printf("Enter the name of the song you want to search: ");
    scanf("%s", name);

    for(int i=0; i<num_songs; i++){
        if(strcmp(name, (songs+i)->name) == 0){
            printf("Song found!\n");
            printf("Name: %s\n", (songs+i)->name);
            printf("Artist: %s\n", (songs+i)->artist);
            printf("Album: %s\n", (songs+i)->album);
            printf("Year: %d\n", (songs+i)->year);
            return;
        }
    }
    printf("Song not found.\n");
}

void deleteSong(struct song *songs, int *num_songs){
    char name[30];
    printf("Enter the name of the song you want to delete: ");
    scanf("%s", name);

    for(int i=0; i<*num_songs; i++){
        if(strcmp(name, (songs+i)->name) == 0){
            for(int j=i; j<*num_songs-1; j++){
                strcpy((songs+j)->name, (songs+j+1)->name);
                strcpy((songs+j)->artist, (songs+j+1)->artist);
                strcpy((songs+j)->album, (songs+j+1)->album);
                (songs+j)->year = (songs+j+1)->year;
            }
            (*num_songs)--;
            printf("Song deleted successfully!\n");
            return;
        }
    }
    printf("Song not found.\n");
}