//FormAI DATASET v1.0 Category: Music Library Management System ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct music_library{
    char songname[50];
    char artist[50];
    char genre[15];
    int duration;
};

void add_song(struct music_library* library, int size){
    // Function to add a new song to the music library
    printf("\nEnter Song Name: ");
    scanf("%s",library[size].songname);
    printf("Enter Artist Name: ");
    scanf("%s",library[size].artist);
    printf("Enter Genre: ");
    scanf("%s",library[size].genre);
    printf("Enter Song Duration (in seconds): ");
    scanf("%d",&library[size].duration);
    printf("\nSong added successfully!\n\n");
}

void view_library(struct music_library* library, int size){
    // Function to view the entire music library
    if(size == 0){
        printf("\nMusic Library is Empty!\n\n");
        return;
    }
    printf("\n\n------------------------Music Library------------------------\n\n");
    printf("%-30s %-30s %-20s %-10s\n\n","Song Name","Artist Name","Genre","Duration");
    for(int i=0;i<size;i++){
        printf("%-30s %-30s %-20s %-10d\n",library[i].songname,library[i].artist,library[i].genre,library[i].duration);
    }
    printf("\n----------------------------------------------------------------\n\n");
}

void random_playlist(struct music_library* library, int size){
    // Function to generate a random playlist of 5 songs from the music library
    if(size == 0){
        printf("\nMusic Library is Empty!\n\n");
        return;
    }
    if(size < 5){
        printf("\nMusic Library has less than 5 songs. Cannot generate playlist!\n\n");
        return;
    }
    printf("\n\n----------------------Random Playlist (5 Songs)---------------------\n\n");
    printf("%-30s %-30s %-20s %-10s\n\n","Song Name","Artist Name","Genre","Duration");
    int indexes[5],count=0;
    srand(time(NULL));
    while(count<5){
        int index = rand()%size;
        int flag=0;
        for(int j=0;j<count;j++){
            if(index==indexes[j]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            indexes[count]=index;
            count++;
        }
    }
    for(int i=0;i<5;i++){
        printf("%-30s %-30s %-20s %-10d\n",library[indexes[i]].songname,library[indexes[i]].artist,library[indexes[i]].genre,library[indexes[i]].duration);
    }
    printf("\n-----------------------------------------------------------------------\n\n");
}

void search_song(struct music_library* library, int size){
    // Function to search for a song in the music library
    if(size == 0){
        printf("\nMusic Library is Empty!\n\n");
        return;
    }
    char search_songname[50];
    printf("\nEnter Song Name to be searched: ");
    scanf("%s",search_songname);
    int flag=0;
    for(int i=0;i<size;i++){
        if(strcmp(library[i].songname,search_songname)==0){
            flag=1;
            printf("\n\nSong Found!\n\n");
            printf("%-30s %-30s %-20s %-10s\n\n","Song Name","Artist Name","Genre","Duration");
            printf("%-30s %-30s %-20s %-10d\n",library[i].songname,library[i].artist,library[i].genre,library[i].duration);
            break;
        }
    }
    if(flag==0){
        printf("\n\nSong not found!\n\n");
    }
}

int main(){
    struct music_library library[100];
    int size=0;

    int choice=-1;
    do{
        printf("-------------------------------------------------------------\n");
        printf("\nEnter 1 to add new song.\n");
        printf("Enter 2 to view entire Music Library.\n");
        printf("Enter 3 to generate a random playlist.\n");
        printf("Enter 4 to search for a song.\n");
        printf("Enter 0 to exit.\n");
        printf("-------------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: add_song(library,size);
                    size++;
                    break;
            case 2: view_library(library,size);
                    break;
            case 3: random_playlist(library,size);
                    break;
            case 4: search_song(library,size);
                    break;
            case 0: printf("\n\nExiting....\n\n");
                    break;
            default: printf("Invalid choice. Try again!"); 
        }
    }while(choice!=0);
    return 0;
}