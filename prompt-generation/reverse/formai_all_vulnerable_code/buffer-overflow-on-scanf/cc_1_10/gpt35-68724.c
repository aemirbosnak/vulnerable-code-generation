//FormAI DATASET v1.0 Category: Music Library Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[30];
    char artist[30];
    char album[30];
    int year;
};

struct Node {
    struct Song song;
    struct Node* next;
};

void display_menu() {
    printf("\nWelcome to My Music Library\n");
    printf("\n1. Add Song");
    printf("\n2. Display All Songs");
    printf("\n3. Search by Title");
    printf("\n4. Search by Artist");
    printf("\n5. Search by Album");
    printf("\n6. Quit");
}

void add_song(struct Node** head_ref) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter song title: ");
    scanf("%s", new_node->song.title);
    printf("Enter artist name: ");
    scanf("%s", new_node->song.artist);
    printf("Enter album name: ");
    scanf("%s", new_node->song.album);
    printf("Enter release year: ");
    scanf("%d", &new_node->song.year);
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("\nSong successfully added to library!\n");
}

void display_all_songs(struct Node* root) {
    if (root == NULL) {
        printf("\nThere are no songs in your library!\n");
    }
    else {
        printf("\nAll Songs in Your Library\n");
        printf("------------------------------------\n");
        while (root != NULL) {
            printf("Title: %s\n", root->song.title);
            printf("Artist: %s\n", root->song.artist);
            printf("Album: %s\n", root->song.album);
            printf("Year: %d\n", root->song.year);
            printf("------------------------------------\n");
            root = root->next;
        }
    }
}

void search_by_title(struct Node* root, char title[]) {
    int count = 0;
    while (root != NULL) {
        if (strcmp(root->song.title, title) == 0) {
            printf("\nSong Found!\n");
            printf("------------------------------------\n");
            printf("Title: %s\n", root->song.title);
            printf("Artist: %s\n", root->song.artist);
            printf("Album: %s\n", root->song.album);
            printf("Year: %d\n", root->song.year);
            printf("------------------------------------\n");
            count++;
        }
        root = root->next;
    }
    if (count == 0) {
        printf("\nNo songs found with that title.\n");
    }
}

void search_by_artist(struct Node* root, char artist[]) {
    int count = 0;
    while (root != NULL) {
        if (strcmp(root->song.artist, artist) == 0) {
            printf("\nSong Found!\n");
            printf("------------------------------------\n");
            printf("Title: %s\n", root->song.title);
            printf("Artist: %s\n", root->song.artist);
            printf("Album: %s\n", root->song.album);
            printf("Year: %d\n", root->song.year);
            printf("------------------------------------\n");
            count++;
        }
        root = root->next;
    }
    if (count == 0) {
        printf("\nNo songs found with that artist.\n");
    }
}

void search_by_album(struct Node* root, char album[]) {
    int count = 0;
    while (root != NULL) {
        if (strcmp(root->song.album, album) == 0) {
            printf("\nSong Found!\n");
            printf("------------------------------------\n");
            printf("Title: %s\n", root->song.title);
            printf("Artist: %s\n", root->song.artist);
            printf("Album: %s\n", root->song.album);
            printf("Year: %d\n", root->song.year);
            printf("------------------------------------\n");
            count++;
        }
        root = root->next;
    }
    if (count == 0) {
        printf("\nNo songs found with that album name.\n");
    }
}

int main() {
    struct Node* head = NULL;
    int choice;
    do {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_song(&head);
                break;
            case 2:
                display_all_songs(head);
                break;
            case 3: {
                char title[30];
                printf("\nEnter title to search: ");
                scanf("%s", title);
                search_by_title(head, title);
                break;
            }
            case 4: {
                char artist[30];
                printf("\nEnter artist to search: ");
                scanf("%s", artist);
                search_by_artist(head, artist);
                break;
            }
            case 5: {
                char album[30];
                printf("\nEnter album to search: ");
                scanf("%s", album);
                search_by_album(head, album);
                break;
            }
            case 6:
                printf("\nHave a nice day!");
                break;
            default:
                printf("\nInvalid choice, please enter a valid choice!");
        }
    } while (choice != 6);
    return 0;
}