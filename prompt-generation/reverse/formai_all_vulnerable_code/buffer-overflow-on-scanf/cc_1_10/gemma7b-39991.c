//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a music record
typedef struct music_record {
    char title[50];
    char artist[50];
    char genre[50];
    struct music_record* next;
} music_record;

// Recursive function to insert a music record into the library
void insert_record(music_record* head) {
    music_record* new_record = (music_record*)malloc(sizeof(music_record));
    printf("Enter the title of the music record: ");
    scanf("%s", new_record->title);
    printf("Enter the artist of the music record: ");
    scanf("%s", new_record->artist);
    printf("Enter the genre of the music record: ");
    scanf("%s", new_record->genre);
    new_record->next = NULL;

    if (head == NULL) {
        head = new_record;
    } else {
        insert_record(head->next);
    }
}

// Recursive function to search for a music record in the library
music_record* search_record(music_record* head, char* title) {
    if (head == NULL) {
        return NULL;
    }

    if (strcmp(head->title, title) == 0) {
        return head;
    } else {
        return search_record(head->next, title);
    }
}

// Recursive function to delete a music record from the library
void delete_record(music_record* head, char* title) {
    music_record* previous = NULL;
    music_record* current = head;

    while (current) {
        if (strcmp(current->title, title) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        } else {
            previous = current;
            current = current->next;
        }
    }

    return;
}

int main() {
    music_record* head = NULL;

    // Insert some music records into the library
    insert_record(head);
    insert_record(head);
    insert_record(head);

    // Search for a music record in the library
    music_record* record = search_record(head, "The Beatles - Let Us Be Together");
    if (record) {
        printf("Title: %s\n", record->title);
        printf("Artist: %s\n", record->artist);
        printf("Genre: %s\n", record->genre);
    } else {
        printf("Record not found.\n");
    }

    // Delete a music record from the library
    delete_record(head, "The Rolling Stones - Exile on Main Street");
    record = search_record(head, "The Rolling Stones - Exile on Main Street");
    if (record) {
        printf("Title: %s\n", record->title);
        printf("Artist: %s\n", record->artist);
        printf("Genre: %s\n", record->genre);
    } else {
        printf("Record not found.\n");
    }

    return 0;
}