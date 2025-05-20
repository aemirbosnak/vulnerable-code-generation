//FormAI DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SONGS 1000

struct song {
    char title[50];
    char artist[50];
    int year;
    char genre[20];
    float duration;
};

int menu(){
    int choice;
    printf("\n\nWelcome to the Music Library Management System\n");
    printf("1. Add a song\n");
    printf("2. Display all songs\n");
    printf("3. Search for a song\n");
    printf("4. Edit a song\n");
    printf("5. Remove a song\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void display(struct song arr[], int length){
    if(length == 0){
        printf("\n\nThe music library is empty\n\n");
        return;
    }
    printf("\n\n%-20s%-20s%-20s%-20s%-20s\n", "Title", "Artist", "Year", "Genre", "Duration");
    for(int i=0; i<length; i++){
        printf("%-20s%-20s%-20d%-20s%-20.2f\n", arr[i].title, arr[i].artist, arr[i].year, arr[i].genre, arr[i].duration);
    }
}

void search(struct song arr[], int length){
    char title[50];
    printf("Enter the title of the song: ");
    scanf("%s", title);
    for(int i=0; i<length; i++){
        if(strcmp(arr[i].title, title)==0){
            printf("\n\n%-20s%-20s%-20s%-20s%-20s\n", "Title", "Artist", "Year", "Genre", "Duration");
            printf("%-20s%-20s%-20d%-20s%-20.2f\n\n", arr[i].title, arr[i].artist, arr[i].year, arr[i].genre, arr[i].duration);
            return;
        }
    }
    printf("\n\nThe song is not found\n\n");
}

int add(struct song arr[], int length){
    if(length == MAX_SONGS){
        printf("\n\nThere is no more space to add more songs\n\n");
        return length;
    }
    printf("Enter the title of the song: ");
    scanf("%s", arr[length].title);
    printf("Enter the artist of the song: ");
    scanf("%s", arr[length].artist);
    printf("Enter the year of the song: ");
    scanf("%d", &arr[length].year);
    printf("Enter the genre of the song: ");
    scanf("%s", arr[length].genre);
    printf("Enter the duration of the song: ");
    scanf("%f", &arr[length].duration);
    length++;
    printf("\n\nThe song has been added successfully!\n\n");
    return length;
}

int edit(struct song arr[], int length){
    char title[50];
    printf("Enter the title of the song to edit: ");
    scanf("%s", title);
    for(int i=0; i<length; i++){
        if(strcmp(arr[i].title, title)==0){
            printf("Enter the new title of the song (or enter '0' to skip): ");
            char new_title[50];
            scanf("%s", new_title);
            if(strcmp(new_title, "0")!=0)
                strcpy(arr[i].title, new_title);
            printf("Enter the new artist of the song (or enter '0' to skip): ");
            char new_artist[50];
            scanf("%s", new_artist);
            if(strcmp(new_artist, "0")!=0)
                strcpy(arr[i].artist, new_artist);
            printf("Enter the new year of the song (or enter '0' to skip): ");
            int new_year;
            scanf("%d", &new_year);
            if(new_year!=0)
                arr[i].year = new_year;
            printf("Enter the new genre of the song (or enter '0' to skip): ");
            char new_genre[20];
            scanf("%s", new_genre);
            if(strcmp(new_genre, "0")!=0)
                strcpy(arr[i].genre, new_genre);
            printf("Enter the new duration of the song (or enter '0' to skip): ");
            float new_duration;
            scanf("%f", &new_duration);
            if(new_duration!=0)
                arr[i].duration = new_duration;
            printf("\n\nThe song has been edited successfully!\n\n");
            return 1;
        }
    }
    printf("\n\nThe song is not found\n\n");
    return 0;
}

int remove_song(struct song arr[], int length){
    char title[50];
    printf("Enter the title of the song to remove: ");
    scanf("%s", title);
    for(int i=0; i<length; i++){
        if(strcmp(arr[i].title, title)==0){
            for(int j=i; j<length-1; j++){
                arr[j] = arr[j+1];
            }
            length--;
            printf("\n\nThe song has been removed successfully!\n\n");
            return length;
        }
    }
    printf("\n\nThe song is not found\n\n");
    return length;
}

int main(){
    struct song music_library[MAX_SONGS];
    int length = 0;
    int choice;
    while(1){
        choice = menu();
        switch(choice){
            case 1:
                length = add(music_library, length);
                break;
            case 2:
                display(music_library, length);
                break;
            case 3:
                search(music_library, length);
                break;
            case 4:
                edit(music_library, length);
                break;
            case 5:
                length = remove_song(music_library, length);
                break;
            case 6:
                printf("\n\nThank you for using this program\n\n");
                exit(0);
            default:
                printf("\n\nInvalid choice\n\n");
        }
    }
    return 0;
}