//FormAI DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct diary_entry {
    char date[20];
    char content[500];
};

int main() {
    char choice;
    struct diary_entry entry;
    FILE *diary_file;

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("\ta) Add new entry\n");
        printf("\tb) View previous entries\n");
        printf("\tc) Exit\n");
        printf("Your choice: ");
        scanf(" %c", &choice);
        
        if (choice == 'a') {
            printf("\nEnter date (YYYY-MM-DD): ");
            scanf(" %s", entry.date);
            printf("Enter content: ");
            scanf(" %[^\n]%*c", entry.content);
            
            diary_file = fopen("diary.txt", "a");
            if (diary_file == NULL) {
                printf("Error opening file!");
                exit(1);
            }
            fprintf(diary_file, "%s,%s\n", entry.date, entry.content);
            fclose(diary_file);
        }
        
        else if (choice == 'b') {
            diary_file = fopen("diary.txt", "r");
            if (diary_file == NULL) {
                printf("Error opening file!");
                exit(1);
            }
            printf("\nPrevious Entries:\n");
            printf("------------------\n");
            while(fscanf(diary_file, "%[^,],%[^\n]\n", entry.date, entry.content) == 2) {
                printf("Date: %s\n", entry.date);
                printf("Content: %s\n\n", entry.content);
            }
            fclose(diary_file);
        }
        
        else if (choice == 'c') {
            printf("\nGoodbye!\n");
            exit(0);
        }
        
        else {
            printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
}