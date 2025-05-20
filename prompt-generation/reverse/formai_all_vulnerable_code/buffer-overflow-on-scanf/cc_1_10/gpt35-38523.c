//FormAI DATASET v1.0 Category: Music Library Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This structure represents a music album
struct album {
    char title[50];
    char artist[50];
    int year;
    char genre[50];
};

// This structure represents the linked list node
struct node {
    struct album data;
    struct node *next;
};

// This function adds a new album to the linked list
void add_album(struct node **head, struct album data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

// This function searches for an album by title
void search_album(struct node *head, char *title) {
    struct node *current = head;
    while(current != NULL) {
        if(strcmp(current->data.title, title) == 0) {
            printf("Album found:\n");
            printf("Title: %s\n", current->data.title);
            printf("Artist: %s\n", current->data.artist);
            printf("Year: %d\n", current->data.year);
            printf("Genre: %s\n", current->data.genre);
            return;
        }
        current = current->next;
    }
    printf("Album not found.\n");
}

// This function displays all the albums in the linked list
void display_all(struct node *head) {
    struct node *current = head;
    printf("---------------------\n");
    while(current != NULL) {
        printf("Title: %s\n", current->data.title);
        printf("Artist: %s\n", current->data.artist);
        printf("Year: %d\n", current->data.year);
        printf("Genre: %s\n", current->data.genre);
        printf("---------------------\n");
        current = current->next;
    }
}

// This function removes an album from the linked list by title
void remove_album(struct node **head, char *title) {
    struct node *temp = *head, *prev;
    if(temp != NULL && strcmp(temp->data.title, title) == 0) {
        *head = temp->next;
        free(temp);
        printf("Album removed.\n");
        return;
    }
    while(temp != NULL && strcmp(temp->data.title, title) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Album not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Album removed.\n");
}

// This function saves the albums to a file
void save_to_file(struct node *head, char *filename) {
    FILE *fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    struct node *current = head;
    while(current != NULL) {
        fprintf(fp, "%s,%s,%d,%s\n", current->data.title, current->data.artist, current->data.year, current->data.genre);
        current = current->next;
    }
    printf("Data saved to file successfully.\n");
    fclose(fp);
}

// This function reads the albums from a file
void read_from_file(struct node **head, char *filename) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char line[200];
    while(fgets(line, 200, fp)) {
        char *token;
        struct album data;
        token = strtok(line, ",");
        strcpy(data.title, token);
        token = strtok(NULL, ",");
        strcpy(data.artist, token);
        token = strtok(NULL, ",");
        data.year = atoi(token);
        token = strtok(NULL, ",");
        strcpy(data.genre, token);
        add_album(head, data);
    }
    printf("Data read from file successfully.\n");
    fclose(fp);
}

int main() {
    struct node *head = NULL;
    int choice;
    char title[50];
    struct album data;
    char filename[50];
    do {
        printf("--------Music Library Management System--------\n");
        printf("1. Add album\n");
        printf("2. Search album\n");
        printf("3. Display all\n");
        printf("4. Remove album\n");
        printf("5. Save to file\n");
        printf("6. Read from file\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter album details:\n");
                printf("Title: ");
                scanf("%s", data.title);
                printf("Artist: ");
                scanf("%s", data.artist);
                printf("Year: ");
                scanf("%d", &data.year);
                printf("Genre: ");
                scanf("%s", data.genre);
                add_album(&head, data);
                printf("Album added successfully.\n");
                break;
            case 2:
                printf("Enter album title to search: ");
                scanf("%s", title);
                search_album(head, title);
                break;
            case 3:
                display_all(head);
                break;
            case 4:
                printf("Enter album title to remove: ");
                scanf("%s", title);
                remove_album(&head, title);
                break;
            case 5:
                printf("Enter file name to save data: ");
                scanf("%s", filename);
                save_to_file(head, filename);
                break;
            case 6:
                printf("Enter file name to read data: ");
                scanf("%s", filename);
                read_from_file(&head, filename);
                break;
            case 7:
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 7);
    return 0;
}