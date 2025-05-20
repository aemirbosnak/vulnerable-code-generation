//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Music{
    char title[100];
    char artist[100];
    int duration;
    int genre;
};

struct Music* createMusic(char* title, char* artist, int duration, int genre){
    struct Music* music = (struct Music*)malloc(sizeof(struct Music));
    strcpy(music->title, title);
    strcpy(music->artist, artist);
    music->duration = duration;
    music->genre = genre;
    return music;
}

void displayMusic(struct Music* music){
    printf("Title: %s\n", music->title);
    printf("Artist: %s\n", music->artist);
    printf("Duration: %d seconds\n", music->duration);
    printf("Genre: %d\n", music->genre);
}

void playMusic(struct Music* music){
    printf("Playing %s by %s\n", music->title, music->artist);
}

int main(){
    struct Music* library[100];
    int size = 0;

    library[size] = createMusic("Bohemian Rhapsody", "Queen", 183, 1);
    size++;
    library[size] = createMusic("Stairway to Heaven", "Led Zeppelin", 420, 2);
    size++;
    library[size] = createMusic("Hotel California", "Eagles", 360, 3);
    size++;

    printf("Library Size: %d\n", size);

    for(int i=0; i<size; i++){
        displayMusic(library[i]);
    }

    int choice;
    printf("Enter the number of the song you want to play: ");
    scanf("%d", &choice);

    playMusic(library[choice]);

    return 0;
}