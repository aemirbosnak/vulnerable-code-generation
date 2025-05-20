//FormAI DATASET v1.0 Category: Music Library Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Music {
    char title[50];
    char artist[50];
    char genre[20];
    int year;
};

struct Node {
    struct Music data;
    struct Node *next;
};

struct Node *head = NULL;
int count = 0;

void addMusic() {
    struct Music m;

    printf("Enter Title: ");
    scanf("%s", m.title);

    printf("Enter Artist: ");
    scanf("%s", m.artist);

    printf("Enter Genre: ");
    scanf("%s", m.genre);

    printf("Enter Year: ");
    scanf("%d", &m.year);

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = m;
    temp->next = head;
    head = temp;

    count++;
    printf("\nMusic added successfully.\n");
}

void searchMusic() {
    char temp[50];
    int found = 0;

    printf("Enter title to be searched: ");
    scanf("%s", temp);

    struct Node *ptr = head;
    while(ptr != NULL) {
        if(strcmp(ptr->data.title, temp) == 0) {
            printf("\nTitle: %s\n", ptr->data.title);
            printf("Artist: %s\n", ptr->data.artist);
            printf("Genre: %s\n", ptr->data.genre);
            printf("Year: %d\n", ptr->data.year);
            found = 1;
            break;
        }
        ptr = ptr->next;
    }

    if(found == 0) {
        printf("\nMusic not found.\n");
    }
}

void displayMusic() {
    struct Node *ptr = head;
    if(ptr == NULL) {
        printf("\nNo Music found.\n");
    }
    while(ptr != NULL) {
        printf("\nTitle: %s\n", ptr->data.title);
        printf("Artist: %s\n", ptr->data.artist);
        printf("Genre: %s\n", ptr->data.genre);
        printf("Year: %d\n", ptr->data.year);

        ptr = ptr->next;
    }
}

void deleteMusic() {
    char temp[50];
    int found = 0;

    printf("Enter title to be deleted: ");
    scanf("%s", temp);

    struct Node *ptr = head;
    struct Node *prev = NULL;

    while(ptr != NULL) {
        if(strcmp(ptr->data.title, temp) == 0) {
            if(prev == NULL) {
                head = ptr->next;
            } else {
                prev->next = ptr->next;
            }

            found = 1;
            count--;
            free(ptr);
            break;
        }

        prev = ptr;
        ptr = ptr->next;
    }

    if(found == 0) {
        printf("\nMusic not found.\n");
    } else {
        printf("\nMusic deleted successfully.\n");
    }
}

void saveMusic() {
    FILE *fp = fopen("MusicLibrary.txt", "w");
    struct Node *ptr = head;

    while(ptr != NULL) {
        fprintf(fp, "%s %s %s %d\n", ptr->data.title, ptr->data.artist, ptr->data.genre, ptr->data.year);

        ptr = ptr->next;
    }

    fclose(fp);
    printf("\nMusic library saved successfully.\n");
}

void loadMusic() {
    FILE *fp = fopen("MusicLibrary.txt", "r");
    if(fp == NULL) {
        printf("\nNo Music library found.\n");
        return;
    }

    struct Music m;
    while(fscanf(fp, "%s %s %s %d\n", m.title, m.artist, m.genre, &m.year) != EOF) {
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = m;
        temp->next = head;
        head = temp;

        count++;
    }

    fclose(fp);
    printf("\nMusic library loaded successfully.\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n---------Music Library Management System---------\n");
        printf("1. Add music to library\n");
        printf("2. Search for music\n");
        printf("3. Display all music\n");
        printf("4. Delete music from library\n");
        printf("5. Save library to file\n");
        printf("6. Load library from file\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMusic();
                break;
            case 2:
                searchMusic();
                break;
            case 3:
                displayMusic();
                break;
            case 4:
                deleteMusic();
                break;
            case 5:
                saveMusic();
                break;
            case 6:
                loadMusic();
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}