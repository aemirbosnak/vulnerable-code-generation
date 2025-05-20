//FormAI DATASET v1.0 Category: Digital Diary ; Style: random
#include<stdio.h>

void writeEntry(char filename[], char entry[]); // Function to write an entry to the digital diary
void displayEntries(char filename[]); // Function to display all entries in the digital diary

int main() {
    char filename[50];
    printf("Enter the name of the diary file: ");
    scanf("%s", filename);
    int choice = 0;

    while(choice != 3) {
        printf("\nEnter your choice:\n");
        printf("1. Write an entry\n");
        printf("2. Display all entries\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char entry[100];
                printf("\nEnter your diary entry (Max 100 characters): ");
                scanf(" %[^\n]s", entry);
                writeEntry(filename, entry);
                break;
            }
            case 2: {
                displayEntries(filename);
                break;
            }
            case 3: {
                printf("\nExiting Digital Diary. Goodbye!\n");
                break;
            }
            default: {
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}

void writeEntry(char filename[], char entry[]) {
    FILE *fp;
    fp = fopen(filename, "a");
    fprintf(fp, "%s\n", entry);
    fclose(fp);
    printf("\nEntry added to diary.\n");
}

void displayEntries(char filename[]) {
    FILE *fp;
    char buffer[100];

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: File not found.");
        return;
    }

    printf("\nDiary Entries:\n");
    while(fgets(buffer, 100, fp)) {
        printf("\n%s", buffer);
    }

    fclose(fp);
}