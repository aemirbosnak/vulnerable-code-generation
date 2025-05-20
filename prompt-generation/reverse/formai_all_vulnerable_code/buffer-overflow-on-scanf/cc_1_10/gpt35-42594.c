//FormAI DATASET v1.0 Category: Music Library Management System ; Style: recursive
#include<stdio.h>
#include<string.h>
#define MAX_SONGS 10

struct song {
    char title[20];
    char artist[20];
    int year;
};

struct song library[MAX_SONGS];

void display_menu() {
    printf("\n1. Add song\n");
    printf("2. List all songs\n");
    printf("3. Search for a song\n");
    printf("4. Delete a song\n");
    printf("5. Exit program\n");
    printf("\nEnter your choice: ");
}

void add_song() {
    int n = 0;
    while(strlen(library[n].title) > 0 && n < MAX_SONGS) {
        n++;
    }
    if(n == MAX_SONGS) {
        printf("\nLibrary is full. Cannot add more songs.\n");
        return;
    }
    printf("\nEnter details of song %d\n", n+1);
    printf("Enter title: ");
    fgets(library[n].title, sizeof(library[n].title), stdin);
    printf("Enter artist: ");
    fgets(library[n].artist, sizeof(library[n].artist), stdin);
    printf("Enter year: ");
    scanf("%d", &library[n].year);
    getchar();
    printf("\nSong added successfully!\n");
}

void list_songs(int n) {
    if(n == MAX_SONGS) {
        return;
    }
    if(strlen(library[n].title) > 0) {
        printf("\n%d. %s by %s (%d)", n+1, library[n].title, library[n].artist, library[n].year);
    }
    list_songs(n+1);
}

void search_song() {
    char title[20];
    int n;
    printf("\nEnter title of the song to search: ");
    fgets(title, sizeof(title), stdin);
    for(n=0; n < MAX_SONGS; n++) {
        if(strcmp(library[n].title, title) == 0) {
            printf("\n%d. %s by %s (%d)", n+1, library[n].title, library[n].artist, library[n].year);
            return;
        }
    }
    printf("\nSong not found!\n");
}

void delete_song() {
    int n;
    printf("\nEnter the index of the song to delete: ");
    scanf("%d", &n);
    if(n < 1 || n > MAX_SONGS || strlen(library[n-1].title) == 0) {
        printf("\nInvalid index!\n");
        return;
    }
    library[n-1].title[0] = '\0';
    library[n-1].artist[0] = '\0';
    library[n-1].year = 0;
    printf("\nSong deleted successfully!\n");
}

int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                add_song();
                break;
            case 2:
                list_songs(0);
                break;
            case 3:
                search_song();
                break;
            case 4:
                delete_song();
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }while(choice != 5);

    return 0;
}