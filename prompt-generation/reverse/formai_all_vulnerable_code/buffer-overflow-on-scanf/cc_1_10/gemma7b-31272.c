//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Music_Record {
    char title[50];
    char artist[50];
    char genre[50];
    int quantity;
} Music_Record;

Music_Record music_records[MAX_SIZE];

void insert_record() {
    Music_Record new_record;

    printf("Enter the title: ");
    scanf("%s", new_record.title);

    printf("Enter the artist: ");
    scanf("%s", new_record.artist);

    printf("Enter the genre: ");
    scanf("%s", new_record.genre);

    printf("Enter the quantity: ");
    scanf("%d", &new_record.quantity);

    for (int i = 0; i < MAX_SIZE; i++) {
        if (music_records[i].quantity == 0) {
            music_records[i] = new_record;
            break;
        }
    }
}

void search_record() {
    char search_term[50];

    printf("Enter the search term: ");
    scanf("%s", search_term);

    for (int i = 0; i < MAX_SIZE; i++) {
        if (strstr(music_records[i].title, search_term) ||
            strstr(music_records[i].artist, search_term) ||
            strstr(music_records[i].genre, search_term)) {
            printf("Title: %s\n", music_records[i].title);
            printf("Artist: %s\n", music_records[i].artist);
            printf("Genre: %s\n", music_records[i].genre);
            printf("Quantity: %d\n", music_records[i].quantity);
            printf("\n");
        }
    }
}

void update_record() {
    char update_title[50];

    printf("Enter the title of the record you want to update: ");
    scanf("%s", update_title);

    for (int i = 0; i < MAX_SIZE; i++) {
        if (strcmp(music_records[i].title, update_title) == 0) {
            printf("Enter the new title: ");
            scanf("%s", music_records[i].title);

            printf("Enter the new artist: ");
            scanf("%s", music_records[i].artist);

            printf("Enter the new genre: ");
            scanf("%s", music_records[i].genre);

            printf("Enter the new quantity: ");
            scanf("%d", &music_records[i].quantity);

            break;
        }
    }
}

void delete_record() {
    char delete_title[50];

    printf("Enter the title of the record you want to delete: ");
    scanf("%s", delete_title);

    for (int i = 0; i < MAX_SIZE; i++) {
        if (strcmp(music_records[i].title, delete_title) == 0) {
            music_records[i].quantity = 0;
            break;
        }
    }
}

int main() {
    int choice;

    printf("Welcome to the Music Library Management System!\n");

    printf("1. Insert Record\n");
    printf("2. Search Record\n");
    printf("3. Update Record\n");
    printf("4. Delete Record\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insert_record();
            break;
        case 2:
            search_record();
            break;
        case 3:
            update_record();
            break;
        case 4:
            delete_record();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}