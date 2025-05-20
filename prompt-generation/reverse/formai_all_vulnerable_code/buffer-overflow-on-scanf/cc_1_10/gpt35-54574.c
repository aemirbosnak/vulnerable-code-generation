//FormAI DATASET v1.0 Category: Music Library Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define max size of array and buffer size
#define MAX 100
#define BUFFER_SIZE 100

//define struct for storing song details
struct song {
  char title[MAX];
  char artist[MAX];
  char genre[MAX];
  int year;
  float duration;
};

//function prototypes
void displayMenu();
void addSong(struct song[], int*);
void displaySongs(struct song[], int);
void deleteSong(struct song[], int*);
void searchSongs(struct song[], int);
void saveToFile(struct song[], int);

int main() {
    int choice;
    struct song music_lib[MAX];
    int count = 0;

    while(1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
         
        switch(choice) {
            case 1:
                addSong(music_lib, &count);
                break;
            case 2:
                displaySongs(music_lib, count);
                break;
            case 3:
                deleteSong(music_lib, &count);
                break;
            case 4:
                searchSongs(music_lib, count);
                break;
            case 5:
                saveToFile(music_lib, count);
                break;
            case 6:
                exit(0); //quit program
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n-----------------------\n");
    printf("- Music Library System -\n");
    printf("-----------------------\n\n");
    printf("1. Add Song\n");
    printf("2. Display All Songs\n");
    printf("3. Delete a Song\n");
    printf("4. Search for a Song\n");
    printf("5. Save Library to File\n");
    printf("6. Exit\n\n");
}

void addSong(struct song arr[], int *cnt) {
    if(*cnt == MAX) {
        printf("\nCannot add more songs. Library is full.\n");
        return;
    }
    printf("\n------Adding Song------\n");
    printf("Enter the song title: ");
    scanf("%s", arr[*cnt].title);
    printf("Enter the artist name: ");
    scanf("%s", arr[*cnt].artist);
    printf("Enter the genre of the song: ");
    scanf("%s", arr[*cnt].genre);
    printf("Enter the year the song was released: ");
    scanf("%d", &arr[*cnt].year);
    printf("Enter the song duration in minutes: ");
    scanf("%f", &arr[*cnt].duration);

    (*cnt)++;
    printf("\nSong Successfully Added to Library!\n");
}

void displaySongs(struct song arr[], int cnt) {
    if(cnt == 0) {
        printf("\nLibrary is empty. No songs to display.\n");
        return;
    }
    printf("\n------Displaying All Songs------\n");
    for(int i = 0; i < cnt; i++) {
        printf("\nSong %d\n", i+1);
        printf("Title: %s\n", arr[i].title);
        printf("Artist: %s\n", arr[i].artist);
        printf("Genre: %s\n", arr[i].genre);
        printf("Year: %d\n", arr[i].year);
        printf("Duration: %.2f minutes\n", arr[i].duration);
    }
}

void deleteSong(struct song arr[], int *cnt) {
    if(*cnt == 0) {
        printf("\nLibrary is empty. No songs to delete.\n");
        return;
    }
    char title[BUFFER_SIZE];
    int found = 0;
    printf("\n------Deleting a Song------\n");
    printf("Enter the title of the song to delete: ");
    scanf("%s", title);
    for(int i = 0; i < *cnt; i++) {
        if(strcmp(title, arr[i].title) == 0) {
            found = 1;
            for(int j = i; j < *cnt - 1; j++) {
                arr[j] = arr[j+1];
            }
            (*cnt)--;
            printf("\nSong Successfully Deleted!\n");
            break;
        }
    }
    if(!found) {
        printf("\nThe song \"%s\" was not found in the library.\n", title);
    }
}

void searchSongs(struct song arr[], int cnt) {
    if(cnt == 0) {
        printf("\nLibrary is empty. No songs to search.\n");
        return;
    }
    int choice;
    char input[BUFFER_SIZE];
    int found = 0;
    printf("\n------Searching for a Song------\n");
    printf("Search by:\n");
    printf("1. Title\n");
    printf("2. Artist\n");
    printf("3. Genre\n");
    printf("4. Year\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\nEnter the search keyword: ");
    scanf("%s", input);

    switch(choice) {
        case 1: //search by title
            for(int i = 0; i < cnt; i++) {
                if(strcmp(input, arr[i].title) == 0) {
                    found = 1;
                    printf("\nSong %d\n", i+1);
                    printf("Title: %s\n", arr[i].title);
                    printf("Artist: %s\n", arr[i].artist);
                    printf("Genre: %s\n", arr[i].genre);
                    printf("Year: %d\n", arr[i].year);
                    printf("Duration: %.2f minutes\n", arr[i].duration);
                }
            }
            break;
        case 2: //search by artist
            for(int i = 0; i < cnt; i++) {
                if(strcmp(input, arr[i].artist) == 0) {
                    found = 1;
                    printf("\nSong %d\n", i+1);
                    printf("Title: %s\n", arr[i].title);
                    printf("Artist: %s\n", arr[i].artist);
                    printf("Genre: %s\n", arr[i].genre);
                    printf("Year: %d\n", arr[i].year);
                    printf("Duration: %.2f minutes\n", arr[i].duration);
                }
            }
            break;
        case 3: //search by genre
            for(int i = 0; i < cnt; i++) {
                if(strcmp(input, arr[i].genre) == 0) {
                    found = 1;
                    printf("\nSong %d\n", i+1);
                    printf("Title: %s\n", arr[i].title);
                    printf("Artist: %s\n", arr[i].artist);
                    printf("Genre: %s\n", arr[i].genre);
                    printf("Year: %d\n", arr[i].year);
                    printf("Duration: %.2f minutes\n", arr[i].duration);
                }
            }
            break;
        case 4: //search by year
            for(int i = 0; i < cnt; i++) {
                if(arr[i].year == atoi(input)) {
                    found = 1;
                    printf("\nSong %d\n", i+1);
                    printf("Title: %s\n", arr[i].title);
                    printf("Artist: %s\n", arr[i].artist);
                    printf("Genre: %s\n", arr[i].genre);
                    printf("Year: %d\n", arr[i].year);
                    printf("Duration: %.2f minutes\n", arr[i].duration);
                }
            }
            break;
        default:
            printf("\nInvalid choice. Try again.\n");
    }
    if(!found) {
        printf("\nNo songs found with %s \"%s\".\n", (choice == 4) ? "year" : 
        ((choice == 1) ? "title" : ((choice == 2) ? "artist" : "genre")), input);
    }
}

void saveToFile(struct song arr[], int cnt) {
    if(cnt == 0) {
        printf("\nLibrary is empty. Cannot save to file.\n");
        return;
    }
    FILE *fptr;
    char filename[BUFFER_SIZE];
    printf("\n------Saving Library to File------\n");
    printf("Enter the filename: ");
    scanf("%s", filename);
    fptr = fopen(filename, "w");
    if(fptr == NULL) {
        printf("\nError opening file. Cannot save to file.\n");
        return;
    }
    for(int i = 0; i < cnt; i++) {
        fprintf(fptr, "%s\n", arr[i].title);
        fprintf(fptr, "%s\n", arr[i].artist);
        fprintf(fptr, "%s\n", arr[i].genre);
        fprintf(fptr, "%d\n", arr[i].year);
        fprintf(fptr, "%.2f\n", arr[i].duration);
    }
    fclose(fptr);
    printf("\nLibrary Successfully Saved to File!\n");
}