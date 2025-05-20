//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

struct entry {
    char date[20];
    char title[MAX_ENTRY_LENGTH];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *fptr;
    char filename[50];
    char choice;
    int count = 0;
    struct entry diary[MAX_ENTRIES];

    printf("Welcome to Digital Diary!\n");
    printf("Please enter your name:\n");
    scanf("%s", &filename);

    strcat(filename, ".txt");
    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("\nFile not found! Creating new file...\n");
        fptr = fopen(filename, "w");
    }

    while (count < MAX_ENTRIES) {
        fscanf(fptr, "%s %s %s", diary[count].date, diary[count].title, diary[count].content);
        count++;
    }

    fclose(fptr);

    do {
        printf("\nSelect an option:\n");
        printf("1. Add Entry\n2. View Entries\n3. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("\nEnter date (dd/mm/yyyy):\n");
                scanf("%s", diary[count].date);
                printf("Enter title:\n");
                scanf("%s", diary[count].title);
                printf("Enter content:\n");
                scanf("%[^\n]", diary[count].content);
                count++;
                fptr = fopen(filename, "w");
                for (int i = 0; i < count; i++) {
                    fprintf(fptr, "%s %s %s\n", diary[i].date, diary[i].title, diary[i].content);
                }
                fclose(fptr);
                printf("\nEntry added successfully!\n");
                break;

            case '2':
                printf("\nViewing Entries:\n");
                for (int i = 0; i < count; i++) {
                    printf("%s %s %s\n", diary[i].date, diary[i].title, diary[i].content);
                }
                break;

            case '3':
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice!= '3');

    return 0;
}