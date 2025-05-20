//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char date[12];
    char entry[1000];
} Entry;

int main() {
    FILE *fp;
    Entry entry;
    char filename[20];
    int choice, i, j;
    char ch;

    printf("Welcome to Digital Diary!\n");
    printf("Please enter your name: ");
    scanf("%s", entry.entry);

    while(1) {
        printf("\n\n1. New Entry\n2. View Entries\n3. Search Entries\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the date (dd/mm/yyyy): ");
                scanf("%s", entry.date);
                printf("Enter your entry:\n");
                fgets(entry.entry, sizeof(entry.entry), stdin);
                entry.entry[strcspn(entry.entry, "\n")] = '\0';
                break;

            case 2:
                printf("\nViewing entries...\n");
                strcpy(filename, "diary.txt");
                fp = fopen(filename, "r");

                if(fp == NULL) {
                    printf("\nNo entries found.\n");
                } else {
                    while(fgets(entry.entry, sizeof(entry.entry), fp)!= NULL) {
                        printf("%s", entry.entry);
                    }
                }

                fclose(fp);
                break;

            case 3:
                printf("\nEnter the date to search for (dd/mm/yyyy): ");
                scanf("%s", entry.date);

                strcpy(filename, "diary.txt");
                fp = fopen(filename, "r");

                if(fp == NULL) {
                    printf("\nNo entries found.\n");
                } else {
                    while(fgets(entry.entry, sizeof(entry.entry), fp)!= NULL) {
                        if(strcmp(entry.date, entry.entry) == 0) {
                            printf("%s", entry.entry);
                        }
                    }
                }

                fclose(fp);
                break;

            case 4:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}