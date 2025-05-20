//FormAI DATASET v1.0 Category: Music Library Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct song{
    int id;
    char name[MAX_SIZE];
    char artist[MAX_SIZE];
    char album[MAX_SIZE];
    float duration;
};

struct song_library{
    struct song arr[MAX_SIZE];
    int count;
};

struct song_library init_library(){
    struct song_library slib;
    slib.count = 0;
    return slib;
}

void add_song(struct song_library* slib){
    struct song s;
    printf("Enter Song ID: ");
    scanf("%d", &s.id);
    printf("Enter Song Name: ");
    scanf("%s", s.name);
    printf("Enter Artist Name: ");
    scanf("%s", s.artist);
    printf("Enter Album Name: ");
    scanf("%s", s.album);
    printf("Enter Song Duration (in seconds): ");
    scanf("%f", &s.duration);
    slib->arr[slib->count++] = s;
    printf("Song Added Successfully!\n\n");
}

void print_library(struct song_library slib){
    printf("\n--------------------------------------------------\n");
    printf("Song ID\tName\t\tArtist\t\tAlbum\t\tDuration\n");
    printf("--------------------------------------------------\n");
    for(int i=0; i<slib.count; i++){
        printf("%d\t%-15s\t%-15s\t%-15s\t%.2f\n", slib.arr[i].id, slib.arr[i].name, slib.arr[i].artist, slib.arr[i].album, slib.arr[i].duration);
    }
    printf("--------------------------------------------------\n\n");
}

void search_song(struct song_library slib){
    int id;
    printf("Enter Song ID to Search: ");
    scanf("%d", &id);
    for(int i=0; i<slib.count; i++){
        if(slib.arr[i].id == id){
            printf("Song Found!\n");
            printf("Song ID: %d\n", slib.arr[i].id);
            printf("Song Name: %s\n", slib.arr[i].name);
            printf("Artist Name: %s\n", slib.arr[i].artist);
            printf("Album Name: %s\n", slib.arr[i].album);
            printf("Song Duration (in seconds): %.2f\n\n", slib.arr[i].duration);
            return;
        }
    }
    printf("Song with ID %d not found!\n\n", id);
}

void delete_song(struct song_library* slib){
    int id;
    printf("Enter Song ID to delete: ");
    scanf("%d", &id);
    for(int i=0; i<slib->count; i++){
        if(slib->arr[i].id == id){
            for(int j=i+1; j<slib->count; j++){
                slib->arr[j-1] = slib->arr[j];
            }
            slib->count--;
            printf("Song with ID %d deleted successfully!\n\n", id);
            return;
        }
    }
    printf("Song with ID %d not found!\n\n", id);
}

void write_to_file(struct song_library slib){
    FILE *fp;
    fp = fopen("songs.txt", "w");
    for(int i=0; i<slib.count; i++){
        fprintf(fp, "%d;%s;%s;%s;%.2f\n", slib.arr[i].id, slib.arr[i].name, slib.arr[i].artist, slib.arr[i].album, slib.arr[i].duration);
    }
    fclose(fp);
    printf("Library written to file successfully!\n\n");
}

struct song_library read_from_file(){
    struct song_library slib;
    slib.count = 0;
    FILE *fp;
    fp = fopen("songs.txt", "r");
    if(fp == NULL){
        printf("Error opening file!\n\n");
        return slib;
    }
    printf("Reading songs from file...\n");
    char line[MAX_SIZE];
    while(fgets(line, MAX_SIZE, fp) != NULL){
        struct song s;
        char *token = strtok(line, ";");
        s.id = atoi(token);
        strcpy(s.name, strtok(NULL, ";"));
        strcpy(s.artist, strtok(NULL, ";"));
        strcpy(s.album, strtok(NULL, ";"));
        s.duration = atof(strtok(NULL, ";"));
        slib.arr[slib.count++] = s;
    }
    fclose(fp);
    printf("Songs read successfully from file!\n\n");
    return slib;
}

int main(){
    struct song_library slib = init_library();
    int choice;
    do{
        printf("Music Library Management System\n");
        printf("-------------------------------\n");
        printf("1. Add Song\n");
        printf("2. Print Library\n");
        printf("3. Search Song\n");
        printf("4. Delete Song\n");
        printf("5. Write to File\n");
        printf("6. Read from File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1: add_song(&slib); break;
            case 2: print_library(slib); break;
            case 3: search_song(slib); break;
            case 4: delete_song(&slib); break;
            case 5: write_to_file(slib); break;
            case 6: slib = read_from_file(); break;
            case 7: exit(0);
            default: printf("Invalid Choice!\n");
        }
    } while(1);
    return 0;
}