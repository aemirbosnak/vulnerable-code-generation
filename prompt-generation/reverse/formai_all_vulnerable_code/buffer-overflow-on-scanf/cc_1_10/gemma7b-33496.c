//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store music information
typedef struct MusicRecord {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicRecord* next;
} MusicRecord;

// Function to insert a music record at the end
void insertMusicRecord(MusicRecord* head) {
    MusicRecord* newRecord = (MusicRecord*)malloc(sizeof(MusicRecord));
    printf("Enter the title of the music record: ");
    scanf("%s", newRecord->title);
    printf("Enter the artist of the music record: ");
    scanf("%s", newRecord->artist);
    printf("Enter the genre of the music record: ");
    scanf("%s", newRecord->genre);
    printf("Enter the year of the music record: ");
    scanf("%d", &newRecord->year);

    if (head == NULL) {
        head = newRecord;
    } else {
        MusicRecord* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRecord;
    }
}

// Function to search for a music record
void searchMusicRecord(MusicRecord* head) {
    char searchTitle[50];
    printf("Enter the title of the music record you want to search for: ");
    scanf("%s", searchTitle);

    MusicRecord* temp = head;
    while (temp) {
        if (strcmp(searchTitle, temp->title) == 0) {
            printf("Title: %s\n", temp->title);
            printf("Artist: %s\n", temp->artist);
            printf("Genre: %s\n", temp->genre);
            printf("Year: %d\n", temp->year);
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("No music record found.\n");
    }
}

// Function to delete a music record
void deleteMusicRecord(MusicRecord* head) {
    char deleteTitle[50];
    printf("Enter the title of the music record you want to delete: ");
    scanf("%s", deleteTitle);

    MusicRecord* temp = head;
    MusicRecord* prev = NULL;

    while (temp) {
        if (strcmp(deleteTitle, temp->title) == 0) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("No music record found.\n");
    }
}

int main() {
    MusicRecord* head = NULL;

    while (1) {
        printf("Enter 1 to insert a music record, 2 to search for a music record, 3 to delete a music record, or 4 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertMusicRecord(head);
                break;
            case 2:
                searchMusicRecord(head);
                break;
            case 3:
                deleteMusicRecord(head);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    }

    return 0;
}