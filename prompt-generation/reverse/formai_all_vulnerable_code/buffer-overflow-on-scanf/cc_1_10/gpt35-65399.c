//FormAI DATASET v1.0 Category: Music Library Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

typedef struct music {
    int id;
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char genre[MAX_LENGTH];
    int year;
} Music;

typedef struct music_node {
    Music music_data;
    struct music_node* prev;
    struct music_node* next;
} MusicNode;

void print_music(MusicNode* music_node) {
    printf("ID: %d\n", music_node->music_data.id);
    printf("Title: %s\n", music_node->music_data.title);
    printf("Artist: %s\n", music_node->music_data.artist);
    printf("Genre: %s\n", music_node->music_data.genre);
    printf("Year: %d\n", music_node->music_data.year);
}

void add_music_node(MusicNode** head, MusicNode** tail, Music music_data) {
    MusicNode* new_node = (MusicNode*) malloc(sizeof(MusicNode));
    new_node->music_data = music_data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        *tail = new_node;
        return;
    }

    (*tail)->next = new_node;
    new_node->prev = *tail;
    *tail = new_node;
}

void delete_music_node(MusicNode** head, MusicNode** tail, int id) {
    if (*head == NULL) {
        printf("Music Library is empty!\n");
        return;
    }

    MusicNode* current_node = *head;
    while (current_node != NULL) {
        if (current_node->music_data.id == id) {
            if (current_node == *head && current_node == *tail) {
                *head = NULL;
                *tail = NULL;
            }
            else if (current_node == *head) {
                *head = current_node->next;
                (*head)->prev = NULL;
            }
            else if (current_node == *tail) {
                *tail = current_node->prev;
                (*tail)->next = NULL;
            }
            else {
                current_node->prev->next = current_node->next;
                current_node->next->prev = current_node->prev;
            }
            free(current_node);
            printf("Music with ID %d deleted successfully!\n", id);
            return;
        }
        current_node = current_node->next;
    }

    printf("Music with ID %d not found\n", id);
}

void search_music_node(MusicNode* head) {
    if (head == NULL) {
        printf("Music Library is empty!\n");
        return;
    }

    char search_str[MAX_LENGTH];
    printf("Enter search keyword: ");
    scanf("%s", search_str);

    MusicNode* current_node = head;
    int found = 0;
    while (current_node != NULL) {
        if (strstr(current_node->music_data.title, search_str) != NULL ||
            strstr(current_node->music_data.artist, search_str) != NULL ||
            strstr(current_node->music_data.genre, search_str) != NULL) {
            print_music(current_node);
            found = 1;
        }
        current_node = current_node->next;
    }

    if (!found) {
        printf("No music found with keyword '%s'\n", search_str);
    }
}

void print_all_music(MusicNode* head) {
    if (head == NULL) {
        printf("Music Library is empty!\n");
        return;
    }

    MusicNode* current_node = head;
    while (current_node != NULL) {
        print_music(current_node);
        current_node = current_node->next;
    }
}

int main() {
    MusicNode* head = NULL;
    MusicNode* tail = NULL;

    while (1) {
        printf("\n------ C MUSIC LIBRARY MANAGEMENT SYSTEM ------\n");
        printf("1. Add Music\n");
        printf("2. Delete Music\n");
        printf("3. Search Music\n");
        printf("4. Print All Music\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("\n------ ADD MUSIC ------\n");

                Music music_data;
                printf("Enter Music ID: ");
                scanf("%d", &music_data.id);
                printf("Enter Music Title: ");
                scanf("%s", music_data.title);
                printf("Enter Music Artist: ");
                scanf("%s", music_data.artist);
                printf("Enter Music Genre: ");
                scanf("%s", music_data.genre);
                printf("Enter Music Year: ");
                scanf("%d", &music_data.year);

                add_music_node(&head, &tail, music_data);

                printf("Music added successfully!\n");
                break;
            }
            case 2: {
                printf("\n------ DELETE MUSIC ------\n");

                int id;
                printf("Enter Music ID to delete: ");
                scanf("%d", &id);

                delete_music_node(&head, &tail, id);
                break;
            }
            case 3: {
                printf("\n------ SEARCH MUSIC ------\n");

                search_music_node(head);
                break;
            }
            case 4: {
                printf("\n------ PRINT ALL MUSIC ------\n");

                print_all_music(head);
                break;
            }
            case 5: {
                printf("\n------ THANK YOU FOR USING C MUSIC LIBRARY MANAGEMENT SYSTEM ------\n");
                exit(0);
            }
            default: {
                printf("Invalid choice! Please enter a valid choice.\n");
                break;
            }
        }

    }

    return 0;
}