//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSICS 100
#define MAX_NAME 100
#define MAX_ARTIST 100

typedef struct Music {
    char name[MAX_NAME];
    char artist[MAX_ARTIST];
    int duration;
} Music;

Music library[MAX_MUSICS];
int num_musics = 0;

void add_music() {
    printf("Enter music name: ");
    scanf("%s", library[num_musics].name);

    printf("Enter music artist: ");
    scanf("%s", library[num_musics].artist);

    printf("Enter music duration in seconds: ");
    scanf("%d", &library[num_musics].duration);

    num_musics++;
}

void display_library() {
    printf("\nMusic Library:\n");
    for (int i = 0; i < num_musics; i++) {
        printf("%d. %s by %s (%d seconds)\n", i+1, library[i].name, library[i].artist, library[i].duration);
    }
}

void search_music() {
    char search_name[MAX_NAME];
    printf("Enter music name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_musics; i++) {
        if (strcmp(library[i].name, search_name) == 0) {
            printf("\nMusic found:\n");
            printf("%s by %s (%d seconds)\n", library[i].name, library[i].artist, library[i].duration);
        }
    }
}

int main() {
    int choice;

    do {
        printf("\nMusic Library Management System\n");
        printf("1. Add music\n2. Display library\n3. Search music\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_music();
                break;
            case 2:
                display_library();
                break;
            case 3:
                search_music();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}