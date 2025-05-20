//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SONGS 1000
#define MAX_LEN 255

typedef struct song{
    char name[MAX_LEN];
    char artist[MAX_LEN];
    int year;
    char genre[MAX_LEN];
    int duration;
} song;

song library[MAX_SONGS];
int num_songs = 0;

// function to add a song into the library
void add_song(){
    if(num_songs == MAX_SONGS){
        printf("Library is full, cannot add more songs!\n");
        return;
    }
    song new_song;
    printf("Enter the name of the song: ");
    getchar();
    fgets(new_song.name, MAX_LEN, stdin);
    new_song.name[strcspn(new_song.name, "\n")] = '\0'; // remove the newline character
    printf("Enter the name of the artist: ");
    fgets(new_song.artist, MAX_LEN, stdin);
    new_song.artist[strcspn(new_song.artist, "\n")] = '\0';
    printf("Enter the year of release: ");
    scanf("%d", &new_song.year);
    getchar();
    printf("Enter the genre of the song: ");
    fgets(new_song.genre, MAX_LEN, stdin);
    new_song.genre[strcspn(new_song.genre, "\n")] = '\0';
    printf("Enter the duration of the song in seconds: ");
    scanf("%d", &new_song.duration);
    library[num_songs++] = new_song;
    printf("Song added successfully!\n");
}

// function to search for a song by name
void search_song(){
    char search_name[MAX_LEN];
    printf("Enter the name of the song to search: ");
    getchar();
    fgets(search_name, MAX_LEN, stdin);
    search_name[strcspn(search_name, "\n")] = '\0'; // remove the newline character
    int match_found = 0;
    for(int i=0; i<num_songs; i++){
        if(strcmp(search_name, library[i].name) == 0){
            printf("Song found:\n");
            printf("Name: %s\n", library[i].name);
            printf("Artist: %s\n", library[i].artist);
            printf("Year: %d\n", library[i].year);
            printf("Genre: %s\n", library[i].genre);
            printf("Duration: %d seconds\n", library[i].duration);
            match_found = 1;
            break;
        }
    }
    if(!match_found){
        printf("Song not found.\n");
    }
}

// function to print all songs in the library
void print_library(){
    if(num_songs == 0){
        printf("Library is empty!\n");
        return;
    }
    printf("Song library:\n");
    for(int i=0; i<num_songs; i++){
        printf("Name: %s\n", library[i].name);
        printf("Artist: %s\n", library[i].artist);
        printf("Year: %d\n", library[i].year);
        printf("Genre: %s\n", library[i].genre);
        printf("Duration: %d seconds\n", library[i].duration);
        printf("-------------------------\n");
    }
}

// function to delete a song by name
void delete_song(){
    char delete_name[MAX_LEN];
    printf("Enter the name of the song to delete: ");
    getchar();
    fgets(delete_name, MAX_LEN, stdin);
    delete_name[strcspn(delete_name, "\n")] = '\0'; // remove the newline character
    int match_found = 0;
    for(int i=0; i<num_songs; i++){
        if(strcmp(delete_name, library[i].name) == 0){
            match_found = 1;
            for(int j=i+1; j<num_songs; j++){
                library[j-1] = library[j];
            }
            num_songs--;
            printf("Song deleted successfully!\n");
            break;
        }
    }
    if(!match_found){
        printf("Song not found.\n");
    }
}

// function to perform a case-insensitive search
void strlwr(char *str){
    for(int i=0; str[i]!='\0'; i++){
        str[i] = tolower(str[i]);
    }
}

// function to search for songs by genre
void search_genre(){
    char search_genre[MAX_LEN];
    printf("Enter the genre of the song to search: ");
    getchar();
    fgets(search_genre, MAX_LEN, stdin);
    search_genre[strcspn(search_genre, "\n")] = '\0'; // remove the newline character
    strlwr(search_genre); // converting the genre to lowercase
    int match_found = 0;
    for(int i=0; i<num_songs; i++){
        char song_genre[MAX_LEN];
        strcpy(song_genre, library[i].genre);
        strlwr(song_genre); // converting the song genre to lowercase
        if(strcmp(search_genre, song_genre) == 0){
            if(!match_found){
                printf("Songs found:\n");
            }
            printf("%d. %s (%s)\n", match_found+1, library[i].name, library[i].artist);
            match_found++;
        }
    }
    if(!match_found){
        printf("No songs found for the given genre.\n");
    }
}

// function to display the menu
void display_menu(){
    printf("\n");
    printf("*********************\n");
    printf("1. Add a song\n");
    printf("2. Search for a song\n");
    printf("3. Display library\n");
    printf("4. Delete a song\n");
    printf("5. Search for songs by genre\n");
    printf("6. Exit\n");
    printf("*********************\n");
    printf("\n");
}

int main(){
    int choice;
    do{
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_song();
                break;
            case 2:
                search_song();
                break;
            case 3:
                print_library();
                break;
            case 4:
                delete_song();
                break;
            case 5:
                search_genre();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }while(1);

    return 0;
}