//FormAI DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining Music structure
struct Music {
    char title[50];
    char album[50];
    char artist[50];
    int releaseYear;
};

int main() {
    int option = -1;
    int musicCount = 0;
    int i;
    struct Music musicArr[100];

    printf("Welcome to the Music Library Management System!\n");

    while(option != 0) {

        //Menu
        printf("\n#############################\n");
        printf("Please select an option:\n");
        printf("1. Add new music\n");
        printf("2. View all music\n");
        printf("3. Search for music\n");
        printf("0. Exit\n");
        printf("#############################\n");

        scanf("%d", &option);
        getchar();

        switch(option) {

            //Add new music to the library
            case 1:
                printf("\nEnter the music title: ");
                fgets(musicArr[musicCount].title, 50, stdin);

                printf("Enter the album name: ");
                fgets(musicArr[musicCount].album, 50, stdin);

                printf("Enter the artist name: ");
                fgets(musicArr[musicCount].artist, 50, stdin);

                printf("Enter the release year: ");
                scanf("%d", &musicArr[musicCount].releaseYear);
                getchar();

                printf("\nNew music added to the library successfully!\n");

                musicCount++;
                break;

            //View all music in the library
            case 2:
                if(musicCount == 0) {
                    printf("\nThere is currently no music in the library.\n");
                }
                else {
                    printf("\nAll music in the library:\n");
                    for(i=0; i<musicCount; i++) {
                        printf("Title: %sAlbum: %sArtist: %sRelease Year: %d\n", musicArr[i].title, musicArr[i].album, musicArr[i].artist, musicArr[i].releaseYear);
                    }
                }
                break;
            
            //Search for music in the library
            case 3:
                if(musicCount == 0) {
                    printf("\nThere is currently no music in the library.\n");
                }
                else {
                    char searchTitle[50];
                    int found = 0;

                    printf("\nEnter the title of the music you want to search for: ");
                    fgets(searchTitle, 50, stdin);

                    for(i=0; i<musicCount; i++) {
                        if(strstr(musicArr[i].title, searchTitle) != NULL) {
                            printf("\nSearch results:\n");
                            printf("Title: %sAlbum: %sArtist: %sRelease Year: %d\n", musicArr[i].title, musicArr[i].album, musicArr[i].artist, musicArr[i].releaseYear);
                            found = 1;
                        }
                    }

                    if(found == 0) {
                        printf("\nThe search did not match any results.\n");
                    }
                }
                break;

            //Exit the program
            case 0:
                printf("\nThank you for using the Music Library Management System!\n");
                break;

            //Invalid option
            default:
                printf("\nInvalid option selected. Please try again.\n");
                break;
        }
    }

    return 0;
}