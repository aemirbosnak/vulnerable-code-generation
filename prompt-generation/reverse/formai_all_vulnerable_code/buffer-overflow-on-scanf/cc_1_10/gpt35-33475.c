//FormAI DATASET v1.0 Category: Music Library Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record{
    char album[50];
    char artist[50];
    int year;
    int track_count;
};

struct Record music_library[100];

void add_record(){
    int i;
    for(i=0;i<100;i++){
        if(strcmp(music_library[i].album,"")==0){
            printf("Enter album name: ");
            fgets(music_library[i].album,50,stdin);
            printf("Enter artist name: ");
            fgets(music_library[i].artist,50,stdin);
            printf("Enter year of release: ");
            scanf("%d", &music_library[i].year);
            printf("Enter number of tracks: ");
            scanf("%d", &music_library[i].track_count);
            getchar();
            break;
        }
    }
}

void view_records(){
    int i;
    for(i=0;i<100;i++){
        if(strcmp(music_library[i].album,"")!=0){
            printf("Album: %sArtist: %sYear of Release: %dNumber of Tracks: %d\n",music_library[i].album,music_library[i].artist,music_library[i].year,music_library[i].track_count);
            }
    }
}

void delete_record(char album_name[]){
    int i;
    for(i=0;i<100;i++){
        if(strcmp(music_library[i].album,album_name)==0){
            memset(&music_library[i],0,sizeof(music_library[i]));
            printf("Record deleted successfully!\n");
            return;
        }
    }
    printf("Record not found.\n");
}

void search_record(char album_name[]){
    int i;
    for(i=0;i<100;i++){
        if(strcmp(music_library[i].album,album_name)==0){
            printf("Album: %sArtist: %sYear of Release: %dNumber of Tracks: %d\n",music_library[i].album,music_library[i].artist,music_library[i].year,music_library[i].track_count);
            return;
        }
    }
    printf("Record not found.\n");
}

int main(){
    int choice;
    char album_name[50];
    while(1){
        printf("--------------------\n");
        printf("Music Library System\n");
        printf("--------------------\n");
        printf("1. Add record\n");
        printf("2. View records\n");
        printf("3. Delete record\n");
        printf("4. Search record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
                add_record();
                break;
            case 2:
                view_records();
                break;
            case 3:
                printf("Enter album name to delete: ");
                fgets(album_name,50,stdin);
                delete_record(album_name);
                break;
            case 4:
                printf("Enter album name to search: ");
                fgets(album_name,50,stdin);
                search_record(album_name);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}