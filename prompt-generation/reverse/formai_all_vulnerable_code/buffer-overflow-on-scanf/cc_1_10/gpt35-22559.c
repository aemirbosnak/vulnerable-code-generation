//FormAI DATASET v1.0 Category: Music Library Management System ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

// Define a structure to represent a music library item
struct music_item {
    char name[50];
    char artist[50];
    int year;
};

int main() {
    int choice, num_items = 0;
    struct music_item *library = NULL;

    printf("Welcome to the Music Library Management System!\n");

    while(1) {
        printf("\nPlease select an option:\n1. Add music item\n2. Display all music items\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                num_items++;
                library = (struct music_item*)realloc(library, num_items * sizeof(struct music_item));

                printf("Enter name of music item: ");
                scanf("%s", library[num_items-1].name);

                printf("Enter artist of music item: ");
                scanf("%s", library[num_items-1].artist);

                printf("Enter year of music item: ");
                scanf("%d", &library[num_items-1].year);

                printf("Music item added successfully!\n");
                break;

            case 2:
                if(num_items == 0) {
                    printf("No music items found.\n");
                }
                else {
                    printf("List of music items in library:\n");
                    printf("%-50s %-50s %-10s\n", "Name", "Artist", "Year");

                    for(int i=0;i<num_items;i++) {
                        printf("%-50s %-50s %-10d\n", library[i].name, library[i].artist, library[i].year);
                    }
                }
                break;

            case 3:
                printf("Thank you for using the Music Library Management System!\n");
                free(library);
                return 0;

            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    }
}