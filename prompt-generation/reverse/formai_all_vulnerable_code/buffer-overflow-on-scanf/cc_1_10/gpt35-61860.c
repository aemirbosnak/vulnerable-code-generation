//FormAI DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

struct Entry {
    char date[20];
    char heading[50];
    char content[1000];
};

int total_entries = 0;
struct Entry diary[MAX_ENTRIES];

void read_diary()
{
    FILE *fp;
    fp = fopen("diary.txt", "r");
    if(fp == NULL) {
        printf("No diary entries found!\n");
        return;
    }
    while(!feof(fp)) {
        fscanf(fp, "%[^\n] %[^\n] %[^\n]\n", diary[total_entries].date, 
                                               diary[total_entries].heading, 
                                               diary[total_entries].content);
        total_entries++;
    }
    fclose(fp);
}

void write_diary()
{
    FILE *fp;
    fp = fopen("diary.txt", "a");
    if(fp == NULL) {
        printf("Error writing to diary! Please try again later.\n");
        return;
    }
    printf("Enter today's date (dd-mm-yyyy): ");
    scanf(" %[^\n]", diary[total_entries].date);
    printf("Enter the heading for the entry: ");
    scanf(" %[^\n]", diary[total_entries].heading);
    printf("Enter the content of the entry: ");
    scanf(" %[^\n]", diary[total_entries].content);
    fprintf(fp, "%s\n%s\n%s\n", diary[total_entries].date, 
                                diary[total_entries].heading, 
                                diary[total_entries].content);
    fclose(fp);
    printf("Entry added successfully!\n");
    total_entries++;
}

void print_diary()
{
    if(total_entries == 0) {
        printf("No entries in diary!\n");
        return;
    }
    printf("Total entries: %d\n", total_entries);
    for(int i = 0; i < total_entries; i++) {
        printf("\nEntry %d:\n", i+1);
        printf("\tDate: %s\n", diary[i].date);
        printf("\tHeading: %s\n", diary[i].heading);
        printf("\tContent: %s\n", diary[i].content);
    }
}

int main()
{
    int choice;
    read_diary();
    printf("Welcome to your digital diary!\n");
    do {
        printf("\nWhat would you like to do today?\n");
        printf("1. Add an entry\n2. View entries\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: write_diary();
                    break;
            case 2: print_diary();
                    break;
            case 3: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    } while(1);
    return 0;
}