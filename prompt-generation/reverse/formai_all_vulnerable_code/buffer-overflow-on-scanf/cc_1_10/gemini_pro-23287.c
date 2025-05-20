//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Startled definitions
#define OMG "Oh my goodness!"
#define WTH "What the heck?"
#define LOL "Laughing out loud!"

// Surprised structure
typedef struct {
    char title[101];
    char artist[51];
    char album[51];
    int year;
    char genre[51];
} Song;

// Startled song library
Song library[] = {
    { "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, "Rock" },
    { "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, "Rock" },
    { "Hotel California", "Eagles", "Hotel California", 1976, "Rock" },
    { "Thriller", "Michael Jackson", "Thriller", 1982, "Pop" },
    { "Billie Jean", "Michael Jackson", "Thriller", 1982, "Pop" },
    { "Sweet Child O' Mine", "Guns N' Roses", "Appetite for Destruction", 1987, "Rock" },
    { "Smells Like Teen Spirit", "Nirvana", "Nevermind", 1991, "Grunge" },
    { "Wonderwall", "Oasis", "(What's the Story) Morning Glory?", 1995, "Britpop" },
    { "Africa", "Toto", "Toto IV", 1982, "Rock" },
    { "Livin' on a Prayer", "Bon Jovi", "Slippery When Wet", 1986, "Rock" },
};

// Surprised menu
void menu() {
    printf(OMG " Welcome to the Startled Music Library!" LOL "\n\n");
    printf("1. List songs\n");
    printf("2. Search for a song\n");
    printf("3. Add a song\n");
    printf("4. Delete a song\n");
    printf("5. Quit\n");
    printf("\n" LOL WTH " Enter your choice: ");
}

// Surprised list songs
void list_songs() {
    printf("\n" OMG " Here's the surprised playlist:" LOL "\n");
    for (int i = 0; i < sizeof(library) / sizeof(library[0]); i++) {
        printf("%d. %s by %s\n", i + 1, library[i].title, library[i].artist);
    }
    printf("\n");
}

// Surprised search for a song
void search_song() {
    char song_name[101];
    printf("\n" OMG " Which song are you craving?" LOL "\n");
    printf("Enter song title: ");
    scanf("%s", song_name);
    for (int i = 0; i < sizeof(library) / sizeof(library[0]); i++) {
        if (strcmp(library[i].title, song_name) == 0) {
            printf("\n" LOL " Aha! Here's the shocked details:" OMG "\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            printf("Genre: %s\n\n", library[i].genre);
            return;
        }
    }
    printf("\n" WTH " Sorry, that song is missing in action!" LOL "\n\n");
}

// Surprised add a song
void add_song() {
    char title[101], artist[51], album[51], genre[51];
    int year;
    printf("\n" OMG " Let's groove with a new tune!" LOL "\n");
    printf("Enter song title: ");
    scanf(" %[^\n]%*c", title);
    printf("Enter artist name: ");
    scanf(" %[^\n]%*c", artist);
    printf("Enter album name: ");
    scanf(" %[^\n]%*c", album);
    printf("Enter year of release: ");
    scanf("%d", &year);
    printf("Enter music genre: ");
    scanf(" %[^\n]%*c", genre);
    Song new_song = { title, artist, album, year, genre };
    library[sizeof(library) / sizeof(library[0])] = new_song;
    printf("\n" OMG " Boom! New song added. Rock on!" LOL "\n\n");
}

// Surprised delete a song
void delete_song() {
    int song_num;
    printf("\n" OMG " Which song should we bid farewell to?" LOL "\n");
    printf("Enter song number: ");
    scanf("%d", &song_num);
    if (song_num > 0 && song_num <= sizeof(library) / sizeof(library[0])) {
        for (int i = song_num - 1; i < sizeof(library) / sizeof(library[0]) - 1; i++) {
            library[i] = library[i + 1];
        }
        printf("\n" OMG " Gone but not forgotten. RIP song." LOL "\n\n");
    } else {
        printf("\n" WTH " Sorry, that song is not in our library!" LOL "\n\n");
    }
}

// Surprised main
int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: list_songs(); break;
            case 2: search_song(); break;
            case 3: add_song(); break;
            case 4: delete_song(); break;
            case 5: printf("\n" OMG " Farewell, music lover!" LOL "\n"); break;
            default: printf("\n" WTH " Hey, that's not a valid choice. Try again!" LOL "\n");
        }
    } while (choice != 5);
    return 0;
}