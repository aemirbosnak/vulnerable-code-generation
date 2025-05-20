//FormAI DATASET v1.0 Category: Digital Diary ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Entry {
    char title[50];
    char date[20];
    char content[1000];
};

void addEntry(FILE *diary);
void viewEntries(FILE *diary);
void searchEntries(FILE *diary);
void deleteEntry(FILE *diary);

int main() {
    FILE *diary;

    diary = fopen("digital_diary.txt", "a+"); //read and append

    if(diary == NULL) {
        printf("Error: Unable to open file");
        exit(1);
    }

    int choice;

    do {
        printf("\nWelcome to your digital diary!\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Delete an entry\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEntry(diary);
                break;
            case 2:
                viewEntries(diary);
                break;
            case 3:
                searchEntries(diary);
                break;
            case 4:
                deleteEntry(diary);
                break;
            case 5:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }

    }while(choice != 5);

    fclose(diary);

    return 0;
}

void addEntry(FILE *diary) {
    struct Entry entry;

    printf("\nEnter title: ");
    scanf(" %[^\n]%*c", entry.title);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", entry.date);
    printf("Enter content: ");
    scanf(" %[^\n]%*c", entry.content);

    fprintf(diary, "%s\n%s\n%s\n", entry.title, entry.date, entry.content);

    printf("\nEntry successfully added!\n");
}

void viewEntries(FILE *diary) {
    char c;
    rewind(diary);

    while((c = fgetc(diary)) != EOF) {
        putchar(c);
    }
}

void searchEntries(FILE *diary) {
    char keyword[50], line[1000];

    printf("\nEnter keyword to search: ");
    scanf("%s", keyword);

    rewind(diary);

    while(fgets(line, 1000, diary) != NULL) {
        if(strstr(line, keyword) != NULL) {
            printf("%s%s%s", line, fgets(line, 1000, diary), fgets(line, 1000, diary));
        }
    }
}

void deleteEntry(FILE *diary) {
    char title[50], date[20];
    char temp[1000], c;
    int found = 0;

    printf("\nEnter title of entry to delete: ");
    scanf(" %[^\n]%*c", title);
    printf("Enter date of entry (dd/mm/yyyy): ");
    scanf("%s", date);

    rewind(diary);

    while(!feof(diary)) {
        fgets(temp, 1000, diary);

        if(strncmp(title, temp, strlen(title)-1) == 0 && fgets(temp, 1000, diary) != NULL && strncmp(date, temp, strlen(date)) == 0) {
            fgets(temp, 1000, diary); //move to next line after content
            found = 1;
            break;
        }
    }

    if(found) {
        FILE *tempFile = fopen("temp.txt", "w"); //temporary file to hold diary without deleted entry

        rewind(diary);

        while((c = fgetc(diary)) != EOF) {
            if(c == '\n') {
                temp[0] = '\0';
                fgets(temp, 1000, diary); //move to next line
                if(strncmp(title, temp, strlen(title)-1) == 0 && fgets(temp, 1000, diary) != NULL && strncmp(date, temp, strlen(date)) == 0) {
                    fgets(temp, 1000, diary);
                    continue; //skip deleting line
                }
            }
            fputc(c, tempFile);
        }

        fclose(diary);
        fclose(tempFile);

        remove("digital_diary.txt");
        rename("temp.txt", "digital_diary.txt");

        diary = fopen("digital_diary.txt", "a+");
        printf("\nEntry successfully deleted!\n");
    } else {
        printf("\nEntry not found. Please try again.\n");
    }
}