//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[15];
} entry_t;

int main() {
    FILE *fp;
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;

    fp = fopen("phonebook.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %s", entries[num_entries].name, entries[num_entries].phone)!= EOF) {
        num_entries++;
    }

    fclose(fp);

    do {
        system("clear"); // Clear the console

        printf("\nPhonebook\n");
        for (int i = 0; i < num_entries; i++) {
            printf("%d. %s - %s\n", i+1, entries[i].name, entries[i].phone);
        }

        printf("\nWhat would you like to do?\n");
        printf("A - Add an entry\n");
        printf("S - Search for an entry\n");
        printf("Q - Quit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                system("clear");
                printf("\nAdd an entry:\n");
                printf("Name: ");
                scanf("%s", entries[num_entries].name);
                printf("Phone: ");
                scanf("%s", entries[num_entries].phone);
                num_entries++;
                printf("\nEntry added.\n");
                break;
            case 'S':
                system("clear");
                printf("\nSearch for an entry:\n");
                printf("Name: ");
                scanf("%s", entries[num_entries-1].name);
                printf("\nPhone: %s\n", entries[num_entries-1].phone);
                break;
            case 'Q':
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= 'Q');

    return 0;
}