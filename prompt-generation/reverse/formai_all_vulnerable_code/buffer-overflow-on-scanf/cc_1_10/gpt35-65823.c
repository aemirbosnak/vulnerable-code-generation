//FormAI DATASET v1.0 Category: Music Library Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[100];
    char artist[100];
    char album[100];
    int year;
};

typedef struct Song Song;

struct Node {
    Song *data;
    struct Node *next;
};

typedef struct Node Node;

Node *head = NULL;
Node *tail = NULL;

void display_menu();
int get_choice();
Song *create_song(Song *song);
void display_songs();
void add_song();
void delete_song();
void search_song();
void save_songs();
void load_songs();

int main() {
    load_songs();
    int choice;
    do {
        display_menu();
        choice = get_choice();
        switch (choice) {
            case 1:
                display_songs();
                break;
            case 2:
                add_song();
                break;
            case 3:
                delete_song();
                break;
            case 4:
                search_song();
                break;
            case 5:
                save_songs();
                break;
            case 6:
                exit(0);
        }
    } while (choice != 6);
    return 0;
}

void display_menu() {
    printf("\n********** C MUSIC LIBRARY MANAGEMENT SYSTEM **********\n\n");
    printf("1. Display songs\n");
    printf("2. Add a song\n");
    printf("3. Delete a song\n");
    printf("4. Search for a song\n");
    printf("5. Save songs to file\n");
    printf("6. Exit\n");
    printf("\n*******************************************************\n");
}

int get_choice() {
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

Song *create_song(Song *song) {
    song = (Song *)malloc(sizeof(Song));
    printf("\nEnter song title: ");
    scanf("%s", &song->title);
    printf("Enter artist: ");
    scanf("%s", &song->artist);
    printf("Enter album: ");
    scanf("%s", &song->album);
    printf("Enter release year: ");
    scanf("%d", &song->year);
    return song;
}

void display_songs() {
    if (head == NULL) {
        printf("\nNo songs found!\n");
        return;
    }
    printf("\nTitle\t\tArtist\t\tAlbum\t\tYear\n");
    Node *current = head;
    while (current != NULL) {
        printf("%s\t\t%s\t\t%s\t\t%d\n", current->data->title, current->data->artist, current->data->album, current->data->year);
        current = current->next;
    }
}

void add_song() {
    Song *song = NULL;
    song = create_song(song);
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = song;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    printf("\nSong added successfully!\n");
}

void delete_song() {
    if (head == NULL) {
        printf("\nNo songs found!\n");
        return;
    }
    char title[100];
    printf("\nEnter title of the song to delete: ");
    scanf("%s", title);
    Node *current = head;
    Node *previous = NULL;
    while (current != NULL && strcmp(current->data->title, title) != 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("\nSong not found\n");
        return;
    }
    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    if (current == tail) {
        tail = previous;
    }
    free(current);
    printf("\nSong deleted successfully!\n");
}

void search_song() {
    if (head == NULL) {
        printf("\nNo songs found!\n");
        return;
    }
    char title[100];
    printf("\nEnter title of the song to search: ");
    scanf("%s", title);
    Node *current = head;
    while (current != NULL && strcmp(current->data->title, title) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        printf("\nSong not found\n");
        return;
    }
    printf("\nTitle\t\tArtist\t\tAlbum\t\tYear\n");
    printf("%s\t\t%s\t\t%s\t\t%d\n", current->data->title, current->data->artist, current->data->album, current->data->year);
}

void save_songs() {
    if (head == NULL) {
        printf("\nNo songs found!\n");
        return;
    }
    FILE *fp;
    fp = fopen("songs.txt", "w");
    if (fp == NULL) {
        printf("\nError in opening file");
        return;
    }
    Node *current = head;
    while (current != NULL) {
        fprintf(fp, "%s %s %s %d\n", current->data->title, current->data->artist, current->data->album, current->data->year);
        current = current->next;
    }
    fclose(fp);
    printf("\nSongs saved to file successfully!\n");
}

void load_songs() {
    FILE *fp;
    fp = fopen("songs.txt", "r");
    if (fp == NULL) {
        printf("\nNo saved songs found!\n");
        return;
    }
    while (!feof(fp)) {
        Song *song = (Song *)malloc(sizeof(Song));
        fscanf(fp, "%s %s %s %d", song->title, song->artist, song->album, &song->year);
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = song;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    fclose(fp);
    printf("\nSongs loaded from file successfully!\n");
}