//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000
#define MAX_MUSIC 100
#define MAX_PLAYLIST 10
#define MAX_MUSIC_NAME 100
#define MAX_PLAYLIST_NAME 100

struct Music{
    char name[MAX_MUSIC_NAME];
    int duration;
    int genre;
};

struct Playlist{
    char name[MAX_PLAYLIST_NAME];
    int num_music;
    struct Music* music[MAX_MUSIC];
};

struct Music* createMusic(char* name, int duration, int genre){
    struct Music* music = malloc(sizeof(struct Music));
    strcpy(music->name, name);
    music->duration = duration;
    music->genre = genre;
    return music;
}

struct Playlist* createPlaylist(char* name){
    struct Playlist* playlist = malloc(sizeof(struct Playlist));
    strcpy(playlist->name, name);
    playlist->num_music = 0;
    return playlist;
}

void addMusicToPlaylist(struct Playlist* playlist, struct Music* music){
    playlist->music[playlist->num_music] = music;
    playlist->num_music++;
}

int main(){
    struct Music* music1 = createMusic("Despacito", 220, 1);
    struct Music* music2 = createMusic("Shape of You", 200, 2);
    struct Music* music3 = createMusic("Closer", 180, 3);
    struct Playlist* playlist1 = createPlaylist("Latin Hits");
    struct Playlist* playlist2 = createPlaylist("Pop Hits");
    addMusicToPlaylist(playlist1, music1);
    addMusicToPlaylist(playlist1, music2);
    addMusicToPlaylist(playlist2, music3);
    printf("Playlist Name: %s\n", playlist1->name);
    printf("Number of Music: %d\n", playlist1->num_music);
    printf("Music Name: %s\n", music1->name);
    printf("Music Duration: %d\n", music1->duration);
    printf("Music Genre: %d\n\n", music1->genre);
    printf("Playlist Name: %s\n", playlist2->name);
    printf("Number of Music: %d\n", playlist2->num_music);
    printf("Music Name: %s\n", music2->name);
    printf("Music Duration: %d\n", music2->duration);
    printf("Music Genre: %d\n", music2->genre);
    printf("Music Name: %s\n", music3->name);
    printf("Music Duration: %d\n", music3->duration);
    printf("Music Genre: %d\n", music3->genre);
    return 0;
}