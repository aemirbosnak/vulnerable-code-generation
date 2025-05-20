//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[100];
    char artist[100];
    char album[100];
    int year;
};

struct node {
    struct song s;
    struct node *next;
};

struct node* head = NULL;

void add_song() {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter song title: ");
    scanf("%s", temp->s.title);
    printf("Enter artist name: ");
    scanf("%s", temp->s.artist);
    printf("Enter album name: ");
    scanf("%s", temp->s.album);
    printf("Enter year of release: ");
    scanf("%d", &temp->s.year);
    temp->next = head;
    head = temp;
    printf("Song added successfully!\n\n");
}

void search_song(char* title) {
    struct node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->s.title, title) == 0) {
            printf("Title: %s\n", temp->s.title);
            printf("Artist: %s\n", temp->s.artist);
            printf("Album: %s\n", temp->s.album);
            printf("Year: %d\n", temp->s.year);
            return;
        }
        temp = temp->next;
    }
    printf("Song not found!\n");
}

void print_library() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("Title: %s\n", temp->s.title);
        printf("Artist: %s\n", temp->s.artist);
        printf("Album: %s\n", temp->s.album);
        printf("Year: %d\n\n", temp->s.year);
        temp = temp->next;
    }
}

int main() {
    int choice;
    char title[100];
    while (1) {
        printf("1. Add song\n");
        printf("2. Search song\n");
        printf("3. Print library\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                printf("Enter song title: ");
                scanf("%s", title);
                search_song(title);
                break;
            case 3:
                print_library();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n\n");
        }
    }
    return 0;
}