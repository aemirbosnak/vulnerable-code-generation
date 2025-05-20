//FormAI DATASET v1.0 Category: Music Library Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char artist[50];
    char title[50];
    char album[50];
    int year;
};

void display_menu() {
    printf("Welcome to Music Library Management System!\n");
    printf("1. Add Song\n");
    printf("2. Search Song\n");
    printf("3. Delete Song\n");
    printf("4. Display Songs\n");
    printf("5. Exit\n");
}

int main() {

    int choice;
    struct song *library;
    int size = 0;
    int index = 0;

    do {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                size++;
                library = realloc(library, size * sizeof(struct song));

                printf("\nEnter Song Artist: ");
                scanf("%s", library[index].artist);

                printf("Enter Song Title: ");
                scanf("%s", library[index].title);

                printf("Enter Album Name: ");
                scanf("%s", library[index].album);

                printf("Enter Year of Release: ");
                scanf("%d", &library[index].year);

                index++;
                printf("\nSong added successfully!\n");
                break;

            case 2:
                if(size == 0) {
                    printf("\nNo songs found in the Library!\n");
                    break;
                }

                char search[50];
                int found = 0;
                printf("\nEnter the Song Artist or Title to search for: ");
                scanf("%s", search);

                for(int i=0; i<size; i++) {
                    if(strcmp(library[i].artist, search) == 0 || strcmp(library[i].title, search) == 0) {
                        printf("\nSong found at index %d:\n", i+1);
                        printf("Artist: %s\n", library[i].artist);
                        printf("Title: %s\n", library[i].title);
                        printf("Album: %s\n", library[i].album);
                        printf("Year: %d\n", library[i].year);
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("\nSong not found in the Library!\n");
                }
                break;

            case 3:
                if(size == 0) {
                    printf("\nNo songs found in the Library!\n");
                    break;
                }

                int remove_index;
                printf("\nEnter the index of the Song to be removed: ");
                scanf("%d", &remove_index);

                if(remove_index > size || remove_index < 1) {
                    printf("\nInvalid index! Please try again.\n");
                    break;
                }

                for(int i=remove_index-1; i<size-1; i++) {
                    library[i] = library[i+1];
                }

                size--;
                library = realloc(library, size * sizeof(struct song));
                printf("\nSong removed successfully!\n");
                break;

            case 4:
                if(size == 0) {
                    printf("\nNo songs found in the Library!\n");
                    break;
                }

                for(int i=0; i<size; i++) {
                    printf("\nSong %d:\n", i+1);
                    printf("Artist: %s\n", library[i].artist);
                    printf("Title: %s\n", library[i].title);
                    printf("Album: %s\n", library[i].album);
                    printf("Year: %d\n", library[i].year);
                }
                break;

            case 5:
                printf("\nThank you for using Music Library Management System!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please choose again.\n");
        }
    } while(choice != 5);

    free(library);
    return 0;
}