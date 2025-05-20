//FormAI DATASET v1.0 Category: Music Library Management System ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char title[50];
    char artist[50];
    int year;
    int rating;
} Music;

void add_song(Music *library, int index); //function prototype
void print_library(Music *library, int size); //function prototype
void sort_library(Music *library, int size); //function prototype
int search_title(Music *library, int size, char search_title[50]); //function prototype
void delete_song(Music *library, int *size, int index); //function prototype

int main(){
    int size=0, option=0, index=0;
    char search_title[50];
    Music *library = (Music*) malloc(sizeof(Music)); //dynamically allocate memory for the music library
    
    while(option!=5){
        printf("\n**********C Music Library Management System**********\n");
        printf("1. Add Song\n2. Print Library\n3. Sort Library\n4. Delete a Song\n5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        
        switch(option){
            case 1:
                add_song(library, size);
                size++;
                break;
            case 2:
                print_library(library, size);
                break;
            case 3:
                sort_library(library, size);
                break;
            case 4:
                printf("Enter the index of the song you want to delete: ");
                scanf("%d", &index);
                delete_song(library, &size, index-1);
                break;
            case 5:
                printf("Thank you and have a nice day!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }
    
    free(library); //free dynamically allocated memory
    
    return 0;
}

void add_song(Music *library, int index){
    printf("Enter the title of the song: ");
    scanf("%s", library[index].title);
    printf("Enter the artist of the song: ");
    scanf("%s", library[index].artist);
    printf("Enter the year of the song: ");
    scanf("%d", &library[index].year);
    printf("Enter the rating of the song (1-5): ");
    scanf("%d", &library[index].rating);
}

void print_library(Music *library, int size){
    printf("\n**********Music Library**********\n");
    printf("|%-20s|%-20s|%-10s|%-10s|\n", "Title", "Artist", "Year", "Rating");
    for(int i=0;i<size;i++){
        printf("|%-20s|%-20s|%-10d|%-10d|\n", library[i].title, library[i].artist, library[i].year, library[i].rating);
    }
}

void sort_library(Music *library, int size){
    Music temp;
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(strcmp(library[j].title, library[j+1].title)>0){
                temp=library[j];
                library[j]=library[j+1];
                library[j+1]=temp;
            }
        }
    }
    printf("Library sorted by title.\n");
}

int search_title(Music *library, int size, char search_title[50]){
    int found=0, index=0;
    for(int i=0;i<size;i++){
        if(strcmp(library[i].title, search_title)==0){
            found=1;
            index=i;
        }
    }
    if(found==0){
        printf("Song not found.\n");
        return -1;
    }
    else{
        return index;
    }
}

void delete_song(Music *library, int *size, int index){
    if(index<0 || index>=*size){ //check index validity
        printf("Invalid index, please try again.\n");
        return;
    }
    for(int i=index;i<*size-1;i++){
        library[i]=library[i+1];
    }
    *size=*size-1;
    printf("Song deleted.\n");
}