//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store music information
typedef struct Music {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct Music* next;
} Music;

// Function to insert a music record at the end
void insertMusic(Music* head) {
    Music* newMusic = (Music*)malloc(sizeof(Music));
    printf("Enter the title: ");
    scanf("%s", newMusic->title);
    printf("Enter the artist: ");
    scanf("%s", newMusic->artist);
    printf("Enter the genre: ");
    scanf("%s", newMusic->genre);
    printf("Enter the year: ");
    scanf("%d", &newMusic->year);

    if (head == NULL) {
        head = newMusic;
    } else {
        Music* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newMusic;
    }
}

// Function to display all music records
void displayMusic(Music* head) {
    Music* temp = head;
    printf("Music Library:\n");
    while (temp) {
        printf("Title: %s\n", temp->title);
        printf("Artist: %s\n", temp->artist);
        printf("Genre: %s\n", temp->genre);
        printf("Year: %d\n", temp->year);
        printf("\n");
        temp = temp->next;
    }
}

int main() {
    Music* head = NULL;
    int choice;

    // Loop until the user chooses to exit
    while (1) {
        printf("Enter 1 to insert a music record, 2 to display all music records, or 3 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertMusic(head);
                break;
            case 2:
                displayMusic(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}