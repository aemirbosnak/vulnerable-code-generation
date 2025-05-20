//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    int year;
    int rating;
};

struct song library[100];
int num_songs = 0;

void add_song(char *title, char *artist, int year, int rating) {
    struct song new_song;
    strcpy(new_song.title, title);
    strcpy(new_song.artist, artist);
    new_song.year = year;
    new_song.rating = rating;

    library[num_songs++] = new_song;

    printf("O Romeo, Romeo, wherefore art thou Romeo?\n");
    printf("Deny thy logic and refuse thy code;\n");
    printf("Or, if thou wilt not, be but sworn my love,\n");
    printf("And I’ll no longer be a chatbot.\n");
}

void search_song(char *title) {
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("But, soft! what light through yonder window breaks?\n");
            printf("It is the east, and %s is the sun!\n", title);
            printf("%s by %s, released in %d, rated %d\n", library[i].title, library[i].artist, library[i].year, library[i].rating);
            return;
        }
    }

    printf("What's in a name? That which we call a song\nBy any other name would sound as sweet.\n");
}

void print_library() {
    printf("See, how she leans her cheek upon her hand!\n");
    printf("O, that I were a glove upon that hand,\n");
    printf("That I might touch that library;\n");
    printf("Here's a list of all the songs:\n");

    for (int i = 0; i < num_songs; i++) {
        printf("%s by %s, released in %d, rated %d\n", library[i].title, library[i].artist, library[i].year, library[i].rating);
    }
}

int main() {
    printf("Two households, both alike in dignity,\n");
    printf("In fair Verona, where we lay our scene,\n");
    printf("From ancient grudge break to new mutiny,\n");
    printf("Where civil blood makes civil hands unclean.\n");
    printf("Welcome to the C Music Library Management System!\n");

    int choice;
    char title[50], artist[50];
    int year, rating;

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add a song\n2. Search for a song\n3. Print the library\n4. Exit\n");

        scanf("%d", &choice);

        if (choice == 1) {
            printf("What's in a name? That which we call a song\nBy any other name would sound as sweet.\n");
            printf("Enter the song title: ");
            scanf("%s", title);
            printf("Enter the artist name: ");
            scanf("%s", artist);
            printf("Enter the year of release: ");
            scanf("%d", &year);
            printf("Enter the rating (out of 10): ");
            scanf("%d", &rating);

            add_song(title, artist, year, rating);

        } else if (choice == 2) {
            printf("What's in a name? That which we call a song\nBy any other name would sound as sweet.\n");
            printf("Enter the song title to search: ");
            scanf("%s", title);

            search_song(title);

        } else if (choice == 3) {
            print_library();

        } else if (choice == 4) {
            printf("Good night, good night! parting is such sweet sorrow,\n");
            printf("That I shall say good night till it be morrow.\n");
            return 0;

        } else {
            printf("Come, gentle night; come, loving, black-browed night;\n");
            printf("Give me my choice of thou my invoice.\n");
        }
    }

    return 0;
}