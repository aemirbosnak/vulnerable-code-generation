//FormAI DATASET v1.0 Category: Music Library Management System ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// structure for holding information about music albums
struct album {
    char name[50];
    char artist[50];
    int year;
    char genre[20];
    int rating;
};

// function to add a new album to the library
void add_album(struct album* library, int num_albums) {
    printf("Enter the album name: ");
    fgets(library[num_albums].name, 50, stdin);
    printf("Enter the artist name: ");
    fgets(library[num_albums].artist, 50, stdin);
    printf("Enter the year of release: ");
    scanf("%d", &library[num_albums].year);
    fflush(stdin);
    printf("Enter the genre: ");
    fgets(library[num_albums].genre, 20, stdin);
    printf("Enter the rating (out of 10): ");
    scanf("%d", &library[num_albums].rating);
    fflush(stdin);
    printf("Album \"%s\" added successfully to the library!\n", library[num_albums].name);
}

// function to search for an album by its name and display its information
void search_album(struct album* library, int num_albums) {
    char search[50];
    int found = 0;
    printf("Enter the name of the album to search for: ");
    fgets(search, 50, stdin);
    for(int i=0; i<num_albums; i++) {
        if(strcmp(search, library[i].name) == 0) {
            found = 1;
            printf("Album Information:\n");
            printf("Name: %s", library[i].name);
            printf("Artist: %s", library[i].artist);
            printf("Year of Release: %d\n", library[i].year);
            printf("Genre: %s", library[i].genre);
            printf("Rating: %d/10\n", library[i].rating);
        }
    }
    if(!found) {
        printf("Album \"%s\" not found in the library!\n", search);
    }
}

int main() {
    int option, num_albums=0;
    struct album* library = (struct album*)malloc(100*sizeof(struct album));
    while(1) {
        printf("\n");
        printf("C Music Library Management System\n");
        printf("---------------------------------\n");
        printf("Enter 1 to add a new album\n");
        printf("Enter 2 to search for an album\n");
        printf("Enter 3 to exit the program\n\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        fflush(stdin);
        switch(option) {
            case 1:
                add_album(library, num_albums);
                num_albums++;
                break;
            case 2:
                search_album(library, num_albums);
                break;
            case 3:
                printf("\nGoodbye! Thank you for using the C Music Library Management System.\n\n");
                free(library);
                return 0;
            default:
                printf("\nInvalid option selected!\n");
        }
    }
    return 0;
}