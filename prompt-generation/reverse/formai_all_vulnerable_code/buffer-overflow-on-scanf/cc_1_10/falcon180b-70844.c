//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>

struct Music {
    char title[50];
    char artist[50];
    char genre[20];
    int year;
};

void addMusic(struct Music *music, int n) {
    printf("\nEnter details for music %d:\n", n+1);
    printf("Title: ");
    scanf("%s", music[n].title);
    printf("Artist: ");
    scanf("%s", music[n].artist);
    printf("Genre: ");
    scanf("%s", music[n].genre);
    printf("Year: ");
    scanf("%d", &music[n].year);
}

void displayMusic(struct Music *music, int n) {
    printf("\nMusic %d:\n", n+1);
    printf("Title: %s\n", music[n].title);
    printf("Artist: %s\n", music[n].artist);
    printf("Genre: %s\n", music[n].genre);
    printf("Year: %d\n\n", music[n].year);
}

void searchMusic(struct Music *music, int n, char *query) {
    int i;
    for(i=0; i<n; i++) {
        if(strstr(music[i].title, query) || strstr(music[i].artist, query) || strstr(music[i].genre, query)) {
            displayMusic(&music[i], i);
        }
    }
}

int main() {
    int n, i;
    printf("\nEnter number of music: ");
    scanf("%d", &n);
    struct Music music[n];
    printf("\nEnter details for music:\n");
    for(i=0; i<n; i++) {
        addMusic(music, i);
    }
    char query[50];
    while(1) {
        printf("\nEnter search query: ");
        scanf("%s", query);
        searchMusic(music, n, query);
    }
    return 0;
}