//FormAI DATASET v1.0 Category: Music Library Management System ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct music {
    char title[20];
    char artist[20];
    char album[20];
    int year;
};

int main() {
    // declaration of variables
    char response, search_term[20];
    int option, size = 0, index = -1;
    struct music m[MAX_SIZE];

    // initial welcome message
    printf("\nWelcome to the Music Library Management System!\n");

    do {
        // display menu options
        printf("\n1. Add music record\n");
        printf("2. Search music records\n");
        printf("3. Edit music record\n");
        printf("4. Delete music record\n");
        printf("5. View all music records\n");
        printf("6. Exit\n");

        // get user input for menu option
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &option);

        // switch case for each option
        switch(option) {
            case 1: // add music record
                if(size == MAX_SIZE) { // check if array is full
                    printf("\nError: Music library is full!\n");
                    break;
                }
                printf("\nEnter music title: ");
                scanf("%s", m[size].title);
                printf("Enter artist name: ");
                scanf("%s", m[size].artist);
                printf("Enter album name: ");
                scanf("%s", m[size].album);
                printf("Enter year of release: ");
                scanf("%d", &m[size].year);
                printf("\nRecord added!\n");
                size++;
                break;

            case 2: // search music record
                if(size == 0) { // check if array is empty
                    printf("\nError: Music library is empty!\n");
                    break;
                }
                printf("\nEnter search term: ");
                scanf("%s", search_term);
                index = -1; // reset index
                printf("\nSearch Results:\n");
                for(int i=0; i<size; i++) {
                    if(strstr(m[i].title, search_term) != NULL || strstr(m[i].artist, search_term) != NULL || strstr(m[i].album, search_term) != NULL ||
                       m[i].year == atoi(search_term)) { // check if any record matches search term
                        printf("%s | %s | %s | %d\n", m[i].title, m[i].artist, m[i].album, m[i].year);
                        index = i; // update index
                    }
                }
                if(index == -1) { // check if no record matches search term
                    printf("No match found!\n");
                }
                break;

            case 3: // edit music record
                if(size == 0) { // check if array is empty
                    printf("\nError: Music library is empty!\n");
                    break;
                }
                printf("\nEnter title of record to edit: ");
                scanf("%s", search_term);
                index = -1; // reset index
                for(int i=0; i<size; i++) {
                    if(strcmp(m[i].title, search_term) == 0) { // check if title matches search term
                        index = i; // update index
                        break;
                    }
                }
                if(index == -1) { // check if no record matches search term
                    printf("\nError: No record found with given title!\n");
                    break;
                }
                printf("\nEnter new title (or press enter to keep current title): ");
                scanf("%s", m[index].title);
                printf("Enter new artist name (or press enter to keep current artist): ");
                scanf("%s", m[index].artist);
                printf("Enter new album name (or press enter to keep current album): ");
                scanf("%s", m[index].album);
                printf("Enter new year of release (or press 0 to keep current year): ");
                scanf("%d", &m[index].year);
                printf("\nRecord updated!\n");
                break;

            case 4: // delete music record
                if(size == 0) { // check if array is empty
                    printf("\nError: Music library is empty!\n");
                    break;
                }
                printf("\nEnter title of record to delete: ");
                scanf("%s", search_term);
                index = -1; // reset index
                for(int i=0; i<size; i++) {
                    if(strcmp(m[i].title, search_term) == 0) { // check if title matches search term
                        index = i; // update index
                        break;
                    }
                }
                if(index == -1) { // check if no record matches search term
                    printf("\nError: No record found with given title!\n");
                    break;
                }
                for(int i=index; i<size-1; i++) { // shift array elements
                    strcpy(m[i].title, m[i+1].title);
                    strcpy(m[i].artist, m[i+1].artist);
                    strcpy(m[i].album, m[i+1].album);
                    m[i].year = m[i+1].year;
                }
                printf("\nRecord deleted!\n");
                size--;
                break;

            case 5: // view all music records
                if(size == 0) { // check if array is empty
                    printf("\nError: Music library is empty!\n");
                    break;
                }
                printf("\nAll Music Records:\n");
                for(int i=0; i<size; i++) {
                    printf("%s | %s | %s | %d\n", m[i].title, m[i].artist, m[i].album, m[i].year);
                }
                break;

            case 6: // exit program
                printf("\nThank you for using the Music Library Management System!");
                exit(0);
                break;

             default: // invalid input
                printf("\nError: Invalid input! Please choose an option between 1-6.\n");
                break;
        }

        // ask user if they want to continue
        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &response);

    } while(response == 'y' || response == 'Y');

    // exit program
    printf("\nThank you for using the Music Library Management System!");
    return 0;
}