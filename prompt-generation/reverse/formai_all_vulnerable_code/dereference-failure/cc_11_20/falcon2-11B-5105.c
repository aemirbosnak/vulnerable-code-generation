//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char diary[10][50];
    char name[50];
    int num_entries = 0;

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("Please enter your name: ");
        fgets(name, 50, stdin);

        if (strlen(name) == 0) {
            printf("Name cannot be empty.\n");
            continue;
        }

        printf("Please enter your age: ");
        scanf("%d", &num_entries);

        if (num_entries < 1 || num_entries > 120) {
            printf("Age must be between 1 and 120.\n");
            continue;
        }

        printf("Please enter a short description of your day: ");
        fgets(diary[num_entries], 50, stdin);

        printf("Your entry has been saved!\n");
        break;
    }

    while (1) {
        printf("Please enter your name: ");
        fgets(name, 50, stdin);

        if (strlen(name) == 0) {
            printf("Name cannot be empty.\n");
            continue;
        }

        int num_matches = 0;
        for (int i = 0; i < num_entries; i++) {
            if (strcmp(diary[i], name) == 0) {
                printf("%s's entry: %s\n", name, diary[i]);
                num_matches++;
            }
        }

        if (num_matches == 0) {
            printf("No matching entries found.\n");
        } else if (num_matches == 1) {
            printf("You have 1 matching entry: %s\n", diary[num_matches - 1]);
        } else {
            printf("You have %d matching entries:\n", num_matches);
            for (int i = 0; i < num_matches; i++) {
                printf("%s: %s\n", diary[i], diary[i + 1]);
            }
        }

        printf("Would you like to view another entry? (y/n): ");
        char choice[10];
        fgets(choice, 10, stdin);

        if (choice[0]!= 'y' && choice[0]!= 'Y') {
            printf("Goodbye!\n");
            break;
        }
    }

    return 0;
}