//FormAI DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining structure for each music file
struct music_file {
    char title[50];
    char artist[50];
    char album[50];
    char genre[20];
    int year;
};

// Function to display all music files in the library
void display_all_files(struct music_file files[], int num_files) {
    printf("---------------------\n");
    printf("|      Music        |\n");
    printf("|     Library       |\n");
    printf("---------------------\n\n");
    printf("Total Music Files: %d\n", num_files);

    for(int i=0; i<num_files; i++) {
        printf("\nFile %d:\n", i+1);
        printf("Title: %s\n", files[i].title);
        printf("Artist: %s\n", files[i].artist);
        printf("Album: %s\n", files[i].album);
        printf("Genre: %s\n", files[i].genre);
        printf("Year: %d\n", files[i].year);
    }
}

// Function to add a new music file to the library
void add_new_file(struct music_file files[], int *num_files) {
    printf("\nEnter details of the new music file:\n");

    printf("Title: ");
    scanf("%s", files[*num_files].title);

    printf("Artist: ");
    scanf("%s", files[*num_files].artist);

    printf("Album: ");
    scanf("%s", files[*num_files].album);

    printf("Genre: ");
    scanf("%s", files[*num_files].genre);

    printf("Year: ");
    scanf("%d", &files[*num_files].year);

    printf("\nNew music file added!\n");
    *num_files = *num_files + 1;
}

// Function to search for music files based on title
void search_files(struct music_file files[], int num_files) {
    printf("\nEnter the title of the music file to be searched: ");
    char search_title[50];
    scanf("%s", search_title);

    printf("\nMusic Files matching the search criteria:\n");

    for(int i=0; i<num_files; i++) {
        if(strstr(files[i].title, search_title) != NULL) {
            printf("\nFile %d:\n", i+1);
            printf("Title: %s\n", files[i].title);
            printf("Artist: %s\n", files[i].artist);
            printf("Album: %s\n", files[i].album);
            printf("Genre: %s\n", files[i].genre);
            printf("Year: %d\n", files[i].year);
        }
    }
}

int main() {
    int num_files = 0; // Initializing the number of music files to 0
    struct music_file files[100]; // Assuming a total of 100 music files can be stored in the library

    int choice;

    do {
        printf("\n---------------------\n");
        printf("|      Music        |\n");
        printf("|     Library       |\n");
        printf("---------------------\n\n");

        printf("MENU:\n");
        printf("1. Display all music files\n");
        printf("2. Add a new music file\n");
        printf("3. Search for music files based on title\n");
        printf("4. Quit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display_all_files(files, num_files);
                break;
            case 2:
                add_new_file(files, &num_files);
                break;
            case 3:
                search_files(files, num_files);
                break;
            case 4:
                printf("\nThank you for using the Music Library Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
        }

    } while(1);

    return 0;
}