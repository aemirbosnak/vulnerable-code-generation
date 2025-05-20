//FormAI DATASET v1.0 Category: Phone Book ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct PhoneBook {
    char name[30];
    char number[15];
};

struct PhoneBook pb[MAX];
int num_entries = 0;

void addEntry() {
    if (num_entries < MAX) {
        printf("Enter name: ");
        fflush(stdin);
        fgets(pb[num_entries].name, 30, stdin);
        pb[num_entries].name[strcspn(pb[num_entries].name, "\n")] = '\0'; // remove trailing newline
        printf("Enter phone number (format [XXX-XXX-XXXX]): ");
        fflush(stdin);
        fgets(pb[num_entries].number, 15, stdin);
        pb[num_entries].number[strcspn(pb[num_entries].number, "\n")] = '\0'; // remove trailing newline
        printf("\nEntry added successfully!\n\n");
        num_entries++;
    } else {
        printf("\nThe phone book is full. No more entries can be added.\n\n");
    }
}

void searchEntry() {
    char name[30];
    printf("Enter the name to be searched: ");
    fflush(stdin);
    fgets(name, 30, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove trailing newline
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(name, pb[i].name) == 0) {
            printf("\nName: %s\tNumber: %s\n\n", pb[i].name, pb[i].number);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nEntry not found.\n\n");
    }
}

void displayEntries() {
    if (num_entries == 0) {
        printf("\nThe phone book is empty.\n\n");
    } else {
        printf("\nPhone Book Entries:\n");
        for (int i = 0; i < num_entries; i++) {
            printf("Name: %s\tNumber: %s\n", pb[i].name, pb[i].number);
        }
        printf("\n");
    }
}

void saveToFile() {
    char filename[50];
    printf("Enter the filename to save: ");
    fflush(stdin);
    fgets(filename, 50, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // remove trailing newline
    FILE *fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("\nError: Could not open file.\n\n");
    } else {
        for (int i = 0; i < num_entries; i++) {
            fprintf(fptr, "%s,%s\n", pb[i].name, pb[i].number);
        }
        fclose(fptr);
        printf("\nData saved successfully to file.\n\n");
    }
}

void loadFromFile() {
    char filename[50];
    printf("Enter the filename to load: ");
    fflush(stdin);
    fgets(filename, 50, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // remove trailing newline
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("\nError: Could not open file.\n\n");
    } else {
        num_entries = 0;
        while(fscanf(fptr, "%[^,],%s\n", pb[num_entries].name, pb[num_entries].number) == 2) {
            num_entries++;
        }
        fclose(fptr);
        printf("\nData loaded successfully from file.\n\n");
    }
}

int main() {
    int choice;
    while(1) {
        printf("1. Add entry\n2. Search entry\n3. Display entries\n4. Save to file\n5. Load from file\n6. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                searchEntry();
                break;
            case 3:
                displayEntries();
                break;
            case 4:
                saveToFile();
                break;
            case 5:
                loadFromFile();
                break;
            case 6:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n\n");
        }
    }
    return 0;
}